#include <wiringPi.h>
#include <stdio.h>
#include "RCSwitch.h"
#include "RcOok.h"
#include "Sensor.h"
#include <ctime>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    int RXPIN = 7;
    int TXPIN = 0;

    if(wiringPiSetup() == -1)
        return 0;

    RCSwitch *rc = new RCSwitch(RXPIN,TXPIN);

    while (1)
    {
         if ( rc->OokAvailable() )
         {
             char message[100];

             rc->getOokCode(message);
             //printf("%s\n",message);

             Sensor *s = Sensor::getRightSensor(message);
             if ( s != NULL )
             {
                 printf("%.2f;%.2f;%d\n",s->getTemperature(), s->getHumidity(),s->getChannel());
             }
             delete s;
          }
          delay(1000);
    }
}

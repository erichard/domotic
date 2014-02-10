all: test

oregon: RCSwitch.o RcOok.o Sensor.o oregon.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o oregon

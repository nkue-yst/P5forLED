CXXFLAGS = -Wall
BINARIES  = Demo CPP_Test_User
LED_INCLUDE_DIR = -I../../../include
LED_LIBRARY_DIR = ../../../lib
LED_LIBRARY 	= $(LED_LIBRARY_DIR)/librgbmatrix.a
LED_FLAGS	    = -lrt -lm -lpthread -lstdc++
JNI_INCLUDE_DIR = -I/usr/lib/jvm/java-1.8.0-openjdk-armhf/include -I/usr/lib/jvm/java-1.8.0-openjdk-armhf/include/linux
LIB_FLAGS		= -fPIC -shared

all : Demo Test

Demo : Demo.o
	$(CXX) $< $(LED_LIBRARY) -o $@ $(LED_FLAGS)

Test : Test.o
	$(CXX) $< $(LED_LIBRARY) $(LED_FLAGS) -o lib$@.so $(LIB_FLAGS)
	#javac Test.java
	#sudo LD_LIBRARY_PATH=. java Test

CPP_Test : CPP_Test.o CPP_Test_User.o
	$(CXX) CPP_Test.o $(LED_LIBRARY) -o lib$@.so $(LIB_FLAGS) $(LED_FLAGS)
	$(CXX) CPP_Test_User.o -o CPP_Test_User -L. -L../../../lib -lCPP_Test

%.o : %.cpp
	$(CXX) $(LED_INCLUDE_DIR) $(JNI_INCLUDE_DIR) $(CXXFLAGS) -c -o $@ $<

clean-log :
	rm -f *.log core

clean : clean-log
	rm -f *.o *.so $(BINARIES) *.class

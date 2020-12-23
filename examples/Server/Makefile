CXXFLAGS = -Wall
OBJECTS  = LED_Server.o
BINARIES = LED_Server
INCLUDE_DIR = -I../../include/server
LIBRARY = -lP5forLED

LED_INCLUDE_DIR = -I../../../include
LED_FLAGS   = -lrt -lm -lpthread -lstdc++

all : $(BINARIES)

LED_Server : LED_Server.o
	$(CXX) $< $(LIBRARY_DIR) $(LIBRARY) $(LED_FLAGS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< $(INCLUDE_DIR) $(LED_INCLUDE_DIR) -c -o $@

clean :
	rm -f $(OBJECTS) $(BINARIES)

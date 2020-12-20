CXXFLAGS = -Wall
OBJECTS  = Server.o
BINARIES = Server
INCLUDE_DIR = -I../../include/server
LIBRARY = -lP5forLED

LED_INCLUDE_DIR = -I../../../include
LED_FLAGS   = -lrt -lm -lpthread -lstdc++

all : $(BINARIES)

Server : Server.o
	$(CXX) $< $(LIBRARY_DIR) $(LIBRARY) $(LED_FLAGS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< $(INCLUDE_DIR) $(LED_INCLUDE_DIR) -c -o $@

clean :
	rm -f $(OBJECTS) $(BINARIES)

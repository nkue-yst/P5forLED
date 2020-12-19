CXXFLAGS = -Wall
OBJECTS  = hello_server.o hello_client.o led_server.o
BINARIES = hello_server hello_client led_server
CLASSES  = Hello_client.class LED_Client.class

LED_INCLUDE_DIR = -I../../../include
LED_LIBRARY_DIR = ../../../lib
LED_LIBRARY = $(LED_LIBRARY_DIR)/librgbmatrix.a
LED_FLAGS   = -lrt -lm -lpthread -lstdc++

all : $(BINARIES) $(CLASSES)

hello_server : hello_server.o
	$(CXX) $< -o $@

hello_client : hello_client.o
	$(CXX) $< -o $@

hello_client-java : Hello_client.class

led_server : led_server.o
	$(CXX) $< $(LED_LIBRARY) $(LED_FLAGS) -o $@

led_client-java : LED_Client.class

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< $(LED_INCLUDE_DIR) -c -o $@

%.class : %.java
	javac $<

clean :
	rm -f $(OBJECTS) $(BINARIES) $(CLASSES)

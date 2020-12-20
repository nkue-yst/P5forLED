CXXFLAGS = -Wall
OBJECTS  = test.o LEDManager.o Socket.o
BINARIES = test

INCLUDE_DIR = -I../../../include/server
LIB_FLAGS   = -fPIC -shared

LED_INCLUDE_DIR = -I../../../../include
LED_LIBRARY_DIR = ../../../../lib
LED_LIBRARY = $(LED_LIBRARY_DIR)/librgbmatrix.a
LED_FLAGS   = -lrt -lm -lpthread -lstdc++

all : $(OBJECTS) $(BINARIES)

install : lib
	sudo mv ../libP5forLED.so /usr/lib/

uninstall : clean
	sudo rm -f /usr/lib/libP5forLED.so

lib : LEDManager.o Socket.o
	$(CXX) $^ $(LED_LIBRARY) $(LED_FLAGS) $(LIB_FLAGS) -o ../libP5forLED.so

test : $(OBJECTS)
	$(CXX) $^ $(LED_LIBRARY) $(LED_FLAGS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< $(INCLUDE_DIR) $(LED_INCLUDE_DIR) -c -o $@

clean :
	rm -f $(OBJECTS) $(BINARIES) ../*.so

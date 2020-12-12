CFLAGS = -Wall
OBJECTS = 01.o 02_lib.o 02.o
LIBRARIES = lib02_lib.so
BINARIES = 01 02

LED_INCLUDE_DIR = ../../../include
LED_LIBRARY_DIR = ../../../lib
LED_LIBRARY = $(LED_LIBRARY_DIR)/librgbmatrix.a
LED_FLAGS  += -L$(LED_LIBRARY_DIR) -lrgbmatrix -lrt -lm -lpthread -lstdc++
LIBFLAGS   += -fPIC -shared

all : $(BINARIES)

01 : 01.o $(LED_LIBRARY)
	$(CC) $< -o $@ $(LED_FLAGS)

02 : 02_lib.o 02.o $(LED_LIBRARY)
	$(CC) $(LIBFLAGS) $< -o lib02_lib.so $(LED_FLAGS)
	$(CC) 02.o -o $@ $(LED_FLAGS) -L./ -l02_lib

%.o : %.c
	$(CC) -I$(LED_INCLUDE_DIR) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJECTS) $(BINARIES) $(LIBRARIES)

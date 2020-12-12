CFLAGS = -Wall
OBJECTS = 04.o 05_lib.o 05.o
LIBRARIES = lib05_lib.so
BINARIES = 04 05

LED_INCLUDE_DIR = ../../../include
LED_LIBRARY_DIR = ../../../lib
LED_LIBRARY = $(LED_LIBRARY_DIR)/librgbmatrix.a
LED_FLAGS  += -L$(LED_LIBRARY_DIR) -lrgbmatrix -lrt -lm -lpthread -lstdc++
LIBFLAGS   += -fPIC -shared

all : $(BINARIES)

04 : 04.o $(LED_LIBRARY)
	$(CC) $< -o $@ $(LED_FLAGS)

05 : 05_lib.o 05.o $(LED_LIBRARY)
	$(CC) $(LIBFLAGS) $< -o lib05_lib.so $(LED_FLAGS)
	$(CC) 05.o -o $@ $(LED_FLAGS) -L./ -l05_lib

%.o : %.c
	$(CC) -I$(LED_INCLUDE_DIR) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJECTS) $(BINARIES) $(LIBRARIES)

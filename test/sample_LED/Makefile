CFLAGS = -Wall
OBJECTS = sample01.o sample02.o sample02-2.o
BINARIES = sample01 libsample02.so sample02-2

INCLUDE_DIR = ../../../include
LIBRARY_DIR = ../../../lib
LIBRARY = $(LIBRARY_DIR)/librgbmatrix.a
LDFLAGS += -L$(LIBRARY_DIR) -lrgbmatrix -lrt -lm -lpthread

sample01 : sample01.o $(LIBRARY)
	$(CC) $< -o $@ $(LDFLAGS) -lstdc++

sample02 : sample02.o sample02-2.o $(LIBRARY)
	$(CC) -fPIC -shared $< -o lib$@.so $(LDFLAGS) -lstdc++
	$(CC) sample02-2.o -o sample02-2 $(LDFLAGS) -lstdc++ -L./ -lsample02

%.o : %.c
	$(CC) -I$(INCLUDE_DIR) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJECTS) $(BINARIES)

CFLAGS    = -Wall
OBJECTS   = 01_lib.o 02.o
LIBRARIES = lib01_lib.so
BINARIES  = 02
LIBFLAGS += -fPIC -shared

CLASSPATH = -cp .:jna.jar
CLASSES   = 03.class

all : 01 02 03 04

01 : 01_lib.o
	$(CC) $(CFLAGS) $(LIBFLAGS) $< -o lib01_lib.so

02 : 01 02.o
	$(CC) $(CFLAGS) 02.o -o $@ -L. -l01_lib

03 : 01 Sample03.class

04 : Sample_Processing01/Sample04.class
	jar cvf Sample_Processing01/Sample04.jar Sample_Processing01/Sample04.class

%.o : %.c
	$(CC) -I$(LED_INCLUDE_DIR) $(CFLAGS) -c -o $@ $<

%.class : %.java
	javac $(CLASSPATH) $<

clean :
	rm -f $(BINARIES) *.class *.so *.o
	rm -f Sample_Processing01/*.class Sample_Processing01/*.jar

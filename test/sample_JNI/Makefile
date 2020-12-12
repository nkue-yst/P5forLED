CFLAGS    = -Wall
OBJECTS   = SimpleIO.o
LIBRARIES = *.so
BINARIES  = 
LIBFLAGS += -fPIC -shared
JNI_DIR   = /usr/lib/jvm/java-1.8.0-openjdk-armhf/include
JNI_DIR2  = /usr/lib/jvm/java-1.8.0-openjdk-armhf/include/linux

all : SimpleIO

SimpleIO : SimpleIO.o
	$(CXX) $(LIBFLAGS) -o lib$@.so $<
	javac SimpleIO.java

%.o : %.cpp
	$(CXX) $(CFLAGS) $(LIBFLAGS) -I$(JNI_DIR) -I$(JNI_DIR2) -o $@ $<

clean :
	rm -f $(BINARIES) *.class $(LIBRARIES) $(OBJECTS)

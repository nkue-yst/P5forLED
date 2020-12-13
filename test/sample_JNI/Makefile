CFLAGS    = -Wall
OBJECTS   = *.o
LIBRARIES = *.so
BINARIES  = 
LIBFLAGS += -fPIC -shared
JNI_INCLUDE   = -I/usr/lib/jvm/java-1.8.0-openjdk-armhf/include -I/usr/lib/jvm/java-1.8.0-openjdk-armhf/include/linux

all : SimpleIO Multiply

SimpleIO : SimpleIO.o
	$(CXX) $(LIBFLAGS) -o lib$@.so $<
	javac $@.java

Multiply : Multiply.o
	$(CXX) $(LIBFLAGS) -o lib$@.so $<
	javac $@.java

%.o : %.cpp
	$(CXX) $(CFLAGS) $(LIBFLAGS) $(JNI_INCLUDE) -o $@ $<

clean :
	rm -f $(BINARIES) *.class $(LIBRARIES) $(OBJECTS)

# Execution
# $ LD_LIBRARY_PATH=. java Hoge

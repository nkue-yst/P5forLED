CXXFLAGS = -Wall
OBJECTS  = hello_server.o hello_client.o
BINARIES = hello_server hello_client
CLASSES  = Hello_client.class

all : $(BINARIES) $(CLASSES)

hello_server : hello_server.o
	$(CXX) $< -o $@

hello_client : hello_client.o
	$(CXX) $< -o $@

hello_client-java : Hello_client.class

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

%.class : %.java
	javac $<

clean :
	rm -f $(OBJECTS) $(BINARIES) $(CLASSES)

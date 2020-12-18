CXXFLAGS = -Wall
OBJECTS  = hello_server.o hello_client.o
BINARIES = hello_server hello_client

all : $(BINARIES)

hello_server : hello_server.o
	$(CXX) $< -o $@

hello_client : hello_client.o
	$(CXX) $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean :
	rm -f $(OBJECTS) $(BINARIES)

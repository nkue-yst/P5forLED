all : Client

install : Client
	jar cvf ../p5led.jar ../p5led
	cp ../p5led.jar ../../../examples/Client/
	mkdir ~/sketchbook/libraries/p5led
	mkdir ~/sketchbook/libraries/p5led/library
	cp ../p5led.jar ~/sketchbook/libraries/p5led/library

uninstall : 
	rm -f ../p5led.jar
	rm -rf ~/sketchbook/libraries/p5led

Client : Client.class

%.class : %.java
	javac $< -d ../

clean :
	rm -rf ../p5led

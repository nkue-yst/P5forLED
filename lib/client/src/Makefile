all : Client

install : Client
	jar cvf ../p5led.jar ../p5led
	mkdir -p ~/sketchbook/libraries/p5led
	mkdir -p ~/sketchbook/libraries/p5led/library
	cp ../p5led.jar ~/sketchbook/libraries/p5led/library

uninstall : 
	rm -f ../p5led.jar
	rm -rf ~/sketchbook/libraries/p5led

Client : Client.class

%.class : %.java
	javac -cp /usr/local/lib/processing-3.5.3/core/library/core.jar $< -d ../

clean :
	rm -rf ../p5led

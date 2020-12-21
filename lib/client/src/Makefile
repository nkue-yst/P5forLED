all : Client

install : Client
	jar cvf ../p5led.jar ../p5led
	cp ../p5led.jar ../../../examples/Client/

uninstall : 
	rm -f ../p5led.jar

Client : Client.class

%.class : %.java
	javac $< -d ../

clean :
	rm -rf ../p5led

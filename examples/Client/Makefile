all : LED_Client

LED_Client : LED_Client.class

%.class : %.java
	javac -classpath .:p5led.jar $< -d .

clean :
	rm -f LED_Client.class p5led.jar

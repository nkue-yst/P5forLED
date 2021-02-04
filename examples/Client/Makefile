all : LED_Client

LED_Client : LED_Client.class

%.class : %.java
	javac -classpath .:p5led.jar:/usr/local/lib/processing-3.5.3/core/library/core.jar  $< -d .

clean :
	rm -f LED_Client.class p5led.jar

CLASS_PATH = -cp .:jna.jar

Hello : Hello.class
	java $(CLASS_PATH) $@

%.class : %.java
	javac $(CLASS_PATH) $<

clean : 
	rm -f *.class

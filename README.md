# Processing for LED matrix
## How to Use (Run LED from Java program)
1. Install the RGBMatrix library on the Raspberry Pi using [this page](https://learn.adafruit.com/adafruit-rgb-matrix-plus-real-time-clock-hat-for-raspberry-pi) as a reference 
2. Download this repository like `~/rpi-rgb-led-matrix/{This repository}`
3. Install this libraries (and Compile sample programs)
```bash
$ cd P5forLED
$ make
```
4. Run server program
```Bash
$ cd examples/Server/
$ sudo ./LED_Server
```
5. Run client program
```bash
$ cd examples/Client/
$ java -cp .:p5led.jar LED_Client
```
6. Check tree
```bash
$ tree
.
├── LICENSE
├── Makefile
├── README.md
├── examples
│   ├── Client
│   │   ├── LED_Client.class
│   │   ├── LED_Client.java
│   │   ├── Makefile
│   │   └── p5led.jar
│   └── Server
│       ├── LED_Server
│       ├── LED_Server.cpp
│       ├── LED_Server.o
│       └── Makefile
├── include
│   └── server
│       ├── LEDManager.hpp
│       └── Socket.hpp
└── lib
    ├── client
    │   ├── p5led
    │   │   └── client
    │   │       └── Client.class
    │   ├── p5led.jar
    │   └── src
    │       ├── Client.java
    │       └── Makefile
    └── server
        ├── libP5forLED.so
        └── src
            ├── LEDManager.cpp
            ├── LEDManager.o
            ├── Makefile
            ├── Socket.cpp
            ├── Socket.o
            └── test.cpp
```

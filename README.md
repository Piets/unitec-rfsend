# unitec-rfsend

This is a fork of [jacobmellin/unitec-rfsend](https://github.com/jacobmellin/unitec-rfsend). The original code didn't work for me so I modified it a little bit. In particular I added sending of a header before each datagram but on the other hand I removed the delay between datagrams.  
I based my research on the implementation done by [guh](https://github.com/guh/guh) for similiar sockets, therefore I switched over to their nomenclature (long pulse is logical zero and short pulse is logical one). Therefore the codes you see may seem "inverted" to you. But to be honest, it works for me, so at least I'm happy :-)

## Usage

Unfortunately I was not able to find a pattern in the codes used, so the tool just works with a sequence of binary digits indicating HIGH/LOW signals to be sent. 

The second argument you need to provide is the pin number the transmitter is connected to.  

To switch on socket A, run the following command:

```
unitec-rfsend 001011000011111010001111 0
```

You may use spaces in the code for better readability:

```
unitec-rfsend "0010 1100 0011 1110 1000 1111" 0
```

See below for a number of possible codes.


## Model & Signal Data

Type: 48110  
Receiver: 55006x10

```
0 = 975us HIGH, 475us LOW  
1 = 475us HIGH, 975us LOW
```

## Codes for controlling the four included outlets:

```
A ON:	0010 1100 0011 1110 1000 1111
A OFF:	0010 0010 0110 0001 0101 1111

B ON:	0010 1100 0011 1110 1000 1011
B OFF:	0010 0010 0110 0001 0101 1011

C ON:	0010 1100 0011 1110 1000 0011
C OFF:	0010 0010 0110 0001 0101 0011
```

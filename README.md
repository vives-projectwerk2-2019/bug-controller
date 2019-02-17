# bug-controller

## clone project
```shell
git clone git@github.com:vives-projectwerk2-2019/bug-controller.git
```
Vervolgens zal voor de mbed functionaliteit de volgende commando's is de work map moeten uitgevoerd worden:
```shell
mbed new .
mbed deploy
```
## Requirements
1. mbed NUCLEO-L476RG
2. touchberry PI

## compile
```shell
mbed compile -m NUCLEO_L476RG -t GCC_ARM -f
```
## function
Read pushing the capacitive buttons (QT1070).
Work with i2c the read function will output an integer with which you can determine wich button was pushed. I used Putty to monitor which buttons were pressed.

Values that will be captured when certain buttons ar pressed:
![alt text](buttonint.jpg "Setup")

## image of the setup
![alt text](setup.jpg "Setup")

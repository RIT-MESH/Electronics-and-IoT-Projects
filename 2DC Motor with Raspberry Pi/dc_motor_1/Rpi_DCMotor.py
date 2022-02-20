import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
pinA = 2
pinB = 21
GPIO.setup(pinA,GPIO.OUT)
GPIO.setup(pinB,GPIO.OUT)
delay = 2
def forward():
    GPIO.output(pinA,True)
    GPIO.output(pinB,False)

def backward():
    GPIO.output(pinB,True)
    GPIO.output(pinA,False)
try:
	while True:
                x = int(input("pass your input 1 as on 0 as off"))
                if(x==1):
                    forward()
		        elif(x==2):
                    backward()
except KeyboardInterrupt:
	GPIO.cleanup()

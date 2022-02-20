import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
leds = [4,17,27,22,18,23,24,25]
print('Leds Scrolling program Please connect Leds order as same in this list:',leds)
for i in leds:GPIO.setup(i,GPIO.OUT)
delay = 0.5
try:
        while True:
                for i in leds:
                        GPIO.output(i,True)
                        print("on")
                        time.sleep(delay)
                        GPIO.output(i,False)
                        print("off")
except KeyboardInterrupt:
        GPIO.cleanup()

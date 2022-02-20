import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
print('Multiple Leds program')
ledPin = 18
GPIO.setup(ledPin,GPIO.OUT)
delay = 2
try:
	while True:
		GPIO.output(ledPin,True)
		print("on")
		time.sleep(delay)
		GPIO.output(ledPin,False)
		print("off")
		time.sleep(delay)
except KeyboardInterrupt:
	GPIO.cleanup()

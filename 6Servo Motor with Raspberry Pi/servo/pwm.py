import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.OUT)
p=GPIO.PWM(2,50)
p.start(0)
try:
	while True:
		for dc in range(1,13,1):
			p.ChangeDutyCycle(dc)
			time.sleep(0.1)
			print(dc)
		for dc in range(12,0,-1):
			p.ChangeDutyCycle(dc)
			time.sleep(0.1)
			print(dc)
except KeyboardInterrupt:
	p.stop()
	GPIO.cleanup()

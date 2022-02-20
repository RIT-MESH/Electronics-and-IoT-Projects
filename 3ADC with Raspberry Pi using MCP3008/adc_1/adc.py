import time
import os
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

# read SPI data from MCP3008 chip, 8 possible adc's (0 thru 7)
def readadc(adcnum, clockpin, mosipin, misopin, cspin):
        if ((adcnum > 7) or (adcnum < 0)):
                return -1
        GPIO.output(cspin, True)

        GPIO.output(clockpin, False)  # start clock low
        GPIO.output(cspin, False)     # bring CS low

        commandout = adcnum
        commandout |= 0x18  # start bit + single-ended bit
        commandout <<= 3    # we only need to send 5 bits here
        for i in range(5):
                if (commandout & 0x80):
                        GPIO.output(mosipin, True)
                else:
                        GPIO.output(mosipin, False)
                commandout <<= 1
                GPIO.output(clockpin, True)
                GPIO.output(clockpin, False)

        adcout = 0
        # read in one empty bit, one null bit and 10 ADC bits
        for i in range(12):
                GPIO.output(clockpin, True)
                GPIO.output(clockpin, False)
                adcout <<= 1
                if (GPIO.input(misopin)):
                        adcout |= 0x1

        GPIO.output(cspin, True)
        
        adcout >>= 1       # first bit is 'null' so drop it
        return adcout

# change these as desired - they're the pins connected from the
# SPI port on the ADC to the Cobbler
SPICLK = 18
SPIMISO = 23
SPIMOSI = 24
SPICS = 25

# set up the SPI interface pins
GPIO.setup(SPIMOSI, GPIO.OUT)
GPIO.setup(SPIMISO, GPIO.IN)
GPIO.setup(SPICLK, GPIO.OUT)
GPIO.setup(SPICS, GPIO.OUT)


while True:
        # read the analog pin
        data_8_channel = [readadc(pin, SPICLK, SPIMOSI, SPIMISO, SPICS) for pin in range(8)]                 
        print (data_8_channel)
        #Easy way is below
        """
        CH0 = readadc(0, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH1 = readadc(1, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH2 = readadc(2, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH3 = readadc(3, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH4 = readadc(4, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH5 = readadc(5, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH6 = readadc(6, SPICLK, SPIMOSI, SPIMISO, SPICS)
        CH7 = readadc(7, SPICLK, SPIMOSI, SPIMISO, SPICS)
        print("CH0:{0},CH1:{1},CH2:{2},CH3:{3},CH4:{4},CH5:{5},CH6:{6},CH7:{7}".format(CH0,CH1,CH2,CH3,CH4,CH5,CH6,CH7))
        """
        

                

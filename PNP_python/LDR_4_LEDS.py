"""
P Opcional
German Bueno, Pol Pavo
ISABA 2025
"""


from machine import Pin, ADC
from time import sleep

LED_LOW = Pin(15,Pin.OUT)
LED_MID = Pin(2,Pin.OUT)
LED_HIGH = Pin(4,Pin.OUT)

LDR = ADC(Pin(14, Pin.IN))

while True:
    lectura = int(LDR.read())
    print(lectura)
    sleep(0.1)

    if lectura <= 1024:
        print("LOW")
        LED_LOW.on()
        LED_MID.on()
        LED_HIGH.on()
    elif lectura <= 2048:
        print("MID")
        LED_LOW.on()
        LED_MID.on()
        LED_HIGH.off()
    elif lectura <= 3072:
        LED_LOW.on()
        LED_MID.off()
        LED_HIGH.off()
    else:
        LED_LOW.off()
        LED_MID.off()
        LED_HIGH.off()

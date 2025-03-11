"""
P Opcional
German Bueno, Pol Pavo
ISABA 2025
"""
from machine import Pin
from time import sleep

LED = Pin(2, Pin.OUT)


if __name__ == "__main__":
    while True:
        LED.on()
        sleep(1)
        LED.off()
        sleep(1)
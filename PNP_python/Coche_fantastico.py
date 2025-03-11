"""
P Opcional
German Bueno, Pol Pavo
ISABA 2025
"""
from machine import Pin
from time import sleep

LEDs = [Pin(15, Pin.OUT),
        Pin(2, Pin.OUT),
        Pin(4, Pin.OUT),
        Pin(16, Pin.OUT),
        Pin(17, Pin.OUT),
        Pin(5, Pin.OUT),
        Pin(18, Pin.OUT),
        Pin(19, Pin.OUT),
        ]


if __name__ == "__main__":
    while True:
        print("Hola")
        for i in range(1, len(LEDs)):
            LEDs[i-1].off()
            LEDs[i].on()
            sleep(0.05)
        for i in range(len(LEDs)-2, -1, -1):
            LEDs[i+1].off()
            LEDs[i].on()
            sleep(0.05)

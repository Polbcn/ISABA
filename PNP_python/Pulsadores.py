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

Pulsador1 = Pin(21, Pin.IN)
Pulsador2 = Pin(22, Pin.IN, Pin.PULL_UP)
Pulsador3 = Pin(23, Pin.IN, Pin.PULL_DOWN)


if __name__ == "__main__":
    print("Hola")
    while True:
        if Pulsador1.value() == 1:
            print("Hola 1")
            LEDs[0].on()
            sleep(0.5)
        else:
            LEDs[0].off()
        if Pulsador2.value() == 0:
            print("Hola 2")
            LEDs[1].on()
            sleep(0.5)
        else:
            LEDs[1].off()
        if Pulsador3.value() == 1:
            print("Hola 3")
            LEDs[2].on()
            sleep(0.5)
        else:
            LEDs[2].off()
        sleep(0.02)


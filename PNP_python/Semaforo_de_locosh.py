"""
P Opcional
German Bueno, Pol Pavo
ISABA 2025
"""
from machine import Pin
from time import sleep

S1 = Pin(15, Pin.OUT)
S2 = Pin(2, Pin.OUT)
S3 = Pin(4, Pin.OUT)
        
S4 = Pin(16, Pin.OUT)
S5 = Pin(17, Pin.OUT)
S6 = Pin(5, Pin.OUT)

Pulsador1 = Pin(22, Pin.IN, Pin.PULL_UP)

def parpadeo_amarillo(semaforo):
    if (semaforo == 1):
        S1.off()
        S3.off()
        for i in range(1, 10):
            S2.on()
            sleep(0.5)
            S2.off()
            sleep(0.5)
    else:
        S4.off()
        S6.off()
        for i in range(1, 10):
            S5.on()
            sleep(0.5)
            S5.off()
            sleep(0.5)



if __name__ == "__main__":
    print("Hola")
    while True:
        print(Pulsador1.value())
        if(Pulsador1.value() == 0):
            S1.off()
            S2.off()
            S3.off()
            S4.off()
            S5.off()
            S6.on()
            parpadeo_amarillo(1)
            S1.off()
            S2.off()
            S3.on()
            S4.on()
            S5.off()
            S6.off()
            sleep(5)
            parpadeo_amarillo(2)
        else:
            S1.on()
            S2.off()
            S3.off()
            S4.off()
            S5.off()
            S6.on()
            sleep(1)

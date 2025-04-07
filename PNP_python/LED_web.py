"""" *********************************  ESP32 WEB LED ***********************************
      Programa que permite el control de salidas digitales desde una página web local

    Encarna García                                                    Septiembre 2024
************************************************************************************"""
"""
P Opcional
German Bueno, Pol Pavo
ISABA 2025
"""
from machine import Pin
import network
import socket
import time

ssid = 'PUCRA'       # Escribe aquí el nombre de tu red wifi
password = 'PUCRA585858' # Escribe aquí el nombre de la contraseña de tu wifi.

miwifi= network.WLAN(network.STA_IF)

miwifi.active(True)
miwifi.connect(ssid, password)

while miwifi.isconnected() == False:
  pass

print('Dispositivo conectado')
print(miwifi.ifconfig())

led = Pin(15, Pin.OUT)
led2 = Pin(2, Pin.OUT)
led3 = Pin(4, Pin.OUT)

# Función que permite programar la página web en html
#Tutorial html: https://www.freecodecamp.org/espanol/news/aprende-las-bases-de-html-para-principiantes-en-solo-15-minutos/

def web_page():
  if led.value() == 1:
    estado_LED="Encendido"
  if led2.value() == 1:
    estado_LED2="Encendido"
  if led3.value() == 1:
    estado_LED3="Encendido"
  if led.value() == 0:
    estado_LED="Apagado"
  if led2.value()==0:
    estado_LED2="Apagado"
  if led3.value()==0:
    estado_LED3="Apagado"

  html = """<html>

    <head>
        <title> ESP32 LED Web Server </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="icon" href="data:,">

        <style>
            html{
                font-family: Helvetica;
                display:inline-block;
                margin: 0px auto;
                text-align: center;
            }

            h1{
                color: #0F3376;
                padding: 2vh;
                }

            p{
            font-size: 1.5rem;
            }

            .button{
                display: inline-block;
                background-color: #EC7063;
                border: none;
                border-radius: 4px;
                color: white;
                padding: 16px 40px;
                text-decoration: none;
                font-size: 30px;
                margin: 2px;
                cursor: pointer;
            }

           .button_OFF{
               background-color: #4286f4;
            }

        </style>

    </head>

    <body>
        <h1> Control encendido LED </h1>
        <p>Estado del LED: <strong>""" + estado_LED + """</strong>
        <p>Estado del LED 2: <strong>""" + estado_LED2 + """</strong>
        <p>Estado del LED 3: <strong>""" + estado_LED3 + """</strong>
        </p>

        <p>
            <a href="/1">
            <button class="button"> LED 1 </button>
            </a>
        </p>
        <p>
            <a href="/2">
            <button class="button"> LED 2 </button>
            </a>
        </p>
        <p>
            <a href="/3">
            <button class="button"> LED 3 </button>
            </a>
        </p>

        <p> <a href="/off">
        <button class="button button_OFF">DESACTIVAR</button>
            </a>
        </p>
    </body>

</html>"""
  return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)

while True:
  conn, addr = s.accept()
  print('Got a connection from %s' % str(addr))
  request = conn.recv(1024)
  request = str(request)
  print('Content = %s' % request)


  led_on = request.find('/1')   # mensaje que se envía al clicar cada botón
  led_on2 = request.find('/2')
  led_on3 = request.find('/3')
  led_off = request.find('/off')

  if led_on == 6:
    print('LED ON')
    led.value(1)
  if led_on2 == 6:
    print('LED ON')
    led2.value(1)
  if led_on3 == 6:
    print('LED ON')
    led3.value(1)
  if led_off == 6:
    print('LED OFF')
    led.value(0)
    led2.value(0)
    led3.value(0)

  response = web_page()
  conn.send('HTTP/1.1 200 OK\n')
  conn.send('Content-Type: text/html\n')
  conn.send('Connection: close\n\n')
  conn.sendall(response)
  conn.close()

# https://randomnerdtutorials.com/esp32-esp8266-micropython-web-server/
# https://todomaker.com/blog/montar-un-servidor-web-en-el-esp32-con-espasyncwebserver-y-spiffs/
# https://www.youtube.com/watch?v=kep8hVQMN6o&t=263s

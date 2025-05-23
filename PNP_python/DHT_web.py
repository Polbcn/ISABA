"""" *********************************  ESP32 WEB DHT11 ********************************
      Programa que permite la visualización de lectura de los valores de temperatura y
      humedad de un sensor DHT11 desde una página web local

    Encarna García                                                    Septiembre 2024
************************************************************************************"""
"""
P Opcional
German Bueno, Pol Pavo
ISABA 2025
"""
#https://lastminuteengineers.com/esp32-dht11-dht22-web-server-tutorial/#google_vignette
#https://randomnerdtutorials.com/micropython-esp32-esp8266-dht11-dht22-web-server/
# problema= para actualizar valores es necesario refrescar web

from machine import Pin, time_pulse_us, ADC
from dht import DHT11
import time

import network
import socket
import time

#-----------------  Configuración WIFI --------------------------
ssid = 'PUCRA'
password = 'PUCRA585858'

miwifi= network.WLAN(network.STA_IF)

miwifi.active(True)
miwifi.connect(ssid, password)

while miwifi.isconnected() == False:
  pass

print('Dispositivo conectado')
print(miwifi.ifconfig())
# -----------------------------------------------------------------

sensorDHT = DHT11 (Pin(5))   # Configuración pin conexion DHT11
puls = Pin(23, Pin.IN)
pin = Pin(32)
LDR = ADC(pin)

def read_sensor():
  global temp, hum, prem, ldr
  ldr = int(LDR.read()/4095*100)
  prem = puls.value()
  temp = hum = 0
  sensorDHT.measure()
  temp=sensorDHT.temperature()
  hum=sensorDHT.humidity()
  msg = (b'{0:3.1f},{1:3.1f}, {2:3.1f}, {3:3.1f}'.format(temp, hum, prem,  ldr))

      # uncomment for Fahrenheit
      #temp = temp * (9/5) + 32.0

  return(msg)

# Función que permite programar la página web en html
#Tutorial html: https://www.freecodecamp.org/espanol/news/aprende-las-bases-de-html-para-principiantes-en-solo-15-minutos/

def web_page():
  html = """<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>ESP DHT Server</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i>
    <span class="dht-labels">Temperature</span>
    <span>"""+str(temp)+"""</span>
    <sup class="units">&deg;C</sup>
  </p>
  <p>
    <i class="fas fa-tint" style="color:#00add6;"></i>
    <span class="dht-labels">Humidity</span>
    <span>"""+str(hum)+"""</span>
    <sup class="units">%</sup>
  </p>
  <p>
    <i class="fas fa-lightbulb" style="color:#00add6;"></i>
    <span class="dht-labels">LDR</span>
    <span>"""+str(ldr)+"""</span>
    <sup class="units">%</sup>
  </p>
  <p>
    <i class="fas fa-broadcast-tower" style="color:#00add6;"></i>
    <span class="dht-labels">Presion</span>
    <span>"""+str(prem)+"""</span>
    <sup class="units">\</sup>
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
  print('Content = %s' % str(request))

  sensor_readings = read_sensor()
  print(sensor_readings)
  response = web_page()

  conn.send('HTTP/1.1 200 OK\n')
  conn.send('Content-Type: text/html\n')
  conn.send('Connection: close\n\n')
  conn.sendall(response)
  conn.close()

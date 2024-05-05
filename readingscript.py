import serial
import requests
import time
arduino = serial.Serial(port='COM13', baudrate=115200, timeout=.1) # setting the serial port
#arduino.open() # open serial port
while True:
    line = arduino.read(100)
    if line  != b'':
        print(line)
        line = line[0:-2]
        print(line.decode())
        print(type(line))
        time.sleep(5)
        var=line.decode()
        print(type(var))
        response = requests.post('https://influx-prod-36-prod-us-west-0.grafana.net/api/v1/push/influx/write',
                         headers = {'Content-Type': 'text/plain'},
                         data = 'test,bar_label=light_intensity,source=grafana_cloud_docs metric='+var,
                         auth = ("1561857", "GraphanaKEY (removed from repo for security reasons)"))
        print(response.text)
    arduino.close
    # we need to read the buffer value
10:22

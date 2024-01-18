import os
import serial
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=0.1)

while True:
    msg = input("input: ")
    arduino.write(bytes(msg, 'utf-8'))

    msgRD = arduino.readline()
    msgRD = msgRD.decode('utf-8')
    print(f'[MSG]: {msgRD}\n')

    if msg == "Exit":
        exit()
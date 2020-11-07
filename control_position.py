import platform
import time
import serial


arduino = serial.Serial("com6",9600)  

while True:
    move =int(input('position you want move:😍 '))
    while (move <= 0 or move >=10):
        move =int(input('position you want move: '))
    if move == 1:
            arduino.write(b'1')
            
    elif move == 2:
            arduino.write(b'2')
            
    elif move == 3:
            arduino.write(b'3')
            
    elif move == 4:
            arduino.write(b'4')
            
    elif move == 5:
            arduino.write(b'5')
            
    elif move == 6:
            arduino.write(b'6')
            
    elif move == 7:
            arduino.write(b'7')
            
    elif move == 8:
            arduino.write(b'8')
            
    elif move == 9:
            arduino.write(b'9')
        




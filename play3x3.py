from math import inf as infinity
from random import choice
import platform
import time
import serial
from os import system
import socket

# creative board
board = ["-","-","-","-","-","-","-","-","-"]
arduino = serial.Serial("com6",9600)  #Create Serial port object called arduinoSerialData
#global variable
index1 = int



def display_board():
    print(board[0] + " | " + board[1] + " | " + board[2])
    print(board[3] + " | " + board[4] + " | " + board[5])
    print(board[6] + " | " + board[7] + " | " + board[8])
    print("--------------------------------------------")

# check board full or not
def full():    
    if '-' not in board:
        return 1
    return 0

# check user win
def user_win():
    for i in range (0,9,3):
        if ((board[i] == board[i+1] == board[i+2]) and (board[i] == "o")):
            return 1
    for i in range (3):
        if ((board[i] == board[i+3] == board[i+6]) and (board[i] == "o")):
            return 1
    if ((board[0] == board[4] == board[8]) and (board[0] == "o")):
        return 1
    if ((board[2] == board[4] == board[6]) and (board[2] == "o")):
        return 1
    return 0
    
# check cpu win
def cpu_win():
    for i in range (0,9,3):
        if ((board[i] == board[i+1] == board[i+2]) and (board[i] == "x")):
            return 1
    for i in range (3):
        if ((board[i] == board[i+3] == board[i+6]) and (board[i] == "x")):
            return 1
    if ((board[0] == board[4] == board[8]) and (board[0] == "x")):
        return 1
    if ((board[2] == board[4] == board[6]) and (board[2] == "x")):
        return 1
    return 0    


def minimax(flag):
    global index1
    max_value = -1000
    min_value = 1000
    value = 1
    if cpu_win() == 1:
        return 10
    elif user_win() == 1:
        return -10
    elif full() == 1:
        return 0
    score  = [1,1,1,1,1,1,1,1,1]
    for i in range (9):
        if board[i] == "-":
            if min_value > max_value:
                if flag == True:
                    board[i] = "x"
                    value = minimax(False)
                else:
                    board[i] = "o"
                    value = minimax(True)
                board[i] = "-"
                score[i] = value
    if (flag == True):
        max_value = -1000
        for j in range(9):
            if (score[j] > max_value and score[j] != 1):
                max_value = score[j]
                index1 = j   
        return max_value
    elif (flag == False):
        min_value = 1000
        for j in range (9):
            if (score[j] < min_value and score[j] != 1):
                min_value = score[j]
                index1 = j
        return min_value
    return index1


def check():
    if cpu_win() == 1:
        print ("CPU WIN")
        return 2
    elif user_win() == 1:
        print ("USER WIN")
        return 2
    elif full() == 1:
        print ("DRAW")
        return 2
    return 3



choice = int(input("1 user first ; 2 cpu first "))
if choice == 1:
    move = int(input("Choice one position from 1 to 9 \n Enter the move: "))
    board[move - 1] = "o"
else:
    print ("CPU move: ")
    board[4] = 'x'
    arduino.write(b'5')
    display_board()
    move = int(input("Choice one position from 1 to 9 \n Enter the move: "))
    while (board[move -1] != '-'):
        move = int(input("Choice one position from 1 to 9 \n Enter the move again: "))
    board[move - 1] = "o"  

while True:
    display_board()
    print("CPU move")
    minimax(True)
    board[index1] = "x"
    if index1 == 4:
        arduino.write(b'5')
    elif index1 == 0:
        arduino.write(b'1')
    elif index1 == 1:
        arduino.write(b'2')
    elif index1 == 2:
        arduino.write(b'3')
    elif index1 == 3:
        arduino.write(b'4')
    elif index1 == 5:
        arduino.write(b'6')
    elif index1 == 6:
        arduino.write(b'7')
    elif index1 == 7:
        arduino.write(b'8')
    elif index1 == 8:
        arduino.write(b'9')
    check()
    display_board()
    if check() == 2:
        break
    move = int(input("Choice one position from 1 to 9 \n Enter the move: "))
    while board[move - 1] != '-':
        move = int(input("Choice one position from 1 to 9 \n Enter the move again: "))
    board[move - 1] = "o"
    check()
    display_board()
    if check() == 2:
        break


        




















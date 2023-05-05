import socket
import threading
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
leds = [23, 24, 25, 1]
for i in leds:
    GPIO.setup(i, GPIO.OUT)
    pass

HOST = 'localhost'
PORT = 9999

send_message:str = ''

def sending_message(clnt):
    while True: # while doesRun
        if GPIO.input(leds[0]):
            pass
        elif GPIO.input(leds[1]):
            pass
        elif GPIO.input(leds[2]):
            pass
        elif GPIO.input(leds[3]):
            pass

def received_message(clnt):
    try:
        peopleNum = 0
        while True:
            data = clnt.recv(1024).decode(encoding='utf-8')
            data = data.strip()
    #enter user 
            for i in range(3) :  
                if peopleNum == i and data[0:3] == '@@@':
                    GPIO.output(leds[i], GPIO.HIGH)
                    peopleNum += 1
                    data = ""
                    print(peopleNum)

    #exit user
            for i in range(3) :  
                if peopleNum == (i + 1) and data[0:3] == 'VVV':
                    GPIO.output(leds[i], GPIO.LOW)
                    peopleNum -= 1
                    data = ""
                    print(peopleNum)
    # racegmae
            if data[0:3] == '***':
                for i in range(3) : 
                    GPIO.output(leds[i], GPIO.LOW)
                i = 0
                while i != 2 :  
                    data = clnt.recv(1024).decode(encoding='utf-8')
                    data = data.strip()
                    if data[:len('/join')] == '/join':
                        GPIO.output(leds[i], GPIO.HIGH)
                        i += 1               
            if data[0:3] == '!!!' :
                for i in range(peopleNum - 1) : 
                    GPIO.output(leds[i], GPIO.LOW)
                for i in range(peopleNum - 1) :  
                    GPIO.output(leds[i], GPIO.HIGH)
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        clnt.close() 

with socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM, proto=0) as clnt:
    try:
        clnt.connect((HOST, PORT)) 
        for i in range(3) :  
            GPIO.output(leds[i], GPIO.LOW)
            GPIO.output(leds[i], GPIO.LOW)
            GPIO.output(leds[i], GPIO.LOW)
            GPIO.output(leds[i], GPIO.LOW)
        t1 = threading.Thread(target=sending_message, args=(clnt,))
        t2 = threading.Thread(target=received_message, args=(clnt,))
        t1.start()
        t2.start()
        t1.join()
        t2.join()
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        GPIO.cleanup()

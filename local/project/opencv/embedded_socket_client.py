import socket
import threading
import RPi.GPIO as GPIO
import smbus
from Motor_Lib import PWM
from time import sleep
#LED 
GPIO.setmode(GPIO.BCM)
leds = [23, 24, 25, 1]
for i in leds:
    GPIO.setup(i, GPIO.OUT)
    pass
#serv_mot
SERVO1 = 3
SERVO2 = 4
i2c_bus = smbus.SMBus(1)
pwm = PWM(i2c_bus)
pwm.set_frequency(60)

#socket
HOST = 'localhost'
PORT = 9999

def LED_thread(clnt):
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
        t1 = threading.Thread(target=open_door)
        while True:
            data = clnt.recv(1024).decode(encoding='utf-8')
            data = data.strip()
            print(data)
            if (data == 'myface' and not t1.is_alive()):
                t1 = threading.Thread(target=open_door)
                t1.start()  #why not use JOIN 
                
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        clnt.close() 
        i2c_bus.close()

def open_door():
    pwm.set_duty(SERVO1, 100)
    for i in range(8):
        sleep(0.5)
        #if i < 4:
        GPIO.output(leds[i%4], (GPIO.HIGH if i < 4 else GPIO.LOW))
        if i%2 :
            pwm.set_duty(SERVO2, (i/2+1)*100) 
    pwm.set_duty(SERVO1, 500)
        #else :
         #   GPIO.output(leds[i%4], GPIO.LOW)
#def SERV_clock():
#    for i in range (1,6):
#        pwm.set_duty(SERVO2, i*100)
#        sleep(1)

with socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM, proto=0) as clnt:
    try:
        pwm.set_duty(SERVO1, 500)
        pwm.set_duty(SERVO2, 100)
        #for i in range(4):
        GPIO.output([leds[i] for i in range(4)], GPIO.LOW)
        clnt.connect((HOST, PORT))
        t1 = threading.Thread(target=LED_thread, args=(clnt,))
        t2 = threading.Thread(target=received_message, args=(clnt,))
        t1.start()
        t2.start()
        t1.join()
        t2.join()
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        GPIO.cleanup()

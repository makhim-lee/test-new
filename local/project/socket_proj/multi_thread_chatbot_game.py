import socket
import threading
import time
import random

HOST = 'localhost' # 127.0.0.1
PORT = 9999
flag = 0
class Line:
    def __init__(self):
        self.line = ['0','0','0','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ','E']
    
    def info(self):
        return ''.join(self.line)
    
    def count0(self):
        return self.line.count('0')
    def move(self):
        if self.count0() == 5:
            first_zero = self.line.index('0')
            last_zero = len(self.line) - 1 - self.line[::-1].index('0')
            self.line[first_zero] = ' '
            self.line[last_zero] = ' '
            pass
        elif self.count0() == 3:
            last_zero = len(self.line) - 1 - self.line[::-1].index('0')
            self.line[last_zero + 1] = '0'
            self.line[last_zero + 2] = '0'
            pass
    def finish(self):
        if self.line[-1] == '0' :
            return 1
        
    def buster(self, other):
        self_first_zero = self.line.index('0')
        other_first_zero = other.line.index('0')
        return other_first_zero - self_first_zero
    def sendMessage(self, other):
        time.sleep(0.01)
        send_message:str = self.info()
        send_message.strip()
        clnt.sendall(send_message.encode(encoding = 'utf-8'))
        time.sleep(0.001)
        send_message:str = "##############"
        send_message.strip()
        clnt.sendall(send_message.encode(encoding = 'utf-8'))
        time.sleep(0.001)
        send_message:str = other.info()
        send_message.strip()
        clnt.sendall(send_message.encode(encoding = 'utf-8'))
        time.sleep(0.001)


def clear_screen(x = 0, y = 0):
    time.sleep(random.uniform(x, y))
    send_message:str = '/cleanup'
    send_message.strip()
    clnt.sendall(send_message.encode(encoding = 'utf-8'))

# task func
def sending_message(clnt): 
    global flag
    try:
        while True :
        # 3. game
            if flag == 2 :
                l1 = Line()
                l2 = Line()
                clear_screen(0)
                while True:
                    l1.sendMessage(l2)

                    if l1.finish() :
                        send_message:str = "!!!player 1 win!!!"
                        send_message.strip()
                        clnt.sendall(send_message.encode(encoding = 'utf-8'))
                        flag = 0
                        break
                    elif l2.finish() :
                        send_message:str = "!!!player 2 win!!!!!"
                        send_message.strip()
                        clnt.sendall(send_message.encode(encoding = 'utf-8'))
                        flag = 0
                        break
                    clear_screen(0.3, 1.3)
                    if l1.buster(l2) >= 4 and random.randint(1, 5) >= 4:
                        for i in range(3):
                            l1.sendMessage(l2)
                            l1.move()
                            clear_screen(0.3, 0.5)
                    elif l2.buster(l1) >= 4 and random.randint(1, 5) >= 4:
                        for i in range(3):
                            l1.sendMessage(l2)
                            l2.move()
                            clear_screen(0.3, 0.5)
                    else :
                        if random.randint(0, 1) :
                            l1.move()
                            pass
                        else :
                            l2.move()
                            pass
                print("end game")
            continue
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        clnt.close() 
        
def received_message(clnt):
    global flag 
    try:
        while True:
        # 1. stand gmae start 
            data:str = clnt.recv(1024).decode(encoding = 'utf-8')
            data = data.strip()
            if data[0:len('/start race game')] == '/start race game' :
                send_message:str = "***start race game***"
                send_message.strip()
                clnt.sendall(send_message.encode(encoding = 'utf-8'))
        # 2. chack join
                while True: 
                    data:str = clnt.recv(1024).decode(encoding = 'utf-8')
                    data = data.strip()
                    if data[:len('/join')] == '/join':
                        flag += 1
                        send_message:str = '/r '+data.split('\t')[1]+' your player '+ str(flag)
                        send_message.strip()
                        clnt.sendall(send_message.encode(encoding = 'utf-8'))
                        print('play ' + str(flag) + ' : ' +str(data.split('\t')[1]))
                    elif flag == 2 :
                        print('game start')
                        break
        # 3. game()
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        clnt.close() 

with socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM, proto=0) as clnt:
    try:
        clnt.connect((HOST, PORT))  
        t1 = threading.Thread(target=sending_message, args=(clnt,))
        t2 = threading.Thread(target=received_message, args=(clnt,))
        t1.start()
        t2.start()
        t1.join()
        t2.join()
    except KeyboardInterrupt:
        print("Keyboard interrupt")
    finally:
        clnt.close() 
import socket
import threading
import os

HOST = 'localhost' # 127.0.0.1
PORT = 9999

name:str = input("Nick Name? ")
black:str = ''
flag = 0
  
print("   __  __    ___       __      ___  ")
print("  / / / /   / _ \     / /     / _ \ ")
print(" / /_/ /   | | | |   / /     | | | | ")
print(" \__, /    | |_| |  /  L__   | |_| | ")
print("/____/      \___/  /______|   \___/  ")
def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

# task func
def sending_message(clnt): 
    try:
        global black
        while True: 
            input_msg:str = input() #hello to blah
            input_msg.strip()  #remove \r\n
            if input_msg[0] == '/':
                if input_msg[1:3] == 'no':
                    pass
                elif input_msg[1] == 'q':
                    input_msg = input_msg.lstrip("/q ")
                    clnt.sendall(input_msg.encode(encoding = 'utf-8'))
                    pass
                elif input_msg[1] == 'g':
                    black = input_msg[3:]
                    print(black+ " is black")
                    pass
                else :
                    input_msg = input_msg + "\t" + name
                    clnt.sendall(input_msg.encode(encoding = 'utf-8')) 
                    pass
            else :
                input_msg = input_msg + "\t" + name
                clnt.sendall(input_msg.encode(encoding = 'utf-8')) 
                pass
    except KeyboardInterrupt:
        print("Error: sending_message")
    finally:
        clnt.close()

def receiving_message(clnt): 
    global flag
    try:
        while True:
            data:str = clnt.recv(1024).decode(encoding = 'utf-8')
            if data[0] == '/':
                if data[1] == 'r' and data[3:len(name) + 3] == name :
                    data = data.split(' ', 2)[2]
                    print(data)
                    pass
                elif  data.startswith('/cleanup') :
                    clear_screen()
                    pass
            elif black == data.split('\t')[-1].strip() :
                print(black + " send message")
                pass
            elif flag == 1:
                flag = 0
                data = ''
                pass
            elif flag == 0 and data.split('\t')[0].rfind(name) != -1 :
                print(data.split('\t')[-1].strip()+"님이 나를 찾고 있어요")
                print(data)
                pass
            else :
                print(data)
                pass  
    except KeyboardInterrupt:
        print("Error: receiving_message")
    finally:
        clnt.close()  

with socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM, proto=0) as clnt:
    try:
        clnt.connect((HOST, PORT))
        enterMeg:str = '@@@' + name + ' client enter' + '@@@'
        clnt.sendall(enterMeg.encode(encoding = 'utf-8'))
        flag = 1
        t1 = threading.Thread(target=sending_message, args=(clnt,))
        t2 = threading.Thread(target=receiving_message, args=(clnt,))
        t1.start() # strat thread
        t2.start()
        t1.join()
        t2.join()
    except KeyboardInterrupt:
        outMeg:str = 'VVV'+name+'client out'+'VVV'
        flag = 1
        clnt.sendall(outMeg.encode(encoding = 'utf-8'))
    finally:
        clnt.close() 
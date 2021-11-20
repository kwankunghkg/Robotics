#! python3
import socket
HEADERSIZE = 10
server_ip = "192.168.2.111"
client_ip = "192.168.2.101"

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#s.connect((socket.gethostname(), 1243))
client.connect((server_ip, 1243))

while True:
    full_msg = ''
    new_msg = True
    while True:
        msg = client.recv(16)
        if new_msg:
            print("new msg len : ",msg[:HEADERSIZE])
            msglen = int(msg[:HEADERSIZE])
            new_msg = False

        print(f"full message length : {msglen}", end =" / ")
        full_msg += msg.decode("utf-8")
        print(len(full_msg))

        if len(full_msg)-HEADERSIZE == msglen:
            print("full msg recvd :")
            print(full_msg)
            print("     msg recvd :")
            print(full_msg[HEADERSIZE:])
            new_msg = True
            full_msg = ""

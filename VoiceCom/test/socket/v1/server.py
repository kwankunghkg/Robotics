#! python3
import socket
import time
FORMAT = 'utf-8'
HEADERSIZE = 10
server_ip = "192.168.2.111"
client_ip = "192.168.2.101"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#s.bind((socket.gethostname(), 1243))
server.bind((server_ip, 1243))
server.listen(5)

#while True:
# now our endpoint knows about the OTHER endpoint.
clientsocket, address = server.accept()
print(f"Connection from {address} has been established.")
msg = "Welcome to the server!"
msg = f"{len(msg):<{HEADERSIZE}}"+msg
clientsocket.send(bytes(msg,FORMAT))

while True:
    time.sleep(0.567)
    msg = f"The time is {time.time()}"
    msg = f"{len(msg):<{HEADERSIZE}}"+msg
    print(msg)
    clientsocket.send(bytes(msg,FORMAT))

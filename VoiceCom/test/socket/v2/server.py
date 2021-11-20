#! python3
import socket
import time
import pickle
FORMAT = 'utf-8'
HEADERSIZE = 50
BUFFERSIZE = 1024
server_ip = "192.168.2.111"
client_ip = "192.168.2.101"
file_name_in = "../data/song.m4a"
file_name_out = "../data/back.m4a"

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#serversocket.bind((socket.gethostname(), 1243))
serversocket.bind((server_ip, 1243))
serversocket.listen(5)
#file_in = open(file_name_in, 'rb') # opening a file
file_out = open(file_name_out, 'wb') # opening a file
clientsocket, address = serversocket.accept()
msg_send = f"Connection from {address} has been established."
print(msg_send)

def main():
    wait_for_file_size = True
    while wait_for_file_size:
        file_size_str = clientsocket.recv(HEADERSIZE)
        file_size = int(file_size_str)
        if int(file_size) > 0:
            wait_for_file_size = False

    print("client sending file length : ", file_size)
    msg_send = "server ack : "+str(file_size)
    print("send str : ", msg_send)
    #msg = f"{len(msg):<{HEADERSIZE}}"+msg
    clientsocket.send(bytes(msg_send,FORMAT))

    loop_socket_read(file_size)
    file_out.close()
    serversocket.close()
    clientsocket.close()


def loop_socket_read(file_length):
    data_pointer = 0
    loop_continue = True
    while loop_continue:
        # Seek can be called one of two ways:
        #   x.seek(offset)
        #   x.seek(offset, starting_point)
        # starting_point can be 0, 1, or 2
        # 0 - Default. Offset relative to beginning of file
        # 1 - Start from the current position in the file
        # 2 - Start from the end of a file (will require a negative offset)
        data_buffer = clientsocket.recv(BUFFERSIZE)
        #file_out.seek(data_pointer)
        file_out_size = file_out.write(data_buffer)
        #num_bytes_written = file_out.write(data_buffer)
        #print("Wrote %d bytes to " % num_bytes_written)
        #clientsocket.send(bytes(data_buffer,FORMAT))
        data_pointer += file_out_size
        if data_pointer >= file_length :
            loop_continue = False
            print("loop end")


def dummy():
    time.sleep(0.567)
    msg = f"The time is {time.time()}"
    msg = f"{len(msg):<{HEADERSIZE}}"+msg
    print(msg)
    clientsocket.send(bytes(msg,FORMAT))


main()

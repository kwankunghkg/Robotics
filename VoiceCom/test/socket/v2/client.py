#! python3
import os
import socket
import pickle
HEADERSIZE = 50
BUFFERSIZE = 1024
FORMAT = 'utf-8'
server_ip = "192.168.2.111"
client_ip = "192.168.2.101"
file_name_in = "../data/song.m4a"
file_name_out = "../data/back.m4a"

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#clientsocket.connect((socket.gethostname(), 1243))
clientsocket.connect((server_ip, 1243))
file_in = open(file_name_in, 'rb') # opening a file
#file_out = open(file_name_out, 'wb') # opening a file
file_in_length = os.path.getsize(file_name_in)

def main():
    print("file_in_name : ",file_name_in)
    print("file_in_length : ",file_in_length)
    msg_send = str(file_in_length)
    print("send str : ",file_in_length)
    clientsocket.send(bytes(msg_send,FORMAT))
    #clientsocket.send(msg_send)
    #msg_recv = clientsocket.recv(HEADERSIZE)
    #print("server reply : ",msg_recv)
    wait_for_ack = True
    while wait_for_ack:
        ack_str = clientsocket.recv(HEADERSIZE)
        print("ack str : ",ack_str)
        ack_str_len=len("server ack : ")
        print("ack str len : ",ack_str_len)
        file_size_ack_str=ack_str[ack_str_len:]
        print("file_size_ack_str : ",file_size_ack_str)
        file_size_ack = int(file_size_ack_str)
        print("file_size_ack : ",file_size_ack)
        #if int(file_size) > 0:
        #if len(ack_str) > 0:
        if file_size_ack==file_in_length :
            print("file length ack CORRECT")
            wait_for_ack = False

    loop_socket_write(file_in_length)
    file_in.close()
    #file_out.close()
    #serversocket.close()
    clientsocket.close()


def loop_socket_write(file_length):
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
        file_in.seek(data_pointer)
        data_buffer = file_in.read(BUFFERSIZE)
        #num_bytes_written = file_out.write(data_buffer)
        #print("Wrote %d bytes to " % num_bytes_written)
        #clientsocket.send(bytes(data_buffer,FORMAT))
        send_size = clientsocket.send(bytes(data_buffer))
        print("sent : ",send_size)
        data_pointer += send_size
        print("pointer : ",data_pointer)
        if data_pointer >= file_length :
            loop_continue = False
            print("loop end")



def loop_send():
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
            full_msg += msg.decode(FORMAT)
            print(len(full_msg))

            if len(full_msg)-HEADERSIZE == msglen:
                print("full msg recvd :")
                print(full_msg)
                print("     msg recvd :")
                print(full_msg[HEADERSIZE:])
                new_msg = True
                full_msg = ""

main()

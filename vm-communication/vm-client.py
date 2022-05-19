import socket
 
IP = '10.20.20.143'
PORT = 4458
ADDR = (IP, PORT)
FORMAT = "utf-8"
SIZE = 1024
 
def main():

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(ADDR)
    file = open("vmstat.txt", "r")
    data = file.read()
    client.send("vmstat.txt".encode(FORMAT))
    msg = client.recv(SIZE).decode(FORMAT)
    print(f"[SERVER]: {msg}")
    client.send(data.encode(FORMAT))
    msg = client.recv(SIZE).decode(FORMAT)
    print(f"[SERVER]: {msg}")
    file.close()
    client.close()
 
 
if __name__ == "__main__":
    main()


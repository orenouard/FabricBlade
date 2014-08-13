# Faking Blade server in Python

from time import *
from socket import *
from threading import *

HOSTNAME = gethostname()
HOSTIP = gethostbyname(HOSTNAME)
BROADCASTPORT = 7007
SERVERPORT = 7008
XMLHEADER = """<?xml version="1.0" standalone="yes" ?>"""

# continuous broadcast of the server information

def DivaServerBroadcast(BroadcastPort=BROADCASTPORT, IPAdress=HOSTIP, ComputerName=HOSTNAME, Port=SERVERPORT):
    BroadSock = socket(AF_INET, SOCK_DGRAM)
    BroadSock.bind(('', 0))
    BroadSock.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
    data = """<DivaServer IPAddress="%s" ComputerName="%s" Port="%s" />""" % (HOSTIP, HOSTNAME, SERVERPORT)
    message = XMLHEADER + data
    while True:
        print message
        BroadSock.sendto(message, ('<broadcast>', BROADCASTPORT))
        sleep(2)
        
BroadcastThread = Thread(None, DivaServerBroadcast, "Thread-Broadcast", (), {})
BroadcastThread.daemon = True
BroadcastThread.start()

# Connection socket

Sock = socket(AF_INET, SOCK_STREAM)
Sock.bind((HOSTIP,SERVERPORT))
Sock.listen(1)

Client = None
Address = None
try :
    Client, Address = Sock.accept()
except error, msg :
    print 'Accept failed. Error code: ', str(msg[0]), 'Error message: ', msg[1]
else :
    print 'Client ', Address, ' connected'
    frame = 0
    try:
        while BroadcastThread.isAlive():
            data = """<DivaCommand ScriptText="setTime %s;" />""" % frame
            message = XMLHEADER + data
            print message
            Client.sendall(message)
            frame += 1
            BroadcastThread.join(1)
    except (KeyboardInterrupt, SystemExit):
        exit()
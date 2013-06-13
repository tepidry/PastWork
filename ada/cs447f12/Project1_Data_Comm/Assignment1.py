"""
    author Ryan Draper
    CS 447
    Project 1
"""

#import socket module
from socket import *                                  
serverSocket = socket(AF_INET, SOCK_STREAM)
#Prepare a sever socket
#Fill in start
serverSocket.bind(('147.222.165.72',9000))
serverSocket.listen(1)
#Fill in end
while True:
    #Establish the connection
    print 'Ready to serve...'
    connectionSocket, addr =  serverSocket.accept()     
    try:
        message = connectionSocket.recv(5000)              
        filename = message.split()[1]                 
        f = open(filename[1:])                        
        outputdata = f.read()                  
       #Send one HTTP header line into socket
        #Fill in start
        connectionSocket.send('HTTP/1.1 4500 OK\r\n\r\n')
       #Fill in end                
        #Send the content of the requested file to the client
        for i in range(0, len(outputdata)):           
            connectionSocket.send(outputdata[i])
        connectionSocket.close()
    except IOError:
        #Send response message for file not found
        print 'IOError'
        connectionSocket.send('404: File Not Found')
        #Fill in start        
#Fill in end
        #Close client socket
        connectionSocket.close()
#Fill in end
serverSocket.close()

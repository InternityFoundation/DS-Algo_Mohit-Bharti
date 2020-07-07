import socket
import getpass
from decimal import Decimal 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def main():

    host = socket.gethostname()
    #host = '127.0.0.1'
    port = 12345
    s.connect((host, port))
    
    a=1
    while (a):
        response  = input('If you want to\nExit, press 0\nLogin, press 1\nCreate New Account, press 2\n: ')
        if (response == "0"):
            s.sendall("0".encode())
            print("Your have opted to exit, Thanks for your interest!")
            a=0
            s.close()
        elif(response=="1"):
            sendLoginInformation()
        elif(response=="2"):
            createacc()
        else:
            print("invalid input")

def createacc():
    option = "2"
    s.sendall(option.encode())
    username = input("Enter your username:")
    password = getpass.getpass("Enter your password:")
    email = input("Enter your email:")
    age = input("Enter your age:")
    password = RSA_encrypt(password)
    s.sendall(username.encode())
    s.sendall(password.encode())
    s.sendall(email.encode())
    s.sendall(age.encode())
    print(s.recv(1024).decode())
    

def sendLoginInformation():
    option = "1"
    s.sendall(option.encode())
    username = input("Username: ")
    password = getpass.getpass("Password: ")
    password = RSA_encrypt(password)
    s.sendall(username.encode())
    s.sendall(password.encode())
    op = s.recv(1024).decode()
    if(op == "1"):
        print("Success, Welcome! " + username)
        b=1
        while (b):
            p = input('If you want to\nUpdate Account, press 3\nDelete account, press 4\nRetrieve Info, press 5\nLogout, press 6\n:')
            if (p == "3"):
                updateInfo()
            elif (p == "4"):
                b=0
                deleteAccount()
            elif (p == "5"):
                retrieveInfo()
            elif (p == "6"):
                l = logout();
                if(l=="1"):
                    b=0
                    print("Logout successful!")
                elif(l=="0"):
                    print("Logout unsuccessful!")
                elif(l=="2"):
                    print("Command not valid, try Yes or No")
            else:
                print("Invalid Choice")
    elif (op == "2"):
        print("No such user exist, please try again.")

            
def updateInfo():
    print("Updating Info\n")
    g = "3"
    s.sendall(g.encode())
    email = input("Email: ")
    age = input("Age: ")
    s.sendall(email.encode())
    s.sendall(age.encode())
    print(s.recv(1024).decode())

def deleteAccount():
    print("Delete Account\n")
    g = "4"
    s.sendall(g.encode())
    print(s.recv(1024).decode())

def retrieveInfo():
    print("Retrieving Info\n")
    g = "5"
    s.sendall(g.encode())
    print(s.recv(1024).decode())
    
def logout():
    g = "6"
    s.sendall(g.encode())
    print("Would you like to logout?")
    response = input("Yes or No ?? ")
    s.sendall(response.encode())
    return s.recv(1024).decode()
    

def gcd(a,b): 
    if b==0: 
        return a 
    else: 
        return gcd(b,a%b) 
    
    
def RSA_encrypt(password):
    p = 53 #prime number
    q = 59 #prime number

    li=[]
    for i in password:
        li.extend(ord(num)%64 for num in i)

    no=0
    for j in li:
        no=(no*10)+j

    n = p*q 
    t = (p-1)*(q-1) 

    for e in range(2,t): 
        if gcd(e,t)== 1: 
            break


    for i in range(1,10): 
        x = 1 + i*t 
        if x % e == 0: 
            d = int(x/e) 
            break
    ctt = Decimal(0) 
    ctt =pow(no,e) 
    ct = ctt % n 
    
    return (str(ct))
    
    
    
main()
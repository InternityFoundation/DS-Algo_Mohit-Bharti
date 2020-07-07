import socket
import mysql.connector
mydb=mysql.connector.connect(host="localhost",user="root",passwd="india@123",database="pytesting")
mycursor=mydb.cursor()


def initServer():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = socket.gethostname()
    #host = '127.0.0.1'
    port = 12345
    s.bind((host, port))
    s.listen(5)
    print('Server Listening...')
    print("Waiting for Client to connect")

    conn, addr = s.accept()
    print("Got connection from: ", addr)
    c=1
    while (c):
        option = conn.recv(1024).decode()
        print(option)
        if (option == "0"):
            c=0
            conn.close()
            
        elif option == "1":
            username = conn.recv(1024).decode()
            password = conn.recv(1024).decode()
            login = validateLogin(username, password)
            conn.sendall(login.encode())
            if (login =="1"):
                d=1
                while (d):
                    g = conn.recv(1024).decode()
                    if (g == "3"):
                        email = conn.recv(1024).decode()
                        age = conn.recv(1024).decode()
                        update = updateInfo(username,password,email,age)
                        conn.sendall(update.encode())
                    elif (g == "4"):
                        d=0
                        delete = deleteAccount(username,password)
                        conn.sendall(delete.encode())
                    elif (g == "5"):
                        retrieve = retrieveInfo(username,password)
                        conn.sendall(retrieve.encode())
                    elif (g == "6"):
                        response = conn.recv(1024).decode()
                        Logout = logout(response)
                        conn.sendall(Logout.encode())
                        if(Logout == "1"):
                            d=0
                    else:
                        return "Invalid choice"

        elif option == "2":
            username = conn.recv(1024).decode()
            password = conn.recv(1024).decode()
            email = conn.recv(1024).decode()
            age = conn.recv(1024).decode()
            print("passing")
            create = createacc(username,password,email,age)
            print("passed")
            conn.sendall(create.encode())
            
        else:
            print("Invalid")

def createacc(username,password,email,age):
    p=[]
    mycursor.execute("select name,pass from py3")
    for i in mycursor:
        p.append(i)
    if (username,password) in p:
        return "Username already exists!!"
    mycursor.execute("insert into py3 values(%s,%s,%s,%s)",(username,password,email,age))
    mydb.commit()
    return "Your Account has been created"


def validateLogin(username,password):
    p=[]
    mycursor.execute("select name,pass from py3")
    for i in mycursor:
        p.append(i)
    if (username,password) in p:
        print("1")
        return "1"
    else:
        print("2")
        return "2"
    
def updateInfo(username,password,email,age):
    mycursor.execute("update py3 set email=%s,age=%s where name=%s and pass=%s",(email,age,username,password))
    mydb.commit()
    return "Your age & gender is updated"
    
    
def deleteAccount(username,password):
    mycursor.execute("delete from py3 where name=%s and pass=%s",(username,password))
    mydb.commit()
    return "Your account is deleted!"


def retrieveInfo(username,password):
    mycursor.execute("select * from py3 where name=%s and pass=%s",(username,password))
    p=[]
    for i in mycursor:
        p=i
    mydb.commit()
    h=("username= "+ p[0] + " , password= " + p[1] + " ,email= " + p[2] +", age= "+ p[3])
    return h


def logout(response):
    if response == ("yes") or response == ("Yes") or response == ("YES"):
        return "1"
    elif response == ("no") or response == ("No") or response == ("NO"):
        return "0"
    else:
        return "2"

initServer()
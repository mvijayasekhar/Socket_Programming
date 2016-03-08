
VPATH=:./inc/:./src/:./obj

TARGET1=SERVER
TARGET2=CLIENT

HEADER= -I ./inc

CFLAGS=-g -Wall -lsctp

LIB=-lsctp

$(TARGET1) : Server.o Client.o
	gcc $(CFLAGS) -o $(TARGET1) Server.o $(HEADER) $(LIB)
	gcc $(CFLAGS) -o $(TARGET2) Client.o $(HEADER) $(LIB)
	mv *.o ./obj

%.o : %.c
	gcc $(CFLAGS) -c $< $(HEADER) $(LIB)

clean :
	rm -f $(TARGET1) $(TARGET2)
	rm -f ./obj/*
	rm -f *.o

rmbackup : 
	rm -f *~
	rm -f ./src/*~
	rm -f ./inc/*~



VPATH=:./inc/:./src/:./obj

TARGET1=SERVER
TARGET2=CLIENT

HEADER= -I ./inc

CFLAGS=-g -Wall


$(TARGET1) : Server.o Client.o
	gcc $(CFLAGS) -o $(TARGET1) Server.o $(HEADER)
	gcc $(CFLAGS) -o $(TARGET2) Client.o $(HEADER)
	mv *.o ./obj

%.o : %.c
	gcc $(CFLAGS) -c $< $(HEADER)
		


clean :
	rm -f $(TARGET1) $(TARGET2)
	rm -f ./obj/*
	rm -f *.o

rmbackup : 
	rm -f *~
	rm -f ./src/*~
	rm -f ./inc/*~


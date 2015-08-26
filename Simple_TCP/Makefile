
VPATH=:./Header/:./Src/:./Obj

TARGET1=SERVER
TARGET2=CLIENT

HEADER= -I ./Header

CFLAGS=-g -Wall


$(TARGET1) : Server.o Client.o
	gcc $(CFLAGS) -o $(TARGET1) Server.o $(HEADER)
	gcc $(CFLAGS) -o $(TARGET2) Client.o $(HEADER)
	mv *.o ./Obj

%.o : %.c
	gcc $(CFLAGS) -c $< $(HEADER)
		


clean :
	rm -f $(TARGET1) $(TARGET2)
	rm -f ./Obj/*
	rm -f *.o

rmbackup : 
	rm -f *~
	rm -f ./Src/*~
	rm -f ./Header/*~


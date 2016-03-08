
VPATH=:./inc/:./src/:./obj

TARGET=RawSocket

HEADER= -I ./inc

CFLAGS=-g -Wall


$(TARGET) : RawSocket.o PrintEthHeader.o PrintIPHeader.o PrintTCPHeader.o PrintUDPHeader.o  
	gcc $(CFLAGS) -o $(TARGET) $^ $(HEADER)
	mv *.o ./obj

%.o : %.c
	gcc $(CFLAGS) -c $< $(HEADER)
		


clean :
	rm -f $(TARGET) 
	rm -f ./obj/*
	rm -f *.o

rmbackup : 
	rm -f *~
	rm -f ./src/*~
	rm -f ./inc/*~


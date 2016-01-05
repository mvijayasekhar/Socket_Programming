
VPATH=:./Header/:./Src/:./Obj

TARGET=RawSocket

HEADER= -I ./Header

CFLAGS=-g -Wall


$(TARGET) : RawSocket.o PrintEthHeader.o PrintIPHeader.o PrintTCPHeader.o PrintUDPHeader.o  
	gcc $(CFLAGS) -o $(TARGET) $^ $(HEADER)
	mv *.o ./Obj

%.o : %.c
	gcc $(CFLAGS) -c $< $(HEADER)
		


clean :
	rm -f $(TARGET) 
	rm -f ./Obj/*
	rm -f *.o

rmbackup : 
	rm -f *~
	rm -f ./Src/*~
	rm -f ./Header/*~


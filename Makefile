OBJS	= mastermind.3.o
SOURCE	= mastermind.3.c
HEADER	= 
OUT	= MasterMind.exe
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

mastermind.o: mastermind.c
	$(CC) $(FLAGS) mastermind.c 


clean:
	rm -f $(OBJS) $(OUT)

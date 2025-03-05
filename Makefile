# Makefile
# Author: Daniel Guerra-Rojas

Design = TicTacWowWeeWow TicTacWowWeeWowTest

CC     = gcc
DEBUG  = -DDEBUG # used for TicTacWowWeeWowTest only; for normal program, need to add manually
CFLAGS = -ansi -std=c99 -Wall -c
LFLAGS = -ansi -std=c99 -Wall
AR     = ar rc
RANLIB = ranlib

all: TicTacWowWeeWow TicTacWowWeeWowTest

#target to clean directory
clean:
	rm -f $(Design)
	rm -f *.o
	rm -f *.a

##### Generate Object Files #####

#target to create Settings.o 
Settings.o: Settings.c Settings.h
	$(CC) $(CFLAGS) Settings.c -o Settings.o

#target to create GameControl.o
GameControl.o: GameControl.c GameControl.h AI.h BoardStruct.h
	$(CC) $(CFLAGS) GameControl.c -o GameControl.o

#target to create AI.o
AI.o: AI.c AI.h GameControl.h
	$(CC) $(CFLAGS) AI.c -o AI.o

#target to create BoardStruct.o
BoardStruct.o: BoardStruct.c BoardStruct.h
	$(CC) $(CFLAGS) BoardStruct.c -o BoardStruct.o

#target to create Replay.o
Replay.o: Replay.c Replay.h BoardStruct.h
	$(CC) $(CFLAGS) Replay.c -o Replay.o

#target to create TicTacWowWeeWow.o
#debug is optional, but must code in
TicTacWowWeeWow.o: TicTacWowWeeWow.c GameControl.h Settings.h PlayerStruct.h BoardStruct.h Replay.h
	$(CC) $(CFLAGS) TicTacWowWeeWow.c -o TicTacWowWeeWow.o

#target to create TicTacWowWeeWowTest.o
#debug is hardcoded in
TicTacWowWeeWowTest.o: TicTacWowWeeWow.c GameControl.h Settings.h PlayerStruct.h BoardStruct.h Replay.h
	$(CC) $(CFLAGS) $(DEBUG) TicTacWowWeeWow.c -o TicTacWowWeeWowTest.o

##### Generate Libaries #####

#target to generate AI Libary
libAI.a: AI.o
	$(AR) libAI.a AI.o
	$(RANLIB) libAI.a

##### Generate Executables #####

#target to generate TicTacWowWeeWow
TicTacWowWeeWow: TicTacWowWeeWow.o libAI.a GameControl.o Settings.o BoardStruct.o Replay.o
	$(CC) $(LFLAGS) TicTacWowWeeWow.o GameControl.o Settings.o BoardStruct.o Replay.o -L. -lAI -o TicTacWowWeeWow

#target to generate TicTacWowWeeWowTest
TicTacWowWeeWowTest: TicTacWowWeeWowTest.o libAI.a GameControl.o Settings.o BoardStruct.o Replay.o
	$(CC) $(LFLAGS) TicTacWowWeeWowTest.o GameControl.o Settings.o BoardStruct.o Replay.o -L. -lAI -o TicTacWowWeeWowTest

# EOF #

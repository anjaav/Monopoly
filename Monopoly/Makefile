PROGRAM=monopoly
CC=g++
CXXFLAGS= -Wall -std=c++17

$(PROGRAM): main.cpp field.hpp player.o  city.o utilities.o station.o parking.o tax.o vchance.o vchest.o start.o goToJail.o jail.o card.o cardGetOutJail.o cardGiveMoney.o cardGoToJail.o cardMove.o cardTakeMoney.o cardTransfer.o game.o 
	$(CC) $(CXXFLAGS) -o $@ $^


.PHONY: clean dist

clean:
	rm *.o $(PROGRAM) 



# make -> generate 'main' executable for comparing portfolio computations
# make main -> same as 'make'
# make generate-portfolio -> generate 'generate-portfolio' executable to create 'fake-stock-portfolio.csv'
# make clean -> remove all executables, object files, and temporary files

CC = g++
CFLAGS  = -g -Wall

main: main.o dod-stock-portfolio.o oop-stock-portfolio.o 
	$(CC) $(CFLAGS) -O2 -o main main.o dod-stock-portfolio.o oop-stock-portfolio.o

main.o: main.cpp dod-stock-portfolio.h oop-stock-portfolio.h 
	$(CC) $(CFLAGS) -c main.cpp

dod-stock-portfolio.o: dod-stock-portfolio.cpp dod-stock-portfolio.h 
	$(CC) $(CFLAGS) -c dod-stock-portfolio.cpp

oop-stock-portfolio.o: oop-stock-portfolio.cpp oop-stock-portfolio.h 
	$(CC) $(CFLAGS) -c oop-stock-portfolio.cpp

generate-portfolio: generate-portfolio.o
	$(CC) $(CFLAGS) -o generate-portfolio generate-portfolio.o

generate-portfolio.o: generate-portfolio.cpp
	$(CC) $(CFLAGS) -c generate-portfolio.cpp

clean: 
	$(RM) main generate-portfolio *.o *~

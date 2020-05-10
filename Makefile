# make -> generate 'main' executable for comparing portfolio computations
# make main -> same as 'make'
# make generate-portfolio -> generate 'generate-portfolio' executable to create 'fake-stock-portfolio.csv'
# make clean -> remove all executables, object files, and temporary files

CC = g++
CFLAGS  = -g -Wall

main: main.o dod-stock-portfolio.o oop-stock-portfolio.o 
	$(CC) $(CFLAGS) -O2 -o main main.o dod-stock-portfolio.o oop-stock-portfolio.o

main.o: src/main.cpp src/dod-stock-portfolio.h src/oop-stock-portfolio.h 
	$(CC) $(CFLAGS) -c src/main.cpp

dod-stock-portfolio.o: src/dod-stock-portfolio.cpp src/dod-stock-portfolio.h 
	$(CC) $(CFLAGS) -c src/dod-stock-portfolio.cpp

oop-stock-portfolio.o: src/oop-stock-portfolio.cpp src/oop-stock-portfolio.h 
	$(CC) $(CFLAGS) -c src/oop-stock-portfolio.cpp

generate-portfolio: generate-portfolio.o
	$(CC) $(CFLAGS) -o generate-portfolio generate-portfolio.o

generate-portfolio.o: src/generate-portfolio.cpp
	$(CC) $(CFLAGS) -c src/generate-portfolio.cpp

clean: 
	$(RM) main generate-portfolio *.o *~

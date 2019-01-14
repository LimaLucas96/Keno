Keno: funcoes.o KenoBet.o main.o
	g++ -Wall -std=c++11 funcoes.o KenoBet.o main.o -o Keno -lm
	-rm *.o
funcoes.o:
	g++ -std=c++11 -o funcoes.o -c src/functions.cpp
KenoBet.o:
	g++ -std=c++11 -o KenoBet.o -c src/KenoBet.cpp
main.o:
	g++ -std=c++11 -o main.o -c src/main.cpp
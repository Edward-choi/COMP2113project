MC1.o: MC1.cpp mc1.h
	g++ -c MC1.cpp
MC2.o: MC2.cpp mc2.h
	g++ -c MC2.cpp
MC3.o: MC3.cpp mc3.h
	g++ -c MC3.cpp
MC4.o: MC4.cpp mc4.h
	g++ -c MC4.cpp
Opponent.o: Opponent.cpp opponent.h
	g++ -c Opponent.cpp
User.o: User.cpp user.h
	g++ -c User.cpp
numberGuess.o: numberGuess.cpp user.h opponent.h numberGuess.h
	g++ -c numberGuess.cpp
RPS.o: RPS.cpp rps.h
	g++ -c RPS.cpp
battleshipGame.o: battleshipGame.cpp mc1.h mc2.h mc3.h mc4.h opponent.h user.h numberGuess.h rps.h
	g++ -c battleshipGame.cpp
main: MC1.o MC2.o MC3.o MC4.o Opponent.o User.o numberGuess.o RPS.o battleshipGame.o
	g++ MC1.o MC2.o MC3.o MC4.o Opponent.o User.o numberGuess.o RPS.o battleshipGame.o -o main

clean:
	rm -f MC1.o MC2.o MC3.o MC4.o Opponent.o User.o numberGuess.o RPS.o battleshipGame.o main
.PHONY: clean

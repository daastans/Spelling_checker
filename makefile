bin/scheck : main.o parser.o csvreporter.o
	g++ bin/main.o bin/parser.o bin/csvreporter.o -o bin/scheck
main.o : src/main.cpp inc/parser.h inc/error.h inc/dictionary.h inc/csvreporter.h
	g++ -I inc -c src/main.cpp -o bin/main.o
parser.o : src/parser.cpp inc/error.h inc/parser.h
	g++ -I inc -c src/parser.cpp -o bin/parser.o
csvreporter.o:src/csvreporter.cpp inc/csvreporter.h
		g++ -I inc -c src/csvreporter.cpp -o bin/csvreporter.o

clean:
	rm bin/*.o

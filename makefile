bin/scheck : main.o parser.o csvreporter.o xmlreporter.o commandline.o settings.o
	g++ bin/main.o bin/parser.o bin/csvreporter.o bin/xmlreporter.o bin/commandline.o bin/settings.o -o bin/scheck
main.o : src/main.cpp inc/parser.h inc/error.h inc/dictionary.h inc/csvreporter.h
	g++ -I inc -c src/main.cpp -o bin/main.o
parser.o : src/parser.cpp inc/error.h inc/parser.h
	g++ -I inc -c src/parser.cpp -o bin/parser.o
csvreporter.o:src/csvreporter.cpp inc/csvreporter.h
	g++ -I inc -c src/csvreporter.cpp -o bin/csvreporter.o
xmlreporter.o:src/xmlreporter.cpp inc/xmlreporter.h
	g++ -I inc -c src/xmlreporter.cpp -o bin/xmlreporter.o
commandline.o:src/commandline.cpp inc/commandline.h
	g++ -I inc -c src/commandline.cpp -o bin/commandline.o
settings.o : src/settings.cpp inc/settings.h
	g++ -I inc -c src/settings.cpp -o bin/settings.o

clean:
	rm bin/*.o

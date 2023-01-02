CC = g++
APPNAME = advent
FILES := $(filter-out source/test.cpp, $(wildcard source/*.cpp))
TESTFILES := $(filter-out source/main.cpp, $(wildcard source/*.cpp))
FLAGS := -std=c++17 
DEBUG_FLAGS := -Wall -std=c++17

$(APPNAME).exe: $(patsubst source/%.cpp, ./%.o, $(FILES))
	$(CC) $(FLAGS) $^ -o $@

debug: $(patsubst source/%.cpp, ./%.o, $(TESTFILES))
	$(CC) $(FLAGS) $^ -o $(APPNAME)_test.exe

%.o: source/%.cpp
	$(CC) $(FLAGS) -c -MD $<

%.o: test/%.cpp
	$(CC) $(FLAGS) -c -MD $<

clean:
	rm *.o *.exe *.d *.out
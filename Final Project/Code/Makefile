CC = mpiCC
#CC = mpixx #for stampede2

CXXFLAGS_C = -std=c++11 -Wall -c -O3 -ffast-math -mavx
CXXFLAGS = -std=c++11 -Wall -O3 -ffast-math -mavx
LDFLAGS = -lm


all: collect.o dudt.o exact.o update.o wave.o

clean:
	rm -rf *.o 

collect.o: collect.cpp collect.hpp
		$(CC) $(CXXFLAGS_C) collect.cpp $(LDFLAGS)
dudt.o: dudt.cpp dudt.hpp
		$(CC) $(CXXFLAGS_C) dudt.cpp $(LDFLAGS)
exact.o: exact.cpp exact.hpp
		$(CC) $(CXXFLAGS_C) exact.cpp $(LDFLAGS)
update.o: update.cpp update.hpp
		$(CC) $(CXXFLAGS_C) update.cpp $(LDFLAGS)
wave.o: collect.o dudt.o exact.o update.o
		$(CC) $(CXXFLAGS) -O -o wave collect.o dudt.o exact.o update.o wave.cpp $(LDFLAGS)



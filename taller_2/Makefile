BIN		:= MergeSort_serial MergeSort_parallel generate

CFLAGS		:= -std=c++14 -O3 -m64
LDFLAGS		:= -fopenmp

CXX		:= g++

HEADS		:=  generate_random.hpp
SRC		:=  generate_random.cpp



MergeSort_serial: MergeSort_serial.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ MergeSort_serial.cpp

MergeSort_parallel: MergeSort_parallel.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ MergeSort_parallel.cpp

generate: generate.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) generate.cpp

clean:
	rm $(BIN) *.o core*

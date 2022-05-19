CXXFLAGS=-Wall -Werror -std=c++11

all: test_pqueue test_bstream

test_pqueue: test_pqueue.cc pqueue.h
	g++ -g $(CXXFLAGS) -o test_pqueue test_pqueue.cc -pthread -lgtest

test_bstream: test_bstream.cc bstream.h
	g++ -g $(CXXFLAGS) -o test_bstream test_bstream.cc -pthread -lgtest

clean:
	-rm -f test_pqueue test_bstream
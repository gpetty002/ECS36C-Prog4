CXXFLAGS=-Wall -Werror -std=c++11

all: test_pqueue test_bstream zap unzap

test_pqueue: test_pqueue.cc pqueue.h
	g++ -g $(CXXFLAGS) -o test_pqueue test_pqueue.cc -pthread -lgtest

test_bstream: test_bstream.cc bstream.h
	g++ -g $(CXXFLAGS) -o test_bstream test_bstream.cc -pthread -lgtest

zap: pqueue.h bstream.h huffman.h
	g++ -g $(CXXFLAGS) -o zap zap.cc

unzap: pqueue.h bstream.h huffman.h
	g++ -g $(CXXFLAGS) -o unzap unzap.cc

clean:
	-rm -f test_pqueue test_bstream zap unzap
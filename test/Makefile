all: test run

test: test.cpp
	g++ test.cpp -o test `pkg-config opencv --libs`
run:
	./test
clean:
	rm -f test

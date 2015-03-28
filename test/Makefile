all: check test run

check:
	@apt-cache showpkg libopencv-dev > /dev/null
test: test.cpp
	g++ test.cpp -o test `pkg-config opencv --libs`
run:
	./test
clean:
	rm -f test

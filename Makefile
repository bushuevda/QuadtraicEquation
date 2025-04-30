files_to_delete = $(wildcard test main)


run: clean test
	g++ main.cpp quadratic_equation/quadratic_equation.cpp -o main && ./main

clean:
	rm -f ${files_to_delete}

test: clean
	g++ -std=c++11 tests/test_quadratic_equation.cpp \
	quadratic_equation/quadratic_equation.cpp -o test && ./test && rm test
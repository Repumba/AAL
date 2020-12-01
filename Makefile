make:
	g++ main.cpp -o main.e
	g++ gen.cpp -o gen.e
clean:
	rm test*

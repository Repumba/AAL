make:
	g++ main.cpp src/cli.cpp src/mainAlgorithm.cpp src/MeasureTime.cpp -o main.e -w

clean:
	rm main.e
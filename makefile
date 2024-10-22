main: main.o
	g++ main.cpp glad.c LoadShader.cpp -o main -lglfw3

main.o: main.cpp LoadShader.cpp


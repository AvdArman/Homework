command = -std=c++11
all: tree.exe

tree.exe: main.o BinaryTree.o
	g++ $(command) main.o BinaryTree.o -o tree.exe

main.o: main.cpp
	g++ $(command) -c main.cpp

BinaryTree.o: BinaryTree.cpp
	g++ $(command) -c BinaryTree.cpp

clean:
	rm -rf *.0 tree.exe

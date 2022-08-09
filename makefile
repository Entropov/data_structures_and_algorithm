bubbleSort:sort/bubbleSort.c
	gcc -o bin/bubbleSort sort/bubbleSort.c

selectionSort:sort/selectionSort.c
	gcc -o bin/selectionSort sort/selectionSort.c

monkeySort:sort/monkeySort.cpp
	g++ -o bin/monkeySort sort/monkeySort.cpp

test:test.c
	gcc -o bin/test test.c struct/adjList.h struct\adjList.h struct\queue.h struct\binaryTree.h struct\stack.h struct\linkList.h
	bin/test

clean:
	del /F bin\*
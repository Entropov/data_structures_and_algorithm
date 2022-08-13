bubbleSort:sort/bubbleSort.c
	gcc -o bin/bubbleSort sort/bubbleSort.c
	
insertionSort:sort/insertionSort.c
	gcc -o bin/insertionSort sort/insertionSort.c

selectionSort:sort/selectionSort.c
	gcc -o bin/selectionSort sort/selectionSort.c

monkeySort:sort/monkeySort.cpp
	g++ -o bin/monkeySort sort/monkeySort.cpp

shellSort:sort/shellSort.c
	gcc -o bin/shellSort sort/shellSort.c

mergeSort:sort/mergeSort.c
	gcc -o bin/mergeSort sort/mergeSort.c

BFS:algorithm/BFS.c
	gcc -o bin/BFS algorithm/BFS.c struct/graph.h struct/queue.h

test:test.c
	gcc -o bin/test test.c struct/adjList.h struct\adjList.h struct\queue.h struct\binaryTree.h struct\stack.h struct\linkList.h
	bin/test

clean:
	del /F bin\*

recursive.o: recursive.c
	gcc -c recursive.c
recursive: recursive.o
	gcc recursive.o -o recursive
non-recursive.o: non-recursive.c
	gcc -c non-recursive.c
non-recursive: non-recursive.o
	gcc non-recursive.o -o non-recursive
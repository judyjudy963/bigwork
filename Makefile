main:main.o Queue.o Stack.o Tree.o
	gcc  main.o Queue.o Stack.o Tree.o -o a.out

main.o:main.c
	gcc  -c main.c

Queue.o:Queue.c
	gcc  -c Queue.c

Stack.o:Stack.c
	gcc  -c Stack.c

Tree.o:Tree.c
	gcc  -c Tree.c

clean:
	rm main.o && rm Queue.o && rm Tree.o && rm Stack.o && rm a.out

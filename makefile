default: all

all: p1 p2 p3 

p1: ./program1_1.c
	gcc program1_1.c -o p1

p2: ./program1_2.c
	gcc ./program1_2.c -o p2

p3: ./program1_3.c
	gcc ./program1_3.c -o p3

clean:
	rm -f p1 p2 p3
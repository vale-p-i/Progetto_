link	: box list main operation stack_list eq item
	gcc box.o list.o main.o operation.o stack_list.o eq.o item.o -o eq

box	:
	gcc -c box.c

list	:
	gcc -c list.c

main	:
	gcc -c main.c

operation	:
	gcc -c operation.c

stack_list	:
	gcc -c stack_list.c

eq	:
		gcc -c eq.c

item	:
	gcc -c item.c

clean	:
	rm -f box.o list.o main.o operation.o stack_list.o eq.o item.o eq

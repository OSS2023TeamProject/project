main : manager.o employee.o main.c
	gcc manager.o employee.o main.c -o main
manager.o : manager.c manager.h
	gcc -c manager.c
employee.o : employee.c employee.h
	gcc -c employee.c
clean :
	rm *.o main
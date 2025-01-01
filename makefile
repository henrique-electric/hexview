all:
	@gcc -c hexview.c
	@gcc hexview.o main.c -o main
	
all:
	@gcc -s -c src/hexview.c
	@gcc -s -O3 hexview.o src/main.c -o main
	
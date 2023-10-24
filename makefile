all: compile

compile: main.o fsys.o misc.o include/fsys.h include/misc.h
	@gcc -o KlaudFS main.o fsys.o misc.o

run:
	@clear
	@./KlaudFS

clean:
	@rm *.o
	@rm KlaudFS

clean_disk:
	@rm disk

debug:
	@clear
	@valgrind --leak-check=yes ./KlaudFS
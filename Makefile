all: game_of_life

game_of_life: src/*.c
	gcc -o GOL src/*.c -lncurses

rebuild: clean all

clean:
	rm -rf GOL
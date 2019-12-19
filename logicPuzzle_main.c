#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int term_w = 0;
int term_h = 0;

WINDOW *create_win(int h, int w, int y, int x) {
	WINDOW *new_win;

	new_win = newwin(h, w, y, x);
	if (new_win == NULL) 
		return NULL;
	
	box(new_win, 0, 0);
	wrefresh(new_win);
	return new_win;
}

int main() {
	WINDOW *win;
	int x, y, w, h;
	int ch;

	/* start curses */
	initscr();

	/* print it on to the real screen */
	refresh();

	/* draw border */
	w = 100;
	h = 50;
	y = 0;
	x = 0;

	mvprintw(w / 4, h / 2, "TEST");
	win = create_win(h, w, y, x);

	/* wait for user input */
	getch();

	/* end curses mode */
	endwin();

	return 0;
}

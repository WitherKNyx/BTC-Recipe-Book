#include <cstdlib>
#include <locale.h>
#include <ncurses.h>

void init_curses() {
	setlocale(LC_ALL, "");
	initscr();
	use_default_colors();
	cbreak();
	noecho();
}

void draw_start_screen() {
	mvprintw(19, 47, "│");
	mvprintw(20, 27, "┌──╮  ──┬──  ╭───╮  │");
	mvprintw(21, 27, "│  │    │    │      │");
	mvprintw(22, 27, "├──⧼    │    │      │");
	mvprintw(23, 27, "│  │    │    │      │");
	mvprintw(24, 27, "└──╯ ●  ╵  ● ╰───╯  │");
	mvprintw(25, 27, "    Recipe Book     │");
	mvprintw(26, 47, "│");
	// mvprintw(20, 50, "Welcome back,");
	// mvprintw(21, 50, "Jill."); // Change to use usr
	mvprintw(21, 50, "Welcome back,");
	mvprintw(21, 64, "Jill."); // Change to use usr
	mvprintw(24, 50, "Use the navigation bar");
	mvprintw(25, 50, "to start browsing.");
}

void draw_name_screen() {
	mvprintw(16, 20, "Search by: Name");
	mvprintw(20, 25, "B");
	mvprintw(25, 25, "F");
	mvprintw(30, 25, "M");
	mvprintw(35, 25, "S");
	mvprintw(20, 30, "C");
	mvprintw(25, 30, "G");
	mvprintw(30, 30, "P");
	mvprintw(35, 30, "Z");
	move(20, 25);
}

void draw_flavor_screen() {
	mvprintw(16, 20, "Search by: Flavor");
	mvprintw(20, 20, "Sweet Drinks");
	mvprintw(23, 20, "Bitter Drinks");
	mvprintw(26, 20, "Sour Drinks");
	mvprintw(29, 20, "Spicy Drinks");
	mvprintw(32, 20, "Bubbly Drinks");
	move(20, 20);
}

void draw_type_screen() {
	mvprintw(16, 20, "Search by: Type");
	mvprintw(20, 20, "Girly Drinks");
	mvprintw(23, 20, "Manly Drinks");
	mvprintw(26, 20, "Classic Drinks");
	mvprintw(29, 20, "Classy Drinks");
	mvprintw(32, 20, "Promo Drinks");
	move(20, 20);
}

bool term_size_ok() {
	int lines, cols;
	getmaxyx(stdscr, lines, cols);
	return (lines >= 28) && (cols >= 57);
}

int main(int argc, char* argv[]) {
	init_curses();

	char key = 0;

	while (key != 'q') {
		if (!term_size_ok()) {
			mvprintw(1, 1, "Terminal size too small!");
			continue;
		}
		switch (key) {
			case 'n':
			case 'N':
				clear();
				draw_name_screen();
				break;
			case 'f':
			case 'F':
				clear();
				draw_flavor_screen();
				break;
			case 't':
			case 'T':
				clear();
				draw_type_screen();
				break;
			case 0:
			case '0':
				clear();
				draw_start_screen();
				break;
			default:
				break;
		}
		refresh();
		key = getch();
	}

	endwin();
	return EXIT_SUCCESS;
}

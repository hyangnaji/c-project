#include"function.h"

int main() {

	input_data();

	while (pause) {
		gotoxy(5, 3); printf("환영합니다.");
		main_menu();
	}

	return 0;
}
// WGC.cpp : Defines the entry point for the console application.
// «адача о волке, козе и капусте

#include "stdafx.h"
#define NUM 4
#define MAX 10

// правый берег - 1
// левый берег - 0
// целевое значение - 0 0 0 0 


// массив состо€ний дл€ каждого шага
int states[NUM];
int index;
int path[MAX][NUM];
int number;

// существа
int F = 0, // фермер
W = 1, // волк
G = 2, // коза
C = 3; // капуста

void start();
void read_path();
bool safe();
void move_F_self();
void move_F_C();
void move_F_W();
void move_F_G();
void move(int x, int y);
bool checking();

int main()
{
	start();
	while (states[F] != 0 || states[C] != 0 || states[W] != 0 || states[G] != 0) {
		// перевозка фермера
		move_F_self();
		// проверка на допустимость текущего состо€ни€
		if (!safe()) {
			if (states[F] == 0) {
				states[F] = 1;
			} else {
				states[F] = 0;
			}
		}
		// запись пройденного пути
		if (!checking()) {
			read_path();
		}

		// перевозка волка
		move_F_W();
		// проверка на допустимость текущего состо€ни€
		if (!safe()) {
			move(F, W);
		}
		// запись пройденного пути
		if (!checking()) {
			read_path();
		}

		// перевозка козы
		move_F_G();
		// проверка на допустимость текущего состо€ни€
		if (!safe()) {
			move(F, G);
		}
		// запись пройденного пути
		if (!checking()) {
			read_path();
		}

		// перевозка капусты
		move_F_C();
		// проверка на допустимость текущего состо€ни€
		if (!safe()) {
			move(F, C);
		}
		// запись пройденного пути
		if (!checking()) {
			read_path();
		}
	}

	// вывод решени€
	for (int i = 0; i < number; i++) {
		printf("%d. {%d,", i+1, path[i][F]);
		printf("%d,", path[i][C]);
		printf("%d,", path[i][W]);
		printf("%d}\n", path[i][G]);
	}
    return 0;
}

// функци€ дл€ инициализации стартовыми значени€ми
void start() {
	number = 0;
	states[F] = 1;
	states[W] = 1;
	states[G] = 1;
	states[C] = 1;
}

// функци€ дл€ записи пройденного пути
void read_path() {
	path[number][F] = states[F];
	path[number][W] = states[W];
	path[number][G] = states[G];
	path[number][C] = states[C];
	number++;
}

// функци€ дл€ проверки 
bool checking() {
	for (int i = 0; i < number; i++) {
		if (path[i][F] == states[F] && path[i][C] == states[C] && path[i][W] == states[W] && path[i][G] == states[G]) {
			return true; // совпадает
		}
	}
	return false; // совпадени€ не найдены
}

// функци€ дл€ проверки состо€ни€ на опасность
bool safe() {
	if (states[G] == states[W] && states[F] != states[W]) {
		return false; // опасное состо€ние
	}
	if (states[G] == states[C] && states[F] != states[G]) {
		return false; // опасное состо€ние
	}
	return true;
}

// функци€ переправы через реку F
void move_F_self() {
	if (states[F] == 0) {
		states[F] = 1;
	} else {
		states[F] = 0;
	}
}

// функци€ дл€ переправы через реку F и C
void move_F_C() {
	if (states[F] == states[C]) {
		move(F, C);
	}
}

// функци€ дл€ переправы через реку F и W
void move_F_W() {
	if (states[F] == states[W]) {
		move(F, W);
	}
}

// функци€ дл€ переправы через реку F и G
void move_F_G() {
	if (states[F] == states[G]) {
		move(F, G);
	}
}

// функци€ дл€ перевозки двух существ
void move(int x, int y) {
	if (states[x] == 0) {
		states[x] = 1;
		states[y] = 1;
	} else {
		states[x] = 0;
		states[y] = 0;
	}
}
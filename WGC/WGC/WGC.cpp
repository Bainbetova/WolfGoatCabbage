// WGC.cpp : Defines the entry point for the console application.
// ������ � �����, ���� � �������

#include "stdafx.h"
#define NUM 4
#define MAX 10

// ������ ����� - 1
// ����� ����� - 0
// ������� �������� - 0 0 0 0 


// ������ ��������� ��� ������� ����
int states[NUM];
int index;
int path[MAX][NUM];
int number;

// ��������
int F = 0, // ������
W = 1, // ����
G = 2, // ����
C = 3; // �������

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
		// ��������� �������
		move_F_self();
		// �������� �� ������������ �������� ���������
		if (!safe()) {
			if (states[F] == 0) {
				states[F] = 1;
			} else {
				states[F] = 0;
			}
		}
		// ������ ����������� ����
		if (!checking()) {
			read_path();
		}

		// ��������� �����
		move_F_W();
		// �������� �� ������������ �������� ���������
		if (!safe()) {
			move(F, W);
		}
		// ������ ����������� ����
		if (!checking()) {
			read_path();
		}

		// ��������� ����
		move_F_G();
		// �������� �� ������������ �������� ���������
		if (!safe()) {
			move(F, G);
		}
		// ������ ����������� ����
		if (!checking()) {
			read_path();
		}

		// ��������� �������
		move_F_C();
		// �������� �� ������������ �������� ���������
		if (!safe()) {
			move(F, C);
		}
		// ������ ����������� ����
		if (!checking()) {
			read_path();
		}
	}

	// ����� �������
	for (int i = 0; i < number; i++) {
		printf("%d. {%d,", i+1, path[i][F]);
		printf("%d,", path[i][C]);
		printf("%d,", path[i][W]);
		printf("%d}\n", path[i][G]);
	}
    return 0;
}

// ������� ��� ������������� ���������� ����������
void start() {
	number = 0;
	states[F] = 1;
	states[W] = 1;
	states[G] = 1;
	states[C] = 1;
}

// ������� ��� ������ ����������� ����
void read_path() {
	path[number][F] = states[F];
	path[number][W] = states[W];
	path[number][G] = states[G];
	path[number][C] = states[C];
	number++;
}

// ������� ��� �������� 
bool checking() {
	for (int i = 0; i < number; i++) {
		if (path[i][F] == states[F] && path[i][C] == states[C] && path[i][W] == states[W] && path[i][G] == states[G]) {
			return true; // ���������
		}
	}
	return false; // ���������� �� �������
}

// ������� ��� �������� ��������� �� ���������
bool safe() {
	if (states[G] == states[W] && states[F] != states[W]) {
		return false; // ������� ���������
	}
	if (states[G] == states[C] && states[F] != states[G]) {
		return false; // ������� ���������
	}
	return true;
}

// ������� ��������� ����� ���� F
void move_F_self() {
	if (states[F] == 0) {
		states[F] = 1;
	} else {
		states[F] = 0;
	}
}

// ������� ��� ��������� ����� ���� F � C
void move_F_C() {
	if (states[F] == states[C]) {
		move(F, C);
	}
}

// ������� ��� ��������� ����� ���� F � W
void move_F_W() {
	if (states[F] == states[W]) {
		move(F, W);
	}
}

// ������� ��� ��������� ����� ���� F � G
void move_F_G() {
	if (states[F] == states[G]) {
		move(F, G);
	}
}

// ������� ��� ��������� ���� �������
void move(int x, int y) {
	if (states[x] == 0) {
		states[x] = 1;
		states[y] = 1;
	} else {
		states[x] = 0;
		states[y] = 0;
	}
}
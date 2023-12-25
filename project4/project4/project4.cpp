#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;



HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int const N = 6;
int down = -99, up = 99;
bool printFlag = false;


void printArr(int arr[][N]) {

	cout << "\n";

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			if (j % 2 != 0);

			cout.width(
				4);
			cout << *(*(arr + i) + j) << ' ';
		}
		cout << "\n";
	}
}

void snakeFill(int arr[][N]) {

	system("cls");

	srand(time(NULL));


	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	int queue = 0;


	for (int i = 0; i <= N - 1; i += 2) {


		for (int j = 0; j < N; j++) {

			destCoord.X = queue * 4;
			destCoord.Y = j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);
			*(*(arr + j) + queue) = down + rand() % (up + up + 1);
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *(*(arr + j) + queue);
			Sleep(100);
		}
		queue++;

		for (int j = N - 1; j >= 0; j--) {

			destCoord.X = queue * 4;
			destCoord.Y = j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);


			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *(*(arr + j) + queue);
			Sleep(100);
		}
		queue++;
	}


	destCoord.X = 0;
	destCoord.Y = N * 2;
	SetConsoleCursorPosition(hStdout, destCoord);

	printFlag = true;

}

void spiralFill(int arr[][N]) {

	system("cls");

	srand(time(0));


	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int up = 0, down = N - 1, left = 0, right = N - 1;

	while (right >= left && up <= down) {
		//upper line

		for (int j = left; j <= right; j++) {

			destCoord.X = j * 4;
			destCoord.Y = up * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + up) + j) = -99 + rand() % (99 + 99 + 1);

			cout << *(*(arr + up) + j);

			cout.flush();
			Sleep(100);

		}
		up++;

		//right column

		for (int j = up; j <= down; j++) {

			destCoord.X = right * 4;
			destCoord.Y = j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);



			*(*(arr + j) + right) = -99 + rand() % (99 + 99 + 1);


			cout << *(*(arr + j) + right);

			cout.flush();
			Sleep(100);

		}
		right--;

		//bottom line

		for (int j = right; j >= left; j--) {

			destCoord.X = j * 4;
			destCoord.Y = down * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + down) + j) = -99 + rand() % (99 + 99 + 1);


			cout << *(*(arr + down) + j);

			cout.flush();
			Sleep(100);
		}
		down--;

		//left column

		for (int j = down; j >= up; j--) {

			destCoord.X = left * 4;
			destCoord.Y = j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + j) + left) = -99 + rand() % (99 + 99 + 1);

			cout << *(*(arr + j) + left);

			cout.flush();
			Sleep(100);

		}
		left++;
	}



	destCoord.X = 0;
	destCoord.Y = N * 2;
	SetConsoleCursorPosition(hStdout, destCoord);

	printFlag = true;

}

void spiralMix(int arr[][N]) {


	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (N / 2); j++) {
			swap(*(*(arr + i + (N / 2)) + j + (N / 2)), *(*(arr + i) + j));
		}

	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < N; j++) {
			swap(*(*(arr + i + (N / 2)) + j), *(*(arr + i) + j));
		}
	}
}
void diagonalMix(int arr[][N]) {

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N; j++) {
			swap(*(*(arr + N / 2 + i) + j), *(*(arr + i) + j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(*(*(arr + i) + j + N / 2), *(*(arr + i) + j));

		}
	}
}

void horizontalMix(int arr[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(*(*(arr + i) + j + N / 2), *(*(arr + i) + j));
		}
	}
}

void verticalMix(int arr[][N]) {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N; j++) {
			swap(*(*(arr + N / 2 + i) + j), *(*(arr + i) + j));
		}
	}
}

void insertSortPtr(int* arr) {
	int j;
	int* end = arr + N * N - 1;
	for (int* i = arr + 1; i <= end; i++) {
		if (*i < *(i - 1)) {
			for (j = *i; i > arr && *(i - 1) > j; i--) {
				*i = *(i - 1);
			}
			*i = j;
		}

	}
}

void calculate(int arr[][N], int sign, int num) {
	switch (sign) {
	case (1): {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(arr + i) + j) += num;
			}
		}
		break;
	}
	
	case (2): {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(arr + i) + j) -= num;
			}
		}
		break;
	}
	case (3): {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(arr + i) + j) *= num;
			}
		}
		break;
	}
	case (4): {
		for (int i = 0; i < N; i++) {
			if (num == 0) {
				break;
			}
			for (int j = 0; j < N; j++) {
				*(*(arr + i) + j) /= num;
			}
		}
		break;
	}
	}

}

void trans(int arr[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i != j) {
				swap(*(*(arr + i) + j), *(*(arr + j) + i));
			}
		}
	}
	printArr(arr);
}


int main() {

	//system("chcp 1251");
	setlocale(0, "");
	int gooon = 1;
	while (gooon){

		int ask;

		int goon = 1;

		int arr[N][N];

		int choose = 0;
		srand(static_cast<int>(time(0)));


		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {


				arr[i][j] = (rand() % 199) - 99;
			}
		}

		while (goon) {

			cout << "Выберите, что вы хотите сделать?\n"\
				"1.Вывести матрицу " << N << '*' << N << " змейкой или по спирали\n"\
				"2.Разделить матрицу на четыре блока и поменять их местами\n"\
				"3.Отсортировать элементы матрицы по возрастанию\n"\
				"4.Выполнить математическое действие над элементами матрицы\n"\
				"5.Транспонировать матрицу\n"\
				"6.Вывести матрицу обычным способом\n"\
				"0.ВЫХОД/ПЕРЕСОЗДАНИЕ МАТРИЦЫ\n\n\n";

			cout << "\nВаш выбор: ";
			cin >> choose;
			cout << "\n\n";


			switch (choose) {
			case 0: {
				goon = 0;
				break;
			}

			case 1: {

				int fillChoose;

				cout << "Как вы хотите вывести матрицу?\n 1. Змейкой \n 2. По спирали\n\n";
				cout << "\nВаш выбор: ";
				cin >> fillChoose;
				cout << "\n\n";

				switch (fillChoose) {

				default: {
					cout << "Введите число \n\n";
					break;
				}

				case 1: {
					snakeFill(arr);
					break;
				}
				case 2: {
					spiralFill(arr);
					break;
				}
				}

				  break;
			}

			case 2: {

				int mixChoose;

				cout << "Как будем менять блоки?\n 1. По часовой стрелке.\n 2. Крест-накрест \n 3. Поменять местами верхние с нижними \n 4. Поменять местами правые с левыми.\n\n ";
				cout << "\nВаш выбор: ";
				cin >> mixChoose;
				cout << "\n\n";

				switch (mixChoose) {

				default: {
					cout << "Введите число\n\n";
				}
				case 1: {
					spiralMix(arr);
					printArr(arr);
					break;
				}

				case 2: {
					diagonalMix(arr);
					printArr(arr);
					break;
				}

				case 3: {
					verticalMix(arr);
					printArr(arr);
					break;
				}

				case 4: {
					horizontalMix(arr);
					printArr(arr);
					break;
				}
				}

				break;
			}

			case 3: {
				cout << "Неотсортированная матрица:\n";
				printArr(arr);
				cout << "Отсортированная:";
				insertSortPtr(*arr);
				printArr(arr);
				break;
			}

			case 4: {

				int sign;
				int num;

				cout << "\n\nВведите математическую операцию (1.'+', 2.'-', 3.'*' 4.'/' )\n\n";
				cout << "\nВаш выбор: ";
				cin >> sign;
				cout << "\n\nВведите число, с которым вы хотите производить вычисления\n\n";
				cout << "\nВаш выбор: ";
				cin >> num;
				cout << "\n\n";
				printArr(arr);
				calculate(arr, sign, num);
				printArr(arr);
				break;
			}

			case 5: {
				cout << "Изначальная матрица:\n";
				printArr(arr);
				cout << "Новая матрица:\n";
				trans(arr);
				break;
			}
			case 6: {
				printArr(arr);
				break;
			}
			default: {
				cout << "Введите число!" << "\n\n";
				break;
			}
			}

		}
		cout << "Пересоздаем массив или выходим?" << '\n'
			<< "1.Выходим(" << '\n'
			<< "2.Пересоздать массив)" << '\n';
		cin >> ask;
		if (ask == 1) {
			cout << "Пака";
			gooon = 0;
			break;
		}
		else{
			system("cls");
		}
	}

	return 0;
}

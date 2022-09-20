#include "Header.h"
using namespace std;
int main()
{
	int* vect=NULL;
	int** b=NULL;
	int n, s;
	int s_vect, s_mat;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int k;
	bool flag = true;
	bool flag1 = false, flag2 = false, flag3 = false;;
	do {
		cout << "------------------------------------------------------" << endl;
		cout<<"1-ввод входных данных\n2-создание матрицы и вектора\n3-ввод элемент с клавиатуры\n";
		cout << "4-ввод элементов рандомно\n5-выполнение задания\n6-посмотреть вектор и матрицу\n";
		cout << "7-удалить матрицу и вектор\n8-конец\n";
		cout << "------------------------------------------------------" << endl;
		cin >> k;
		if (cin.fail()) {
			cout << "Неверные входные данные\n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		else flag = false;
		switch (k) {
		case 1: 
			if (!flag1) {
				input_data(n, s);
				flag1 = true;
			}
			else
				cout << "Вы уже ввели размеры удалите их\n";
			break;
		case 2:
			if (flag1&&!flag2)
			{
				create_vect(vect, n);
				create_mat(b, n);
				flag2 = true;
			}
			else {
				if (!flag1)
				cout << "Вы еще не ввели размеры вектора и матрицы!\n";
				if (flag2)
					cout << "Вы уже создали матрицу удалите ее";
			}
			
			break;
		case 3:
			if (flag1 && flag2) {
				add_simb(vect, b, n);
				flag3 = true;
			}
			else {
				if (!flag1)
					cout << "Вы еще не ввели размеры вектора и матрицы!\n";
				if (!flag2)
					cout << "Вы еще не создали матрицу и вектор!\n";
			}
			
			break;
		case 4:
			if (flag1 && flag2) {
				input_rand(vect, b, n);
				flag3 = true;
			}
			else {
				if (!flag1)
					cout << "Вы еще не ввели размеры вектора и матрицы!\n";
				if (!flag2)
					cout << "Вы еще не создали матрицу и вектор!\n";
			}
			
			break;
		case 5:
			if (flag1 && flag2 && flag3) {
				s_vect = sum_vect(vect, n);
				s_mat = sum_mat(b, n, s);
				task(s_mat, s_vect, vect, n);
			}
			else {
				if (!flag1)
					cout << "Вы еще не ввели размеры вектора и матрицы!\n";
				if (!flag2)
					cout << "Вы еще не создали матрицу и вектор!\n";
				if (!flag3)
					cout << "Вы еще не ввели элементы матрицы и вектора\n";
			}
			break;
		case 6:
			if (flag1 && flag2 && flag3) {
				show(vect, b, n);
			}
			else {
				if (!flag1)
					cout << "Вы еще не ввели размеры вектора и матрицы!\n";
				if (!flag2)
					cout << "Вы еще не создали матрицу и вектор!\n";
				if (!flag3)
					cout << "Вы еще не ввели элементы матрицы и вектора\n";
			}
			break;
		case 7:
			if (flag1 && flag2) {
				delete_v_and_m(b, vect, n);
				flag1 = false; flag2 = false;
			}
			else {
				if (!flag1)
					cout << "Вы еще не ввели размеры вектора и матрицы!\n";
				if (!flag2)
					cout << "Вы еще не создали матрицу и вектор!\n";
			}
			break;
		case 8: break;
		default:
			cout << "Нет такой команды\n";
			break;
		}
	} while (k!=8);
	if(flag1&&flag2)
		delete_v_and_m(b, vect, n);
}


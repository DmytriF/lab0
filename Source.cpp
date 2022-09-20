#include "Header.h"
void input_data(int& n, int& s) {
	bool flag;
	flag = true;
	do {
		cout << "Введите входные данные:";
		cin>>n;
		if (cin.fail() || n<=1) {
			cout << "Неверные входные данные\n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		else flag = false;
	} while (flag);
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Введите(s) количество элементов от 1 до " << n * n<<"\n";
	flag = true;
	do {
		cout << "Введите входные данные(s):";
		cin >> s;
		if (cin.fail() || s > (n * n) || s <=1 ) {
			cout << "Неверные входные данные\n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		else flag = false;
	} while (flag);
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	return ;
}
void create_vect(int*& vect,int n) {
	vect = new int[n];
	return;
}
void create_mat(int**& mas, int n) {
	int i;
	mas = new int* [n];
	for (i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	return;
}
int sum_vect(int* vect, int n) {
	int i;
	int s;
	s = 0;
	for (i = 0; i < n; i++)
		s += vect[i];
	return s;
}
int sum_mat(int** b, int n, int s) {
	int i, j;
	i = 0;
	j = 0;
	int c = 0;
	int summa = 0;
	while (c <= s) {
		j = 0;
		while (j < n && c <= s) {
			summa += b[i][j];
			j++;
			c++;
		}
		i++;
	}
	return summa;
}
void  task(int summa, int s, int* &vect, int n) {
	int i;
	if (s < summa) {
		for (i = 0; i < n; i++)
			vect[i] += s;
	}
	else
		for (i = 0; i < n; i++)
			vect[i] -= s;
	return;
}
void delete_v_and_m(int**& b, int*& vect, int n) {
	delete[]vect;
	int j;
	for (j = 0; j < n; j++) {
		delete[] b[j];
	}
	delete[]b;
	return ;

}
void input_rand(int * &vect, int** &mas, int n) {
	for (int i = 0; i < n; i++)
		vect[i] = rand();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mas[i][j] = rand();
	return;
}
void add_simb(int*& vect, int**& mas, int n) {
	int i;
	bool flag;
	cout << "Введите элементы вектора:\n";
	for (i = 0; i < n; i++)
	{
		flag = true;
		do {
			cout  << i+1 <<"):";
			cin >> vect[i];
			if (cin.fail()) {
				cout << "Неверные входные данные\n";
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			}
			else flag = false;
		} while (flag);
	}
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Введите элементы матрцы:\n";
	for (i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			flag = true;
			do {
				cout <<i+1 << ","<<j+1 << "):";
				cin >> mas[i][j];
				if (cin.fail()) {
					cout << "Неверные входные данные\n";
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				else flag = false;
			} while (flag);
		}
	return;
}

void show(int* vect, int** mas, int n) {
	cout << "vector:(";
	for (int i = 0; i < n - 1; i++)
		cout << vect[i] << ",";
	cout << vect[n-1] << ")\n";
	cout << "matrix:";
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n - 1; j++) {
			cout << setw(4) << mas[i][j] << " |";
		}
		cout <<setw(4) << mas[i][n - 1] << " |\n";
		cout.width(8);
	}
}

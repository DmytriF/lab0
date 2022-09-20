#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
void input_data(int &n,int &s);
void create_vect(int * &vect,int n);
void create_mat(int**& mas, int n);
int sum_vect(int *vect, int n);
int sum_mat(int** mas, int n, int s); 
void task(int sum,int s, int * &vect, int n);
void delete_v_and_m(int ** &mas, int * &vect, int n);
void input_rand(int*& vect, int**& mas, int n);
void add_simb(int*& vect, int**& mas, int n);
void show(int* vect, int** mas, int n);
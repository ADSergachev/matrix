//
// Created by Сергачев Андрей on 22.06.2018.
//

#include "Matrix.h"
#include <iostream>

using namespace std;
// Функция вывода матрицы
void Matrix::PrintMatr(int **mas, int m) {
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<m; j++)  {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}
// Получение матрицы без i-й строки и j-го столбца
void Matrix::GetMatr(int **mas, int **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}
// Рекурсивное вычисление определителя
int Matrix::Determinant(int **mas, int m) {
    int i, j, d, k, n;
    int **p;
    p = new int*[m];
    for (i = 0; i<m; i++)
        p[i] = new int[m];
    j = 0; d = 0;
    k = 1; //(-1) в степени i
    n = m - 1;
    if (m == 1) {
        d = mas[0][0];
        return(d);
    }
    if (m == 2) {
        d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
        return(d);
    }
    if (m>2) {
        for (i = 0; i<m; i++) {
            GetMatr(mas, p, i, 0, m);
            cout << mas[i][j] << endl;
            PrintMatr(p, n);
            d = d + k * mas[i][0] * Determinant(p, n);
            k = -k;
        }
    }
    return(d);
}

void Matrix::checkDimension(int N) {
    if (N < 0){
        throw invalid_argument("Invalid input, the dimension of the matrix is less than 0");
    }
    if (N == 0) {
        throw invalid_argument("Invalid input, the dimension of the matrix is 0");

    }
}
 int Matrix::result() {
    int m,  d;
    int **mas;
    cin >> m;
    //обработка исключения
    try{
        checkDimension(m);
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        return -1;
    }

    mas = new int*[m];
    for (int i = 0; i<m; i++) {
        mas[i] = new int[m];
        for (int j = 0; j<m; j++) {
            cin >> mas[i][j];
        }
    }
    PrintMatr(mas, m);
    d = Determinant(mas, m);
    cout << "Определитель матрицы равен " << d;
    cin.get(); cin.get();
     return 0;
}

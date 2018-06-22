//
// Created by Сергачев Андрей on 22.06.2018.
//

#ifndef LAB8_MATRIX_H
#define LAB8_MATRIX_H


class Matrix {
public:
    int mainFunc();

private:
    int Determinant(int **mas, int m);
    void checkDimension(int N);
    void GetMatr(int **mas, int **p, int i, int j, int m);
    int result();
};


#endif //LAB8_MATRIX_H

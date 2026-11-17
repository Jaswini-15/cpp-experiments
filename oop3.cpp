#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];

        return result;
    }

    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }

        return result;
    }

    int *operator[](int index)
    {
        return data[index];
    }

    friend ostream &operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";

            out << endl;
        }

        return out;
    }
};

int main()
{
    int a, b, c, d;
    int e, f, g, h;

    cout << "Enter Matrix A (4 values): ";
    cin >> a >> b >> c >> d;

    cout << "Enter Matrix B (4 values): ";
    cin >> e >> f >> g >> h;

    Matrix A(a, b, c, d);
    Matrix B(e, f, g, h);

    Matrix sum = A + B;
    Matrix product = A * B;

    cout << "\nMatrix A:\n";
    cout << A;

    cout << "\nMatrix B:\n";
    cout << B;

    cout << "\nAddition of Matrices:\n";
    cout << sum;

    cout << "\nMultiplication of Matrices:\n";
    cout << product;

    return 0;
}
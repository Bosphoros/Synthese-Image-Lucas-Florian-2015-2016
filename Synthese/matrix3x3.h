#ifndef MATRIX3X3_H
#define MATRIX3X3_H


class Matrix3x3
{
private:
    int values[9];
public:
    Matrix3x3();
    Matrix3x3(int values[]) : values(values) {}

    inline void fill(int value);

    inline const Matrix3x3 operator+(const Matrix3x3& m1, const Matrix3x3& m2);
    inline const Matrix3x3 operator-(const Matrix3x3& m1, const Matrix3x3& m2);
    inline const Matrix3x3 operator/(const Matrix3x3& m1, const Matrix3x3& m2);
    inline const Matrix3x3 operator*(const Matrix3x3& m1, const Matrix3x3& m2);
};

inline void fill(int value)
{
    for (int i = 0; i < 9; i++)
    {
        values[i] = value;
    }
}

inline const Matrix3x3 operator+(const Matrix3x3& m1, const Matrix3x3& m2)
{

}

#endif // MATRIX3X3_H

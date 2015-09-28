#ifndef MATRIX3X3_H
#define MATRIX3X3_H
#include "vector3d.h"

class Matrix3x3
{
private:
    int values[9];
public:
    Matrix3x3();
    Matrix3x3(int values[]);

    inline void fill(int value);

    friend inline const Matrix3x3 operator+(const Matrix3x3& m1, const Matrix3x3& m2);
    friend inline const Matrix3x3 operator-(const Matrix3x3& m1, const Matrix3x3& m2);
    friend inline const Matrix3x3 operator/(const Matrix3x3& m1, const Matrix3x3& m2);
    friend inline const Matrix3x3 operator*(const Matrix3x3& m1, const Matrix3x3& m2);
    friend inline const Matrix3x3 operator*(const Matrix3x3& m, const Vector3D& v);

    const Matrix3x3 inverse() const;
    int determinant() const;

};

inline void Matrix3x3::fill(int value)
{
    for (int i = 0; i < 9; i++)
    {
        values[i] = value;
    }
}

inline const Matrix3x3 operator+(const Matrix3x3& m1, const Matrix3x3& m2)
{
    int output[9];
    for (int i = 0; i < 9; i++)
    {
        output[i] = m1.values[i] + m2.values[i];
    }
    return Matrix3x3(output);
}

inline const Matrix3x3 operator-(const Matrix3x3& m1, const Matrix3x3& m2)
{
    int output[9];
    for (int i = 0; i < 9; i++)
    {
        output[i] = m1.values[i] - m2.values[i];
    }
    return Matrix3x3(output);
}


#endif // MATRIX3X3_H

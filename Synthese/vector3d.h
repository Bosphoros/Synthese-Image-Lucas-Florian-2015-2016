#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "vector2d.h"
#include <cmath>
#include <iostream>

class Vector2D;

class Vector3D
{
public:

    Vector3D();
    Vector3D(double xpos, double ypos, double zpos):xp(xpos), yp(ypos), zp(zpos){}
    Vector3D(const Vector2D& vector);
    Vector3D(const Vector2D& vector, float zpos);

    double x() const;
    double y() const;
    double z() const;

    void setX(double xpos);
    void setY(double ypos);
    void setZ(double zpos);

    double length() const;
    double lengthSquared() const;

    Vector3D normalized() const;
    void normalize();

    Vector3D &operator+=(const Vector3D &vector);
    Vector3D &operator-=(const Vector3D &vector);
    Vector3D &operator*=(double factor);
    Vector3D &operator/=(double divisor);
    double operator*(const Vector3D& v1) const;
    const Vector3D operator^(const Vector3D& v2)const ;

    static Vector3D normal(const Vector3D& v1, const Vector3D& v2);
    static Vector3D normal(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3);

    double distanceToPoint(const Vector3D& point) const;
    double distanceToPointSquared(const Vector3D& point) const;
    double distanceToPlane(const Vector3D& plane, const Vector3D& normal) const;
    double distanceToPlane(const Vector3D& plane1, const Vector3D& plane2, const Vector3D& plane3) const;
    double distanceToLine(const Vector3D& point, const Vector3D& direction) const;

    friend inline bool operator==(const Vector3D &v1, const Vector3D &v2);
    friend inline bool operator!=(const Vector3D &v1, const Vector3D &v2);
    friend inline const Vector3D operator+(const Vector3D &v1, const Vector3D &v2);
    friend inline const Vector3D operator-(const Vector3D &v1, const Vector3D &v2);
    friend inline const Vector3D operator*(float factor, const Vector3D &vector);
    friend inline const Vector3D operator*(const Vector3D &vector, float factor);
    friend inline const Vector3D operator-(const Vector3D &vector);
    friend inline const Vector3D operator/(const Vector3D &vector, float divisor);

    friend inline bool fuzzyCompare(const Vector3D& v1, const Vector3D& v2);
    friend inline std::ostream& operator<<(std::ostream& out, const Vector3D& v);

private:
    double xp;
    double yp;
    double zp;
};


inline Vector3D::Vector3D() : xp(0.0), yp(0.0), zp(0.0) {}

inline double Vector3D::x() const { return xp; }
inline double Vector3D::y() const { return yp; }
inline double Vector3D::z() const { return zp; }

inline void Vector3D::setX(double aX) { xp = aX; }
inline void Vector3D::setY(double aY) { yp = aY; }
inline void Vector3D::setZ(double aZ) { zp = aZ; }

inline Vector3D &Vector3D::operator+=(const Vector3D &vector)
{
    xp += vector.xp;
    yp += vector.yp;
    zp += vector.zp;
    return *this;
}

inline Vector3D &Vector3D::operator-=(const Vector3D &vector)
{
    xp -= vector.xp;
    yp -= vector.yp;
    zp -= vector.zp;
    return *this;
}

inline Vector3D &Vector3D::operator*=(double factor)
{
    xp *= factor;
    yp *= factor;
    zp *= factor;
    return *this;
}

inline Vector3D &Vector3D::operator/=(double factor)
{
    xp /= factor;
    yp /= factor;
    zp /= factor;
    return *this;
}

inline bool operator==(const Vector3D &v1, const Vector3D &v2)
{
    return v1.xp == v2.xp && v1.yp == v2.yp && v1.zp == v2.zp;
}

inline bool operator!=(const Vector3D &v1, const Vector3D &v2)
{
    return v1.xp != v2.xp || v1.yp != v2.yp || v1.zp != v2.zp;
}

inline const Vector3D operator+(const Vector3D &v1, const Vector3D &v2)
{
    return Vector3D(v1.xp + v2.xp, v1.yp + v2.yp, v1.zp + v2.zp);
}

inline const Vector3D operator-(const Vector3D &v1, const Vector3D &v2)
{
    return Vector3D(v1.xp - v2.xp, v1.yp - v2.yp, v1.zp - v2.zp);
}

inline const Vector3D operator*(double factor, const Vector3D &vector)
{
    return Vector3D(vector.x() * factor, vector.y() * factor, vector.z() * factor);
}

inline const Vector3D operator*(const Vector3D &vector, double factor)
{
    return Vector3D(vector.x() * factor, vector.y() * factor, vector.z() * factor);
}

inline double Vector3D::operator*(const Vector3D &v1) const
{
    return xp * v1.x()+ yp * v1.y()+ zp * v1.z();
}

inline const Vector3D Vector3D::operator^(const Vector3D &v1) const
{
    return Vector3D(yp*v1.z()-zp*v1.y(),zp*v1.x()-xp*v1.z(),xp*v1.y()-yp*v1.x());
}

inline const Vector3D operator-(const Vector3D &vector)
{
    return Vector3D(-vector.xp, -vector.yp, -vector.zp);
}

inline const Vector3D operator/(const Vector3D &vector, double divisor)
{
    return Vector3D(vector.x() / divisor, vector.y() / divisor, vector.z() / divisor);
}

inline bool fuzzyCompare(const Vector3D& v1, const Vector3D& v2)
{
    return v1.distanceToPointSquared(v2)<0.0000001;
}

inline double Vector3D::length() const
{
    return sqrt(xp*xp+yp*yp+zp*zp);
}
inline double Vector3D::lengthSquared() const
{
    return xp*xp+yp*yp+zp*zp;
}

inline Vector3D Vector3D::normalized() const
{
    double invlength =1/length();

    return Vector3D(xp*invlength,yp*invlength,zp*invlength);
}
inline void Vector3D::normalize()
{
    double invlength =1/length();
    xp*=invlength;
    yp*=invlength;
    zp*=invlength;
}

inline double Vector3D::distanceToPoint(const Vector3D& point) const
{
    return (point-(*this)).length();
}

inline double Vector3D::distanceToPointSquared(const Vector3D& point) const
{
    return (point-(*this)).lengthSquared();
}

inline std::ostream& operator<<(std::ostream& out, const Vector3D& v){
    return out<<"("<<v.x()<<", "<<v.y()<<", "<<v.z()<<")";
}


#endif // VECTOR3D_H


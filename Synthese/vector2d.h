#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
#include <cmath>
#include "vector3d.h"

class Vector3D;

class Vector2D
{
private:
    double xp;
    double yp;
public:
    Vector2D();
    Vector2D(double xpos, double ypos);

    double x() const;
    double y() const;

    void setX(double x);
    void setY(double y);

    double length() const;
    double lengthSquared() const;

    Vector2D normalized() const;
    void normalize();

    double distanceToPoint(const Vector2D& point) const;
    double distanceToPointSquared(const Vector2D& point) const;
    double distanceToLine(const Vector2D& point, const Vector2D& direction) const;

    Vector2D &operator+=(const Vector2D& vector);
    Vector2D &operator-=(const Vector2D& vector);
    Vector2D &operator*=(double factor);
    Vector2D &operator/=(double divisor);

    friend inline bool operator==(const Vector2D& v1, const Vector2D& v2);
    friend inline bool operator!=(const Vector2D& v1, const Vector2D& v2);
    friend inline const Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
    friend inline const Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
    friend inline const Vector2D operator*(double factor, const Vector2D& v2);
    friend inline const Vector2D operator*(const Vector2D& v1, double factor);
    friend inline const double operator*(const Vector2D& v1, const Vector2D& v2);
    friend inline const Vector2D operator-(const Vector2D& v1);
    friend inline const Vector2D operator/(const Vector2D& v1, double divisor);

    friend inline bool fuzzyCompare(const Vector2D& v1, const Vector2D& v2);

    friend inline std::ostream& operator<<(std::ostream& os, const Vector2D& v);

    Vector3D toVector3D() const;

    friend class Vector3D;
};

inline Vector2D::Vector2D() : xp(0.0d), yp(0.0d) {}

inline Vector2D::Vector2D(double xpos, double ypos) : xp(xpos), yp(ypos) {}

inline double Vector2D::x() const {return xp;}
inline double Vector2D::y() const {return yp;}

inline void Vector2D::setX(double ax) { xp = ax; }
inline void Vector2D::setY(double ay) { yp = ay; }

inline double Vector2D::length() const {
    return sqrt(xp*xp+yp*yp);
}

inline double Vector2D::lengthSquared() const {
    return xp*xp+yp*yp;
}

double Vector2D::distanceToPoint(const Vector2D& point) const {
    return (point-(*this)).length();
}

double Vector2D::distanceToPointSquared(const Vector2D& point) const {
    return (point-(*this)).lengthSquared();
}

inline Vector2D& Vector2D::operator+=(const Vector2D& v) {
    xp += v.xp;
    yp += v.yp;
    return *this;
}

inline Vector2D& Vector2D::operator-=(const Vector2D& v) {
    xp -= v.xp;
    yp -= v.yp;
    return *this;
}

inline Vector2D& Vector2D::operator*=(double factor) {
    xp *= factor;
    yp *= factor;
    return *this;
}

inline Vector2D& Vector2D::operator/=(double divisor) {
    xp /= divisor;
    yp /= divisor;
    return *this;
}

inline bool operator==(const Vector2D& v1, const Vector2D& v2) {
    return v1.xp == v2.xp && v1.yp == v2.yp ;
}

inline bool operator!=(const Vector2D& v1, const Vector2D& v2) {
    return v1.xp != v2.xp && v1.yp != v2.yp ;
}

inline const Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.xp + v2.xp , v1.yp + v2.yp);
}

inline const Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.xp - v2.xp , v1.yp - v2.yp);
}

inline const Vector2D operator*(double factor, const Vector2D& v) {
    return Vector2D(v.xp * factor, v.yp * factor);
}

inline const Vector2D operator*(const Vector2D& v, double factor) {
    return Vector2D(v.xp * factor, v.yp * factor);
}

inline const double operator*(const Vector2D& v1, const Vector2D& v2) {
    return (v1.xp * v2.xp + v1.yp * v2.yp);
}

inline const Vector2D operator-(const Vector2D& v) {
    return Vector2D(-v.xp, -v.yp);
}

inline const Vector2D operator/(const Vector2D& v, double divisor) {
    return Vector2D(v.xp / divisor, v.yp / divisor);
}

inline bool fuzzyCompare(const Vector2D& v1, const Vector2D& v2) {
    return v1.distanceToPointSquared(v2) < 0.0000001;
}

inline std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    return os << "(" << v.xp << ", " << v.yp << ")";
}


#endif // VECTOR2D_H

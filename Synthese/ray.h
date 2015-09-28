#ifndef RAY_H
#define RAY_H
#include "vector3d.h"
#include "terrain.h"
class Ray
{
private:
    const Vector3D origine; /**< Origin of the ray*/
    const Vector3D direction; /**< Direction of the ray*/
    static double pas; /**< Step for Ray marching*/
public:
    /**
     * Constructor of Ray
     * @param[in] o The origin of the ray
     * @param[in] d The direction of the ray
     */
    Ray(const Vector3D &o, const Vector3D &d);

    /**
     * Gets the point found f times the direction from the origin
     * @param[in] f The factor of direction
     * @return origin + f * direction
     */
    Vector3D getPoint(double f) const;

    /**
     * Finds if the ray intersects the plane defined by three points
     * @param[in] a The first point on the plane
     * @param[in] b The second point on the plane
     * @param[in] c The third poitn on the plane
     * @param[out] out The intersection point
     * @return true if there is an intersection, else false
     */
    bool intersects(const Vector3D& a, const Vector3D& b, const Vector3D& c, Vector3D& out);

    /**
     * Finds the intersection points of the Ray with an Axis Aligned Box, defined by a and b.
     * @param[in] a The bottom front left corner of the box
     * @param[in] b The upper back right corner of the box
     * @param[out] in The entry point of the ray in the box
     * @param[out] out The out point of the ray out of the box
     * @return The number of intersections found. If 0, in and out can't be trusted.
     */
    int intersectsBox(const Vector3D& a, const Vector3D& b, Vector3D& in, Vector3D& out);
    bool intersectRayMarching(Terrain &t, const Vector3D &aBox, const Vector3D &bBox, Vector3D &resu, bool &isBox);
    bool intersectAdvanced(Terrain &t, Vector2D &a, Vector2D &b, Vector3D &resu);

    inline const Vector3D& getOrigine() const;
    inline const Vector3D& getDirection() const;
};

inline const Vector3D& Ray::getOrigine() const {
    return origine;
}

inline const Vector3D& Ray::getDirection() const {
    return direction;
}

#endif // RAY_H

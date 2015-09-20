#ifndef TERRAINIMAGE_H
#define TERRAINIMAGE_H

#include "terrain.h"
#include <QImage>
/**
 * @brief The TerrainImage class, a Terrain defined by an image
 */
class TerrainImage : public Terrain
{
private:
    std::vector<quint8> mat; /**< A vector containing the values read in the image*/
    int w; /**< The width of the base image */
    int h; /**< The height of the base image */
    double blanc; /**< The height value associated with white */
    double noir; /**< The height value associated with black */

public:
    /**
     * Constructor of TerrainImage
     * @param i The image to read the grey value from
     * @param bl The height value to associate with white
     * @param no The height value to associate with black
     * @param a the first point of definition of the TerrainImage on the plan
     * @param b the second point of definition of the TerrainImage on the plan
     */
    TerrainImage(const QImage &i, double bl, double no, const Vector2D& a, const Vector2D& b);

    /**
     * @brief Gets the height associated to 2D coordinates
     * @param p the coordinates to find the corresponding height
     * @return the height at p
     */
    virtual double getHauteur(const Vector2D &p) const;

    /**
     * Finds the minimal height of the Terrain
     * @return the minimal height of the Terrain
     */
    virtual double getHauteurMin() const;

    /**
     * Finds the maximal height of the Terrain
     * @return the maximal height of the Terrain
     */
    virtual double getHauteurMax() const;

    /**
     * Finds the greatest difference of height between two points
     * @return the greatest difference of height between two points
     */
    virtual double getPenteMax() const;
};

inline double TerrainImage::getHauteurMax() const
{
    return blanc>noir?blanc:noir;
}

inline double TerrainImage::getHauteurMin() const
{
    return blanc<noir?blanc:noir;
}

#endif // TERRAINIMAGE_H

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
class Circle : public Shape
{
    // TODO:
private:
    int r,x,y;
public:
    Circle(int x, int y, int r):r(r),x(x),y(y){}
    ~Circle(){};

    bool isIn(int x, int y) const override;

    inline int getRadius() const{ return this->r; }
    inline int getX() const{ return this->x; }
    inline int getY() const{ return this->y; }
};
} // namespace Shapes

#endif // CIRCLE_H

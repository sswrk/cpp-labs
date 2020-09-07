#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
    // TODO:
private:
    int x_start, x_end, y_start, y_end;
public:
    Rectangle(int x_start, int y_start, int x_end, int y_end):x_start(x_start),x_end(x_end),y_start(y_start),y_end(y_end){}
    ~Rectangle(){};
    bool isIn(int x, int y) const override;
    int getX() const{ return this->x_start; }
    int getY() const{ return this->y_start; }
    int getXTo() const{ return this->x_end; }
    int getYTo() const{ return this->y_end; }
};
} // namespace Shapes

#endif // RECTANGLE_H

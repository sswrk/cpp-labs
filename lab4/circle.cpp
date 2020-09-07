#include "circle.h"

namespace Shapes{
    bool Circle::isIn(int x, int y) const {
        int x_distance = this->x-x;
        if(x_distance<0) x_distance*=(-1);
        int y_distance = this->y-y;
        if(y_distance<0) y_distance*=(-1);
        if(x_distance*x_distance+y_distance*y_distance>r*r) return false;
        return true;
    }
}

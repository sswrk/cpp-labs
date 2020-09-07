#include "rectangle.h"

namespace Shapes{

    bool Rectangle::isIn(int x, int y) const {
        if(x<this->x_start || x>this->x_end || y<this->y_start || y>this->y_end) return false;
        return true;
    }
}

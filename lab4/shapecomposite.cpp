#include "shapecomposite.h"

namespace Shapes{
    ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation)
    :shape1(shape1), shape2(shape2), operation(operation){}

    bool ShapeComposite::isIn(int x, int y) const {
        switch(this->operation){
            case ShapeOperation::INTERSECTION:
                return (this->shape1->isIn(x, y) && this->shape2->isIn(x, y));
            case ShapeOperation::DIFFERENCE:
                return (this->shape1->isIn(x, y) && !this->shape2->isIn(x, y));
            case ShapeOperation::SUM:
                return (this->shape1->isIn(x, y) || this->shape2->isIn(x, y));
        }
    }

}
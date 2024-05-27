//
// Created by Michał Kępka on 20/05/2024.
//

#ifndef LAB12_CONSOLE_COMPLEX_SHAPE_H
#define LAB12_CONSOLE_COMPLEX_SHAPE_H


#include "shape.h"
#include "operation.h"

namespace CSG2D {
    class ComplexShape: public Shape {
    private:
        std::shared_ptr<Shape> shape1_;
        std::shared_ptr<Shape> shape2_;
        OPERATION operation_;
    public:
        ComplexShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, OPERATION operation);
        [[nodiscard]] bool isIn(const sf::Vector2f& test_position) const override;
    };
}

#endif //LAB12_CONSOLE_COMPLEX_SHAPE_H

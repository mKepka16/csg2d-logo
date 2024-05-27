//
// Created by Michał Kępka on 20/05/2024.
//

#ifndef LAB12_CONSOLE_CIRCLE_H
#define LAB12_CONSOLE_CIRCLE_H

#include "shape.h"

namespace CSG2D {
    class Circle: public CSG2D::Shape {
    private:
        float radius;
    public:
        Circle(float r, const sf::Vector2f &pos);
        [[nodiscard]] bool isIn(const sf::Vector2f& test_position) const override;
    };
}

#endif //LAB12_CONSOLE_CIRCLE_H

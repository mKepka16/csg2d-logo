//
// Created by Michał Kępka on 20/05/2024.
//

#ifndef LAB12_CONSOLE_RECTANGLE_H
#define LAB12_CONSOLE_RECTANGLE_H

#include "shape.h"
#include "libincludes.h"

namespace CSG2D {
    class Rectangle: public Shape {

    private:
        float width, height;
    public:
        Rectangle(float w, float h, const sf::Vector2f &pos, float angl);
        [[nodiscard]] bool isIn(const sf::Vector2f &test_position) const override;
    };
}


#endif //LAB12_CONSOLE_RECTANGLE_H

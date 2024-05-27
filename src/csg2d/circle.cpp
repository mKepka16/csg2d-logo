//
// Created by Michał Kępka on 20/05/2024.
//

#include "circle.h"
#include "cmath"

namespace CSG2D {
    Circle::Circle(float r, const sf::Vector2f &pos) : CSG2D::Shape(pos, 0), radius(r)
    {
    }

    bool Circle::isIn(const sf::Vector2f &test_position) const
    {
        float distanceSquare = pow((position_.x - test_position.x), 2) + pow((position_.y - test_position.y), 2);
        return distanceSquare <= pow(radius, 2);
    }
}

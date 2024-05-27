//
// Created by Michał Kępka on 20/05/2024.
//

#include "rectangle.h"
#include "functions.h"
#include "cmath"

namespace CSG2D {
//     Rectangle::Rectangle(float w, float h, const sf::Ve &pos, float angl): Shape(pos, angl), width(w), height(h) {}

//     bool Rectangle::isIn(const Vector2D &test_position) const {
//         auto diffVector = test_position - position_;
//         auto newPoint = rotate(diffVector, -angle_rad_);
// //        return newPoint.x() >= position_.x() - width/2 && newPoint <= position_.x() + width/2 && newPoint >= position_.y() - height/2 && newPoint <= position_.y() + height/2;
//         return abs(newPoint.x()) <= width/2 && abs(newPoint.y()) <= height/2;
//     }
    Rectangle::Rectangle(float w, float h, const sf::Vector2f &pos, float angl) : Shape(pos, angl), width(w), height(h)
    {
    }
    bool Rectangle::isIn(const sf::Vector2f &test_position) const
    {
        auto diffVector = test_position - position_;
        auto newPoint = rotate(diffVector, -angle_rad_);
        return abs(newPoint.x) <= width/2 && abs(newPoint.y) <= height/2;

      return false;
    }
}

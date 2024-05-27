//
// Created by Michał Kępka on 20/05/2024.
//

#include "complex_shape.h"
#include "iostream"

CSG2D::ComplexShape::ComplexShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                                  CSG2D::OPERATION operation): Shape(sf::Vector2f(0, 0), 0), shape1_(shape1), shape2_(shape2), operation_(operation) {

}

bool CSG2D::ComplexShape::isIn(const sf::Vector2f &test_position) const {
    if (operation_ == OPERATION::UNION)
    {
        return shape1_->isIn(test_position) || shape2_->isIn(test_position);
    }
    if (operation_ == OPERATION::DIFFERENCE) {
        return shape1_->isIn(test_position) && !shape2_->isIn(test_position);
    }
    if (operation_ == OPERATION::INTERSECTION) {
        return shape1_->isIn(test_position) && shape2_->isIn(test_position);
    }
    return false;
}


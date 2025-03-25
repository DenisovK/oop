// src/Rectangle.cpp
#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle() : vertices(4) {}

Rectangle::Rectangle(const std::vector<std::pair<double, double>>& vertices) : vertices(vertices) {}

double Rectangle::area() const {
    double width = std::abs(vertices[1].first - vertices[0].first);
    double height = std::abs(vertices[2].second - vertices[1].second);
    return width * height;
}

std::pair<double, double> Rectangle::center() const {
    double x = (vertices[0].first + vertices[1].first + vertices[2].first + vertices[3].first) / 4;
    double y = (vertices[0].second + vertices[1].second + vertices[2].second + vertices[3].second) / 4;
    return {x, y};
}

void Rectangle::print(std::ostream& os) const {
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Rectangle::read(std::istream& is) {
    for (auto& vertex : vertices) {
        is >> vertex.first >> vertex.second;
    }
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    return vertices == other.vertices;
}
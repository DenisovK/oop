// src/Trapezoid.cpp
#include "Trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid() : vertices(4) {}

Trapezoid::Trapezoid(const std::vector<std::pair<double, double>>& vertices) : vertices(vertices) {}

double Trapezoid::area() const {
    double a = std::abs(vertices[1].first - vertices[0].first);
    double b = std::abs(vertices[2].first - vertices[3].first);
    double height = std::abs(vertices[2].second - vertices[1].second);
    return (a + b) * height / 2;
}

std::pair<double, double> Trapezoid::center() const {
    double x = (vertices[0].first + vertices[1].first + vertices[2].first + vertices[3].first) / 4;
    double y = (vertices[0].second + vertices[1].second + vertices[2].second + vertices[3].second) / 4;
    return {x, y};
}

void Trapezoid::print(std::ostream& os) const {
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (auto& vertex : vertices) {
        is >> vertex.first >> vertex.second;
    }
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return vertices == other.vertices;
}
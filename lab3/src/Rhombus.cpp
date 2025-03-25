// src/Rhombus.cpp
#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus() : vertices(4) {}

Rhombus::Rhombus(const std::vector<std::pair<double, double>>& vertices) : vertices(vertices) {}

double Rhombus::area() const {
    double d1 = std::sqrt(std::pow(vertices[1].first - vertices[3].first, 2) + std::pow(vertices[1].second - vertices[3].second, 2));
    double d2 = std::sqrt(std::pow(vertices[0].first - vertices[2].first, 2) + std::pow(vertices[0].second - vertices[2].second, 2));
    return (d1 * d2) / 2;
}

std::pair<double, double> Rhombus::center() const {
    double x = (vertices[0].first + vertices[1].first + vertices[2].first + vertices[3].first) / 4;
    double y = (vertices[0].second + vertices[1].second + vertices[2].second + vertices[3].second) / 4;
    return {x, y};
}

void Rhombus::print(std::ostream& os) const {
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Rhombus::read(std::istream& is) {
    for (auto& vertex : vertices) {
        is >> vertex.first >> vertex.second;
    }
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    return vertices == other.vertices;
}
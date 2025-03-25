// src/main.cpp
#include <iostream>
#include <vector>
#include <memory>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Rhombus.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    std::cout << "Enter number of figures: ";
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter figure type (1 - Rectangle, 2 - Trapezoid, 3 - Rhombus): ";
        int type;
        std::cin >> type;

        std::unique_ptr<Figure> figure;
        if (type == 1) {
            figure = std::make_unique<Rectangle>();
        } else if (type == 2) {
            figure = std::make_unique<Trapezoid>();
        } else if (type == 3) {
            figure = std::make_unique<Rhombus>();
        } else {
            std::cerr << "Invalid figure type!" << std::endl;
            continue;
        }

        std::cin >> *figure;
        figures.push_back(std::move(figure));
    }

    for (const auto& figure : figures) {
        std::cout << "Area: " << static_cast<double>(*figure) << ", Center: (" << figure->center().first << ", " << figure->center().second << ")" << std::endl;
    }

    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}
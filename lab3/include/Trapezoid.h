// include/Trapezoid.h
#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <vector>

class Trapezoid : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Trapezoid();
    Trapezoid(const std::vector<std::pair<double, double>>& vertices);
    double area() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Trapezoid& operator=(const Trapezoid& other);
    bool operator==(const Trapezoid& other) const;
};

#endif // TRAPEZOID_H
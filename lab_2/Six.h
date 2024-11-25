#ifndef SIX_H
#define SIX_H

#include "Array.h"
#include <iostream>

class Six : public Array {
public:
    Six();
    Six(const size_t & n, unsigned char t = 0);
    Six(const std::initializer_list<unsigned char> &t);
    Six(const std::string &t);
    Six(const Six& other);
    Six(Six&& other) noexcept;

    Six& operator=(const Six& other);
    Six& operator=(Six&& other) noexcept;

    Six operator+(const Six& other) const;
    Six operator-(const Six& other) const;

    bool operator>(const Six& other) const;
    bool operator<(const Six& other) const;
    bool operator==(const Six& other) const;

    void print() const;
};

#endif 

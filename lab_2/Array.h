#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <string>
#include <stdexcept>

class Array {
public:
    Array();
    Array(const size_t & n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char> &t);
    Array(const std::string &t);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

    size_t size() const;
    unsigned char& operator[](size_t index);
    const unsigned char& operator[](size_t index) const;

protected:
    size_t m_size;
    unsigned char* m_data;
};

#endif // ARRAY_H

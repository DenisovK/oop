#include "Array.h"

Array::Array() : m_size(0), m_data(nullptr) {}

Array::Array(const size_t & n, unsigned char t) : m_size(n) {
    if (n == 0) {
        m_data = nullptr;
    } else {
        m_data = new unsigned char[n];
        std::fill(m_data, m_data + n, t);
    }
}

Array::Array(const std::initializer_list<unsigned char> &t) : m_size(t.size()) {
    m_data = new unsigned char[m_size];
    std::copy(t.begin(), t.end(), m_data);
}

Array::Array(const std::string &t) : m_size(t.size()) {
    m_data = new unsigned char[m_size];
    for (size_t i = 0; i < m_size; ++i) {
        if (t[i] < '0' || t[i] > '5') {
            throw std::invalid_argument("Invalid character for base-6 number");
        }
        m_data[i] = t[i] - '0';
    }
}

Array::Array(const Array& other) : m_size(other.m_size) {
    m_data = new unsigned char[m_size];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

Array::Array(Array&& other) noexcept : m_size(other.m_size), m_data(other.m_data) {
    other.m_data = nullptr;
    other.m_size = 0;
}

Array::~Array() noexcept {
    delete[] m_data;
}

size_t Array::size() const {
    return m_size;
}

unsigned char& Array::operator[](size_t index) {
    if (index >= m_size) throw std::out_of_range("Index out of range");
    return m_data[index];
}

const unsigned char& Array::operator[](size_t index) const {
    if (index >= m_size) throw std::out_of_range("Index out of range");
    return m_data[index];
}

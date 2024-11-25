#include "Six.h"

Six::Six() : Array() {}

Six::Six(const size_t & n, unsigned char t) : Array(n, t) {}

Six::Six(const std::initializer_list<unsigned char> &t) : Array(t) {}

Six::Six(const std::string &t) : Array(t) {}

Six::Six(const Six& other) : Array(other) {}

Six::Six(Six&& other) noexcept : Array(std::move(other)) {}

Six& Six::operator=(const Six& other) {
    if (this != &other) {
        Array::operator=(other);
    }
    return *this;
}

Six& Six::operator=(Six&& other) noexcept {
    if (this != &other) {
        Array::operator=(std::move(other));
    }
    return *this;
}

Six Six::operator+(const Six& other) const {
    // Сложение шестиричных чисел
    size_t maxSize = std::max(this->size(), other.size());
    Six result(maxSize + 1); // +1 для возможного переноса
    unsigned char carry = 0;

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < this->size()) ? this->operator[](i) : 0;
        unsigned char digit2 = (i < other.size()) ? other.operator[](i) : 0;
        unsigned char sum = digit1 + digit2 + carry;
        result[i] = sum % 6; // Остаток от деления на 6
        carry = sum / 6; // Перенос
    }

    if (carry > 0) {
        result[maxSize] = carry; // Записываем последний перенос, если он есть
    } else {
        result = result.slice(0, maxSize); // Убираем последний элемент, если он равен 0
    }

    return result;
}

Six Six::operator-(const Six& other) const {
    // Вычитание шестиричных чисел
    // Предполагается, что this >= other
    size_t maxSize = std::max(this->size(), other.size());
    Six result(maxSize);
    
    unsigned char borrow = 0;

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < this->size()) ? this->operator[](i) : 0;
        unsigned char digit2 = (i < other.size()) ? other.operator[](i) : 0;

        if (digit1 < digit2 + borrow) {
            digit1 += 6; // Заимствуем из следующей цифры
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[i] = digit1 - digit2 - borrow;
    }

    // Удаление ведущих нулей, если они есть
    while (result.size() > 1 && result[result.size() - 1] == 0) {
        result = result.slice(0, result.size() - 1);
    }

    return result;
}

bool Six::operator>(const Six& other) const {
    if (this->size() != other.size()) {
        return this->size() > other.size();
    }
    
    for (size_t i = this->size(); i-- > 0;) {
        if (this->operator[](i) != other.operator[](i)) {
            return this->operator[](i) > other.operator[](i);
        }
    }
    
    return false;
}

bool Six::operator<(const Six& other) const {
    return !(*this >= other);
}

bool Six::operator==(const Six& other) const {
    if (this->size() != other.size()) return false;

    for (size_t i = 0; i < this->size(); ++i) {
        if (this->operator[](i) != other.operator[](i)) return false;
    }
    
    return true;
}

void Six::print() const {
    for (size_t i = 0; i < this->size(); ++i) {
        std::cout << static_cast<int>(this->operator[](i));
    }
}

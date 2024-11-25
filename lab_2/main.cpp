#include "Six.h"

int main() {
    try {
        Six num1("123");
        Six num2("45");

        num1.print();
        num2.print();

        Six sum = num1 + num2;
        sum.print();

        Six diff = num1 - num2;
        diff.print();

        std::cout << (num1 > num2 ? "num1 больше" : "num2 больше") << std::endl;
        
        if (num1 == num2)
            std::cout << "Числа равны" << std::endl;

        return 0;
        
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}

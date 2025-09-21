#include "calculator.h"
#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char* argv[]) {
    std::string operation;
    double operand;
    bool useDegrees;
    
    // Парсим аргументы командной строки
    if (!parseArguments(argc, argv, operation, operand, useDegrees)) {
        return 1;
    }
    
    double result = 0.0;
    
    // Выполняем операцию
    if (operation == "sin") {
        result = calculateSin(operand, useDegrees);
    }
    else if (operation == "cos") {
        result = calculateCos(operand, useDegrees);
    }
    else {
        std::cerr << "Ошибка: неизвестная операция: " << operation << std::endl;
        std::cerr << "Доступные операции: sin, cos" << std::endl;
        return 1;
    }
    
    // Выводим результат
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Результат: ";
    
    if (operation == "sin") {
        std::cout << "sin(";
    } else {
        std::cout << "cos(";
    }
    
    std::cout << operand;
    
    if (useDegrees) {
        std::cout << "°)";
    } else {
        std::cout << " rad)";
    }
    
    std::cout << " = " << result << std::endl;
    
    return 0;
}

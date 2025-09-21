#include "calculator.h"
#include <iostream>
#include <string>
#include <cstdlib>

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

double radiansToDegrees(double radians) {
    return radians * 180.0 / PI;
}

double calculateSin(double value, bool useDegrees) {
    if (useDegrees) {
        value = degreesToRadians(value);
    }
    return sin(value);
}

double calculateCos(double value, bool useDegrees) {
    if (useDegrees) {
        value = degreesToRadians(value);
    }
    return cos(value);
}

void printHelp() {
    std::cout << "Тригонометрический калькулятор\n";
    std::cout << "Использование:\n";
    std::cout << "  calculator -o OPERATION [--degrees] ОПЕРАНД\n";
    std::cout << "  calculator --operation OPERATION [--degrees] ОПЕРАНД\n\n";
    std::cout << "Операции:\n";
    std::cout << "  sin  - вычисление синуса\n";
    std::cout << "  cos  - вычисление косинуса\n\n";
    std::cout << "Опции:\n";
    std::cout << "  -o, --operation  задает операцию (обязательный параметр)\n";
    std::cout << "  --degrees        использовать градусы вместо радиан\n";
    std::cout << "  -h, --help       показать справку\n\n";
    std::cout << "Примеры:\n";
    std::cout << "  calculator -o sin 45 --degrees\n";
    std::cout << "  calculator --operation cos 3.14159\n";
}

bool parseArguments(int argc, char* argv[], 
                   std::string& operation, 
                   double& operand, 
                   bool& useDegrees) {
    
    useDegrees = false;
    operation = "";
    operand = 0.0;
    
    if (argc == 1) {
        printHelp();
        return false;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printHelp();
            return false;
        }
        else if (arg == "--degrees") {
            useDegrees = true;
        }
        else if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
            } else {
                std::cerr << "Ошибка: не указана операция после " << arg << std::endl;
                return false;
            }
        }
        else {
            // Пытаемся распарсить операнд
            try {
                operand = std::stod(arg);
            } catch (...) {
                std::cerr << "Ошибка: неверный формат операнда: " << arg << std::endl;
                return false;
            }
        }
    }
    
    if (operation.empty()) {
        std::cerr << "Ошибка: не указана операция" << std::endl;
        return false;
    }
    
    return true;
}

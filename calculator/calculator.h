#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <cmath>

const double PI = 3.14159265358979323846;

// Функция для преобразования градусов в радианы
double degreesToRadians(double degrees);

// Функция для преобразования радианов в градусы
double radiansToDegrees(double radians);

// Функция вычисления синуса (градусы или радианы)
double calculateSin(double value, bool useDegrees);

// Функция вычисления косинуса (градусы или радианы)
double calculateCos(double value, bool useDegrees);

// Функция для вывода справки
void printHelp();

// Функция для парсинга аргументов командной строки
bool parseArguments(int argc, char* argv[], 
                   std::string& operation, 
                   double& operand, 
                   bool& useDegrees);

#endif //CALCULATOR_H

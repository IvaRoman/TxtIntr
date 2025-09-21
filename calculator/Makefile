#Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
#Имя исполняемого файла
TARGET = calculator
#исходные файлы
SRCS = main.cpp calculator.cpp
OBJS = $(SRCS:.cpp=.o)
#Правило по умолчанию
all: $(TARGET)
#Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
#Компилятор .cpp файлов в .o файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#Очистка
clean:
	rm -f $(OBJS) $(TARGET)
#Пересборка
rebuild: clean all

.PHONY: all clean rebuild

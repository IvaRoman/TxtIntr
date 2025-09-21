# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

# Имя исполняемого файла
TARGET = calculator

# Исходные файлы
SRCS = main.cpp calculator.cpp
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Компиляция .cpp файлов в .o файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)

# Пересборка
rebuild: clean all

# Установка (если нужно)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

.PHONY: all clean rebuild install

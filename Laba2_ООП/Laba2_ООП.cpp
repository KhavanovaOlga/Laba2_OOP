// Laba2_ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>

using namespace std;

class Point {
protected:
    int x, y;
public:

    Point() {
        printf("'Пустая точка'");
        x = 0;
        y = 0;
        printf("(%d;%d)\n", x, y);
        printf("Конструктор по умолчанию класса Point запустился\n");
    }

    Point(int x, int y) {
        printf("'Точка с координатами");
        this->x = x;
        this->y = y;
        printf("Конструктор с параметрами класса Point запустился\n");
        printf("(%d;%d)\n", x, y);
    }

    Point(const Point& p) {
        printf("'Точка копия'");
        x = p.x;
        y = p.y;
        printf("Конструктор копирования класса Point запустился\n");
        printf("(%d;%d)\n", x, y);
    }

    ~Point() {
        printf("Деструктор класса Point запустился\n");
        printf("Удаление точки с координатами (%d;%d)\n", x, y);
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
        printf("Метод move класса Point запустился ");
        printf("(%d;%d)\n", x, y);
    }
    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
    printf("Метод reset класса Point запустился ");
    printf("(%d;%d)\n", x, y);
}

int main()
{
    std::cout << "Hello World!\n";
}



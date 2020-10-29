// Laba2_ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <conio.h>

using namespace std;

class Point {
public:
    int x, y;

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

class ColorPoint : public Point {
protected:
    int Color;
public:

    ColorPoint() {
        printf("'Пустая цветная точка'");
        x = 0;
        y = 0;
        Color = 0;
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    ColorPoint(int x, int y, int Color) :Point(x, y) {
        printf("'Цветная точка с координатами'");
        this->x = x;
        this->y = y;
        this->Color = Color;
        printf("Конструктор с параметрами класса СolorPoint запустился\n");
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    ColorPoint(int x, int y, int Color) :Point(x, y) {
        printf("'Цветная точка с координатами'");
        this->x = x;
        this->y = y;
        this->Color = Color;
        printf("Конструктор с параметрами класса ColorPoint запустился\n");
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    ColorPoint(const ColorPoint& c) {
        printf("'Цветная точка-копия'");
        x = c.x;
        y = c.y;
        Color = c.Color;
        printf("Конструктор копирования класса СolorPoint запустился\n");
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    ~ColorPoint() {
        printf("Деструктор класса ColorPoint запустился\n");
        printf("Удаление цветной точки с координатами (%d;%d;%d)\n", x, y, Color);
    }
};

class Line {

public:
    Point* p1;
    Point* p2;

    Line() {
        printf("'Пустая линия'\n");
        p1 = new Point;
        p2 = new Point;
        printf("Конструктор по умолчанию класса Line запустился\n");
        printf("p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
    }

    Line(int x, int y, int x2, int y2) {
        printf("'Линия с координатами'\n");
        p1 = new Point(x, y);
        p2 = new Point(x2, y2);
        printf("Конструктор с параметрами класса Line запустился\n");
    }

    Line(const Line& l) {
        printf("'Линия-копия'\n");

        p1 = new Point(*(l.p1));
        p2 = new Point(*(l.p2));
        printf("p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
    }

    ~Line() {
        printf("Удаление линии с координатами p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
        delete p1;
        delete p2;
        printf("Деструктор класса Line запустился\n");
    }
};

int main()
{
    std::cout << "Hello World!\n";
}



// Laba2_ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

using namespace std;

//Cоздание класса-предка
class Point {
public:
    int x, y; //Публичные атрибуты, можем обращаться к их св-ам

    //Конструктор по умолчанию
    Point() {
        printf("'Пустая точка'");
        x = 0;
        y = 0;
        printf("(%d;%d)\n", x, y);
        //printf("Конструктор по умолчанию класса Point запустился\n");
    }

    //Конструктор с параметрами
    Point(int x, int y) {
        printf("'Точка с координатами");
        this->x = x;
        this->y = y;
        //printf("Конструктор с параметрами класса Point запустился\n");
        printf("(%d;%d)\n", x, y);
    }

    //Конструктор копирующий, переносит все свойства из передающегося объекта
    Point(const Point& p) {
        printf("'Точка копия'");
        x = p.x;
        y = p.y;
        //printf("Конструктор копирования класса Point запустился\n");
        printf("(%d;%d)\n", x, y);
    }

    //Деструктор
    ~Point() {
        //printf("Деструктор класса Point запустился\n");
        printf("Удаление точки с координатами (%d;%d)\n", x, y);
    }

    //Метод move, изменяет координаты x и y на соответствующие значения
    void move(int dx, int dy) {
        x += dx;
        y += dy;
        printf("Метод move класса Point запустился ");
        printf("(%d;%d)\n", x, y);
    }
    void reset();
};

//Метод reset без параметров, устанавливающий значения в координаты x и y = 0
void Point::reset() {
    x = 0;
    y = 0;
    printf("Метод reset класса Point запустился ");
    printf("(%d;%d)\n", x, y);
}

//Создание класса-потомка, наследуемый от предка (класса Point)
class ColorPoint : public Point {
protected:
    int Color;
public:

    //Конструктор по умолчанию
    ColorPoint() {
        printf("'Пустая цветная точка'");
        x = 0;
        y = 0;
        Color = 0;
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    //Конструктор с параметрами СolorPoint
    //Вызываем конструктор с параметрами класса Point
    ColorPoint(int x, int y, int Color) :Point(x, y) {
        printf("'Цветная точка с координатами'");
        this->x = x;
        this->y = y;
        this->Color = Color;
        //printf("Конструктор с параметрами класса СolorPoint запустился\n");
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    //Конструктор копирующий
    ColorPoint(const ColorPoint& c) {
        printf("'Цветная точка-копия'");
        x = c.x;
        y = c.y;
        Color = c.Color;
        //printf("Конструктор копирования класса СolorPoint запустился\n");
        printf("(%d;%d;%d)\n", x, y, Color);
    }

    //Деструктор
    ~ColorPoint() {
        //printf("Деструктор класса ColorPoint запустился\n");
        printf("Удаление цветной точки с координатами (%d;%d;%d)\n", x, y, Color);
    }
};

//Пример композиции
class Line {

public:
    //указатели на первую и вторую точку отрезка
    Point* p1; 
    Point* p2;

    //Конструктор по умолчанию
    Line() {
        printf("'Пустая линия'\n");
        p1 = new Point;
        p2 = new Point;
        //printf("Конструктор по умолчанию класса Line запустился\n");
        printf("p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
    }

    //Конструктор с параметрами
    Line(int x, int y, int x2, int y2) {
        printf("'Линия с координатами'\n");
        p1 = new Point(x, y);
        p2 = new Point(x2, y2);
        //printf("Конструктор с параметрами класса Line запустился\n");
        printf("p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
    }

    //Конструктор копирования
    Line(const Line& l) {
        printf("'Линия-копия'\n");

        //Глубокое копирование: создание точных копий переданных точек с помощью вызова конструктора копирования точки
        p1 = new Point(*(l.p1)); //l-объект, p1-указатель на класс Point
        p2 = new Point(*(l.p2));
        printf("p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
    }

    ~Line() {
        printf("Удаление линии с координатами p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
        delete p1;
        delete p2;
        //printf("Деструктор класса Line запустился\n");
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    {
        {
            printf("================================================\n");
            printf("         Взаимодействие с классом Point \n");
            printf("================================================\n");

            //Статическое создание объектов
            {
                Point point1;
                Point point2(1, 2);
                Point point3(point2);
            }

            _getch();
            printf("\n\n");

            //Динамическое создание объектов
            {
                Point* point0 = new Point();

                //Создание объекта класса Point и перемещение его в переменную своего собственного класса
                Point* point01 = new Point(3, 4);
                Point* point02 = new Point(*point01);
                point0->reset();
                point0->move(6, 6);
                //Самостоятельно удаляем объекты для наглядности
                delete point0;
                delete point01;
                delete point02;
            }
        }
    }
    printf("\n\n");
    printf("====================================================\n");
    printf("        Взаимодействие с классом ColorPoint \n");
    printf("====================================================\n");
    {
        //Статическое создание объектов
        {
            ColorPoint CPoint1;
            ColorPoint CPoint2(1, 2, 25);
            ColorPoint CPoint3(CPoint2);
        }

        _getch();
        printf("\n\n");

        //Динамическое создание объектов
        {
            Point* CPoint = new ColorPoint(1, 2, 25);
            delete CPoint;

            ColorPoint* CPoint0 = new ColorPoint();
            ColorPoint* CPoint01 = new ColorPoint(3, 4, 25);
            ColorPoint* CPoint02 = new ColorPoint(*CPoint01);

            delete CPoint0;
            delete CPoint01;
            delete CPoint02;
        }
    }
    printf("\n\n");
    printf("===============================================\n");
    printf("         Взаимодействие с классом Line \n");
    printf("===============================================\n");
    {
        //Статическое создание объектов
        {
            Line line1;
            Line line2(1, 2, 3, 4);
            Line line3(line2);
        }

        _getch();
        printf("\n\n");

        //Динамическое создание объектов
        {
            Line* line0 = new Line();
            delete line0;
            Line* line01 = new Line(3, 4, 5, 6);
            Line* line02 = new Line(*line01);
            delete line01;
            delete line02;
        }
    }

    _getch();
    return 0;
};


    





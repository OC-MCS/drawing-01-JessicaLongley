#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct record
{
    Color col;
    ShapeEnum shape;
    Vector2f pos;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
    record temp;
public:
    DrawingShape(Color c, ShapeEnum s, Vector2f p)
    {
        temp.col = c;
        temp.shape = s;
        temp.pos = p;
    }
    virtual void draw(RenderWindow &win) = 0;//pure virtual function for base class
    //virtual record returnFileRecord() = 0;
};

class Circle : public DrawingShape
{
    CircleShape circ; //CircleShape is a Graphics lib class
public:
    //constructor
    Circle(Color c, Vector2f p): DrawingShape(c, CIRCLE, p)
    {
        circ.setPosition(p);
        circ.setRadius(10);
        circ.setOutlineColor(c);
        circ.setFillColor(c);
    }

    virtual void draw(RenderWindow &win)
    {
        win.draw(circ);
    }

    //virtual record returnFileRecord();
};

// add Circle, Square classes below. These are derived from DrawingShape
class Rectangle : public DrawingShape
{
    RectangleShape rect; 
public:
    //constructor
    Rectangle(Color c, Vector2f p) : DrawingShape(c, SQUARE, p)
    {
        const int SIZE = 20;

        rect.setPosition(p);
        rect.setOutlineColor(c);
        rect.setSize(Vector2f(SIZE,SIZE));
        rect.setFillColor(c);
        rect.setOutlineColor(c);
    }

    virtual void draw(RenderWindow &win)
    {
        win.draw(rect);
    }
    //virtual record returnFileRecord();
};



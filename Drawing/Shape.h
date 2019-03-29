#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

//this structure will be used to record neccesicary shape data 
struct record
{
    int colorNumber;
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
        temp.colorNumber = c.toInteger();
        temp.shape = s;
        temp.pos = p;
    }
    virtual void draw(RenderWindow &win) = 0;//pure virtual functions for base class
    virtual record returnFileRecord() = 0;
};

class Circle : public DrawingShape
{
    CircleShape circ; //CircleShape is a Graphics lib class
public:
    //constructor initializes circle and base class
    Circle(Color c, Vector2f p): DrawingShape(c, CIRCLE, p)
    {
        circ.setPosition(p);
        circ.setRadius(10);
        circ.setOutlineColor(c);
        circ.setFillColor(c);
    }

    void draw(RenderWindow &win) //will be used to draw circles later
    {
        win.draw(circ);
    }

    record returnFileRecord() //will return a struct, ready to be put in a vector
    {
        record temp;
        Color col = circ.getFillColor();
        temp.colorNumber = col.toInteger();
        temp.pos = circ.getPosition();
        temp.shape = CIRCLE;
        return temp;
    }

};

//very similar to circle class
class Square : public DrawingShape
{
    RectangleShape rect; 
public:
    //constructor
    Square(Color c, Vector2f p) : DrawingShape(c, SQUARE, p)
    {
        const int SIZE = 20; 

        rect.setPosition(p);
        rect.setOutlineColor(c);
        rect.setSize(Vector2f(SIZE,SIZE));
        rect.setFillColor(c);
        rect.setOutlineColor(c);
    }
    void draw(RenderWindow &win)
    {
        win.draw(rect);
    }
    record returnFileRecord()
    {
        record temp;
        Color col = rect.getFillColor();
        temp.colorNumber = col.toInteger();
        temp.pos = rect.getPosition();
        temp.shape = SQUARE;
        return temp;
    }
};



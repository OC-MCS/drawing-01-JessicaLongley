#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class. 
//keep track of all drawn shapes

class ShapeMgr
{
private:
    vector<DrawingShape*> ptrVec; //a vector of pointers to DrawingShapes

public:

	ShapeMgr()
	{}

    //returnVector returns a pointer to the vector of pointers to shapes
    vector<DrawingShape*>* returnVector()
    {
        return &ptrVec;
    }
    //addShape will check the type of shape then add it's information to the vector
    //parameters: Vector2f, ShapeEnum, Color
    //returns: void
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color) 
	{
        if (whichShape == CIRCLE)
        {
            Circle *c;
            c = new Circle(color, pos);
            ptrVec.push_back(c);
        }

        if (whichShape == SQUARE)
        {
            Square *s;
            s = new Square(color, pos);
            ptrVec.push_back(s);
        }
	}

    //writeRecord will write all of the shapes in the vector to the binary file
    //parameters: file
    //returns: void
    void writeRecords(fstream &file)
    {
        record recordToWrite;
        for (int i = 0; i < ptrVec.size(); i++)
        {
            recordToWrite = ptrVec[i]->returnFileRecord();
            file.write(reinterpret_cast<char*>(&recordToWrite), sizeof(recordToWrite));
        }
    }

    //readRecords will read all of the shapes from the binary file to the vector
    //parameters: file
    //returns: void
    void readRecords(fstream &file) 
    {
        record recordToRead;
        while(file.read(reinterpret_cast<char*>(&recordToRead), sizeof(recordToRead)))
        {
            Color prev(recordToRead.colorNumber); //prev ious color
            addShape(recordToRead.pos, recordToRead.shape, prev);
        }
    }
};

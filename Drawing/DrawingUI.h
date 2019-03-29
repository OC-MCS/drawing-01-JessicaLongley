#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed
//handle user interface

class DrawingUI
{
private:
    RectangleShape drawSpace; //the space that the user can draw in
public:
    //constructor takes care of the canvas
    //parameters: position where main wants the canvas
	DrawingUI(Vector2f p)
	{
        drawSpace.setPosition(p);
        drawSpace.setSize(Vector2f(560, 580));
        drawSpace.setFillColor(Color::White);
	}

    //draw draws the canvas then all of the shapes that exist (every frame)
    //parameters: RenderWindow &, ShapeMgr*
    //returns: none
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
        //drawingSpace
        win.draw(drawSpace);

        //create instance of ptr to vector of ptr
        vector<DrawingShape*>* ptrVec;
        ptrVec = mgr->returnVector();

        //draw all the shapes for the frame
        for (int i = 0; i < ptrVec->size(); i++)
        {
            (*ptrVec)[i]->draw(win);
        }
	}
	
    //isMouseInCanvas prevents rouge shapes
    //parameters: mouse position as Vector2f
    //returns: bool
	bool isMouseInCanvas(Vector2f mousePos)
	{
        bool returnValue = true; //assume the mouse is on the canvas

        //if the mouse is outside of the canvas, return false
        if (mousePos.x < 230 || mousePos.x > 770 || mousePos.y < 10 || mousePos.y >570)
        {
            returnValue = false;
        }

		return returnValue; 
	}

};


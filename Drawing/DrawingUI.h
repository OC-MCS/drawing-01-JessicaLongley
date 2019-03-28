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

public:
	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return false; // just to make it compile
	}

};


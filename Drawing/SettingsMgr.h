#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed
//keep up with current drawing settings

class SettingsMgr
{
private:
	
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
	}

	Color getCurColor()
	{
		return Color::Blue; // just to make it compile 
	}


	ShapeEnum getCurShape()
	{
		return ShapeEnum::CIRCLE; // just to make it compile;
	}

};

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

//keep up with current drawing settings

struct SettingsRecord //a struct to hold current settings data
{
    ShapeEnum curShape;
    int colorNum;
};

class SettingsMgr
{
private:
    ShapeEnum currentShape; //a holder for the current shape
    Color currentColor; //a holder for the current color

public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
        currentShape = startingShape; //getting started
        currentColor = startingColor;
	}

    //getter and setter functions
	Color getCurColor()
	{
		return currentColor;
	}
    ShapeEnum getCurShape()
    {
        return currentShape;
    }
    void setColor(Color newColor)
    {
        currentColor = newColor;
    }
    void setShape(ShapeEnum newShape)
    {
        currentShape = newShape;
    }

    //redPrevSettings will read existing information from the file
    //parameters: fstream &file
    //returns: none
    void readPrevSettings(fstream &file)
    {
        SettingsRecord settings;
        file.read(reinterpret_cast<char*>(&settings), sizeof(settings));
        Color prevColor(settings.colorNum);
        currentColor = prevColor;
        currentShape = settings.curShape;
    }
    //saveSettings will write new information to the file
    //parameters: fstream &file
    //returns:  none
    void saveSettings(fstream &file)
    {
        SettingsRecord settings;
        settings.curShape = currentShape;
        settings.colorNum = currentColor.toInteger();
        file.write(reinterpret_cast<char*>(&settings), sizeof(settings));
    }
};

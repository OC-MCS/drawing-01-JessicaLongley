#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed
//change settings

class SettingsUI
{
private:
    CircleShape redBtn, greenBtn, bluBtn, circShape;
    RectangleShape squrShape;
    SettingsMgr *UIsetMgr; //so that we can use getter and setter data of SettingsMgr

public:
    //constructor tells the buttons where and how to be
    //parameters: settingsMgr*
	SettingsUI(SettingsMgr *mgr)
	{
        UIsetMgr = mgr;

        //red button
        Vector2f pos(100, 80);
        setButton(redBtn, Color::Red, pos);
        //green button
        Vector2f pos2(100, 130);
        setButton(greenBtn, Color::Green, pos2);
       //blue button
        Vector2f pos3(100, 180);
        bluBtn.setPosition(pos3);
        setButton(bluBtn, Color::Blue, pos3);

        //circle shape
        Vector2f pos4(100, 300);
        setButton(circShape, Color::White, pos4);

        //rectangle shape
        Vector2f pos5(100, 350);
        squrShape.setPosition(pos5);
        squrShape.setOutlineColor(Color::White);
        squrShape.setOutlineThickness(3);
        squrShape.setSize(Vector2f(30, 30));
        squrShape.setFillColor(Color::Transparent);

	}

    //setButton will set up circle shapes of the same size and transparenty
    //parameters: circleShape that will be influenced, color, position
    //returns: void
    void setButton(CircleShape &button, Color c,Vector2f p)
    {
        button.setPosition(p);
        button.setRadius(15);
        button.setOutlineColor(c);
        button.setOutlineThickness(3);
        button.setFillColor(Color::Transparent);
    }

    //handleMouseUp will handle if the mouse button is lifted up while over a button
    //parameters: mouse
    //returns:void
	void handleMouseUp(Vector2f mouse)
	{
        if (redBtn.getGlobalBounds().contains(mouse))
        {
            UIsetMgr->setColor(Color::Red);
        }
        if (bluBtn.getGlobalBounds().contains(mouse))
        {
            UIsetMgr->setColor(Color::Blue);
        }
        if (greenBtn.getGlobalBounds().contains(mouse))
        {
            UIsetMgr->setColor(Color::Green);
        }
        if (squrShape.getGlobalBounds().contains(mouse))
        {
            UIsetMgr->setShape(SQUARE);
        }
        if (circShape.getGlobalBounds().contains(mouse))
        {
            UIsetMgr->setShape(CIRCLE);
        }
	}

    //draw will display the settings panel on the left side of the screen
    //parameters: window
    //returns: void
	void draw(RenderWindow& win)
	{
        //"Selected Color"
        Font font;
        if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
            die("couldn't load font");
        Text title("Selected Color", font, 25);
        title.setPosition(30, 25);
        win.draw(title);

        if (UIsetMgr->getCurColor() == Color::Red)
        {
            redBtn.setFillColor(Color::Red);
            greenBtn.setFillColor(Color::Transparent);
            bluBtn.setFillColor(Color::Transparent);
        }
        else if (UIsetMgr->getCurColor() == Color::Green)
        {
            redBtn.setFillColor(Color::Transparent);
            greenBtn.setFillColor(Color::Green);
            bluBtn.setFillColor(Color::Transparent);
        }
        else if (UIsetMgr->getCurColor() == Color::Blue)
        {
            redBtn.setFillColor(Color::Transparent);
            greenBtn.setFillColor(Color::Transparent);
            bluBtn.setFillColor(Color::Blue);
        }

        if (UIsetMgr->getCurShape() == CIRCLE)
        {
            squrShape.setFillColor(Color::Transparent);
            circShape.setFillColor(Color::White);
        }
        else if (UIsetMgr->getCurShape() == SQUARE)
        {
            squrShape.setFillColor(Color::White);
            circShape.setFillColor(Color::Transparent);
        }
        win.draw(redBtn);
        win.draw(greenBtn);
        win.draw(bluBtn);

        //"Selected Shape"
        Text title2("Selected Shape", font, 25);
        title2.setPosition(30, 250);
        win.draw(title2);

        win.draw(squrShape);
        win.draw(circShape);

	}

    //a utility function to call any time we need to bail out
    //parameters: error msg as string
    //returns: void
    void die(string msg)
    {
        cout << msg << endl;
        exit(-1);
    }

};

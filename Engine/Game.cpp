/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	/***
	* Errata:
	* In Part 3 when we make the gb variable a member variable,
	* it will maintain its value from frame to frame.
	* So if we don't reset it every frame, then the first time we press CTRL and set it to 0,
	* it will forever after be stuck at 0, which is probably not desired behavior. ;)
	***/

	gb = 255;	//reset gb every frame

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight)
		{
		}
		else
		{
			vx = vx + 1;
			inhibitRight = true;
		}

	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}

	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
		}
		else
		{
			vy = vy + 1;
			inhibitDown = true;
		}

	}
	else
	{
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}

	}
	else
	{
		inhibitUp = false;
	}

	x = x + vx;
	y = y + vy;

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gb = 0;
	}

	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
	if (shapeIsChanged)
	{
		gfx.PutPixel(-5 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, -4 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, -3 + y, 255, gb, gb);
		gfx.PutPixel(-4 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(-3 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, 4 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, 3 + y, 255, gb, gb);
		gfx.PutPixel(-4 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(-3 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, -4 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, -3 + y, 255, gb, gb);
		gfx.PutPixel(4 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(3 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, 4 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, 3 + y, 255, gb, gb);
		gfx.PutPixel(4 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(3 + x, 5 + y, 255, gb, gb);
	}
	else
	{
		gfx.PutPixel(-5 + x, y, 255, gb, gb);
		gfx.PutPixel(-4 + x, y, 255, gb, gb);
		gfx.PutPixel(-3 + x, y, 255, gb, gb);
		gfx.PutPixel(3 + x, y, 255, gb, gb);
		gfx.PutPixel(4 + x, y, 255, gb, gb);
		gfx.PutPixel(5 + x, y, 255, gb, gb);
		gfx.PutPixel(x, -5 + y, 255, gb, gb);
		gfx.PutPixel(x, -4 + y, 255, gb, gb);
		gfx.PutPixel(x, -3 + y, 255, gb, gb);
		gfx.PutPixel(x, 3 + y, 255, gb, gb);
		gfx.PutPixel(x, 4 + y, 255, gb, gb);
		gfx.PutPixel(x, 5 + y, 255, gb, gb);
	}
}

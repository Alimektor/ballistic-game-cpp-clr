#pragma once
#include "Stone.h"

using namespace System::Drawing;
using namespace System;

namespace BallisticGame {
	ref class Ballista
	{
	private:
		Color Color;
		int X;
		int Y;
		int Size;
		bool Left;
		Stone ^ Stone;
	public:
		Ballista(int x, int y, System::Drawing::Color color, bool left);
		void draw(Graphics ^ graphics);
		bool shoot(Graphics^ graphics, int x, int y);
		int getAngle();
		void setAngle(int angle);
		int getSpeed();
		void setSpeed(int speed);
		int getMass();
		void setMass(int mass);
		bool isLeft();
		int getX();
		int getY();
	};
}
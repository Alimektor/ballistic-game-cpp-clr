#pragma once


using namespace System::Drawing;
using namespace System;
using namespace System::Collections::Generic;

namespace BallisticGame
{
	ref class Stone
	{
	private:
		int Mass;
		int Speed;
		int Angle;
		System::Drawing::Color Color;
		int X;
		int Y;
		bool Left;
	public:
		Stone(System::Drawing::Color color, int x, int y, bool left);
		int getAngle();
		void setAngle(int angle);
		int getSpeed();
		void setSpeed(int speed);
		int getMass();
		void setMass(int mass);
		bool shoot(Graphics^ graphics, int xTarget, int yTarget, int size);
		bool isLeft();
	};
}
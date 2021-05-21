#include "Ballista.h"

BallisticGame::Ballista::Ballista(int x, int y, System::Drawing::Color color, bool left)
{
    this->Color = color;
    this->X = x;
    this->Y = y;
	this->Stone = gcnew BallisticGame::Stone(color, x, y, left);
	this->Left = left;
	this->Size = 80;
}

void BallisticGame::Ballista::draw(Graphics ^ graphics)
{
	int x = this->X - this->Size / 2;
	int y = this->Y + 260;
	graphics->FillEllipse(gcnew SolidBrush(this->Color), x, y, this->Size, this->Size);

	Pen^ blackPen = gcnew Pen(this->Color, 10);

	int radius = 50;
	int x1 = x + this->Size / 2;
	int y1 = y + this->Size / 2;
	int angle = this->Stone->getAngle();
	int x2 = 0;
	if (this->isLeft())
	{
		x2 = (int) (x1 + radius * Math::Cos(angle / (180.0 / Math::PI)));
	}
	else
	{
		x2 = (int) (x1 - radius * Math::Cos(angle / (180.0 / Math::PI)));
	}
	int y2 = (int) (y1 - radius * Math::Sin(angle / (180.0 / Math::PI)));

	graphics->DrawLine(blackPen, x1, y1, x2, y2);
}

bool BallisticGame::Ballista::shoot(Graphics^ graphics, int x, int y)
{
	return this->Stone->shoot(graphics, x, y, this->Size);
}

int BallisticGame::Ballista::getAngle()
{
	return this->Stone->getAngle();
}

void BallisticGame::Ballista::setAngle(int angle)
{
	this->Stone->setAngle(angle);
}

int BallisticGame::Ballista::getSpeed()
{
	return Stone->getSpeed();
}

void BallisticGame::Ballista::setSpeed(int speed)
{
	this->Stone->setSpeed(speed);
}

int BallisticGame::Ballista::getMass()
{
	return this->Stone->getMass();
}

void BallisticGame::Ballista::setMass(int mass)
{
	this->Stone->setMass(mass);
}

bool BallisticGame::Ballista::isLeft()
{
	return this->Left;
}

int BallisticGame::Ballista::getX()
{
	return this->X;
}

int BallisticGame::Ballista::getY()
{
	return this->Y;
}

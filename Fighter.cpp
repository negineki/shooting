#include "ShootingApp.h"
#include "Fighter.h"

Fighter::Fighter() : FlyingObject(), dir(STOP)
{
}

Fighter::~Fighter()
{
}

void Fighter::init()
{
	FlyingObject::init();

	x = 400;
	vx = 200;
	y = 400;
	vy = 200;
	radius = 30;
}

void Fighter::cleanup()
{
	FlyingObject::cleanup();
}

void Fighter::update()
{
	FlyingObject::update();

	double dx = 0;
	double dy = 0;
	double dt = elapsed.get();

	if (dir & LEFT)
		dx -= vx * dt;
	if (dir & RIGHT)
		dx += vx * dt;
	if (dir & FORE)
		dy -= vy * dt;
	if (dir & BACK)
		dy += vy * dt;

	x += dx;
	y += dy;
	elapsed.reset();
}

void Fighter::draw()
{
	LPCWSTR c;

	c = TEXT("|");
	TextOut(App::hDC, (int)x - 21, (int)y, c, lstrlen(c));
	c = TEXT("|");
	TextOut(App::hDC, (int)x + 18, (int)y, c, lstrlen(c));
	c = TEXT("---");
	TextOut(App::hDC, (int)x - 16, (int)y+10 , c, lstrlen(c));
	c = TEXT("---");
	TextOut(App::hDC, (int)x - 16, (int)y-7, c, lstrlen(c));
	c = TEXT("--+--");
	TextOut(App::hDC, (int)x - 27, (int)y -20, c, lstrlen(c));

	//c = TEXT("-+-");
	//TextOut(App::hDC, (int)x - 23, (int)y + 6, c, lstrlen(c));
	drawDebug();


}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}
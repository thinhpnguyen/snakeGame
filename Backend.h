#pragma once

#ifndef BACKEND_H
#define BACKEND_H
#include <vector>
#include <wx/gdicmn.h>
#include "constants.h"
using namespace std;




class Snake {
public:
	Snake();
	void setDirection(enum Direction direction);
	const std::vector<wxPoint>& getBody() const;
	const wxPoint& getHead() const;
	void addBody(const wxPoint& bodyPart);
	enum Direction getDirection() const;
	bool isAlive() const;
	void setALive(bool alive);
	void move();

private:
	vector<wxPoint> body;
	int bodySize;
	wxPoint head;
	Direction dir;
	bool alive;

};


#endif


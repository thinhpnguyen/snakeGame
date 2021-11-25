#pragma once

#ifndef BACKEND_H
#define BACKEND_H
#include <vector>
#include <wx/gdicmn.h>
#include "constants.h"
using namespace std;



namespace SnakeGame {
	class Snake {
	public:
		Snake();
		void setDirection(enum Direction direction);
		const std::vector<wxPoint>& getBody() const;
		//const wxPoint& getHead() const;
		void addBody(const wxPoint& bodyPart);
		void addSegment(int count = 1);
		enum Direction getDirection() const;
		bool isAlive() const;
		void setALive(bool alive);
		void move();

	private:
		vector<wxPoint> body;
		int bodySize;
		//wxPoint head;
		Direction dir;
		bool alive;

	};

	inline const std::vector<wxPoint>& Snake::getBody() const { return body; };
	inline void Snake::addBody(const wxPoint& bodyPart) { body.push_back(bodyPart); };
	inline enum Direction Snake::getDirection() const { return dir; };
	inline void Snake::setDirection(enum Direction direction) { this->dir = direction; };
	inline bool Snake::isAlive() const { return alive; };
	inline void Snake::setALive(bool alive) { this->alive = alive; };
	//inline const wxPoint& Snake::getHead() const { return head; };
}

#endif


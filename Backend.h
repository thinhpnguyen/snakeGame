#pragma once

#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <vector>
using namespace std;

struct coordinate {
	int x, y;
	coordinate() {};
	coordinate(int a, int b) :x(a), y(b) {};
	bool operator== (const coordinate& other) const {
		if ((other.x == x) && (other.y == y) ){
			return true;
		}
		else {
			return false;
		}
	}
};

class snake {
public:
private:
	vector<coordinate> body;
	int bodysize;
	coordinate head;
	enum direction { UP, DOWN, LEFT, RIGHT };
	direction dir;
};

#endif


#include "Backend.h"
using namespace SnakeGame;



Snake::Snake(): dir(LEFT), alive(true), bodySize(3) {
    // center the Snake vertically in the middle of the screen
    wxPoint point((640 / 2) - BLOCK_SIZE, (480 / 2) - (2 * BLOCK_SIZE));

    for (int i = 0; i < 4; i++) {
        body.push_back(point);
        point.x += BLOCK_SIZE;
    }

}
void Snake::addSegment(int count) {
    // get the last part of the Snake
    wxPoint &body_temp = body[body.size() - 1];

    // clone it
    for (int i = 0; i < count; i++) {
    	body.push_back(body_temp);
    }
}

void Snake::move() {
    // move the body towards the head
    for (unsigned int i = body.size() - 1; i >= 1; --i) {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }

    // move the head in the current direction
    if (dir == UP) {
        body[0].y -= BLOCK_SIZE;
    }
    else if (dir == RIGHT) {
        body[0].x += BLOCK_SIZE;
    }
    else if (dir == DOWN) {
        body[0].y += BLOCK_SIZE;
    }
    else {
        body[0].x -= BLOCK_SIZE;
    }
}

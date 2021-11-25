#include "Backend.h"
using namespace SnakeGame;



Snake::Snake(): dir(RIGHT), alive(true), bodySize(3) {
    // center the Snake vertically in the middle of the screen
    wxPoint point((640 / 2) - BLOCK_SIZE, (480 / 2) - (2 * BLOCK_SIZE));

    for (int i = 0; i < 3; i++) {
        body.push_back(point);
        point.x += BLOCK_SIZE;
    }
    head = point;
}


void Snake::move() {
    // move the body towards the head
    for (unsigned int i = body.size() - 1; i >= 1; --i) {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }

    // move the head in the current direction
    if (dir == UP) {
        head.y -= BLOCK_SIZE;
    }
    else if (dir == RIGHT) {
        head.x += BLOCK_SIZE;
    }
    else if (dir == DOWN) {
        head.y += BLOCK_SIZE;
    }
    else {
        head.x -= BLOCK_SIZE;
    }
}

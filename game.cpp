#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "game.h"
#include "Snake.h"
#include "timer.h"
#include "Backend.h"
using namespace SnakeGame;


Game::Game(GamePanel & panel) : snake(NULL), panel(panel),
playing(false), paused(false), score(0) {
    // create the game Timer
    timer = new Timer(*this);
}

Game::~Game() {
    // end the Game
    end();

    // delete the Timer
    delete timer;
}
void Game::end() {
    // if we are playing
    if (playing) {
        // stop playing
        playing = false;

        // stop the Timer
        timer->Stop();

        // remove the snake
        delete snake;
    }
}
void Game::start() {
    // end the current Game
    end();
    timer->Start(t);
    snake = new Snake();
    // now we are playing
    moveApple();
    playing = true;
}


void Game::changeDirection(enum Direction direction) {
    snake->setDirection(direction);
    updated = false;
}
bool Game::isSnakeAlive() { 
    return snake->isAlive();
};

const std::vector<wxPoint>& Game::getSnakeBody() const {
    return snake->getBody();
};

enum Direction Game::getSnakeDirection() const {
    return snake->getDirection();
}
void Game::togglePause() {
    // toggle pause value
    paused = !paused;

    if (paused) {
         //stop the timer
        timer->Stop();
    }
    else {
         //(re)start the timer
        timer->Start(t);
    }
}
void Game::moveApple() {
    for (;;) {
        // find a random spot for the apple
        apple.x = (rand() / ((RAND_MAX / (PANEL_WIDTH / BLOCK_SIZE)) + 1)) * BLOCK_SIZE;
        apple.y = (rand() / ((RAND_MAX / (PANEL_HEIGHT / BLOCK_SIZE)) + 1)) * BLOCK_SIZE;

        if (!isOccupied(apple, true)) {
            // if we found a free spot, we're done
            break;
        }

        // otherwise we have to keep looking
    }
}

bool Game::isOccupied(const wxPoint &point, bool checkHead) const {
    int start = (checkHead ? 0 : 1);

    // is the point occupied by the Snake
    for (unsigned int i = start; i < snake->getBody().size(); i++) {
        if (point == snake->getBody()[i]) {
            return true;
        }
    }

    if ((point.x > PANEL_WIDTH - BLOCK_SIZE) || (point.x < 0)) {
        return true;
    }

    if ((point.y > PANEL_HEIGHT - BLOCK_SIZE) || (point.y < 0)) {
        return true;
    }

    // is the point occupied by a Wall?
//    if (level.isWall(point)) {
//        return true;
//    }

    return false;
}
void Game::tick() {
        // move the Snake
        snake->move();

        // did the snake crash?
        if (isOccupied(snake->getBody()[0])) {
            snake->setALive(false);
        }

        // did the snake eat the apple?
        if (snake->getBody()[0] == apple) {
            // randomize the apple position
            moveApple();

            // grow the snake
            snake->addSegment(1);
            score++;
        }

        // refresh the panel
        panel.Refresh();
        updated = true;
}


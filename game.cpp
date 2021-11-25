#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "game.h"
#include "Snake.h"
#include "timer.h"
#include "Backend.h"

using namespace SnakeGame;


Game::Game(GamePanel & panel) : snake(NULL), panel(panel),
playing(false), paused(true) {
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
    timer->Start(500);
    snake = new Snake();
    // now we are playing
    moveApple();
    playing = true;
}


void Game::changeDirection(enum Direction direction) {
    snake->setDirection(direction);
}


void Game::togglePause() {
    // toggle pause value
    paused = !paused;

    if (paused) {
        // stop the timer
        timer->Stop();
    }
    else {
        // (re)start the timer
        timer->Start(-1);
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

    // is the point occupied by a Wall?
//    if (level.isWall(point)) {
//        return true;
//    }

    return false;
}
void Game::tick() {
    // move the Snake
    snake->move();

    // refresh the panel
    panel.Refresh();
}


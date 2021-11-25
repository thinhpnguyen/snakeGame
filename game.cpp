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

    snake = new Snake();
    // now we are playing
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
        timer->Start(10);
    }
}

void Game::tick() {
    // move the Snake
    snake->move();

    // refresh the panel
    panel.Refresh();
}


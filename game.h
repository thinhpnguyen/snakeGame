#pragma once
#ifndef _GAME_HH_
#define _GAME_HH_

#include <vector>
#include <cstddef>
#include "constants.h"
using namespace std;


namespace SnakeGame {
    class Timer;
    class GamePanel;
    class Snake;

    class Game {
    private:
        wxPoint apple;
        Snake* snake;
        Timer* timer;
        GamePanel& panel;
        bool updated = false; // used to fix race condition when user press too fast
        bool playing, paused;
        void moveApple();
        bool isOccupied(const wxPoint& point, bool checkHead = false) const;
        int score;
    public:
        
        Game(GamePanel& panel);

        ~Game();

        const int getScore() const;
        
        const bool getUpdated() const;

        const Snake& getSnake() const;
        
        bool isSnakeAlive();
        
        const std::vector<wxPoint>& getSnakeBody() const;

        enum Direction getSnakeDirection() const;

        const wxPoint& getApple() const;

        bool isPlaying() const;


        void start();

        void end();


        void changeDirection(enum Direction direction);

        void togglePause();

        void tick();
    };

    inline const Snake& Game::getSnake() const { return *snake; }
    inline bool Game::isPlaying() const { return playing; }
    inline const wxPoint& Game::getApple() const { return apple; }
    inline const int Game::getScore() const {return score;}
    inline const bool Game::getUpdated() const { return updated; };

}
#endif


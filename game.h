#pragma once
#ifndef _GAME_HH_
#define _GAME_HH_

#include <cstddef>
#include "constants.h"

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
        bool playing, paused;
        void moveApple();
        bool isOccupied(const wxPoint& point, bool checkHead = false) const;
        int score;
    public:
        /**
         * Creates a new Game.
         *
         * @param panel the GamePanel displaying this Game.
         */
        Game(GamePanel& panel);

        /**
         * Destructs this Game.
         */
        ~Game();
        /**
        * Gets this Game's Snake.
        *
        * @return The Snake.
        */
        const int getScore() const;
        /**
         * Gets this Game's Snake.
         *
         * @return The Snake.
         */
        const Snake& getSnake() const;
        /**
         * Gets the apple position.
         *
         * @return The apple position.
         */
        const wxPoint& getApple() const;
        /**
         * Queries if this Game is being played.
         *
         * @return true if this Game is being played; false otherwise.
         */
        bool isPlaying() const;

        /**
         * Starts this Game.
         *
         * @param difficulty The difficulty setting.
         */
        void start();

        /**
         * Ends the current Game.
         */
        void end();

        /**
         * Change the direction the Snake is moving.
         *
         * @param direction The new direction.
         */
        void changeDirection(enum Direction direction);

        /**
         * Toggles whether the Game is paused or not.
         */
        void togglePause();

        /**
         * Called when the timer goes off.
         */
        void tick();
    };

    inline const Snake& Game::getSnake() const { return *snake; }
    inline bool Game::isPlaying() const { return playing; }
    inline const wxPoint& Game::getApple() const { return apple; }
    inline const int Game::getScore() const {return score;}

}
#endif


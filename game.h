#pragma once
#ifndef _GAME_HH_
#define _GAME_HH_

#include <cstddef>
#include "Snake.h"
#include "Backend.h"
#include "constants.h"
#include "timer.h"

    class Game {
    private:
        Snake* snake;
        Timer* timer;
        GamePanel& panel;
        bool playing, paused;

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
        const Snake& getSnake() const;




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


#endif


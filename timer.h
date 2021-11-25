#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_
#include "game.h"
#include <wx/timer.h>
namespace SnakeGame {
    class Game;

    class Timer : public wxTimer {
    private:
        Game& game;

        /**
         * Called when the timer goes off.
         */
        void Notify();

    public:
        /**
         * Creates a new Timer.
         *
         * @param game The Game to notify when this Timer goes off.
         */
        Timer(Game& g);
    };
    inline Timer::Timer(Game& g) : wxTimer(), game(g) {}
    inline void Timer::Notify() { game.tick(); }
}

#endif



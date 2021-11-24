#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

#include <wx/timer.h>
#include "game.h"
#include "Backend.h"

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



#endif



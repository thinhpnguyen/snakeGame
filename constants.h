#pragma once
#ifndef _CONSTANTS_H_
#define _CONSTANTS_HH_
#include <wx/gdicmn.h>

    /// The direction the Snake is moving in
    enum Direction {
        UP, RIGHT, DOWN, LEFT
    };

    /// The size of a block
    const int BLOCK_SIZE = 16;
    const int PANEL_WIDTH = 640;
    const int PANEL_HEIGHT = 480;
    
#endif

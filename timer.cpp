#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "timer.h"

inline Timer::Timer(Game& g) : wxTimer(), game(g) {}
inline void Timer::Notify() { game.tick(); }
#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item *item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite)
{
}

void StoveCounter::tick()
{
    ticks++;
    if (ticks % 250 == 0)
    {
        cooked = true;
    }
}
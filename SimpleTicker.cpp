/**
@brief SimpleTicker

@license GPLv2

@author Stephan Ruloff
@date 21.04.2016
*/

#include <limits.h>

#include "SimpleTicker.h"

SimpleTicker::SimpleTicker()
{
  mCb = 0;
  mTime = 0;
  mMillisOld = 0;
}

SimpleTicker::~SimpleTicker()
{
}

void SimpleTicker::begin(unsigned long timeMs, TickerCb cb)
{
  mCb = cb;
  mTime = timeMs;
  mMillisOld = millis();
}

void SimpleTicker::update(void)
{
  unsigned long now;
  unsigned long diff;

  if (!mCb || !mTime) {
    return;
  }
  now = millis();
  if (now < mMillisOld) {
    diff = ULONG_MAX - mMillisOld + now;
  } else {
    diff = now - mMillisOld;
  }
  
  if (diff > mTime) {
    mCb();
    mMillisOld = now;
  }
}

void SimpleTicker::end(void)
{
  mCb = 0;
  mTime = 0;
  mMillisOld = 0;
}

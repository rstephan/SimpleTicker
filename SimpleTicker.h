#ifndef __SIMPLETICKER_H__
#define __SIMPLETICKER_H__
/**
@brief SimpleTicker

@license GPLv2

@author Stephan Ruloff
@date 21.04.2016
*/

#include <Arduino.h>

typedef void (*TickerCb)(void);

class SimpleTicker
{
public:
  SimpleTicker();
  ~SimpleTicker();
  
  void begin(unsigned long timeMs, TickerCb cb);
  void update(void);
  void end(void);
private:
  TickerCb mCb;
  unsigned long mTime;
  unsigned long mMillisOld;
};

#endif

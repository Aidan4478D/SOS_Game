#include <stdbool.h>

#ifndef TURN_LOGIC_H_   //include guard
#define TURN_LOGIC_H_

typedef enum {

  COMPUTER = false,
  USER = true
} TURN;

extern TURN turn; 

#endif

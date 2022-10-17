#include <stdbool.h>

int getRandX();
int getRandY();
void randomMove(); 
void makeMove();
void computerMove(); 
void moveUser(); 

extern bool playComp; 
extern char coords[5][5];
extern char last_choice;
extern int last_x, last_y, user_points, comp_points;
extern int board_x, board_y;
extern int playCounter, compCounter; 

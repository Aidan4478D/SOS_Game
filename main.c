#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "moveLogic.h"
#include "boardLogic.h"
#include "turnDeclaration.h"


bool userFirst, gameOver, playComp;
int compCounter, playCounter, moveCounter = 0;



int board_x = 5, board_y = 5; 

char coords[5][5]; 
char last_choice;
int last_x, last_y, user_points, comp_points;
TURN turn = USER; 



void determineFirst();
void playGame();
void checkWin(); 
void playAgain();
void resetGame();



int main(void) {

  determineFirst();
  populateInitial(coords);

  playGame();
  
  return 0;
}



void checkWin() {

  bool playing = false;

  for(int i = 0; (i < board_x) && (playing == false); i++) {

    for(int j = 0; (j < board_y) && (playing == false); j++) {

      if(coords[i][j] == '-') {
        
        playing = true;
      }
    }
  }

  if(playing) {

    gameOver = false;
  }
  else {

    gameOver = true;
  }
}


void resetGame() {

  for(int i = 0; i < board_x; i++) {

    for(int j = 0; j < board_y; j++) {

      coords[i][j] = '-';
    }
  }

  last_choice = '-', turn = USER, board_x = board_y = last_x = last_y = user_points = comp_points = compCounter = playCounter = 0;
}




void playGame() {

  while (!gameOver) {

    makeMove();
    checkWin(); 
  }

  if(user_points > comp_points) {

	playComp == true ? printf("Great job! You beat the computer %d to %d!", user_points, comp_points) : printf("User 1 has beaten User 2 %d to %d!", user_points, comp_points); 
  }
  else if(user_points == comp_points){
	
	playComp == true ? printf("You have tied the computer %d to %d!", user_points, comp_points) : printf("User 1 and User 2 have tied %d to %d!", user_points, comp_points);	
  }
  else {
	
	playComp == true ? printf("Boohoo.. You lost to the computer %d to %d :(", user_points, comp_points) : printf("User 2 has beaten User 1 %d to %d!", user_points, comp_points);
  }
  playAgain();
}



void determineFirst() {

  printf("Welcome to SOS!\n");
  char choice;
  char buffer[1024];
  char buffer_gc; 

  do {

    printf("\nWould you like to play against a computer?\n(y: yes | n: no)\n\n");
    choice = getchar();
    buffer_gc = getchar();
    fflush(stdout);

  } while (choice != 'y' && choice != 'n');

  playComp = (choice == 'y') ? true : false;
  choice = '\0'; 

  do {

    printf("\nWould you like to play first?\n(y: yes | n: no)\n\n");
    choice = getchar();
    fflush(stdout);

  } while (choice != 'y' && choice != 'n');

  if (choice == 'y') {

    turn = USER; 
  } 
  else {

    turn = COMPUTER; 
  }
}

void playAgain() {

  printf("\n\n Would you like to play again?: (y: yes | n: no)");

  char choice = '\0'; 

  do {

    printf("\nWould you like to play first?\n(y: yes | n: no)\n\n");
    choice = getchar();
    fflush(stdout);

  } while (choice != 'y' && choice != 'n');

  if (choice == 'y') {

    resetGame(); 
    gameOver = false; 
    main(); 
  } 
  else {

    //do nothing!
  }
}



#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "moveLogic.h"
#include "turnDeclaration.h"
#include "boardLogic.h"
#include <stdio.h>
#include <stdbool.h>

extern bool playComp; 
extern char coords[5][5];
extern char last_choice;
extern int last_x, last_y, user_points, comp_points;
extern int board_x, board_y;
extern int playCounter, compCounter; 



int getRandX() {

  return rand() % board_x;
}

int getRandY() {

  return rand() % board_y;
}

void randomMove() {

  char choice = '-'; 
  char rand_c;
  int rand_x, rand_y, c_index; 
  int i = 0, j = 0;

  rand_x = getRandX(); 
  rand_y = getRandY(); 

  c_index = rand() % 2;

  rand_c = ((c_index >= 1) ? 'S' : 'O'); 
  //printf("%c was just placed at %d, %d\n", rand_c, rand_x, rand_y);
  

  if(coords[rand_x][rand_y] != '-') {

    randomMove(); 
  }
  else {
    //printf("%c was just placed at %d, %d\n", rand_c, rand_x, rand_y); 
    coords[rand_x][rand_y] = rand_c; 
    
    last_x = rand_x, last_y = rand_y, last_choice = rand_c; 
  }  
}

void computerMove() {

  if ((compCounter == 0) && (coords[2][2] == '-')) {

    coords[2][2] = 'S';
    last_x = 2, last_y = 2, last_choice = 'S';
  } 
  else {

    randomMove(); 
  } 

}

void moveUser() {

  char buffer, so_choice;
    int x_choice, y_choice;

    printf("\n\nWhere would you like to play?");

    do {
      printf("\nX-Coordinate: ");
      scanf("%d", &x_choice);
      buffer = getchar();
      fflush(stdout);
    } while (x_choice < 0 || x_choice > (board_x - 1));

    do {
      printf("Y-Coordinate: ");
      scanf("%d", &y_choice);
      buffer = getchar();
      fflush(stdout);
    } while (y_choice < 0 || y_choice > (board_y - 1));

    do {
      printf("Letter: ");
      scanf("%c", &so_choice);
      buffer = getchar();

    } while ((so_choice != 'S' && so_choice != 's') &&
             (so_choice != 'O' && so_choice != 'o'));

    so_choice = (so_choice == 's') ? so_choice = 'S' : so_choice;
    so_choice = (so_choice == 'o') ? so_choice = 'O' : so_choice;

    if(coords[x_choice][y_choice] != '-') {

      printf("\nInvalid Move! This square is taken!\n");
      updateBoard(coords);
      makeMove(); 
    }

    last_x = x_choice, last_y = y_choice, last_choice = so_choice;

    coords[x_choice][y_choice] = so_choice;

    updateBoard(coords);
    checkPoint();
}

void makeMove() {

  if (turn == USER) {

    printf("\n\n****User 1 Move****\n");
    moveUser(); 
    turn = COMPUTER; 
    playCounter++; 
  }

  else {

    if(playComp) {
      printf("\n\n****Computer Move****\n");
      computerMove();
      updateBoard(coords);
      checkPoint();
    }
    else {
      printf("\n\n****User 2 Move****\n");
      moveUser();
    }
    turn = USER; 
    compCounter++;
  }
}

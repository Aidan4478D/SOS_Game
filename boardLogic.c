#include <stdio.h>
#include <stdbool.h>
#include "turnDeclaration.h"
#include "boardLogic.h"

extern bool playComp; 
extern int compCounter, playCounter, moveCounter;
extern int board_x, board_y; 
extern char coords[5][5]; 
extern char last_choice;
extern int last_x, last_y, user_points, comp_points;



void populateInitial(char x[board_x][board_y]) {

  for (int i = 0; i < board_x; i++) {

    for (int j = 0; j < board_y; j++) {

      x[i][j] = '-';
    }
  }
}


void updateBoard(char x[board_x][board_y]) {

  printf("\n---------------------\n");

  for (int i = 0; i < board_x; i++) {

    printf("|");
    
    for (int j = 0; j < board_y; j++) {

      char cur = x[i][j];
      printf(" %c |", cur);
    }
    printf("\n---------------------\n");
  }
}


void checkPoint() {

  int start_index_x, start_index_y, end_index_x, end_index_y, i, j;
  int pos_intersect_x, pos_intersect_y, second_intersect_x, second_intersect_y;
  int local_points = 0; 

  start_index_x = (last_x - 1) < 0 ? 0 : last_x - 1;
  start_index_y = (last_y - 1) < 0 ? 0 : last_y - 1;
  end_index_x = (last_x + 1) > (board_x - 1) ? (board_x - 1) : last_x + 1;
  end_index_y = (last_y + 1) > (board_y - 1) ? (board_y - 1) : last_y + 1;

  if (last_choice == 'S') {
    
    for (i = start_index_x; i < end_index_x + 1; i++) {

      for (j = start_index_y; j < end_index_y + 1; j++) {

        int cur_index_i = i, cur_index_j = j;
        
        if(i == last_x && j == last_y) {
          continue; 
        }

        if(coords[i][j] == 'O') {

          pos_intersect_x = i - last_x;
          pos_intersect_y = j - last_y;
          
          second_intersect_x = i + pos_intersect_x;
          second_intersect_y = j + pos_intersect_y;

          char second_intersect_c = coords[second_intersect_x][second_intersect_y];

          if(second_intersect_c == 'S') { 

            local_points++; 
          }    
        }
      }
    }
  }

  else if(last_choice == 'O') {

    for (i = start_index_x; i < end_index_x + 1; i++) {
    
      for (j = start_index_y; j < end_index_y + 1; j++) {

        if(i == last_x && j == last_y) {
          continue; 
        }

        if(coords[i][j] == 'S') {

          pos_intersect_x = i - last_x;
          pos_intersect_y = j - last_y;

          second_intersect_x = last_x - pos_intersect_x;
          second_intersect_y = last_y - pos_intersect_y;

          char second_intersect_c = coords[second_intersect_x][second_intersect_y];

          if(second_intersect_c == 'S') { 

            local_points++; 
          }    
        }
      }
    }
    local_points /= 2;
  }
  
  (turn == USER) ? (user_points += local_points) : (comp_points += local_points); 
  playComp == true ? printf("User points are: %d\nComputer points are: %d\n", user_points, comp_points) : printf("User 1 points are: %d\nUser 2 points are: %d\n", user_points, comp_points);
  local_points = 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/main.h"
#include "../c-head/game.h"
#include "../c-head/getLine.h"

int main (int argc, char* argv[]){
  char input[20] ;
  int retour;
  printf("Hello World\n");
  printf("Enter cmd (help to get help)\n");
  do{ 
    printf(">>> ");
    My_gets(input);
    if (input == NULL) {
      printf ("Error while reading input\n");
    } else {
      if(strcmp("game",input)==0) {
        game();
      } else if(strcmp("help",input)==0){
        help();
      } else if(strcmp("exit",input)==0){
        return 0 ;
      } else {
        wrong();
      }
    }
  }while(strcmp("exit",input)!=0);

  return 0 ;
}

void wrong(){
  printf("Unknown cmd operator. Use help to get help.\n");
}
void help(){
  printf("game starts a new game\n");
  printf("help display help\n");
  printf("exit to exit\n");
}
void game(){
  printf("---Game--- \n");
  // Init the game board
  playAGame();

  printf("Done\nEnter game to start a new one\n");
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/main.h"
#include "../c-head/gameNoUI.h"
#include "../c-head/gameUI.h"
#include "../c-head/getLine.h"
#include "../c-head/gui.h"

int main (int argc, char* argv[]){
  playAGameUI(NORMAL);
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
        int ret  = game();
        if (ret == 1){
          return 0;
        }
      } else if(strcmp("help",input)==0){
          help();
      } else if(strcmp("testUI",input)==0){
          testUserInterface();
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
int game(){
  printf("---Game--- \n");
  // Init the game board
  int ret = playAGame();
  if (ret == 1){
    // Handled error : quit command
    return 1;
  } else {
    printf("Done\nEnter game to start a new one\n");
    return 0;
  }
}
int testUserInterface(){
    playAGameUI(NORMAL);
}

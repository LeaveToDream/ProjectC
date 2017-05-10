#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/main.h"

int main (int argc, char* argv[]){
  char i;
  printf("Hello World\n");
  printf("Enter cmd (h to get help)\n");
  do{
    printf(">>> ");
    i = getCharClean();
    switch(i){
      case 'g' : game(); break;
      case 'h' : help(); break;
      case 'e' : return 0 ;
      default : wrong(); break;
    }
  }while(i!='e');
}

char getCharClean(){
  char c = getchar();
  while(getchar()!='\n');
  return c;
}

void wrong(){
  printf("Unknown cmd operator. Use h to get help.\n");
}
void help(){
  printf("g starts a new game\n");
  printf("h display help\n");
  printf("e to exit\n");
}
void game(){
  int playing = true ;
  printf("---Game--- \n");
  // Init the game board
  playAGame();

}

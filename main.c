#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"

int main (int argc, char* argv[]){
  char i = '1';
  printf("Hello World\n");
  while(i!='e'){
    printf("\n");
    printf("Chose what you want to do ('h' to get help \n or 'g' to game with a friend \n or 'r' to game alone \n or 'e' to exit :( )\n");
    printf(">>>");
    i = getCharClean();
    switch(i){
      case 'g' : game(); break;
      case 'h' : help(); break;
      case 'r' : gamealone(); break; 
      //r comme robot... #intelligence artificielle tout ça tout ça... (oui bah c'est bon hein, on ne critique pas !) 
      case 'e' : return 0 ;
      default : wrong(); break;
    }
  }
}

char getCharClean(){
  char c = getchar();
  while(getchar()!='\n');
  printf("e to exit\n");
}
void game(){
  int playing = 1 ;
  printf("---Game--- \n");
  // Init the game board
  while(playing==1){
    



    playing=0;
  }



}

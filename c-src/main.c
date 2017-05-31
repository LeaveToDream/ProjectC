#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/main.h"
#include "../c-head/gameNoUI.h"
#include "../c-head/gameUI.h"
#include "../c-head/getLine.h"
#include "../c-head/menu.h"
#include "../c-head/rules.h"

int main(int argc, char* argv[]){
  bool running=true;
  ResourcesMenu* res=initResMenu();
  displayMenu(res);
  int retour;
  do {
    EventMenu event = waitForMenuEvent(res);
    if (event==PLAY){
      freeMenu(res);
      do{
          retour = gameUI(ALONE);
          SDL_Delay(200);
      }while(retour==2);
      res=initResMenu();
      displayMenu(res);
    }else if (event==BUTTON_F){
      freeMenu(res);
      do{
          retour = gameUI(EASY);
          SDL_Delay(200);
      }while(retour==2);
      res=initResMenu();
      displayMenu(res);
    }else if (event==BUTTON_M){
      freeMenu(res);
      do{
          retour = gameUI(NORMAL);
          SDL_Delay(200);
      }while(retour==2);
      res=initResMenu();
      displayMenu(res);
      res=initResMenu();
    }else if (event==BUTTON_D){
      freeMenu(res);
      do{
          retour = gameUI(HARD);
          SDL_Delay(200);
      }while(retour==2);
      res=initResMenu();
      displayMenu(res);
    }else if (event==RULES){
      freeMenu(res);
      wrapRules();
      res=initResMenu();
      displayMenu(res);
    }else if (event==QUITMENU){
      freeMenu(res);
      running=false;
    }
  }while(running);
  return 0;
}

int oldMain (int argc, char* argv[]){
  //gameUI();
  //playAGameUI(NORMAL);
  char input[20] ;
  int retour;
  printf("Hello World\n");
  printf("Enter cmd (help to get help)\n");
  do{
      printf(">>> ");
      My_gets(input);
      if(strcmp("game",input)==0) {
        if (game() == 1){
          return 0;
        }
      } else if(strcmp("help",input)==0){
          help();
      } else if(strcmp("gameUI",input)==0){
          do{
              retour = gameUI(ALONE);
          }while(retour==2);
          if(retour == 1){
              return 0;
          }
      }else if(strcmp("gameIA",input)==0){
          do{
              retour = gameUI(NORMAL);
          }while(retour==2);
          if(retour == 1){
              return 0;
          }
      } else if(strcmp("exit",input)==0){
        return 0 ;
      } else {
        wrong();
      }
  }while(strcmp("exit",input)!=0);

  return 0;
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
int gameUI(Level level){
    return playAGameUI(level);
}


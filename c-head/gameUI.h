#ifndef __GAME_UI__
#define __GAME_UI__

#include "../c-head/board.h"
#include "../c-head/gui.h"

int playAGameUI();
Status gamePvPUI(Board b, Resources* res);
Coord playerTurnUI(Resources* res, Board* b, Pawn side);

#endif

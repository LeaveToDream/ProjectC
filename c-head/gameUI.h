#ifndef __GAME_UI__
#define __GAME_UI__

#include "../c-head/board.h"
#include "../c-head/gui.h"

int playAGameUI(Level level);
Status gamePvPUI(Board b, Resources* res);
Status gameIAUI(Board b, Resources* res, Level difficulty);
Coord playerTurnUI(Resources* res, Board* b, Pawn side);
Coord IATurnUI(Resources* res, Board* b, Pawn side, Level difficulty);

#endif

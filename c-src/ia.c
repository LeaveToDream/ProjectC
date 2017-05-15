#include <stdio.h>
#include <string.h>

#include "../c-head/Board.h"
#include "../c-head/Game.h"


int value(B){
}

int negamaxAB(Board B,Coord lastMove, int A, int B, int depth){
	if ((resolveGame(B, lastMove) == Bot)||(resolveGame(P, lastMove) == WhitePlayer)||(resolveGame(P, lastMove) == Draw)||(depth == 0)){
		return moveValue(B);
	}
	else
	{
		bestValue = NULL;
		int count = 0;
		State* nextBoards = nextState(B, &count); //penser à mettre dans count le nombre d'éléments
		for (int i = 0; i < count; ++i)
		{
			nextBoard = stateToBoard(nextBoards[i]);
			value = -negamaxAB(nextBoard, lastMove, -B, -A);
			if (bestValue == NULL){
				bestValue == value;
			} else if (value > bestValue) {
				bestValue = value;
				if (bestValue>A){
					A = bestValue;
					if (A>B){
						return bestValue;
					}
				}
			}
		}
		return bestValue;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
#include <stdio.h>
#include <string.h>


int negamaxAB(Board B, Coord lastMove, int A, int B, int depth, int difficulty){
	switch(resolveGame(B, lastMove)){
		case Bot :
			return moveValue(Bot, depth);
		case WhitePlayer :
			return moveValue(WhitePlayer, depth);
		case Draw :
			return moveValue(Draw, depth);
		case Playing :
			if (depth == difficulty){
				return moveValue(Playing, depth);
			}
			bestValue = NULL;
			int count = 0;
			State* nextBoards = nextState(B, &count); //penser à mettre dans count le nombre d'éléments
			for (int i = 0; i < count; ++i)
			{
				nextBoard = stateToBoard(nextBoards[i]);
				value = -negamaxAB(nextBoard, lastMove, -B, -A, depth + 1);
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

int evaluatePawnPotential(Board B){
	return (B.whiteCount - B.balckCount);
}

int moveValue(Board B, Status s, int depth){
    switch(s){
        case Bot :
            return depth - 10;
        case WhitePlayer :
            return 10 - depth;
        case Draw :
            return depth;
        case Playing :
            return (B.whiteCount - B.balckCount);
    }
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
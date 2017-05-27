#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/ia.h"

bool moveIA(Board* b, coord* x, coord* y){
    negamaxAB_IA();
}


int negamaxAB_IA(Board B, infInt A, infInt B, int depth, int difficulty){
    specialInt bestValue, alpha, beta;
    int count, moveValuation;
    alpha.type = A.type;
    alpha.value = A.value;
    beta.type = B.type;
    beta.value = B.value;
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
			bestValue.type = negInf;
			int count = 0;
			State* nextBoards = nextState(B, &count); //penser à mettre dans count le nombre d'éléments
			for (int i = 0; i < count; ++i)
			{
				nextBoard = stateToBoard(nextBoards[i]);
                //TODO faire une fonction qui prend l'inverse d'un infInt
				moveValuation = -negamaxAB(nextBoard, -beta, -alpha, depth + 1);
				if (bestValue.type == negInf){
					bestValue.type = value;
                    bestValue.value = moveValuation;
				} else if (value > bestValue.value) {
					bestValue.value = moveValuation;
                    if (alpha.type == negInf){
                        alpha.type = value;
                        alpha.value = bestValue.value;
                    }
					if (bestValue.value>alpha.value){
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

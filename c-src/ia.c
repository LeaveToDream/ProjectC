#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/ia.h"
#include "../c-head/board.h"

int negamaxAB_IA(Board b, int A, int B, int depth, int difficulty, Pawn color){
    int moveValuation, bestValue, alpha, beta;
    int* count;
    alpha = A;
    beta = B;
	switch(resolveGame(b, lastMove)){
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
			bestValue = -100;
			int count = 0;

            Move listPossibleMove[144];
            initListPossibleMove(&listPossibleMove);
            generateListePossibleMove(&listPossibleMove, b, &count, color);
			for (int i = 0; i < count; ++i)
			{
				Board nextBoard = copyBoard(b);
                movePawn(nextBoard, listPossibleMove[i].from, listPossibleMove[i].to);
				moveValuation = -negamaxAB(nextBoard, -beta, -alpha, depth + 1, difficulty, enemyPawn(couleur));
                if (moveValuation > bestValue){
                    bestValue = moveValuation;
                    if (bestValue > alpha){
                        alpha = bestValue;
                        if (alpha>beta){
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
            return depth - 20;
        case WhitePlayer :
            return 20 - depth;
        case Draw :
            return depth;
        case Playing :
            return (B.whiteCount - B.balckCount);
    }
}

void initListPossibleMove(Move* listPossibleMove){
    Coord empty = initCoord(-1,-1);
    for (int i = 0; i < 144; i++) {
        listPossibleMove[i] = initMove(empty,empty);
    }
}


int generateListePossibleMove(Move* listPossibleMove, Board b, int* count, Pawn color){
    Coord listPawn[9];
    int pawnCount = 0;
    int j;
    for (int i = 0; i < b.length; i++) {
        for (int j = 0; j < b.length; j++) {
            if (b.board[i][j] == color){
                listPawn[pawnCount] = initCoord(i,j);
                pawnCount++;
            }
        }
    }
    if (color == Black){
        if (pawnCount != b.blackCount){
            printf("Erreur compte des pièces");
            return 1;
        }
    }
    if (color == White){
        if (pawnCount != b.whiteCount){
            printf("Erreur compte des pièces");
            return 1;
        }
    }
    for (int k = 0; k < pawnCount; k++) {
        j = 0;
        while (b.possibleMove[listPawn[k].x][listPawn[k].y][j] != initCoord(-1,-1)){
            listPossibleMove[count] = initMove(listPawn[k],b.possibleMove[listPawn[k].x][listPawn[k].y][j]);
            count++;
            j++;
        }
    }
    return 0;
}

Move initMove(Coord c1, Coord c2){
    Move m;
    m.from = c1;
    m.to = c2;
    return m;
}

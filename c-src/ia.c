#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/ia.h"
#include "../c-head/board.h"

ValuedMove negamaxAB_IA(Board b, int A, int B, int depth, int difficulty, Pawn color, Move lastMove){
    int alpha, beta;
    int count = 0;
    ValuedMove bestMove, newMove;
    bestMove.value = -100;
    bestMove.move = initMove(initCoord(-1,-1),initCoord(-1,-1));
    alpha = A;
    beta = B;
	switch(resolveGame(&b)){
		case Bot :
			return initValuedMove(moveValue(b, Bot, depth),lastMove);
		case WhitePlayer :
			return initValuedMove(moveValue(b, WhitePlayer, depth),lastMove);
		case Draw :
			return initValuedMove(moveValue(b, Draw, depth),lastMove);
		case Playing :
			if (depth == difficulty){
				return initValuedMove(moveValue(b, Playing, depth),lastMove);
			}

            Move listPossibleMove[144];
            initListPossibleMove(listPossibleMove);
            generateListePossibleMove(listPossibleMove, b, &count, color);
			for (int i = 0; i < count; ++i)
			{
				Board nextBoard = copyBoard(b);
                movePawn(nextBoard, listPossibleMove[i].from, listPossibleMove[i].to);
                resolveMove(&nextBoard, listPossibleMove[i].to);
				newMove = negamaxAB_IA(nextBoard, -beta, -alpha, depth + 1, difficulty, enemyPawn(color), listPossibleMove[i]);
                freeBoard(nextBoard);
                newMove.value = -newMove.value;
                printf("Valeur du move : %d\n", newMove.value);
                if (newMove.value > bestMove.value){
                    bestMove.value = newMove.value;
                    bestMove.move = listPossibleMove[i];
                    if (bestMove.value > alpha){
                        alpha = bestMove.value;
                        if (alpha>beta){
                            return bestMove;
                        }
                    }
                /*} else if (newMove.value == bestMove.value){
                    for (int j = 0; j < 10; ++j) {
                        double random = rand()/(double)RAND_MAX;
                        printf("%f   ",random);
                    }
                    double random = (rand()/(double)RAND_MAX);
                    if (random>0.95){
                        bestMove.move = listPossibleMove[i];
                    }*/
                }
			}
			return bestMove;
	}
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
            return (B.whiteCount - B.blackCount);
        default:
            exit(0);
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
    int n;
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
            pawnCount = b.whiteCount;
            return 1;
        }
    }
    if (color == White){
        if (pawnCount != b.whiteCount){
            pawnCount = b.whiteCount;
            return 1;
        }
    }
    for (int k = 0; k < pawnCount; k++) {
        n = 0;
        while (!compareCoord(b.possibleMove[listPawn[k].x][listPawn[k].y][n], initCoord(-1,-1))){
            listPossibleMove[*count] = initMove(listPawn[k],b.possibleMove[listPawn[k].x][listPawn[k].y][n]);
            (*count)++;
            n++;
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

ValuedMove initValuedMove(int value, Move move){
    ValuedMove res;
    res.value = value;
    res.move = move;
    return res;
}


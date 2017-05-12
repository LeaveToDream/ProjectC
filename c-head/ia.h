
typedef struct State State ;
struct State {
	Board* board;
	Pawn* blancs;
	Pawn* noir;
};

int main(nt argc, char const *argv[]);
int negamaxAB(Board B,Coord lastMove, int A, int B, int depth);
State boardToState(Board B);
Board stateToBoard(State S);
State[] nextState(Board B);

int value(Board B);
int evaluatePawnPotential(Board B);
int evaluateEnnemyVictory(Board B);
int evaluateVictoryPotential(Baord B);
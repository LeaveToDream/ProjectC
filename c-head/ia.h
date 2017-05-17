
typedef struct State State ;
struct State {
	Board* board;
	Pawn* blancs;
	Pawn* noir;
};

int main(nt argc, char const *argv[]);
int negamaxAB(Board B,Coord lastMove, int A, int B, int depth, int difficulty);

int moveValue(Board B);
int evaluatePawnPotential(Board B);
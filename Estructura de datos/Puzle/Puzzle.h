class Puzzle {
	private:
	  int solvedBoard[10][10];
	public:
	Puzzle();
	
	void printBoard(int[][10], int);
	void initializeBoard(int[][10], int);
	void slideTile(int[][10],int,int);
	bool isBoardSolved(int[][10],int);
	void scrambleBoard(int[][10],int);
};
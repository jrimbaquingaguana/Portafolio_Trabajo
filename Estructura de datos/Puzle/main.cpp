#include "Puzzle.cpp"

using namespace std;

void WaitKey(); 

int main()
{
	int amount=3;

	int gameBoard[10][10];

	Puzzle p1= Puzzle();
	char input;
	string direction;
	bool invalid = false;
	amount--;
	cout<<"\tPuzzle 3x3"<<endl;
	p1.initializeBoard(gameBoard,amount); 
	p1.printBoard(gameBoard,amount); 
	cout << boolalpha;
	cout<<"El puzzle debe quedar de esta manera"<<endl<<endl;
	cout<<"Presione ENTER para empezar..."<<endl;
	WaitKey(); 
	p1.scrambleBoard(gameBoard, amount); 
	cin.get(); 
	system("CLS");

	p1.printBoard(gameBoard,amount);
	cout<<endl<<endl;
	cout<<"Mueva las flechas en la direccion deseada:"<<endl;
	while(!p1.isBoardSolved(gameBoard, amount)) 
	{
		input = _getch();
		system("CLS");

		switch(input)
		{
		case UP:
			p1.slideTile(gameBoard,3,amount);
			direction = "Up";
			break;
		case LEFT:
			p1.slideTile(gameBoard,1,amount);
			direction = "Left";
			break;
		case DOWN:
			p1.slideTile(gameBoard,2,amount);
			direction = "Down";
			break;
		case RIGHT:
			p1.slideTile(gameBoard,0,amount);
			direction = "Right";
			break;
		default:
			invalid = true;

		}
		p1.printBoard(gameBoard,amount);
		cout<<endl<<endl;
		cout<<"Mueva las flechas en la direccion deseada:"<<endl;
		if(invalid)
			invalid = false;
	}
	cout << endl;
	system("CLS");
	p1.printBoard(gameBoard,amount);
	cout << "PUZZLE RESUELTO! FELICIDADES" << endl;
	system("PAUSE");
	return 0;
}

void WaitKey()
{
	while (_kbhit()) _getch();
	_getch();
	while (_kbhit()) _getch();
}
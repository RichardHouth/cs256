//Richard Houth
//CS 256
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
double getPop(double b, double d, double p);
bool declareResult(char ch, char gameBoard[][3]);
bool selectFilledBoard(char gameBoard[][3]);
void printGameBoard(char gameBoard[][3]);
int main() {


	//Chapter 4 programming challenge #23
	int c;
	double pi = 3.14159;
	double r;
	double area;
	double length;
	double width;
	double b;
	double h;
	printf("***GEOMERTRY CALCULATOR***\n");
	printf("1. Calculate area of a circle\n");
	printf("2. Calculate area of a rectangle\n");
	printf("3. Calculate area of a triangle\n");
	printf("4. Quit\n");
	printf("Enter your choice (1-4):");
	scanf("%d", &c);

	switch (c) {
	case 1:

		printf("Enter radius of the circle:");
		scanf("%lf", &r);
		if (r > 0) {
			area = pi * (r * r);
			printf("Area of the circle: %.2f\n", area);
		} else {
			printf("No negative numbers allowed\n");
		}

		break;
	case 2:
		printf("Enter length of rectangle: ");
		scanf("%lf", &length);
		printf("Enter width of rectangle: ");
		scanf("%lf", &width);
		if (length > 0 && width > 0) {
			area = length * width;
			printf("Area of the rectangle: %.2f\n", area);
		} else {
			printf("No negative numbers\n");
		}

		break;

	case 3:
		printf("Enter base of triangle: ");
		scanf("%lf", &b);
		printf("Enter height of triangle: ");
		scanf("%lf", &h);
		if (b > 0 && h > 0) {
			area = b * h * .5;
			printf("Area of the triangle: %.2f\n", area);
		} else {
			printf("No negative numbers\n");
		}

		break;

	case 4:
		printf("Goodbye!\n");
		return 0;

	default:
		printf("Invalid choice");

	}




	//chapter 6 programming challenge #16
	double startingPop, birthRate, deathRate, newPop;
	int numberOfYears;

	printf("Enter starting population size:\n");
	scanf("%lf", &startingPop);

	printf("Enter birth rate:\n");
	scanf("%lf", &birthRate);

	printf("Enter death rate:\n");
	scanf("%lf", &deathRate);

	printf("Enter number of years to display:\n");
	scanf("%d", &numberOfYears);

	printf("Initial population: %.0f\n", startingPop);
	for (int year = 0; year < numberOfYears; year = year + 1){
		newPop = getPop(birthRate, deathRate, startingPop);
		printf("Population at year: %d = %.0f\n", (year + 1), newPop);
		startingPop = newPop;
	}



	//Chapter 7 programming challenge #18
	char game[3][3] =
	{
			{'*','*','*'},{'*','*','*'},{'*','*','*'}
	};

	printf("***Tic tac toe game***\n\n");
	printGameBoard(game);
	printf("\n");

	while(true){
		printf("player 1 enter row number for 'x':");
		int rows;
		scanf("%d", &rows);
		printf("player1 enter column number for 'x':");
		int column;
		scanf("%d", &column);

		if(game[rows][column] == '*'){
			game[rows][column] = 'x';
		}
		printGameBoard(game);

		if (declareResult('x', game)){
			printf("Player 1 won the game\n");
			system("pause");
			exit(0);
		}
		else if (selectFilledBoard(game)){
			printf("TIE\n");
			system("pause");
			exit(0);
		}

		printf("Player 2 enter row number for 'o':");
		scanf("%d", &rows);
		printf("Player 2 enter column number for 'o':");
		scanf("%d", &column);

		if((game[rows][column]) =='*') {
			game[rows][column] = 'o';
		}
		printGameBoard(game);
		if(declareResult('o', game)){
			printf("Player 2 wins\n");
			system("pause");
			exit(0);
		}
		else if (selectFilledBoard(game)) {
			printf("TIE");
			system("pause");
			exit(0);
		}


	}




	return 0;
}




bool declareResult(char ch, char gameBoard[][3]){
	for (int i = 0; i < 3; i = i + 1){
		if (ch == gameBoard[i][0] && ch == gameBoard[i][1] && ch ==gameBoard[i][2]){
			return true;
		}
	}
	for (int j = 0; j < 3; j = j + 1){
		if(ch == gameBoard[0][j] && ch == gameBoard[1][j] && ch == gameBoard[2][j]){
			return true;
		}
	}

	if (ch == gameBoard[0][0] && ch == gameBoard[1][1] && ch == gameBoard[2][2]) {
		return true;
	}

	if(ch == gameBoard [0][2] && ch == gameBoard[1][1] && ch == gameBoard[2][0]){
		return true;
	}
	return false;
}

bool selectFilledBoard(char gameBoard[][3]){
	for(int i = 0; i < 3; i = i + 1){
		for (int j = 0; j < 3; j = j + 1){
			if (gameBoard[i][j] == '*'){
				return false;
			}
		}
	}
	return true;
}

void printGameBoard(char gameBoard[][3]){
	printf("----------\n");
	for (int i = 0; i < 3; i = i + 1){
		printf("|");
		for(int j = 0; j < 3; j = j + 1){
			printf(" %c|", gameBoard[i][j]);
		}
		printf("\n----------\n");
	}
}



double getPop(double b, double d, double p){
	double newPop;
	newPop = p + (b*p) - (d*p);
	return newPop;
}


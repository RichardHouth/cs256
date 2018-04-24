/*
 * TheaterSeating.c
 *
 *  Created on: Apr 19, 2018
 *      Author: richardhouth
 */

#include <stdio.h>

int rows = 15;
int columns = 30;

void printSeats(char array[rows][columns]);

int main() {
	char arrayChart[rows][columns];
	double prices[rows];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arrayChart[i][j] = '#';
		}
	}

	for (int i = 0; i < rows; i++) {
		printf("Enter the seat prices for row %i: ", i + 1);
		scanf("%lf", &prices[i]);
	}

	int loop = 0;
	int user, row, column, column2;
	double total = 0;
	int seatCount = 0;
	double completeTotal = 0;

	while (loop == 0) {
		printSeats(arrayChart);

		printf("Movie theater menu.\n");
		printf("1. Buy ticket\n");
		printf("2. Check how many seats have been sold\n");
		printf("3. Check how many seats are available in each row\n");
		printf("4. Check how many seats are available in the theater\n");
		printf("5. View total of all ticket sales\n");
		printf("6. Exit\n\n");
		printf("Please choose an option: ");
		scanf("%d", &user);

		switch (user) {
		case 1:
			do {

				printf("Enter row #: ");
				scanf("%i", &row);

				if (row < 1 || row > 15) {
					printf("Invalid input.\n");
					break;
				}

				printf("Enter column #: ");
				scanf("%i", &column);

				if (column < 0 || column > 9) {
					printf("Invalid input.\n");
					break;
				}

				printf("Which column %i", column);
				printf(" to pick? Please enter 1, 2 or 3: ");
				scanf("%i", &column2);

				if (column2 < 1 || column2 > 3) {
					printf("Invalid input. Enter 1, 2 or 3.\n");
					break;
				}

				if (arrayChart[row - 1][column + ((column2 - 1) * 10)] == '#') //the seat is available
						{
					printf(
							"Ticket cost $%.2f. Do you want to buy?  1 = yes, 0 = no. ",
							prices[row - 1]);
					scanf("%i", &user);

					if (user == '0') {
						break;
					} else {
						arrayChart[row - 1][column + ((column2 - 1) * 10)] =
								'*';
						total += prices[row - 1];
						completeTotal += prices[row - 1];
						printf(
								"Thanks for buying a ticket. Current bill is $%.2f. Buy another? 0 = no, 1 = yes ",
								total);
						scanf("%i", &user);
					}
				} else {
					printf("The seat is already taken.\n");
				}
			} while (user == 1);
			total = 0;

			break;

		case 2:
			printf("\nNumber of seats sold: ");
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					if (arrayChart[r][c] == '*') {
						seatCount++;
					}
				}
			}
			printf("%i\n", seatCount);
			seatCount = 0;
			break;

		case 3:
			printf("\nNumber of seats available in each row:\n\n");

			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					if (c == 0 && r < 9) {
						printf("Row %i:  ", r + 1);
					} else if (c == 0 && r >= 9) {
						printf("Row %i: ", r + 1);
					}

					if (arrayChart[r][c] == '#') {
						seatCount++;
					}
				}
				printf("%i\n", seatCount);
				seatCount = 0;
			}

			break;

		case 4:
			printf("\nNumber of seats available in the theater: ");

			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					if (arrayChart[r][c] == '#') {
						seatCount++;
					}
				}
			}

			printf("%i\n", seatCount);
			seatCount = 0;
			break;

		case 5:
			printf("\nTotal of all ticket sold: $%.2lf\n", completeTotal);
			break;

		case 6:
			printf("Thank you, come again!");
			loop = 1;
			break;

		default:
			printf("Invalid input.\n");
			break;
		}
	}

	return 0;
}

void printSeats(char array[rows][columns]) {
	printf("\n\t\t\tSEATS\n");
	printf("        012345678901234567890123456789\n");

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			if (c == 0) {
				printf("Row %i\t", r + 1);
			}
			printf("%c", array[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

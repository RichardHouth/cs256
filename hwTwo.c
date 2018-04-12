/*
 * hwk2.c
 *
 *  Created on: Apr 11, 2018
 *      Author: richardhouth
 */

#include <stdio.h>

int main () {

	//chapter 2 programming challenge #4

	double meal = 88.67;
	double tax = meal * 0.0675;
	double afterTax = meal + tax;
	double tip = afterTax * .20;
	double total;

	total = meal + tax + tip;
	printf("Chapter 2 programming challenge #4\n\n");
	printf("Cost of meal: $%.2f\n", meal);
	printf("Tax amount: $%.2f\n", tax);
	printf("Tip amount: $%.2f\n", tip);
	printf("Your total is: $%.2f\n", total);


	//chapter 2 programming challenge #7

	double ocean = 1.5;
	double ocean5 = ocean * 5;
	double ocean7 = ocean * 7;
	double ocean10 = ocean * 10;
	printf("\n");
	printf("chapter 2 programming challenge #7\n\n");
	printf("Current ocean level: %.2f millimeters\n", ocean);
	printf("Ocean level in 5 years: %.2f millimeters\n", ocean5);
	printf("Ocean level in 7 years: %.2f millimeters\n", ocean7);
	printf("Ocean level in 10 years: %.2f millimeters\n", ocean10);
	printf("\n");


	//chapter 3 programming challenge #23

	double amountPaid = 1000 * 45.50;
	double brokerPay = amountPaid * .02;
	double amountSold = 1000 * 56.90;
	double brokerSold = amountSold * .02;
	double profit = (amountSold - amountPaid) - (brokerPay + brokerSold);
	printf("chapter 3 programming challenge #23\n\n");
	printf("Joe bought the stock for: $%.2f\n", amountPaid);
	printf("His broker was paid: $%.2f\n", brokerPay);
	printf("Joe sold his stock for: $%.2f\n", amountSold);
	printf("After selling, broker got paid: $%.2f\n", brokerSold);
	printf("Joe's profit is: $%.2f\n", profit);

	printf("\n");


	//chapter 5 programming challenge #23

	int i, j;
	int rows = 10;

	printf("chapter 5 programming challenge #23\n\n");
	printf("Pattern A\n");
	    for(i=1; i<=rows; i = i + 1)
	    {
	        for(j=1; j<=i; j = j + 1)
	        {
	            printf("+ ");
	        }
	        printf("\n");
	    }

	 printf("Pattern B\n");
	 	for(i = rows; i >= 1; i = i - 1)
	 	{
	 		for(j = 1; j <= i; j = j + 1)
	 		{
	 			printf("+ ");
	 		}
	 		printf("\n");
	 	}
	return 0;
}

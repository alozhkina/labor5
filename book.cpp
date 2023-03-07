#define _CRT_SECURE_NO_WARNINGS
#include "book.h"
#include <iostream>
///////////////////////////////////////////////////


const char* Ñategorystr[] = { "êëàññèêà", "ðàññêàçû", "íàó÷íàÿ ôàíòàñòèêà ", "óæàñû"};
void printBOOK(const BOOK& book) {
	printf("\nAbout book:\n");
	printf("%s \nauthor: %s\ncategory: %s\nyear release: %d\nprice: %.2lf RUB.\n", book.title, book.author, Ñategorystr[book.category], book.year, book.price);
	printf("\n ");
}//âíèìàíèå íà ññûëêó è óàçàòåëü
void printBOOK(const BOOK* book) {
	printf("\nAbout book:\n");
	printf("%s \nauthor: %s\ncategory: %s\nyear release: %d\nprice: %.2lf RUB.\n", (*book).title, book->author, Ñategorystr[book->category], book->year, book->price);
	printf("\n");
}
void formBOOK(BOOK& book) {
	char title[100];
	printf("Title: ");
	while (getchar() != '\n');
	scanf("%100[^\n]", title);
	strcpy_s(book.title, 100, title);
	
	char author[80];
	printf("Author: ");
	while (getchar() != '\n');
	scanf("%80[^\n]", author);
	strcpy_s(book.author, 80, author);

	double price = 0.0;
	printf("Price: ");
	while (true) {
		while (getchar() != '\n');
		scanf("%lf", &price);
		if (price < 0)
			printf(" Incorrect price, try again \n");
		else {
			book.price = price;
			break;
		}
	}

	int y=0;
	printf("Enter year:");
	while (true) {
		while (getchar() != '\n');//ïîëó÷àåì ñèìâîë
		scanf("%d", &y);
		if (y < 1445 || y > 2022) {
			printf("Incorrect year, try again ");
			continue;
		}
		else {
			book.year = y;
			break;
		}

	}

	int a = 0;
	const char* Ñategorystr[] = { "classics", "Short_stories", "science_fiction ", "horror" };
	printf("Choose number of category\n");
	printf("1.classics, 2.Short_stories, 3.science_fiction, 4.horror\n");
	fflush(stdin);
	while (true) {
		scanf("%i", &a);
		if (a < 1 || a>4) {
			printf("Incorrect category, try again ");
			continue;
		}
		else {
			book.category = static_cast<bCategory>(a - 1);
			break;
		}
	}

}
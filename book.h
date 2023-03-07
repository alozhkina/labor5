
//Прототипы используемых в данном задании функций:


enum bCategory {
	Short_stories,
	horror,
    science_fiction 
};

struct BOOK {
	char author[80];
	char title[100];
	int year;
	double price;
	bCategory category;
};
void printBOOK(const BOOK& book);
void printBOOK(const BOOK* book);
void formBOOK(BOOK& book);
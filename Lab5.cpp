
/*************************************************************
	������������ ������� �5. 
	"������" ��������� ������� ����������� ����������
	��������� �� �������
	���������
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include "other.h"
#include <cmath>;
#include "vld.h"

#define	  stop __asm nop
Book globalBook;
int _tmain()
{
	//���� "������" ��������� ������� ����������� ����������
	//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
	{
		printf("#1\n");
		double A, B, C;
		printf("Enter A: ");
		scanf(" %lf", &A);
		fflush(stdin);
		printf("Enter B: ");
		scanf(" %lf", &B);
		fflush(stdin);
		printf("Enter C: ");
		scanf(" %lf", &C);
		fflush(stdin);
		printf("\n");
		//������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
		//��� ��������� x � ��������� -2 �� +2 � ����� 0.5
		printf("#2\n");
		printf("________________\n");
		printf("|  x  |   f(x) |\n");
		printf("|_____|________|\n");
		for (double x = -2.0; x < 2.01; x += 0.5) {
			printf("|%4.1lf |%8.2lf|\n", x, (A * x * x + B * x + C));
			printf("|_____|________|\n");
		}
		printf("\n");
	}

	///////////////////////////////////////////////////////////////////
		//���� ��������� �� �������

		//������� 1. ��������� �� �������. "�����������".
		//�������� �������:
		//1)Sum - ��������� ��� �������� double � ���������� �����
		//���� ��������
		//2)Sub- ��������� ��� �������� double � ���������� ��������
		//���� ��������
		//3)Mul - *
		//4)Div - /
		//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
		//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
		//		��������� 2: ����������� ���������� ������������� ��������� �������������
		//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
		//		double pow(double, double);

		//������������ ������������	��������� �����������:
		//���� ������������ ����� ������������ �������� ������ ������������,
		//�� ����� ������� ��� �������� � ���� ��������
		//� �� �������� ���������. ��������� ��������� ����������� ������
		//��������������� ����� ������� �� ���������.
		//������������� ����������� ����� ������������������ ����� ��������
	{
		printf("#2.1\n");
		printf("PERFECT CALCULATOR\n you can use operation: + / * ^ -\n");
		printf("if you want stop - enter !, if you want continue - enter smt\n");
		char operation=0;
		double x, y;
		bool cont = true;
		double (*function)(double x, double y);

		while (true) {
			if (!cont) break;
			printf("\n Enter number then operation then number ");
			scanf("%lf %c %lf", &x, &operation, &y);
			fflush(stdin);
			double (*function)(double x, double y);

			switch (operation) {
			case '+': function = Sum; break;
			case '-': function = Sub; break;
			case '*': function = Mul; break;
			case '/': function = Div; break;
			case '^': function = pow; break;
			default: function = 0;
			}

			if (function) {
				printf(" = %.2lf", function(x, y));
			}
			else {
				printf("error");
			}
			char t=0;
			scanf("%c", &t);
			fflush(stdin);
			if (t == '!') {
				cont = false;
				break;
			}
			else continue;//��������� ���� �������� (� �����), ���� ��������� ��������� �������, � ���������� ��������� �������� � �����
	    }
   }stop
		


		//������� 2. ��������� �� ������� � �������� ���������.
		//���� ��������� ������� ���������� ����� �������� - Sort.
		//������� ��������� ��������� ���������:
		//1) ��������� �� ������ ����������� �������
		//2) ���������� ����������� ���������
		//3) ������ �������� � ������
		//4) ��������� �� ������� ������������ ���������
		//5) ��������� �� ������� ��������� ���������

		//2a. �������� ������� ������������ ���� ����� �������� -
		// SwapInt, ������� ��������� ��� void ��������� � 
		//������ �������� �������

		//�������� ������� ��������� ���� ����� �������� -
		// CmpInt, ������� ��������� ��� void ��������� �
		//���������� int ��������� ���������: 
		//<0 - ������ ������� ������, ��� ������
		//=0 - �����
		//>0 - ������ ������� ������, ��� ������
	{printf("\n#2.2a\n");
	const int N = 10;
	int nAr[N];
	fullarr(nAr, N);	//������ ��� ����������

	//������ ��������� �������
	printf("\nbefore:\n");
	printarr(nAr, N);


	//����� ����������
	int nTotal = N;		//���������� ��������� � ������� 
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

	//������ ����������� ����������
	printf("\nafter:\n");
	printarr(nAr, N);
	stop
	}

	//������� 2�. �� �������� � 8� �������� ���������������
	//������� - SwapDouble � CmpDouble � �������� ������� Sort
	//��� ���������� ������� ������������ ��������.
	{
		printf("\n#2.2b\n");
		const int N = 10;
		double nAr[N];
		fullarr(nAr, N);
		printf("\nbefore:\n");
		printarr(nAr, N);
		int nTotal = N;
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(double), SwapDouble, CmpDouble);
		printf("\nafter:\n");
		printarr(nAr, N);
		stop
	}

	//������� 2�*. �� �������� � 8� �������� ���������������
	//������� - SwapStr � CmpStr � �������� ������� Sort 
	//��� ���������� ������� ���������� �� ������.
	{ 
		printf("\n#2.2v\n");
		char const* arStr[] = { "WWW", "SDF", "ABC"};
		int N = sizeof(arStr) / sizeof(arStr[0]);
		int nTotal = N;
		printf("\nbefore:\n");
		printarr(arStr, N);
		Sort(reinterpret_cast<char*>(&arStr[0]), nTotal, sizeof(const char*), Swapstr, Cmpstr);
		printf("\nafter:\n");
		printarr(arStr, N);
		stop
	}


	//������� 3. ������� ���������� �� �������.
	//�������� ��������� ������� ����
	//const char* GetString1();
	//const char* GetString2();
	//		...., ������ �� ������� ���������� ��������� �� ���� ������
	//(��������� - ����� ����� �� ������ ����� ���������� �� �������)


	//�������� � ������������������ ������ ���������� �� �������
	//GetString1,GetString2...
	{ 
		printf("\n#2.3\n");
		const char* (*funcgetstr[])() = { getstr1, getstr2, getstr3, getstr4 };


		//������� ����� �������, ������� �� ������ �������:
		int n;
		std::cout << "Please, enter number of string, max number = "<< sizeof(funcgetstr) / sizeof(funcgetstr[0]) << std::endl;
		std::cin >> n;
		while (n > sizeof(funcgetstr) / sizeof(funcgetstr[0]) || n < 1)
		{
			std::cout << "incorrect value, try again" << std::endl;
			std::cin >> n;
		}
		/*if (n > sizeof(funcgetstr) / sizeof(funcgetstr[0])) {
			std::cout << "Too big number, try again" << std::endl;
			std::cin >> n;
		}
		if (n<1) {
			std::cout << "Too small number, try again" << std::endl;
			std::cin >> n;
		}*/
		//�������� ������� 
		const char* str = (*funcgetstr[n-1])();
		//������������ ���������
		std::cout << str << std::endl;
		std::cout << std::endl;

    }



//////////////////////////////////////////////////////////////////////////////////////

	//����. ��������� �.	
	//������� 1. �������� ��������� BOOK, ����������� �����
	//(�����, ��������, ��� �������, ����, ����������).
	//���������: ������ ���� ����� ���� ���� ���������.
	//���������: ���������� ��������� ������������� ��������
	//� ������������ ����.

	// ����� � �������� ������ char, ��� int, ���� double, ��������� enum category 


	//������� 2. �������� ������� ��������� (����������, ���������, �����������,
	//������������) ���������� (�������) ���� BOOK (��� �������������).
	//���������� - ������� ������ ������� ���������� ��� ������
	//����� ������. ��� ���������������� (��� �� ����������������) ����
	//���������. ���������: �� ���� ������� ����� ���������� ������?
	{
		// ���������� �������� � ������
		Book localBook;
		static Book staticBook;
		Book* dynamicBook = new Book();

		{
			printf("\n#3.2\n");
			std::cout << "Global book size: " << sizeof(globalBook) << " bytes;" << std::endl;
			std::cout << "Local book size: " << sizeof(localBook) << " bytes;" << std::endl;
			std::cout << "Static book size: " << sizeof(staticBook) << " bytes;" << std::endl;
			std::cout << "Dynamic book size: " << sizeof(*dynamicBook) << " bytes;" << std::endl;
			std::cout << std::endl;
		}
		//������� ����������� �� ������ �� ������, ���������� ���������� ��� ����������� ���������� ������ � ��������
		//����� ������������ ���������� ������ ��������� ������� �� : �������������� ������������ ����������� �����������; ����� ��������� ������ �����������.
		//� ����� ������ ������ ������� ������������� � ���, ������� ������ ����� �������� ��� ����������� ���������� � � ����� ��������� ������ �����
		//������������� ������������ ������ ����������� ���������� 
		
		//(�������������� �������+������ ����� ������)

		//������� 3. ��������� ���� ��������� ��������.
		//���������: ���� ��� �������� ������ ������������ ������, ����������
		//������������� "������" �� ������ �� ������� �������.
		strcpy_s(globalBook.author, 80, "Arkady and Boris Strugatsky");
		strcpy_s(globalBook.title, 100, "Roadside Picnic");
		globalBook.year = 1972;
		globalBook.price = 349.99;
		globalBook.category = science_fiction;

		strcpy_s(localBook.author, 80, "H. P. Lovecraft");
		strcpy_s(localBook.title, 100, "At the Mountains of Madness");
		localBook.year = 1936;
		localBook.price = 441.50;
		localBook.category = horror;

		strcpy_s(staticBook.author, 80, "J. D. Salinger");
		strcpy_s(staticBook.title, 100, "Nine Stories");
		staticBook.year = 1953;
		staticBook.price = 254.90;
		staticBook.category = Short_stories;

		strcpy_s(dynamicBook->author, 80, "Edgar Allan Poe");
		strcpy_s(dynamicBook->title, 100, "The Black Cat");
		(* dynamicBook).year = 1843;
		dynamicBook->price = 659.99;
		dynamicBook->category = horror;


		//������� 4. �������� �������, ��������� �� ����� ��������� �����.
		//���������: ��� ����������� ���������� ��������� BOOK � �������.
		//��� ������ �� ������� ����������� ������� ����������� ����������
		//printf
		printf("\n#3.4\n");
		printBook(globalBook);
		printBook(localBook);
		printBook(staticBook);
		printBook(*dynamicBook);
		delete[] dynamicBook;


		//������� 5. �������� ������� ��� ������������ ����� ���������.
		//��� ����� ����������� ������� ����������� ���������� scanf
		//���������: ������� �������� � ����� ������� ����������� ��������
		//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
		//�����, ���... (��� ��������� ������������), ��������� �����������
		//������ �������� �� ������������, ���� �� ����� ���� �������������...
		printf("\n#3.5\n");
		Book newBook;
		formBook(newBook);
		printBook(newBook);
		return 0;
	}
	return 0;
}//main


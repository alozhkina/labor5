
/*************************************************************
	Практическое занятие №5. 
	"Старые" потоковые функции стандартной библиотеки
	Указатели на функции
	Структуры
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
	//Тема "Старые" потоковые функции стандартной библиотеки
	//Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C
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
		//Задание 2. Выведите (красиво!) таблицу значений y=A*x*x + B*x + C
		//при изменении x в диапазоне -2 до +2 с шагом 0.5
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
		//Тема Указатели на функции

		//Задание 1. Указатель на функцию. "Калькулятор".
		//Напишите функции:
		//1)Sum - принимает два значения double и возвращает сумму
		//этих значений
		//2)Sub- принимает два значения double и возвращает разность
		//этих значений
		//3)Mul - *
		//4)Div - /
		//5)а для возведения в степень можете использовать функцию стандартной библиотеки
		//		- pow(). Подсказка 1: прототип функции находится в <cmath>.
		//		Подсказка 2: стандартная библиотека предоставляет несколько перегруженных
		//		вариантов этой функции, а Вам потребуется сформировать указатель на 
		//		double pow(double, double);

		//Предоставьте пользователю	следующую возможность:
		//пока пользователь хочет пользоваться услугами Вашего калькулятора,
		//он может вводить два значения и знак операции
		//а Вы выводите результат. Результат получаете посредством вызова
		//соответствующей Вашей функции по указателю.
		//Предусмотрите возможность ввода непредусмотренного знака операции
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
			else continue;//прерывает одну итерацию (в цикле), если возникает указанное условие, и продолжает следующую итерацию в цикле
	    }
   }stop
		


		//Задание 2. Указатель на функцию в качестве аргумента.
		//Дана заготовка функции сортировки любых объектов - Sort.
		//Функция принимает следующие параметры:
		//1) указатель на первый сортируемый элемент
		//2) количество сортируемых элементов
		//3) размер элемента в байтах
		//4) указатель на функцию перестановки элементов
		//5) указатель на функцию сравнения элементов

		//2a. Напишите функцию перестановки двух целых значений -
		// SwapInt, которая принимает два void указателя и 
		//меняет значения местами

		//Напишите функцию сравнения двух целых значений -
		// CmpInt, которая принимает два void указателя и
		//возвращает int результат сравнения: 
		//<0 - первый элемент меньше, чем второй
		//=0 - равны
		//>0 - первый элемент больше, чем второй
	{printf("\n#2.2a\n");
	const int N = 10;
	int nAr[N];
	fullarr(nAr, N);	//массив для сортировки

	//Печать исходного массива
	printf("\nbefore:\n");
	printarr(nAr, N);


	//Вызов сортировки
	int nTotal = N;		//количество элементов в массиве 
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

	//Печать результатов сортировки
	printf("\nafter:\n");
	printarr(nAr, N);
	stop
	}

	//Задание 2б. По аналогии с 8а создайте вспомогательные
	//функции - SwapDouble и CmpDouble и вызовите функцию Sort
	//для сортировки массива вещественных значений.
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

	//Задание 2в*. По аналогии с 8а создайте вспомогательные
	//функции - SwapStr и CmpStr и вызовите функцию Sort 
	//для сортировки массива указателей на строки.
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


	//Задание 3. Массивы указателей на функцию.
	//Напишите несколько функций вида
	//const char* GetString1();
	//const char* GetString2();
	//		...., каждая из функций возвращает указатель на свою строку
	//(подумайте - какой адрес Вы имеете право возвращать из функции)


	//Объявите и проинициализируйте массив указателей на функции
	//GetString1,GetString2...
	{ 
		printf("\n#2.3\n");
		const char* (*funcgetstr[])() = { getstr1, getstr2, getstr3, getstr4 };


		//Введите номер функции, которую Вы хотите вызвать:
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
		//Вызовите функцию 
		const char* str = (*funcgetstr[n-1])();
		//Распечатайте результат
		std::cout << str << std::endl;
		std::cout << std::endl;

    }



//////////////////////////////////////////////////////////////////////////////////////

	//Тема. Структуры С.	
	//Задание 1. Объявите структуру BOOK, описывающую книгу
	//(автор, заглавие, год издания, цена, категория…).
	//Подумайте: какого типа могут быть поля структуры.
	//Подсказка: объявление структуры рекомендуется выносить
	//в заголовочный файл.

	// автор и заглавие массив char, год int, цена double, категория enum category 


	//Задание 2. Создайте разными способами (глобальный, локальный, статический,
	//динамический) экземпляры (объекты) типа BOOK (без инициализации).
	//Определите - сколько памяти отводит компилятор под каждый
	//такой объект. Как инициализируются (или не инициализируются) поля
	//структуры. Подумайте: от чего зависит объем выделяемой памяти?
	{
		// глобальную объявили в начале
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
		//область определения не влияет на размер, Количество выделяемой для структурной переменной памяти и смещения
		//полей относительно начального адреса структуры зависят от : оптимизирующих возможностей конкретного компилятора; опций командной строки компилятору.
		//В общем случае трудно сделать предположение о том, сколько памяти будет выделено под структурную переменную и с каким смещением данные будут
		//располагаться относительно начала структурной переменной 
		
		//(неиспользуемые резервы+азмеры типов данных)

		//Задание 3. Заполните поля созданных объектов.
		//Замечание: если для хранения строки используется массив, необходимо
		//предусмотреть "защиту" от выхода за границы массива.
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


		//Задание 4. Напишите функцию, выводящую на экран реквизиты книги.
		//Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
		//Для вывода на консоль используйте функцию стандартной библиотеки
		//printf
		printf("\n#3.4\n");
		printBook(globalBook);
		printBook(localBook);
		printBook(staticBook);
		printBook(*dynamicBook);
		delete[] dynamicBook;


		//Задание 5. Напишите функцию для формирования полей структуры.
		//Для ввода используйте функцию стандартной библиотеки scanf
		//Замечание: неплохо заложить в такую функцию возможность проверки
		//корректности введенного значения, например, год издания не может быть
		//меьше, чем... (год появления письменности), категорию ползователь
		//должен выбирать из существующих, цена не может быть отрицательной...
		printf("\n#3.5\n");
		Book newBook;
		formBook(newBook);
		printBook(newBook);
		return 0;
	}
	return 0;
}//main


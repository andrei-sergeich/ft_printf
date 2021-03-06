#include <stdio.h> //Для printf,fflush 

int	main(void)
{
	printf ("1. Вывод простой строки\n");
	printf ("\n2. Вывод целых чисел\n");
	printf ("2.1 Вывод числа 123 с форматом по умолчанию:\n");
	{
		int	d1;

		d1 = 123;
		printf ("%d\n", d1);
	}
	printf ("\n2.2 Вывод чисел c выравниванием по правому краю:\n");
	{
		int	d1 = 123, d2 = 42, d3 = 1543;
		printf ("%6d\n%6d\n%6d\n", d1, d2, d3);
	}
	printf ("\n2.3 Вывод чисел c выравниванием по левому краю:\n");
	{
		int d1 = 123, d2 = 42, d3 = 1543;
		printf ("%-6d\n%-6d\n%-6d\n", d1, d2, d3);
	}
	printf ("\n2.4 Вывод числа с выводом 0 в недостающих символах:\n");
	{
		int d1 = -123;
		printf ("%06d\n", d1);
	}
	printf ("\n2.5 Вывод числа 123 с заданной шириной 6 символов:\n");
	{
		int d1 = 123;
		printf ("%6d\n", d1);
	}
	printf ("\n2.6 Вывод числа 123 с заданной точностью 6 символов:\n");
	{
		int d1 = 123;
		printf ("%.6d\n", d1);
	}
	printf ("\n2.7 Вывод числа типа char:\n");
	{
		char d1 = 123;
		printf ("%hhd\n", d1);
	}
	printf ("\n2.8 Вывод числа типа short int:\n");
	{
		short int d1 = 123;
		printf ("%hd\n", d1);
	}
	printf ("\n2.9 Вывод числа типа long int:\n");
	{
		long int d1 = 123;
		printf ("%ld\n", d1);
	}
	printf ("\n2.10 Вывод числа типа long long int:\n");
	{
		long long int d1 = 123;
		printf ("%lld\n", d1);
	}
	printf ("\n2.11 Вывод целого без знакового числа:\n");
	{
		unsigned int d1 = 123;
		printf ("%u\n", d1);
	}
	printf ("\n2.12 Вывод целого числа в восьмеричном формате:\n");
	{
		unsigned int d1 = 123;
		printf ("%o\n", d1);
	}
	printf ("\n2.13 Вывод целого числа в шестнадцатеричном формате:\n");
	{
		unsigned int d1 = 123;
		printf ("%x\n", d1);
	}
	printf ("\n2.14 Вывод целого числа в шестнадцатеричном формате:\n");
	{
		unsigned int d1=123;
		printf ("%#x\n", d1);
	}
	printf ("\n3. Вывод чисел c плавающей точкой\n");
	printf ("3.1 Вывод числа 123.456 с форматом по умолчанию:\n");
	{
		double d1 = 123.456;
		printf ("%f\n", d1);
	}
	printf ("\n3.2 Вывод числа 123.456 с точностью 2:\n");
	{
		double d1 = 123.456;
		printf ("%.2f\n", d1);
	}
	printf ("\n3.3 Вывод числа 123.456 в экспоненциальной форме:\n");
	{
		double d1 = 123.456;
		printf ("%e\n", d1);
	}
	printf ("\n3.4 Использование преобразователя g:\n");
	{
		double d1 = 123.4567, d2 = 1234567.34567;
		printf ("%g\n%g\n", d1, d2);
	}
	printf ("\n3.5 Вывод числа 123.456 в шестнадцатеричной форме:\n");
	{
		double d1 = 123.456;
		printf ("%a\n", d1);
	}
	printf ("\n4. Вывод символа 'k':\n");
	{
		char d1 = 'k';
		printf ("%c\n", d1);
	}
	printf ("\n5. Вывод строки 'abc':\n");
	{
		char d1[4] = "abc";
		printf ("%s\n", d1);
	}
	printf ("\n6. Вывод указателя:\n");
	{
		char d1[4] = "abc";
		printf ("%p\n", d1);
	}
	printf ("\n7. Подсчет выведенных символов:\n");
	{
		int d1 = 0;
		fflush (stdout);
		printf ("Derived characters:%n", &d1);
		printf (" %d\n", d1);
	}

	//Принудительный вывод строки не дожидаясь заполнения буфера
	printf ("\n6. Вывод буферизированной строки\n");
	{
		char d1[4] = "abc";
		printf ("%s", d1);
		fflush (stdout);
	}
	return (0);
}

﻿
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <atlmem.h>
char* fgets(char* st, int dl, FILE s);
int chisl(char s)
{
	int i,ch = 0;
	char st[11] = "0123456789";
	for (i = 0; i < 10; i++)
		if (s == st[i])
			ch = 1;
	return ch;
}
int main()
{
	int n, i, j, k=0;
	char* st = (char*)calloc(51, sizeof(char));
	fgets(st, 51, stdin);
	puts(st);
	for (n = 0; st[n] != '\0'; n++);
	for (int i = 0; i < n; i++)
		if((st[i]=='a')&&(st[i+1]=='+')&&(st[i+2]=='w'))
			k++;
	for (int i = 0; i < n; i++)
		if ((st[i] == '*') && chisl(st[i+1])){
			n++;	
			for (j = n; j >i; j--)
				st[j+1] = st[j];
				st[i+1] = ' ';
		}
	printf("\nst= ");
		puts(st);
		printf("kolvo w posle a+ =%d",k);
		return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

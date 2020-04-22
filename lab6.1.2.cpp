// lab6.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <memory.h>
#include<string.h>
/*char* fgets(char* st, int dl, FILE s);
char* strstr(char* s1, char* s2);
char* strcat(char* s1, char* s2,int n);*/
int main()
{
	int n,n3=0,kol=0, k = 0,n2=0,z=0,n1=1;
	char* st1, * st2;
	st1 = (char*)calloc(535, sizeof(char));
	st2 = (char*)calloc(51, sizeof(char));
	char* st = (char*)calloc(51,sizeof(char));
	char s[51],s1[53]="",s2[51]="0123456789";
	fgets(s, 50, stdin);
	puts(s);
	char* r = s;
	n = strlen(s);
	while ((r = strchr(r, '-')) != NULL) {
		if (*(r + 1) == '+') {
			strcpy_s(s1, r + 2);
			*(s + (r + 1 - s)) = '\0';
			strcat_s(s, s1);
		}
		r++;
	}
	printf("\nrrrr\n");
	puts(s);
	/*while ( k<n) {
		n2 = -1; 
		n1 = strcspn(s+k,"*");
		k += n1 + 1;
		n2 = strcspn(s + k, s2);
		if (n2 == 0) {
			z++;
			if (k != n + z) {
				strncpy_s(s1, s, k);
				//*(s1 + n1) = '\0';
				puts(s1);
				strcat_s(s1, " ");
				strcat_s(s1, s + k);
				puts(s1);
				strcpy_s(s, s1);
			}
		}
	}
	puts(s);
	k = 0;
	while (k < n) {
		n2 = -1;
		n1 = strcspn(s + k, "a");
		k += n1 + 1;
		n2 = strcspn(s + k, "+");
		n3= strcspn(s + k, "w");
		if (n2 == 0) {
			if (n3 == 1)
				kol++;
		}
	}
	std::cout << "kol="<<kol << std::endl;
	std::cout << "hello";*/
	/*for (int i = 0; i < n; i++)
		if ((st[i] == 'a') && (st[i + 1] == '+') && (st[i + 2] == 'w'))
			k++;
	for (int i = 0; i < n; i++)
		if ((st[i] == '*') && chisl(st[i + 1])) {
			n++;
			for (j = n; j > i; j--)
				st[j + 1] = st[j];
			st[i + 1] = ' ';
		}
	printf("\nst= ");
	puts(st);
	printf("kolvo w posle a+ =%d", k);*/
	return 0;
}

// Запуск  программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

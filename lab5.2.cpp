// lab5.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <conio.h>
#include<callobj.h>
int n_otr(int, int);
int n_max(int, int);
int obr(int, int, int);
int n_otr(int n, int* a)
{
	int n_ot;
	n_ot = -1;
	for (int i = 0; i < n; i++)
	if (a[i] < 0)
	{
		n_ot = i;
		break;
	}
	return n_ot;
}
int n_max(int no, int* a)
{
	int n_mx, max;
	n_mx =  no - 1;
	max = a[n_mx];
	for (int i = no - 1; i >= 0; i--)
		if (max <= a[i])
		{
			max = a[i];
			n_mx = i;
		}
	return n_mx;
}
int obr(int n, int* a, int* b)
{
	int f = 0, jp;
	for (int i = 1, j = 0; i < n; i += 2, j++)
	{
		b[j] = a[i];
		jp = j;
	}
	for (int i = 0, j = jp+1; i < n; i += 2, j++)
		b[j] = a[i];
	for (int i = 0; i < n; i++)
	{
		if (b[i] != a[i])
		{
			f = 1;
			break;
		}
	}
	return f;
}
int main()
{
	int n, i, j,  *a, *b,no,nm, f = 0, max;
	a =  (int*)calloc(15, sizeof(int));
	b = (int*)calloc(15, sizeof(int));
	printf(" vvedite n\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("a[%d]=", i);
		scanf_s("\n%d", &a[i]);
	}
	no = n_otr(n, a);
	if (no == -1)
	{
		printf("net otr elem\n");
	}
	else
	{
		printf("nomer otr elem = %d\n", no);
		if (no == 0)
		{
			printf("net max elem raspoloz do otr\n");
		}
		else
		{
			nm=n_max(no, a);
			printf("nom 1-go max = %d\n", nm);
		}
	}
	printf("\nisxodnii     ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	f=obr(n, a, b);
	if (f != 1)
		printf("vektor ne izmenilsa");
	else
	{
		printf("\npreobr      ");
		for (i = 0; i < n; i++)
			printf("%d ", b[i]);
	}
	free(a);
	free(b);
	_getch();
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

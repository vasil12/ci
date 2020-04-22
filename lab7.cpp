#include<stdio.h>
#include<conio.h>
#include<string.h>
//#include<Windows.h>

//int main();
void dobavlenie();
void prosmotr();
void dobavlenie_po_nomery(int noms);
void udalenie(int noms);
void vivod1();
void vivod2();
void vivod3();
int menu(int kp,const char* nazv[]);
struct department
{
	char naim[40];
	char mater[40];
	char izgot[40];
	int date;
	int colich;
	float cina;
} mas[50];
int N = 0; // Количество элементов в массиве mas
int main()
{
	int k, i, noms;
	int kp = 8, nom;
	int n;
	const char *nazv[] = { "Dobavit zapis" ,"Prosmotr", "Dobavit zapis po nomeru", "Udalit zapis", "vivod po date",
		" zamenna material po ykaz izgot","ydal po zad mater" , "Exit"};
	while (1)
	{
		nom = menu(kp,nazv);
		switch (nom)
		{
		case 1:
			dobavlenie();
			break;
		case 2:
			prosmotr();
			break;
		case 3:
			dobavlenie_po_nomery(nom);
			break;
		case 4:
			udalenie(nom);
			break;
		case 5:
			vivod1();
			break;
		case 6:
			vivod2();
			break;
		case 7:
			vivod3();
			break;
		case 8:
			return 0;
		}
	}
	return 0;
}

int menu(int kp, const char *nazv[])
{
	int i, nomer;
	for (i = 0; i < kp; i++)
		printf("\n%d.%s", i + 1, nazv[i]);
	printf("\n\nViberite punkt menu: ");
	scanf_s("%d", &nomer);
	return nomer;
}

void dobavlenie()

{
	while (1)
	{
		gets_s(mas[N].naim);
		printf("Vvedite naimenovanie izdelia(* - konec vvoda): ");
		_flushall(); 
		gets_s(mas[N].naim);
		if (mas[N].naim[0] == '*')
			return;

		printf("\nVvedite material: ");
		_flushall();
		gets_s(mas[N].mater);
		
		printf("Vvedite izgotovitela : ");
		_flushall();
		gets_s(mas[N].izgot);
		
		printf("\nVvedite daty:\ ");
		scanf_s("%d", &mas[N].date);
		
		printf("Vvedite colich : ");
	    scanf_s("%d", &mas[N].colich);
		
		printf("Vvedite  cena : ");
		scanf_s("%f", &mas[N].cina);

		N++;
	}
}

void prosmotr()
{
	printf("-------------------------------------------------------\n");
	printf("| naimenovanie | material | izgotovitel |data|colich|cena|\n");
	printf("-------------------------------------------------------\n");
	for (int i = 0; i < N; i++)
		printf("|%19s |%14s |%14s |%10d |%10d |%15.2f |\n",
			mas[i].naim, mas[i].mater, mas[i].izgot, mas[i].date, mas[i].colich, mas[i].cina);
	printf("-------------------------------------------------------\n");
	_getch();
}

void dobavlenie_po_nomery(int noms)
{
	printf("Vvedite nomer zapisi: ");
	scanf_s("%d", &noms);
	if (noms <= N + 1)
	{
		for (int i = N; i >= noms; i--)
			mas[i] = mas[i - 1];
		N++;
		gets_s(mas[noms - 1].naim);
		printf("Vvedite naimenovanie izdelia: ");
		_flushall();
		gets_s(mas[noms - 1].naim);

		printf("\nVvedite material: ");
		_flushall();
		gets_s(mas[noms - 1].mater);

		printf("Vvedite izgotovitela : ");
		_flushall();
		gets_s(mas[noms - 1].izgot);

		printf("\nVvedite daty:\ ");
		scanf_s("%d", &mas[noms - 1].date);

		printf("Vvedite colich: ");
		scanf_s("%d", &mas[noms - 1].colich);

		printf("Vvedite cena: ");
		scanf_s("%f", &mas[noms - 1].cina);
	}
	else
		printf(" Nedopustimuy nomer zapisi!");
	_getch();
}

void udalenie(int noms)
{
	printf("Vvedite nomer zapisi: ");
	scanf_s("%d", &noms);
	if (noms <= N)
	{
		for (int i = noms - 1; i < N; i++)
			mas[i] = mas[i + 1];
		N--;
	}
	else
		printf("Zapisey s takim nomerom net!");
	_getch();
}
void vivod1()
{
	int d;
	char f[10];
	printf("vvadite daty ");
	scanf_s("%d",&d);
	int kol = 0; // количество студентов со средним баллом >8.0
	printf("-------------------------------------------------------\n");
	printf("| naimenovanie | material | izgotovitel |data|colich|cena|\n");
	printf("-------------------------------------------------------\n");
	for (int i = 0; i < N; i++)
		if (mas[i].date == d)
		{
			printf("|%19s |%14s |%14s |%10d |%10d |%15.2f |\n",
				mas[i].naim, mas[i].mater, mas[i].izgot, mas[i].date, mas[i].colich, mas[i].cina);
		kol++;
		}
	printf("-------------------------------------------------------\n");
	
	if (kol == 0)
		printf("\nNet zapisei etogo goda \n");
	_getch();
}

void vivod2()
{
	char f[10],g[10];
	printf("vvadite izgotov");
	gets_s(g);
	gets_s(g);
	printf("vvadite material");
	gets_s(f);
	int kol = 0; // количество студентов со средним баллом >8.0
	printf("-------------------------------------------------------\n");
	printf("| naimenovanie | material | izgotovitel |data|colich|cena|\n");
	printf("-------------------------------------------------------\n");
	for (int i = 0; i < N; i++)
		if (strcmp(mas[i].izgot, g))
			;
		else
		{
			strcpy_s(mas[i].mater, "");
			strcpy_s(mas[i].mater, f);
			printf("|%19s |%14s |%14s |%10d |%10d |%15.2f |\n",
				mas[i].naim, mas[i].mater, mas[i].izgot, mas[i].date, mas[i].colich, mas[i].cina);
			kol++;
		}
	printf("-------------------------------------------------------\n");

	if (kol == 0)
		printf("\nNet tacogo izgot \n");
	_getch();
}
void vivod3()
{
	char f[10];
	printf("vvadite material");
	gets_s(f);
	gets_s(f);
	for (int i = 0; i < N; i++)
		if (strcmp(mas[i].mater, f))
			;
		else
			{
				for (int j = i; j < N-1; j++)
					mas[j] = mas[j + 1];
				N--;
				i--;
			}
			
	/*int kol = 0; // количество студентов со средним баллом >8.0
	printf("-------------------------------------------------------\n");
	printf("| naimenovanie | material | izgotovitel |data|colich|cena|\n");
	printf("-------------------------------------------------------\n");
	for (int i = 0; i < N; i++)
		if (strcmp(mas[i].mater, f))
		{
			printf("|%19s |%14s |%14s |%10d |%10d |%15.2f |\n",
				mas[i].naim, mas[i].mater, mas[i].izgot, mas[i].date, mas[i].colich, mas[i].cina);
			kol++;
		}
	printf("-------------------------------------------------------\n");

	if (kol == 0)
		printf("\nydalili vse zapisy \n");*/
	_getch();
}
// scanf_s("%d%*c")
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

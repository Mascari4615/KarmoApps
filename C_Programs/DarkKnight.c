#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Problem18();
void Problem19();

void main()
{
	int n;
	double pi = 0;
	printf("�ݺ�Ƚ��:");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		double temp = (double)4 / (i * 2 - 1);
		if (i % 2 == 1) pi += temp;
		else pi -= temp;
	}

	printf("Pi = %f", pi);
	
	return 0;
}

void Problem18()
{
	int cash = 50;
	int target = 250;
	int bets = 0;
	int win = 0;

	printf("�ʱ�ݾ� $%d\n", cash);
	printf("��ǥ�ݾ� $%d\n", target);

	while (cash < target && cash > 0)
	{
		bets++; // ���� Ƚ�� ����
		if ((double)rand() / RAND_MAX < 0.5)
		{
			cash++; // $1�� ����.
			win++;
		}
		else cash--; // $1�� �Ҵ´�.
	}

	printf("%d ���� %d�� �¸�\n", bets, win);
	printf("�̱� Ȯ��=%f", (double)win / bets * 100);
}

void Problem19()
{
	int n;
	double pi = 0;
	printf("�ݺ�Ƚ��:");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		double temp = (double)4 / (i * 2 - 1);
		if (i % 2 == 1) pi += temp;
		else pi -= temp;
	}

	printf("Pi = %f", pi);
}
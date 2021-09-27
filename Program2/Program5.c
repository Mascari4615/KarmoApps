#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void seat(int n, int c, int * buf)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (buf[i] > buf[j])
			{
				temp = buf[i];
				buf[i] = buf[j];
				buf[j] = temp;
			}
		}
	}

	temp = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%d", buf[i]);
		if (++temp == c) 
		{ 
			printf("\n"); 
			temp = 0; 
		}
		else printf(" ");
	}
}

void main() {
	int n; // �л� ��
	int c; // �ڸ� ��
	int buf[100]; // �л��� Ű ���� �����ϱ� ���� �迭

	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &buf[i]);
	}
	seat(n, c, buf);
}
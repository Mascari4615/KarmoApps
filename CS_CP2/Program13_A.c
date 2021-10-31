#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int IsCouple(char* string);

int main()
{
	int n = 1;
	printf("Enter N : ");
	scanf("%d", &n);

	// char* inputs[n]�� ���� �;�����, VS������ ���� ���� �迭(VLA)�� �������� �ʾ���.. 
	// ������ ���� �����͸� ����ϰ�, malloc �Լ��� �̿��� ���� �Ҵ��ϴ� ��� ���
	char** inputs = (char**)malloc(sizeof(char*) * n);
	char temp[100] = { NULL, };

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		// ���ڿ��� malloc �Լ��� �̿��� ���� �Ҵ�
		inputs[i] = (char*)malloc(sizeof(char) * strlen(temp));
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (IsCouple(inputs[i]))
			printf("Good");
		else
		{
			// IsCouple �Լ����� ¦�� �ִ� ���ĺ����� #���� �ٲ���, #�� �ƴ� ���ĺ��� ���
			for (int j = 0; j < strlen(inputs[i]); j++)
			{
				if (inputs[i][j] != '#')
					printf("%c", inputs[i][j]);
			}
		}

		printf("\n");
		// ���ڿ��� �� �̻� �������� �ʱ� ������, free �Լ��� �̿��� �Ҵ� ����
		free(inputs[i]);
	}

	// ���� �Ҵ��� ��� ���ڿ��� �Ҵ� ���� �� ����, ���� �����͵� �Ҵ� ����
	free(inputs);
	return 0;
}

// �Ű������� ���� ���ڿ� �� ���ĺ����� ��� ¦�� �ִ��� Ȯ��
int IsCouple(char* string)
{
	// ���ĺ� ���� ��, ������ �ٿ��� ��ȯ ���� �����ϴ� �� �����
	int coupleCount = 0;

	// ¦�� �ִ� ���ĺ��� ã�� #���� �ٲٰ�, coupleCount++
	for (int i = 0; i < strlen(string) - 1; i++)
	{
		if (string[i] == '#') continue;

		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[j] == '#') continue;

			if (string[i] == string[j])
			{
				string[i] = '#';
				string[j] = '#';
				coupleCount++;
				break;
			}
		}
	}

	// char�� �ᱹ ������ ������ Ÿ��, ���ĺ�(����) ������ ����
	char temp;
	for (int i = 0; i < strlen(string) - 1; i++)
	{
		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[i] > string[j])
			{
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}

	return (strlen(string) - coupleCount * 2 == 0);
}
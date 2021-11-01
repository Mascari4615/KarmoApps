#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int IsCouple(char* string);

// char* inputs[n]�� ���� �;�����, VS������ ���� ���� �迭(VLA)�� �������� �ʾ���.. 
// ������ ���� �����͸� ����ϰ�, malloc �Լ��� �̿��� ���� �Ҵ��ϴ� ��� ���

void main()
{
	int n;
	printf("Enter N : ");
	scanf("%d", &n);

	char** inputs, temp[100] = { NULL, };
	while ((inputs = malloc(sizeof(char*) * n)) == NULL);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		while ((inputs[i] = malloc(strlen(temp) + 1)) == NULL);
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (IsCouple(inputs[i])) 
			printf("Good");
		else
		{
			// ¦�� ���� ���ĺ� �Ųٷ� ���
			for (int j = strlen(inputs[i]); j >= 0; j--) 
				if (inputs[i][j] != '#')
					printf("%c", inputs[i][j]);
		}
		printf("\n");

		// ���ڿ��� �� ������� �ʱ� ������ �Ҵ� ����
		free(inputs[i]); 
	}

	// ���� �����͵� �Ҵ� ����
	free(inputs); 
}

// �Ű������� ���� ���ڿ� �� ���ĺ����� ��� ¦�� �ִ��� Ȯ��
int IsCouple(char* string) 
{
	int coupleCount = 0;

	// ¦�� �ִ� ���ĺ��� ã�� #���� �ٲٰ�, coupleCount++
	for (int i = 0; i < strlen(string) - 1; i++) 
	{
		if (string[i] == '#')
			continue;

		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[i] == '#')
				continue;

			if (string[i] == string[j])
			{
				string[i] = string[j] = '#';
				coupleCount++;
				break;
			}
		}
	}

	return strlen(string) == coupleCount * 2;
}
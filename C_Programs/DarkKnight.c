#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char** test, ** test2, string[100] = { 0, };
	int c = 0, i;

	printf("Case: "); 
	scanf("%d%*c", &c);  // ��� ������ ����

	test = (char**)malloc(sizeof(char*) * c); // c�� ���� ���� ���� ĳ���������� ����
	test2 = (char**)malloc(sizeof(char*) * c);

	for (i = 0; i < c; i++) 
	{
		gets(string);

		// strchr��	���ڿ� ���� ��ġ�ϴ� ���ڰ� �ִ��� �˻��ϴ� �Լ� ã������ ���ڰ� ������ �ش� ������ ������ �� ��ȯ
		printf("%s\n", (strchr(string, ' ') + 1));
		test2[i] = (strchr(string, ' ') + 1); // strchr�� string���� ������ �ּҰ��� + 1 �Ͽ� ���� ������
		test[i] = strtok(string, " ");

		/*
		if (Anagram(test[i], test2))
			printf("%s & %s are anagrams.", test[i], test2);
		else printf("%s & %s are NOT anagrams.", test[i], test2);
		*/
		printf("\n%s", test[i]);
		printf(" %s", test2[i]);	
	}

	for ( i = 0; i < c; i++)
	{
		printf("\n%s", test[i]);
		printf(" %s", test2[i]);
	}

	free(test);
	free(test2);
}

int Anagram(char* string1, char* string2) 
{
	int check1 = 0, len = strlen(string1), i, j;

	for (i = 0; i < len; i++)
	{
		if (string1[i] != 1)
		{
			for (j = 0; j < len; j++)
			{
				if (string1[i] == string2[j] && string2[j] != 1)
				{
					string1[i] = string2[j] = 1;
					check1 ++;
					break;
				}
			}
		}
	}

	return (check1 == strlen(string1));
}
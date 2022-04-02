#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void Program2_1()
{
	char c, c_array[100];
	int i, i_array[100];
	short s, s_array[100];
	float f, f_array[100];
	long l, l_array[100];

	printf("\n char c ũ�� = %d \t: char c_array ũ�� = %4d", sizeof(c), sizeof(c_array));
	printf("\n int i ũ�� = %d \t: int i_array ũ�� = %4d", sizeof(i), sizeof(i_array));
	printf("\n short s ũ�� = %d \t: short s_array ũ�� = %4d", sizeof(s), sizeof(s_array));
	printf("\n float f ũ�� = %d \t: float f_array ũ�� = %4d", sizeof(f), sizeof(f_array));
	printf("\n long l ũ�� = %d \t: long l_array ũ�� = %4d", sizeof(l), sizeof(l_array));

	getchar();
}

void Program2_2()
{
	int i;
	// 1���� �迭 �ʱ�ȭ
	int score[3] = { 91, 86, 97 };
	char grade[3] = { 'A','B','A' };

	printf("\n *** �г⺰ ��� ���� *** \n\n");

	for (i = 0; i < 3; i++)
	{
		printf("%3d�г� : ���� = %d, ��� = %c\n", i + 1, score[i], grade[i]);
	}

	getchar();
}

void Program2_3()
{
	int i = 0, n;
	int multiply[9];

	printf("\n1~9�� ������ �Է��ϼ��� : ");

	while (1)
	{
		scanf("%d", &n);
		if (n < 0 || n > 9)
		{
			printf("\n 1~9�� ������ �Է��ϼ��� : ");
		}
		else
		{
			break;
		}
	}

	printf("\n");

	for (i = 0; i < 9; i++)
	{
		multiply[i] = n * (i + 1);
		printf(" %d * %d = %d \n", n, (i + 1), multiply[i]);
	}

	getchar();
	getchar();
}

void Program2_4()
{
	char str[20] = "Data Structure!";
	int i;
	printf("\n���� �迭 str[] : ");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
	}
	getchar();
}

void Program2_5()
{
	int i, length = 0;
	char str[50];
	printf("\n���ڿ��� �Է��ϼ��� : ");
	gets(str);
	printf("\n�Էµ� ���ڿ��� \n \"");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n�Դϴ�.");
	printf("\n\n�Էµ� ���ڿ��� ���� = %d \n", length);

	getchar();
}

void Program2_6()
{
	int array[2][3][4];
	int i, j, k, value = 1;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				array[i][j][k] = value;
				printf("\n array[%d][%d][%d] = %d", i, j, k, array[i][j][k]);
				value++;
			}
		}
	}
	getchar();
}

void Program2_7()
{
	int i, j, k;
	char student[2][3][20];
	for (i = 0; i < 2; i++)
	{
		printf("\n �л� %d�� �̸� : ", i + 1);
		gets(student[i][0]);
		printf("\n �л� %d�� �а� : ", i + 1);
		gets(student[i][1]);
		printf("\n �л� %d�� �й� : ", i + 1);
		gets(student[i][2]);
	}

	for (i = 0; i < 2; i++)
	{
		printf("\n\n �л� %d", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("\n\t");
			for (k = 0; student[i][j][k] != '0'; k++)
			{
				printf("%c", student[i][j][k]);
			}
		}
	}
	getchar();
}

void Program2_8()
{
	int i = 10, j = 20;
	int* ptr;
	printf("\n i�� �� = %d \n j�� �� = %d", i, j);
	printf("\n i�� �޸� �ּ�(&i) = %u", &i);
	printf("\n j�� �޸� �ּ�(&j) = %u", &j);

	ptr = &i;
	printf("\n\n << ptr = &i ���� >>");
	printf("\n ptr�� �޸� �ּ�(&ptr) = %u", &ptr);
	printf("\n ptr�� ��(ptr) = %u", ptr);
	printf("\n ptr�� ������(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr = &j ���� >>");
	printf("\n ptr�� �޸� �ּ�(&ptr) = %u", &ptr);
	printf("\n ptr�� ��(ptr) = %u", ptr);
	printf("\n ptr�� ������(*ptr) = %d", *ptr);

	i = *ptr;
	printf("\n\n << i=*ptr ���� >>");
	printf("\n i�� �� = %d", i);

	getchar();
}

void Program2_9()
{
	int i;
	char string1[20] = "Dreams come true!", string2[20], * ptr1, * ptr2;

	ptr1 = string1;
	printf("\n string1�� �ּ� = %u \t ptr1 = %u", string1, string2);
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);
	printf("\n\n %s", ptr1 + 7);
	ptr2 = &string1[7];
	printf("\n %s \n\n ", ptr2);

	for (i = 16; i >= 0; i--)
	{
		putchar(*(ptr1 + i));
	}

	for (i = 0; i < 20; i++)
	{
		string2[i] = *(ptr1 + 1);
	}
	printf("\n\n string1 = %s", string1);
	printf("\n string2 = %s", string2);

	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1);

	getchar();
}

void Program2_10()
{
	int i;
	char* ptrArray[4] = { {"Korea"}, {"Seoul"}, {"Mapo"},  {"152���� 2 / 3"} };

	for (i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	ptrArray[2] = "Jongno";
	printf("\n\n");
	for (i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	getchar();
}

void Program2_11()
{
	char* ptrArray[2];
	char** ptrptr;
	int i;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Seoul";

	ptrptr = ptrArray;
	printf("\n ptrArray[0]�� �ּ� (&ptrArray[0]) = %u", &ptrArray[0]);
	printf("\n ptrArray[0]�� �� (&ptrArray[0]) = %u", ptrArray[0]);
	printf("\n ptrArray[0]�� ������ (*ptrArray[0]) = %��", *ptrArray[0]);
	printf("\n ptrArray[0]�� ���� ���ڿ� (*&ptrArray[0]) = %s \n", *ptrArray);

	printf("\n ptrArray[1]�� �ּ� (&ptrArray[1]) = %u", &ptrArray[1]);
	printf("\n ptrArray[1]�� �� (&ptrArray[1]) = %u", ptrArray[1]);
	printf("\n ptrArray[1]�� ������ (*ptrArray[1]) = %��", *ptrArray[1]);
	printf("\n ptrArray[1]�� ���� ���ڿ� (*&ptrArray[1]) = %s \n", *(ptrArray + 1));

	printf("\n ptrptr�� �ּ� (&ptrArray[0]) = %u", &ptrArray[0]);
	printf("\n ptrptr�� �� (&ptrArray[0]) = %u", ptrArray[0]);
	printf("\n ptrptr�� 1�� ������ (*ptrptr) = %u", *ptrptr);
	printf("\n ptrptr�� 2�� ������ (**ptrptr) = %c", **ptrptr);
	printf("\n ptrptr�� 2�� ���� ���ڿ� (**ptrptr) = %s", *ptrptr);

	printf("\n\n *ptrArray[0] : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrArray[0] + i));
	}
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrptr + i));
	}

	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrArray[1] + i));
	}
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *((ptrptr + 1) + i));
	}

	getchar();
}

struct employee
{
	char name[10];
	int year;
	int pay;
};

void Program2_12()
{
	int i;
	struct employee Lee[4] =
	{
		{ "����ȣ", 2022, 5200},
		{ "���ѿ�", 2023, 4300},
		{ "�̻��", 2023, 4500},
		{ "�̻��", 2024, 3900},
	};

	for (i = 0; i < 4; i++)
	{
		printf("\n �̸� : %s", Lee[i].name);
		printf("\n �Ի� : %s", Lee[i].year);
		printf("\n ���� : %s", Lee[i].pay);
	}

	getchar();
}


void Program2_13()
{
	int i;
	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "�̼���");
	Sptr->year = 2023;
	Sptr->pay = 6900;

	printf("\n �̸� : %s", Sptr->name);
	printf("\n �Ի� : %s", Sptr->year);
	printf("\n ���� : %s", Sptr->pay);

	getchar();
}

long int fact(int n)
{
	int value;
	if (n <= 1)
	{
		printf("\n fact(1) �Լ� ȣ��!");
		printf("\n fact(1) �� 1 ��ȯ!!");
		return;
	}
	else
	{
		printf("\n fact(%d) �Լ� ȣ��!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) �� %ld ��ȯ!!", n, value);
		return value;
	}
}

void Program2_14()
{
	int n, result;
	printf("\n ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d�� ���丮�� ���� %ld�Դϴ�.\n", n, result);
	getchar(); getchar();
}

void hanoi(int n, int start, int work, int target)
{
	if (n == 1)
	{
		printf(" %c���� ���� %d��(��) %c�� �ű� \n", start, n, target);
	}
	else
	{
		hanoi(n - 1, start, target, work);
		printf(" %c���� ���� %d��(��) %c�� �ű� \n", start, n, target);
		hanoi(n - 1, work, start, target);
	}
}

void Program2_15()
{
	hanoi(3, 'A', 'B', 'C');
	getchar();
}

void main()
{
	Program2_15();

	return 0;
}
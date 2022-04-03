#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Address
{
	char name[10];
	char phoneNumber[13];
	char address[10];
	char birthDay[10];
    struct Address* link;
};
typedef struct Address address;

void AddAddress(address*);
void DeleteAddress(address*);
void PrintAddress(address*);
void SearchAddress(address*);

void Program2_24()
{
    address* ptr = (address*)malloc(sizeof(address));
    ptr->link = NULL;

	while (1)
	{
		int command;

		printf("��� : ");
		scanf("%d", &command);

		switch (command)
		{
			case 0: // ���
                PrintAddress(ptr->link);
				break;
			case 1: // �߰�
                AddAddress(ptr);
				break;
			case 2: // Ž��
                SearchAddress(ptr);
				break;
			case 3: // ����
                DeleteAddress(ptr);
				break;
            default:
				exit(0);
				break;
		}
	}
}

void main()
{
    Program2_24();
}

void PrintAddress(address* ptr) 
{
    printf("- ��� \n");
    printf("�̸�\t\t��ȭ��ȣ\t�ּ�\t\t����\n");
    do 
        printf("%s\t\t%s\t\t%s\t\t%s\n", ptr->name, ptr->phoneNumber, ptr->address, ptr->birthDay);
    while ((ptr = ptr->link) != NULL);
    printf("\n");
}

void AddAddress(address* ptr) 
{
    printf("- �߰� \n");
    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = (address*)malloc(sizeof(address));
    ptr = ptr->link;

    printf("�̸� : ");
    scanf("%s", ptr->name);
    printf("��ȭ��ȣ : ");
    scanf("%s", ptr->phoneNumber);
    printf("�ּ� : ");
    scanf("%s", ptr->address);
    printf("���� : ");
    scanf("%s", ptr->birthDay);
    
    ptr->link = NULL;
    printf("\n");

    while (getchar() != '\n');
}

void SearchAddress(address* ptr)
{
    printf("- Ž�� \n");
    char _name[15];

    printf("�̸� : ");
    scanf("%s", _name);

    printf("�̸�\t\t��ȭ��ȣ\t�ּ�\t\t����\n");

    while (ptr != NULL) 
    {
        if (strcmp(_name, ptr->name) == 0) 
        {
            printf("%s\t\t%s\t\t%s\t\t%s\n", ptr->name, ptr->phoneNumber, ptr->address, ptr->birthDay);
        }
        ptr = ptr->link;
    }

    while (getchar() != '\n');
}

void DeleteAddress(address* ptr) 
{
    printf("- ���� \n");
    address* temp;
    char targetName[10];

    printf("�̸� : ");
    scanf("%s", targetName);

    while (ptr->link != NULL) 
    {
        temp = ptr;
        ptr = ptr->link;

        if (strcmp(targetName, ptr->name) == 0) 
        {
            temp->link = ptr->link;
            free(ptr);
            break;
        }
    }

    while (getchar() != '\n');
}
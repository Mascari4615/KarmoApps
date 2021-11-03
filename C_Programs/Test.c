#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*������ �޸� ��뷮 üũ�� �ʿ��� ���*/
#include <Windows.h>
#include <psapi.h>
#include <conio.h>
#include<malloc.h>

/** �ε� �����߿��� �߻��� �޸� �ҿ䷮�� �����Ѵ�. */
static PROCESS_MEMORY_COUNTERS_EX g_mc;

int main()
{
    PROCESS_MEMORY_COUNTERS_EX pmc;
    // �޸� �����¸� ��´�.
    GetProcessMemoryInfo(GetCurrentProcess(),
        (PROCESS_MEMORY_COUNTERS*)&g_mc, sizeof(g_mc));

    //�޸� �ε� �ڵ�
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    char** inputs = NULL, temp[100] = { NULL, };
    while ((inputs = malloc(sizeof(char*) * n)) == NULL);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        while ((inputs[i] = malloc(strlen(temp) + 1)) == NULL);
        strcpy(inputs[i], temp);
    }


    //�ε� �� �޸� ��뷮 ǥ��
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    printf("Memory Usage : %u\n", (pmc.PrivateUsage - g_mc.PrivateUsage));

    //�޸� ���� �ڵ�
    for (int i = 0; i < n; i++)
    {
        free(inputs[i]);
    }

    free(inputs);

    /*���� �� �޸� ��뷮 ǥ��*/
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    printf("Memory Usage : %u\n", (pmc.PrivateUsage - g_mc.PrivateUsage));

    //�ָܼ�� �ڵ� ���� ����
    printf("\nPress any key to exit.");
    while (!_kbhit()); _getch();
}

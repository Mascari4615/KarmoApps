#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void sum_diff_mul(int x, int y);

void main()
{
	int x = 0, y = 0;
	bool restart = true;
	char yn;

	do
	{
	ReInput_XY:

		printf(" =====================================================\n");
		printf(" �� ���� x�� y�� ���� �Է����ּ���. (�̶�, x�� y���� ũ��)\n");

		printf(" x: ");
		scanf("%d", &x);
		printf("%d", x);
		getchar();

		printf(" y: ");
		scanf("%d", &y);
		printf("%d", y);
		getchar();

		printf("\n");

		if (x <= y)
		{
			printf(" x�� y���� �۰ų� �����ϴ�. x�� y���� Ŀ���մϴ�. �ٽ� �Է����ּ���.\n\n");
			goto ReInput_XY;
		}

		sum_diff_mul(x, y);

	ReInput_YN:

		printf(" �ٽ� �����Ͻðڽ��ϱ� ? (Y/N) : ");
		scanf("%c", &yn);
		getchar();

		printf("\n");

		switch (yn)
		{
		case 'Y': case 'y':
			printf(" �ٽ� �����մϴ�.\n\n");
			restart = true;
			break;
		case 'N': case 'n':
			printf(" �ٽ� �������� �ʽ��ϴ�.\n\n");
			restart = false;
			break;
		default:
			printf(" %c �� �ùٸ��� ���� �Է��Դϴ�. Y �Ǵ� N �� �Է����ּ���.\n\n", yn);
			goto ReInput_YN;
		}

	} while (restart);

	printf(" ���α׷��� �����մϴ�. �����մϴ�.\n");

	return 0;
}

void sum_diff_mul(int x, int y)
{
	int sum = x + y;
	int diff = x - y;
	int mul = x * y;

	printf(" ��� - ");
	printf("��(SUM) : %d, ", sum);
	printf("��(DIFF) : %d, ", diff);
	printf("��(MUL) : %d\n\n", mul);
}
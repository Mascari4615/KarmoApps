#include "LinkedQueueS.h"

int main(void)
{
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enCQueue(LQ, 'A'); printCQ(LQ);
	printf("\n ���� B>>"); enCQueue(LQ, 'B'); printCQ(LQ);
	printf("\n ���� C>>"); enCQueue(LQ, 'C'); printCQ(LQ);
	data = peekQ(LQ); printf(" peek item : %c \n", data);
	printf("\n ���� >>"); data = deCQueue(LQ); printCQ(LQ);
	printf("\n���� ������: %c", data);
	printf("\n ���� >>"); data = deCQueue(LQ); printCQ(LQ);
	printf("\n���� ������: %c", data);
	printf("\n ���� >>"); data = deCQueue(LQ); printCQ(LQ);
	printf("\n���� ������: %c", data);

	printf("\n ���� D>>"); enCQueue(LQ, 'D'); printCQ(LQ);
	printf("\n ���� E>>"); enCQueue(LQ, 'E'); printCQ(LQ);

	getchar(); return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "queueS.h"

// ���� ���� ť�� �����ϴ� ����
QueueType* createQueue(void)
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1; // front �ʱ갪 ����
	Q->rear = -1; // reat �ʱ갪 ����
	return Q;
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isQueueEmpty(QueueType* Q)
{
	if (Q->front == Q->rear)
	{
		printf(" Queue is empty! \n\t ");
		return 1;
	}
	else
	{
		return 0;
	}
}

int isQueueFull(QueueType* Q)
{
	if (Q->rear == Q_SIZE - 1)
	{
		printf(" Queue is full! \n\t ");
		return 1;
	}
	else
	{
		return 0;
	}
}

void enQueue(QueueType* Q, element item)
{
	if (isQueueFull(Q))
	{
		return;
	}
	else
}
element deQueue(QueueType* Q);
element peedQ(QueueType* Q);
void prentQ(QueueType* Q);
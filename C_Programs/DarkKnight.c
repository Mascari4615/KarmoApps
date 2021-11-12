#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int*, int, int);
void multiplyArray(int**, int, int, int**, int, int);
/**
* �� ���� ����� ���ϴ� ���α׷�.
*/
int main(void) {

	int oneRow, oneColumn, otherRow, otherColumn;

	printf("ù ��° ����� �� ������ �Է��ϼ���: ");
	scanf_s("%d", &oneRow);
	printf("ù ��° ����� �� ������ �Է��ϼ���: ");
	scanf_s("%d", &oneColumn);
	printf("�� ��° ����� �� ������ �Է��ϼ���: ");
	scanf_s("%d", &otherRow);
	printf("�� ��° ����� �� ������ �Է��ϼ���: ");
	scanf_s("%d", &otherColumn);

	if (oneColumn != otherRow) {
		printf("�� ����� ���� ���� �� ���� ��Ȳ�Դϴ�.\n");
		return 0;
	}

	// ù ��° �迭 ����
	int** one = (int**)malloc(sizeof(int*) * oneRow);
	for (int i = 0; i < oneRow; i++) {
		one[i] = (int*)malloc(sizeof(int) * oneColumn);
	}
	// �� ��° �迭 ����
	int** other = (int**)malloc(sizeof(int*) * otherRow);
	for (int i = 0; i < otherRow; i++) {
		other[i] = (int*)malloc(sizeof(int) * otherColumn);
	}
	// ù ��° �迭�� �� �Ҵ�
	srand(time(NULL));
	for (int i = 0; i < oneRow; i++) {
		for (int j = 0; j < oneColumn; j++) {
			one[i][j] = rand() % 9 + 1;
		}
	}
	// �� ��° �迭�� �� �Ҵ�
	for (int i = 0; i < otherRow; i++) {
		for (int j = 0; j < otherColumn; j++) {
			other[i][j] = rand() % 9 + 1;
		}
	}

	printArray(one, oneRow, oneColumn);
	printf("----------\n");
	printArray(other, otherRow, otherColumn);
	printf("----�� ����� ����----\n");
	multiplyArray(one, oneRow, oneColumn, other, otherRow, otherColumn);

	for (int i = 0; i < oneRow; i++) {
		free(one[i]);
	}
	free(one);
	for (int i = 0; i < otherRow; i++) {
		free(other[i]);
	}
	free(other);

	return 0;
}
/**
* ���(�迭)�� ����ϴ� �޼ҵ�.
*/
void printArray(int** one, int row, int column) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d ", one[i][j]);
		}
		printf("\n");
	}

}
/**
* �� ����� ���ϴ� �޼ҵ�.
*/
void multiplyArray(int** one, int oneRow, int oneColumn, int** other, int otherRow, int otherColumn) {

	// �� ����� ���� �� ����� ������ �� �迭
	int newRow = oneRow; //2
	int newColumn = otherColumn; //3
	int** newOne = (int**)malloc(sizeof(int*) * newRow);
	for (int i = 0; i < newRow; i++) {
		newOne[i] = (int*)malloc(sizeof(int) * newColumn);
	}

	// ��� ���� �� ����
	for (int i = 0; i < newRow; i++) 
	{
		for (int j = 0; j < newColumn; j++) 
		{
			newOne[i][j] = 0;
			for (int k = 0; k < oneColumn; k++)
			{
				newOne[i][j] += one[i][k] * other[k][j];
			}
		}
	}

	printArray(newOne, newRow, newColumn);

	for (int i = 0; i < newRow; i++) {
		free(newOne[i]);
	}
	free(newOne);

}
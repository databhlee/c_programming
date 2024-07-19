#include <stdio.h>
#define SIZE 5

void calculate(double* e, double* m, double* e100, double* m100, double* avg100, int size);

int main(void)
{
	double eng[SIZE] = { 4.1, 3.0, 2.8, 4.2, 3.5 };
	double math[SIZE] = { 3.1, 3.5, 3.3, 3.2, 2.7 };

	double eng100[SIZE];
	double math100[SIZE];
	double avg100[SIZE];

	calculate(eng, math, eng100, math100, avg100, SIZE);

	printf("학생\t영어성적\t수학성적\t평균성적\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%d\t%.1f%%\t\t%.1f%%\t\t%.1f%%\n", i + 1, eng100[i], math100[i], avg100[i]);
	}

	return 0;
}

void calculate(double* e, double* m, double* e100, double* m100, double* avg100, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(e100 + i) = *(e + i) / 4.5 * 100;
		*(m100 + i) = *(m + i) / 4.5 * 100;
		*(avg100 + i) = ((*(e + i) + *(m + i)) / 2) / 4.5 * 100;
	}
}

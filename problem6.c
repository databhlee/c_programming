#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i;
	int scores[100];
	int count = 0;
	int sum = 0;

	for (i = 0; i < 100; i++)
	{
		printf("성적을 입력하세요: ");
		scanf("%d", &scores[i]);

		if (scores[i] < 0)
			break;

		count++;
	}


	for (i = 0; i < count; i++)
	{
		sum += scores[i];
	}

	double average = 0.0;
	average = (double) sum / count;

	printf("평균: %f", average);
	return 0;
}

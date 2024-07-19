#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c;

	printf("계수: a, 계수: b, 계수: c를 차례대로 입력하시오: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a == 0)
	{
		printf("방정식의 근은 %f입니다.", -c / b);
	}
	else if (a < 0)
	{
		printf("실근이 존재하지 않는다.");
	}
	else
	{
		printf("방정식의 근은 %f입니다.\n", (-b + sqrt(b * b - 4 * a * c)) / 2 * a);
		printf("방정식의 근은 %f입니다.\n", (-b - sqrt(b * b - 4 * a * c)) / 2 * a);
	}

	return 0;
}

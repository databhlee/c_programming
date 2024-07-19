#include <stdio.h>


int main(void)
{
	int i, j;
	int* pi, * pj;
	
	double avg;
	double* pavg;

	pi = &i;
	pj = &j;

	*pi = 5;
	*pj = 10;
	
	pavg = &avg;
	*pavg = (*pi + *pj) / 2.0;
	
	printf("pi: %d\n", *pi);
	printf("pj: %d\n", *pj);
	printf("pavg: %.1f\n", *pavg);
	printf("i: %d\n", i);
	printf("j: %d\n", j);
	printf("avg: %.1f\n", avg);

	return 0;
}

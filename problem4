#include <stdio.h>

int main(void) 
{

	int count = 0;

	for (int a = 1; a <= 100; a++)
	{
		for (int b = 1; b <= 100; b++)
		{
			for (int c = 1; c <= 100; c++)
			{
				if (c * c == a * a + b * b)
				{
					printf("직각삼각형: %d %d %d\n", a, b, c);
					count++;
				}
			}
		}
	}
	printf("총 %d개입니다.", count);

	return 0;
}

#include <stdio.h>
#define SIZE 5

void print_image(int* img, int xsize, int ysize);
void brighten_image(int* img, int xsize, int ysize);

int main(void)
{
	int image[SIZE][SIZE] = {
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250} };

	print_image(image, SIZE, SIZE);
	brighten_image(image, SIZE, SIZE);
	print_image(image, SIZE, SIZE);
	return 0;
}

void print_image(int* img, int xsize, int ysize)
{
    for (int i = 0; i < xsize; i++)
    {
        for (int j = 0; j < ysize; j++)
        {
            printf("%d ", *(img + i * xsize + j));
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

void brighten_image(int* img, int xsize, int ysize)
{
    for (int i = 0; i < xsize; i++)
    {
        for (int j = 0; j < ysize; j++)
        {
            if (*(img + i * xsize + j) + 10 <= 255)
            {
                *(img + i * xsize + j) += 10;
            }
            else
            {
                *(img + i * xsize + j) = 255;
            }

        }
    }
}

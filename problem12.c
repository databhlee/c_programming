#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

struct rectangle {
	struct point left_bottom;
	struct point right_top;
};

int calculate_area(struct rectangle rect);
int calcualte_perimeter(struct rectangle rect);

int main(void)
{
	struct rectangle rect;

	printf("왼쪽 하단의 좌표를 입력하시오: ");
	scanf("%d %d", &rect.left_bottom.x, &rect.left_bottom.y);

	printf("오른쪽 상단의 좌표를 입력하시오: ");
	scanf("%d %d", &rect.right_top.x, &rect.right_top.y);

	int area = calculate_area(rect);
	int perimeter = calcualte_perimeter(rect);

	printf("면적은 %d이고 둘레는 %d입니다.\n", area, perimeter);

	return 0;
}

int calculate_area(struct rectangle rect)
{
	int width = rect.right_top.x - rect.left_bottom.x;
	int height = rect.right_top.y - rect.left_bottom.y;

	return width * height;
}

int calcualte_perimeter(struct rectangle rect)
{
	int width = rect.right_top.x - rect.left_bottom.x;
	int height = rect.right_top.y - rect.left_bottom.y;

	return 2 * (width + height);
}

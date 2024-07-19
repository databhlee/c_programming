#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int itemPrice, paidMoney, change;
    int changeType[] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
    char* changeTypeName[] = {"오만원권", "만원권", "오천원권", "천원권", "오백원", "백원", "오십원", "십원"};

	printf("물건 값을 입력하시오: ");
	scanf("%d", &itemPrice);

	printf("사용자가 낸 돈을 입력하시오: ");
	scanf("%d", &paidMoney);

	change = paidMoney - itemPrice;

	printf("거스름돈: %d\n", change);

	for (int i = 0; i < sizeof(changeType) / sizeof(changeType[0]); i++) {

		if (change < changeType[i]) {
			continue;
		}

		printf("%s: %d개\n", changeTypeName[i], change / changeType[i]);
		change %= changeType[i];
	}
    return 0;
}

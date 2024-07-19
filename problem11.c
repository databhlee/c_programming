#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int check(char s[], char a[], char ch);

int main(void) {
	char solution[100] = "meet at midnight";
	char answer[100] = "____ __ ________";
	char ch;

	while (1) {
		printf("현재 문장: %s\n", answer);
		printf("문자 하나를 추측하시오: ");
		ch = getchar();
		if (check(solution, answer, ch) == 1) {
			printf("성공: %s\n", answer);
			break;
		}
		while (ch = getchar() != '\n' && ch != EOF) {};
	}

	return 0;
}

int check(char s[], char a[], char ch)
{
	int length = strlen(s);
	int collect = 1;

	for (int i = 0; i < length; i++) {
		if (s[i] == ch) {
			a[i] = ch;
		}
		if (a[i] == '_') {
			collect = 0;
		}
	}

	if (collect) {
		return  1;
	}

	return 0;
}

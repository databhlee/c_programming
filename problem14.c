#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50

typedef struct Movie {
    char title[S_SIZE];
    float rating;
    struct Movie* link;
} Movie;

int main(void)
{
    Movie* head = NULL;
    Movie* tail = NULL;
    Movie* p, * next;
    char buffer[S_SIZE];
    float rating;
    while (1) {
        printf("영화 제목 (종료하려면 엔터를 입력하시오): ");
        gets(buffer);
        if (buffer[0] == '\0')
            break;
        p = (Movie*)malloc(sizeof(Movie));
        strcpy(p->title, buffer);
        printf("영화 평점: ");
        gets(buffer);
        rating = atoi(buffer);
        p->rating = rating;
        p->link = NULL;
        if (head == NULL)
            head = p;
        else
            tail->link = p;
        tail = p;
    }
    printf("========================\n");
    printf("제목 평점\n");
    printf("========================\n");
        for (p = head; p != NULL; p = p->link)
            printf("%s %f\n", p->title, p->rating);
    printf("========================\n");
    p = head;
    while (p != NULL)
    {
        next = p->link;
        free(p);
        p = next;
    }
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

struct user_info {
    int id_num;
    char id[10];
    char password[10];
};

int print_seats(int s_array[ROWS][COLS]);
int reserve(int s_array[ROWS][COLS], char r, int col, int id);
int cancel(int s_array[ROWS][COLS], char r, int col, int id);
int load_user_info(struct user_info users[]);
int check_login(struct user_info users[], const char id[], const char password[]);
void clear_input_buffer(void);
int load_reservation_info(int s_array[ROWS][COLS]);
int save_reservation_info(int s_array[ROWS][COLS]);
void selection_sort(struct user_info users[], int n);

int main(void) {
    struct user_info users[10];
    int seats[ROWS][COLS] = { {0} };

    int select;
    int result;
    int login_user;
    char id[10], password[10];

    int user_count = load_user_info(users);
    if (user_count < 0) {
        printf("사용자 정보를 불러오는 데 실패했습니다.\n");
        return 1;
    }

    if (load_reservation_info(seats) < 0) {
        printf("예약 정보를 불러오는 데 실패했습니다.\n");
    }

    while (1) {
        printf("로그인을 하세요.\n");
        printf("id: ");
        scanf("%s", id);
        clear_input_buffer();
        printf("password: ");
        scanf("%s", password);
        clear_input_buffer();

        login_user = check_login(users, id, password);

        if (login_user > 0) {
            printf("%s님 반갑습니다.\n", id);
            break;
        }
        else if (login_user == -1) {
            printf("해당 아이디가 존재하지 않습니다. 다시 로그인을 하세요.\n");
        }
        else if (login_user == -2) {
            printf("해당 아이디는 존재하지만, 패스워드가 다릅니다. 다시 로그인을 하세요.\n");
        }
    }

    while (1) {
        printf("1---좌석확인하기\n");
        printf("2---예약하기\n");
        printf("3---예약취소하기\n");
        printf("4---다른 사용자로 로그인하기\n");
        printf("5---종료하기\n");
        printf("메뉴를 선택하시오: ");
        scanf("%d", &select);
        clear_input_buffer();

        if (select == 1) {
            print_seats(seats);
        }
        else if (select == 2) {
            char row;
            int col;

            printf("예약을 원하는 자리는(예- A2)? ");
            scanf(" %c%d", &row, &col);
            clear_input_buffer();

            result = reserve(seats, row, col, login_user);
            if (result == 1) {
                printf("예약이 완료되었습니다.\n");
                print_seats(seats);
            }
            else {
                printf("이미 예약된 자리입니다.\n");
                print_seats(seats);
            }
        }
        else if (select == 3) {
            char row;
            int col;

            printf("예약취소를 원하는 자리는(예 - A2)? ");
            scanf(" %c%d", &row, &col);
            clear_input_buffer();

            result = cancel(seats, row, col, login_user);
            if (result == 1) {
                printf("예약취소가 완료되었습니다.\n");
                print_seats(seats);
            }
            else {
                printf("예약되지 않은 자리입니다.\n");
                print_seats(seats);
            }
        }
        else if (select == 4) {
            // 로그아웃 후 재로그인
            while (1) {
                printf("로그인을 하세요.\n");
                printf("id: ");
                scanf("%s", id);
                clear_input_buffer();
                printf("password: ");
                scanf("%s", password);
                clear_input_buffer();

                login_user = check_login(users, id, password);

                if (login_user > 0) {
                    printf("%s님 반갑습니다.\n", id);
                    break;
                }
                else if (login_user == -1) {
                    printf("해당 아이디가 존재하지 않습니다. 다시 로그인을 하세요.\n");
                }
                else if (login_user == -2) {
                    printf("해당 아이디는 존재하지만, 패스워드가 다릅니다. 다시 로그인을 하세요.\n");
                }
            }
        }
        else if (select == 5) {
            if (save_reservation_info(seats) < 0) {
                printf("예약 정보를 저장하는 데 실패했습니다.\n");
            }
            break;
        }
    }

    printf("선택된 메뉴=종료하기\n\n");
    printf("이용해 주셔서 감사합니다.\n");
    return 0;
}

int print_seats(int s_array[ROWS][COLS]) {
    printf("  | 0  1  2  3  4\n");
    printf("-----------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", s_array[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int reserve(int s_array[ROWS][COLS], char r, int col, int id) {
    int row = r - 'A';
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (s_array[row][col] == 0) {
            s_array[row][col] = id;
            return 1;
        }
    }
    return -1;
}

int cancel(int s_array[ROWS][COLS], char r, int col, int id) {
    int row = r - 'A';
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (s_array[row][col] == id) {
            s_array[row][col] = 0;
            return 1;
        }
    }
    return -1;
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int load_user_info(struct user_info users[]) {
    FILE* file = fopen("C:\\Users\\born4\\Desktop\\user_data.txt", "r");
    if (!file) {
        return -1;
    }

    int i = 0;
    while (fscanf(file, "%d %s %s", &users[i].id_num, users[i].id, users[i].password) != EOF) {
        i++;
    }
    fclose(file);

    selection_sort(users, i);

    return i;
}

int check_login(struct user_info users[], const char id[], const char password[]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(users[i].id, id) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                return users[i].id_num;
            }
            else {
                return -2;
            }
        }
    }
    return -1;
}

int load_reservation_info(int s_array[ROWS][COLS]) {
    FILE* file = fopen("C:\\Users\\born4\\Desktop\\reservation_data.txt", "r");
    if (!file) {
        return -1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%d", &s_array[i][j]);
        }
    }
    fclose(file);
    return 0;
}

int save_reservation_info(int s_array[ROWS][COLS]) {
    FILE* file = fopen("C:\\Users\\born4\\Desktop\\reservation_data.txt", "w");
    if (!file) {
        return -1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%d ", s_array[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}

void selection_sort(struct user_info users[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(users[j].id, users[min_idx].id) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            struct user_info temp = users[i];
            users[i] = users[min_idx];
            users[min_idx] = temp;
        }
    }
}

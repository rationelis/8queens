#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

bool has_diagonal_attacks(int arr[]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(arr[i] - arr[j]) == abs(i - j)) {
                return true;
            }
        }
    }
    return false;
}

void print_solution(int arr[]) {
    char board[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = '-';
        }
    }

    for (int i = 0; i < 8; i++) {
        board[i][arr[i] - 1] = 'X';
    }

    printf("Solution:\n");
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void solve(int arr[], int start, int end, int *counter) {
    if (start == end) {
        if (!has_diagonal_attacks(arr)) {
            // Found a solution!
            (*counter)++;
            print_solution(arr);
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            solve(arr, start + 1, end, counter);
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int range[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(range) / sizeof(range[0]);
    int counter = 0;

    clock_t start = clock();
    solve(range, 0, size - 1, &counter);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Total solutions found: %d\n", counter);
    printf("Time elapsed: %.3f seconds\n", cpu_time_used);

    return 0;
}

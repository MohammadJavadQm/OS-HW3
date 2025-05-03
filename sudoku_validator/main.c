#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

int grid[9][9] = {
    {6,2,4,5,3,9,1,8,7},
    {5,1,9,7,2,8,6,3,4},
    {8,3,7,6,1,4,2,9,5},
    {1,4,3,8,6,5,7,2,9},
    {9,5,8,2,4,7,3,6,1},
    {7,6,2,3,9,1,4,5,8},
    {3,7,1,9,5,6,8,4,2},
    {4,9,6,1,8,2,5,7,3},
    {2,8,5,4,7,3,9,1,6}
};

bool is_sudoku_valid = true;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* validate_rows(void* param) {
    for (int row = 0; row < 9; row++) {
        bool used[10] = {false};
        for (int col = 0; col < 9; col++) {
            int value = grid[row][col];
            if (value < 1 || value > 9 || used[value]) {
                pthread_mutex_lock(&lock);
                is_sudoku_valid = false;
                pthread_mutex_unlock(&lock);
                return NULL;
            }
            used[value] = true;
        }
    }
    return NULL;
}

void* validate_columns(void* param) {
    for (int col = 0; col < 9; col++) {
        bool used[10] = {false};
        for (int row = 0; row < 9; row++) {
            int value = grid[row][col];
            if (value < 1 || value > 9 || used[value]) {
                pthread_mutex_lock(&lock);
                is_sudoku_valid = false;
                pthread_mutex_unlock(&lock);
                return NULL;
            }
            used[value] = true;
        }
    }
    return NULL;
}

void* validate_box(void* param) {
    int box_id = *(int*)param;
    int start_row = (box_id / 3) * 3;
    int start_col = (box_id % 3) * 3;
    bool used[10] = {false};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int value = grid[start_row + i][start_col + j];
            if (value < 1 || value > 9 || used[value]) {
                pthread_mutex_lock(&lock);
                is_sudoku_valid = false;
                pthread_mutex_unlock(&lock);
                return NULL;
            }
            used[value] = true;
        }
    }
    return NULL;
}

int main() {
    pthread_t thread_pool[11];
    int box_indices[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    pthread_create(&thread_pool[0], NULL, validate_rows, NULL);
    pthread_create(&thread_pool[1], NULL, validate_columns, NULL);
    
    for (int i = 0; i < 9; i++) {
        pthread_create(&thread_pool[i + 2], NULL, validate_box, &box_indices[i]);
    }

    for (int i = 0; i < 11; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    printf("Sudoku board is %s\n", is_sudoku_valid ? "valid" : "invalid");

    pthread_mutex_destroy(&lock);
    return 0;
}
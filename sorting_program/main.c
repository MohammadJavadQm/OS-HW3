#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int array[SIZE] = {7, 2, 9, 4, 5, 1, 3, 8, 6, 10};
int sorted_array[SIZE];

typedef struct {
    int start;
    int end;
} SortArgs;

void bubble_sort(int arr[], int start, int end) {
    int length = end - start;
    for (int i = 0; i < length - 1; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid, k = 0;
    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            sorted_array[k++] = arr[i++];
        } else {
            sorted_array[k++] = arr[j++];
        }
    }
    while (i < mid) sorted_array[k++] = arr[i++];
    while (j < right) sorted_array[k++] = arr[j++];
}

void* merge_thread(void* arg) {
    merge(array, 0, SIZE / 2, SIZE);
    return NULL;
}

void* sort_thread(void* arg) {
    SortArgs* args = (SortArgs*)arg;
    bubble_sort(array, args->start, args->end);
    return NULL;
}

int main() {
    pthread_t t1, t2, t_merge;
    SortArgs args1 = {0, SIZE / 2};
    SortArgs args2 = {SIZE / 2, SIZE};

    pthread_create(&t1, NULL, sort_thread, &args1);
    pthread_create(&t2, NULL, sort_thread, &args2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_create(&t_merge, NULL, merge_thread, NULL);
    pthread_join(t_merge, NULL);

    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    return 0;
}
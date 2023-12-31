#include <stdio.h>
#include <stdlib.h>

void nullCheck(void* ptr) {
    if(ptr == NULL) {
        printf("not enough memory");
        exit(0);
    }
}

void allocateArr(int** ptr, size_t n) {
    *ptr = malloc(sizeof(int) * n);
    nullCheck(*ptr);
}

int* initArray(int n) {
    int* arr;
    allocateArr(&arr, n);
    for(size_t i = 0; i < n; i++) arr[i] = i;
    return arr;
}

void printArr(int* arr, int n) {
    for(size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* findSubArr(int* arr1, int* arr2, size_t n1, size_t n2) {
    for(size_t i = 0; i < n1; i++) {
        size_t j = 0;
        int* mem = &arr1[i];
        while(i + j < n1 && arr1[i + j] == arr2[j] && j < n2) {
            if(j == n2 - 1 && arr1[i + j] == arr2[j]) return mem;
            j++; 
        }
    }
    return NULL;
}

void removeSubArr(int* arr1, int* arr2, size_t* n1, size_t n2) {
    int* ptr;
    while((ptr = findSubArr(arr1, arr2, *n1, n2)) != NULL) {
        for(int* i = ptr ; i < arr1 + *n1 - n2; i++) {
            *i = *(i + n2);
        }
        *n1 -= n2;
    }
}

int main() {
    size_t n1 = 8;
    size_t n2 = 2;
    int* arr1 = malloc(sizeof(int) * n1);
    int* arr2 = malloc(sizeof(int) * n2); 
    for(size_t i = 1; i < 7; i++) arr1[i - 1] = i;
    for(size_t i = 6; i <= n1; i++) arr1[i] = i - 5;
    for(size_t i = 1; i < 3; i++) arr2[i - 1] = i;
    printArr(arr1, n1);
    printArr(arr2, n2);
    removeSubArr(arr1, arr2, &n1, n2);
    printArr(arr1, n1);
    free(arr1);
    free(arr2);
}

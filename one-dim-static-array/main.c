#include <stdio.h>

void scanArr(int* arr, int n) {
    for(size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArr(int* arr, int n) {
    for(size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    /* *a = *a ^ *b; */
    /* *b = *a ^ *b; */
    /* *a = *a ^ *b; */
}

void revertArray(int* arr, int n) {
    for(size_t i = 0; i <= n / 2; i++) {
        swap(&arr[i], &arr[n - i - 1]);
    }
}

int maxInArray(int *arr, int n) {
    int max = arr[0];
    for(size_t i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

size_t findInArr(int* arr, int n, int x) {
    size_t i = 0;
    while(arr[i] != x && i < n) i++; 
    if(arr[i] == x) return i + 1;
    else return -1;
}

size_t numberOfDigits(int x) {
    size_t i = 1;
    if(x < 0) x *= -1;
    while(x > 9) {
        x /= 10;
        i++;
    }
    return i;
}

void extractDigits(int* arr, int x, int n) {
    size_t xSize = numberOfDigits(x);      
    if(xSize > n) xSize = xSize - (xSize - n); 
    if(x == 0) {
        arr[0] = x;
        return;
    }
    for(size_t i = xSize; i > 0; i--) {
        arr[i - 1] = x % 10;
        x /= 10;
    }
}

// test -> 

int compareArrays(int* arr1, int* arr2, int n1, int n2) {
    size_t iter = n1 < n2 ? n1 : n2;
    size_t i = 0;
    for(i = 0; i < iter; i++) {
        if(arr1[i] > arr2[i]) return 1;
        if(arr1[i] < arr2[i]) return -1;
    }
    if(arr1[i] == arr2[i] && n1 < n2) return -1;
    if(arr1[i] == arr2[i] && n2 < n1) return 1;
    return 0;
}

int main() {
    int arr[32];    
    int arr_for_digits[30];
    int n = 6;
    scanArr(arr, n);
    int c = findInArr(arr, n, 6);
    revertArray(arr, n);
    printArr(arr, n);
    printf("maxInArray -> %d\n", maxInArray(arr, n));
    printf("findInArray(6) -> %d\n", c);
    printf("[extractDigits test, x = 340123]:\n");
    for(size_t i = 0; i < 30; i++) arr_for_digits[i] = i + 1;
    extractDigits(arr_for_digits, 340123, 30);
    printArr(arr_for_digits, 10);
    int arr1[32];
    int arr2[32];
    int i = 0;
    for(i = 0; i < 10; i++) {
        arr1[i] = i;
        arr2[i] = i;
    }
    printf("[Test for compareArrays] 0 == %d\n", compareArrays(arr1, arr2, i, i));
    arr1[i + 1] = i + 1;
    printf("Result of compareArrays -> %d\n", compareArrays(arr1, arr2, i + 1, i));
}
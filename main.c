#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Ращупкин ЕВ
КЭ-203

Сравнение сортировки
Расчёской
и
Прямым выбором
*/



void PrintArray(int *arr, int n){
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void RandArr(int *arr, int size){
    int i;
    for (i = 0; i < size; i++){
        arr[i] = rand();
    }
}

void CopyArr(int *arr1, int *arr2, int size){
    int i;
    for (i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }

}


void SelectionSort(int *arr, int size){
    int min, tmp;
    for (int i = 0; i < size - 1; i++) {
        min = i; 
        for (int j = i + 1; j < size; j++){  
            if (arr[j] < arr[min]) 
                min = j;
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

void CombSort(int *arr, int size){
    int elementRight, buff;
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < i + 1; j++) {


            elementRight = (size - 1) - (i - j);

            if (arr[j] > arr[elementRight]) {

                buff = arr[j];
                arr[j] = arr[elementRight];
                arr[elementRight] = buff;
            }

        }
    }
}


int main() {
    int n;
    clock_t time_end;
    clock_t time_start;

    printf("Len of arr: ");
    scanf("%d", &n);

    int *arr1 = malloc(n * sizeof(int));
    printf("Fill... \n");
    RandArr (arr1, n);
    printf("Filled. \n");
    //PrintArray (arr1, n);

    
    int *arr2 = malloc(n * sizeof(int));
    printf("Copy... \n");
    CopyArr(arr1, arr2, n);
    printf("Copied. \n");
    //PrintArray(arr2, n);


    printf("Sort by selection sort...\n");
    time_start = clock();
    SelectionSort(arr1, n);
    time_end = clock() - time_start;
    printf("Sorted by selection sort.\n");
    printf("%d ms\n", time_end * 1000 / CLOCKS_PER_SEC);

    printf("Sort by comb sort...\n");
    time_start = clock();
    CombSort(arr2, n);
    time_end = clock() - time_start;    
    printf("Sorted by comb sort.\n");
    printf("%d ms\n", time_end * 1000 / CLOCKS_PER_SEC);



    free(arr1);
    free(arr2);
}

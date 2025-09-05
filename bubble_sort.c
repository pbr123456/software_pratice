#include <stdio.h>

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped; // 用于优化，如果某一轮没有交换，说明已经有序
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        
        // 每一轮将最大的元素"冒泡"到末尾
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换相邻元素
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        // 如果这一轮没有发生交换，说明数组已经有序
        if (!swapped) {
            break;
        }
    }
}

// 打印数组函数
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("原始数组: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("排序后的数组: \n");
    printArray(arr, n);
    
    return 0;
}
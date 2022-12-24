#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define N 1000
#define A 1
#define B 10000

int full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
int calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double findMultiplieElement(double* ptr_array, int n, int k);

void main() {
    setlocale(LC_ALL, "RUS");

    // 1
    double array[N];

    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    full_elements(array, size);
    put_elements(array, size);

    printf("\n%d", find_element(array, size, array[3]));
    printf("\n%.2lf", findMultiplieElement(array, size, 2));
}

int full_elements(double* ptr_array, int n) {
    int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned)ltime / 2;
    srand(stime);
    for (int i = 0; i < n; i++)
    {
        ptr_array[i] = A + rand() % (B - A);
    }
    puts("\n\n\nМассив заполнен случайными значениями!");
    return 0;
}

int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %.2lf\n", i, ptr_array[i]);
    }
    return 0;
}

int calc_elements(double* ptr_array, int n) {
    double min = 100000;
    int minNum;
    for (int i = 0; i < n; i++)
    {
        if (ptr_array[i] < min) {
            min = ptr_array[i];
            minNum = i;
        }
    }
    return minNum;
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0;
    for (int i = begin; i < end; i++)
    {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    int elementId = -1;
    for (int i = 0; i < n; i++)
    {
        if (ptr_array[i] == element) {
            elementId = i + 1;
        }
    }
    return elementId;
}

double findMultiplieElement(double* ptr_array, int n, int k) {
    double min = 1000000;
    for (int i = 0; i < n; i++)
    {
        if ((i % k == 0) && (ptr_array[i] < min)) {
            min = ptr_array[i];
        }
    }
    return min;
}
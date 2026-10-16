#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swapped = 1;
            }
        if (!swapped) break;
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[m]) m = j;
        int t = a[i]; a[i] = a[m]; a[m] = t;
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int t[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) t[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = t[i];
}

void mergeSort(int a[], int t[], int l, int r)
{
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, t, l, m);
    mergeSort(a, t, m + 1, r);
    merge(a, t, l, m, r);
}

void quickSort(int a[], int l, int r)
{
    if (l >= r) return;
    int pivot = a[l + (r - l) / 2], i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        }
    }
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

void heapify(int a[], int n, int root)
{
    int largest = root, l = 2 * root + 1, r = 2 * root + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != root) {
        int t = a[root]; a[root] = a[largest]; a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapify(a, i, 0);
    }
}

void countingSort(int a[], int n)
{
    int min = a[0], max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    long long range = (long long)max - min + 1;
    if (range > 2000000) {
        insertionSort(a, n);
        return;
    }
    int *count = calloc((size_t)range, sizeof *count);
    if (!count) {
        insertionSort(a, n);
        return;
    }
    for (int i = 0; i < n; i++) count[a[i] - min]++;
    int k = 0;
    for (long long i = 0; i < range; i++)
        while (count[i]-- > 0) a[k++] = (int)(i + min);
    free(count);
}

void radixSort(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            insertionSort(a, n);
            return;
        }
        if (a[i] > max) max = a[i];
    }
    int *out = malloc((size_t)n * sizeof *out);
    if (!out) {
        insertionSort(a, n);
        return;
    }
    for (long long exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = {0};
        for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) out[--count[(a[i] / exp) % 10]] = a[i];
        for (int i = 0; i < n; i++) a[i] = out[i];
        if (exp > max / 10) break;
    }
    free(out);
}

typedef void (*SortFunction)(int *, int);

void runTest(const char *name, SortFunction sort, const int *source, int n)
{
    int *copy = malloc((size_t)n * sizeof *copy);
    if (!copy) {
        printf("%-15s | memory allocation failed\n", name);
        return;
    }
    for (int i = 0; i < n; i++) copy[i] = source[i];
    clock_t start = clock();
    sort(copy, n);
    clock_t end = clock();
    printf("%-15s | %.6f seconds\n", name, (double)(end - start) / CLOCKS_PER_SEC);
    free(copy);
}

void runMerge(int *a, int n)
{
    int *temp = malloc((size_t)n * sizeof *temp);
    if (!temp) return;
    mergeSort(a, temp, 0, n - 1);
    free(temp);
}

void runQuick(int *a, int n) { quickSort(a, 0, n - 1); }

int main(void)
{
    const int sizes[] = {1000, 2000, 5000};
    srand((unsigned int)time(NULL));
    printf("SORTING ALGORITHM TIME COMPARISON\n");
    printf("Times vary by computer, compiler, and system load.\n");
    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        int *data = malloc((size_t)n * sizeof *data);
        if (!data) {
            printf("Memory allocation failed for n=%d.\n", n);
            return 1;
        }
        for (int i = 0; i < n; i++) data[i] = rand() % 100000;
        printf("\nNumber of elements: %d\n", n);
        runTest("Bubble sort", bubbleSort, data, n);
        runTest("Selection sort", selectionSort, data, n);
        runTest("Insertion sort", insertionSort, data, n);
        runTest("Merge sort", runMerge, data, n);
        runTest("Quick sort", runQuick, data, n);
        runTest("Heap sort", heapSort, data, n);
        runTest("Counting sort", countingSort, data, n);
        runTest("Radix sort", radixSort, data, n);
        free(data);
    }
    return 0;
}

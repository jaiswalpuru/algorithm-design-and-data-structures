#include "def.h"

void quick_sort_ascending(vi &v, int low, int high);
int partition_ascend(vi &v, int low, int high);

void quick_sort_ascending(vi &v, int low, int high) {
    int pivot = partition_ascend(v, low, high);
    if (low < pivot-1) quick_sort_ascending(v, low, pivot-1);
    if (pivot < high) quick_sort_ascending(v, pivot, high);
}

int partition_ascend(vi &v, int low, int high) {
    int pivot = v[low];
    int i=low,j=high;
    while(i<=j) {
        while(v[i] < pivot) i++;
        while(v[j] > pivot) j--;
        if (i<=j) {
            std::swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    return i;
}

#pragma once
#include <utility>
#include <vector>

template <typename Comparable>
void merge(std::vector<Comparable> &a, std::vector<Comparable> &tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd) {
        if(a[leftPos] <= a[rightPos]) {
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        } else {
            tmpArray[tmpPos++] = std::move(a[rightPos++]);
        }
    }

    while(leftPos <= leftEnd) {
        tmpArray[tmpPos++] = std::move(a[leftPos++]);
    }

    while(rightPos <= rightEnd) {
        tmpArray[rightPos++] = std::move(a[rightPos++]);
    }

    for(int i = 0; i < numElements; ++i, --rightEnd) {
        a[rightEnd] = std::move(tmpArray[rightEnd]);
    }
}

template <typename Comparable>
void mergeSort(std::vector<Comparable> &a, std::vector<Comparable> &tmpArray, int left, int right) {
    if(left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

template <typename Comparable>
void mergeSort(std::vector<Comparable> &a) {
    std::vector<Comparable> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

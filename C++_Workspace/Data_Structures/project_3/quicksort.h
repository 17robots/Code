#pragma once
#include <vector>
#include <utility>

template <typename Comparable>
const Comparable& median3(std::vector<Comparable> &a, int left, int right) {
    int center = (left + right) / 2;
    
    if(a[center] < a[left]) {
        std::swap(a[left], a[center]);
    }
    
    if(a[right] < a[left]) {
        std::swap(a[left], a[right]);
    }
    
    if(a[right] < a[center]) {
        std::swap(a[center], a[right]);
    }
    
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <typename Comparable>
void quickSort(std::vector<Comparable> &a, int left, int right) {
    // removed the if statement condition from before and changed to the one below
    if(a.size() > 1) {
        const Comparable& pivot = median3(a, left, right);
        
        // partitioning 
        int i = left, j = right - 1;
        for(; ;) {
            while(a[++i] < pivot) { }
            while(pivot < a[--j]) { }
            if(i < j) {
                std::swap(a[i], a[j]);
            } else {
                break;
            }
        }
        
        std::swap(a[i], a[right - 1]);
        
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
}

template<typename Comparable>
void quickSort(std::vector <Comparable> &a) {
    quickSort(a, 0, a.size() - 1);
}

#pragma once
#include <vector>
#include <functional>
#include <string>

template<typename T, typename Compare>
void selectionSort(std::vector<T>& arr, Compare comp) {
	for (size_t i = 0; i < arr.size(); ++i) {
		size_t minIdx = i;
		for (size_t j = i + 1; j < arr.size(); ++j) {
			if (comp(arr[j], arr[minIdx])) {
				minIdx = j;
			}
		}
		if (minIdx != i) std::swap(arr[i], arr[minIdx]);
	}
}

template<typename T, typename Key, typename Equal>
int linearSearch(const std::vector<T>& arr, const Key& key, Equal eq) {
	for (size_t i = 0; i < arr.size(); ++i) {
		if (eq(arr[i], key)) return static_cast<int>(i);
	}
	return -1;
}

template<typename T, typename Key, typename Compare>
int binarySearch(const std::vector<T>& arr, const Key& key, Compare comp) {
	int left = 0;
	int right = static_cast<int>(arr.size()) - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (comp(arr[mid], key)) {
			left = mid + 1;
		} else if (comp(key, arr[mid])) {
			right = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

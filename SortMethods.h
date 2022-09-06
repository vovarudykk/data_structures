#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string>

template<typename T>
class SortMethods
{
public:
	static void Insertion(T* arr, int size) {
		for (int i = 1; i < size; i++) {
			for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}

	static void Selection(T* arr, int size) {
		for (int i = 0; i < size - 1; i++) {
			int min_index = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j] < arr[min_index]) {
					min_index = j;
				}
			}
			if (min_index != i) {
				int temp = arr[i];
				arr[i] = arr[min_index];
				arr[min_index] = temp;
			}
		}
	}

	static void Bubble(T* arr, int size) {
		bool swapped = true;
		for (int i = 0; swapped; i++) {
			swapped = false;
			for (int j = 0; j < size - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					swapped = true;
				}
			}
		}
	}

	//static void Bubble(T* arr, int size) {
	//	for (int i = 0; i < size - 1; i++) {
	//		for (int j = 0; j < size - 1 - i; j++) {
	//			if (arr[j] > arr[j + 1]) {
	//				int temp = arr[j];
	//				arr[j] = arr[j + 1];
	//				arr[j + 1] = temp;
	//			}
	//		}
	//	}
	//}

	static void Shell(T* arr, int size) {
		for (int step = size / 2; step > 0; step /= 2) {
			for (int i = step; i < size; i++) {
				for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
					int temp = arr[j];
					arr[j] = arr[j + step];
					arr[j + step] = temp;
				}
			}
		}
	}

	static void Shaker(T* arr, int size) {
		bool swapped = true;
		int start = 0, temp = 0;
		int end = size - 1;
		while(swapped) {
			swapped = false;

			for (int i = start; i < end; i++) {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					swapped = true;
				}
			}
			if (!swapped) break;
			swapped = false;
			end--;

			for (int i = end - 1; i >= start; i--) {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					swapped = true;
				}
			}
			start++;
		}
	}

	static void startQuickSort(T* arr, int size) {
		quickSort(arr, 0, size-1);
	}
	
	static void quickSort(T* arr, int start, int end) {
		if (start < end) {
			int pivot = findPivot(arr, start, end);
			quickSort(arr, start, pivot - 1);
			quickSort(arr, pivot + 1, end);
		}
	}


	static int findPivot(T* arr, int start, int end) {
		int pivot = arr[end];
		int index = start - 1;
		int temp = 0;
		for (int j = start; j < end; j++) {
			if (arr[j] <= pivot) {
				index++;
				temp = arr[index];
				arr[index] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[index +1];
		arr[index +1] = arr[end];
		arr[end] = temp;
		return index + 1;
	}

	//static sortString(string& str, int MAX_CHAR) {
	//	int charCount[MAX_CHAR] = { 0 };

	//	for (int i = 0; i < str.length(); i++) {
	//		charCount[str[i] - 'a']++;
	//	}

	//	for (int i = 0; i < MAX_CHAR; i++) {
	//		for (int j = 0; j < charCount[i]; j++) {
	//			cout << (char)('a' + i);
	//		}
	//	}
	//}

	static void generateRandomNumbers(T* arr, int size, int max, int min) {
		srand((unsigned)time(NULL));
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	static void printConsole(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};


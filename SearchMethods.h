#pragma once
class SearchMethods
{
public: 
	static int binarySearch(int* arr, int start, int end, int item) {
		if (end >= start) {
			int middle = start + (end - start) / 2;

			if (arr[middle] == item) {
				return middle;
			}

			if (arr[middle] > item) {
				return binarySearch(arr, start, middle - 1, item);
			}
			else {
				return binarySearch(arr, middle + 1, end, item);
			}
		}
		return -1;
	}

	static int linearSearch(int* arr, int size, int item) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == item) {
				return i;
			}
		}
		return -1;
	}

	static int findWithBarrier(int* arr, int size, int item) {
		if (size != 0) {
			if (arr[size - 1] == item) {
				return size - 1;
			}

			int last = arr[size - 1];

			arr[size - 1] = item;
			int i = 0;
			while (arr[i] != item) {
				i++;
			}

			arr[size - 1] = last;

			if (i != size - 1) {
				return i;
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}

};


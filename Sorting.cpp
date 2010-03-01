#include "Sorting.h"

vector<int> Sorting::selectionSort(vector<int> items) {
	
	for (int outer = 0; outer < items.size(); outer++) {
		int inner = outer;
		int minIdx = outer;
		for (inner = outer + 1; inner < items.size(); inner++) {
			if (items.at(inner) < items.at(minIdx)) {
				minIdx = inner;
			}
		}
		if (minIdx != outer) {
			swap(items[minIdx], items[outer]);
		}
	}
	return items;
}

void Sorting::swap(int &val1, int &val2) {
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}

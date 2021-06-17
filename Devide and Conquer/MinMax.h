#pragma once

#include <iostream>
#include <vector>
using namespace std;


void MinMaxDC_Recursion(vector<long> arr, long l, long r, long& min, long& max) {
	if (l >= r - 1) {

		if (arr[l] < arr[r]) {
			min = arr[l];
			max = arr[r];
		}
		else {
			min = arr[r];
			max = arr[l];
		}

	}
	else {
		long m = (l + r) / 2;
		long minL = 0, minR = 0;
		long maxL = 0, maxR = 0;

		MinMaxDC_Recursion(arr, l, m, minL, maxL);
		MinMaxDC_Recursion(arr, m + 1, r, minR, maxR);

		min = (minL < minR) ? minL : minR;
		max = (maxL > maxR) ? maxL : maxR;
	}
}

void MinMaxDC_NonRecursion(vector<long> arr, long size, long& min, long& max) {
	long i;
	if (size == 1) {
		return;
	}
	else if (size % 2 == 0) {

		if (arr[0] > arr[1]) {
			min = arr[0];
			max = arr[1];
		}
		else {
			min = arr[1];
			max = arr[0];
		}

		i = 2;
	}
	else {
		min = arr[0];
		max = arr[0];
		i = 1;
	}

	while (i < size - 1) {

		if (arr[i] > arr[i + 1]) {
			if (arr[i] > max)
				max = arr[i];

			if (arr[i + 1] < min)
				min = arr[i + 1];
		}
		else
		{
			if (arr[i + 1] > max)
				max = arr[i + 1];

			if (arr[i] < min)
				min = arr[i];
		}

		i += 2;
	}
}
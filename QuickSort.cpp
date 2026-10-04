// Quick Sort O(nlogn) O(n*n)
#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int Partition(vector <int>& A, int start, int end) { // "start" and "end" are indexes
	int pivot = A[end];
	int pindex = start;
	
	for (int i = start; i < end; i++) { // Elements less than or equal to the pivot are on the left side
		if (A[i] <= pivot) { 
			swap(A[i], A[pindex]); // Pivot is never touched again after this swap
			pindex++;
		}
	}
	swap(A[pindex], A[end]);
	return pindex;
}

void QuickSort(vector <int>& A, int start, int end) { // "start" and "end" are indexes
	if (start <= end) {
		int n = A.size();
		int pindex = Partition(A, start, end); // Get the pivot and set its position
		QuickSort(A, start, pindex - 1); // Work with the left side next to the pivot
		QuickSort(A, pindex + 1, end); // Work with the right side next to the pivot
	}
}

int main() {
	int n;
	cin >> n; // Amount of elements
	
	vector <int> Arr(n); // Vector with "n" elements
	
	for (int i = 0; i < n; i++)
		cin >> Arr[i]; // Assign every vector's element a value
		
	QuickSort(Arr, 0, n - 1);
	
	for (int i : Arr) cout << i << ' ';
	
	return 0;
}
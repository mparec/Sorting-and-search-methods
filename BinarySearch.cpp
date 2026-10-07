// Binary Search O(logn)
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int>& A, int target) {
	int min = 0, max = A.size() - 1;
	while (min <= max) {
		int mid = min + (max - min) / 2;
		if (A[mid] == target)
			return mid;
		else if (A[mid] < target)
			min = mid + 1;
		else
			max = mid - 1;
	}
	return -1;
}

int main() {
	int n;
	cout << "BINARY SEARCH\nEnter the amount of numbers: ";
	cin >> n;
	
	if (n <= 0) {
		cout << "ERROR: The amount of numbers must be greater than 0\n";
		cout << "Closing program...";
		return 1;
	}
	
	vector <int> A(n);
	
	cout << "IMPORTANT: Enter numbers in increasing order\n";
	for (int i = 0; i < n; i++) {
		cout << "Enter number " << i << "/" << n - 1 << ": ";
		cin >> A[i];
		if (i > 0 && A[i] < A[i - 1]) {
			cout << "ERROR: Numbers must be in increasing order\n";
			cout << A[i] << " < " << A[i - 1] << '\n';
			cout << "Closing program...";
			return 1;
		}
	}
		
	int num;
	cout << "Enter your target: ";
	cin >> num;
	
	int answer = binarySearch(A, num);
	cout << "Target's index: " << answer << '\n';
	if (answer == -1) cout << "Your target " << "'" << num << "' was not found";
	
	return 0;
}
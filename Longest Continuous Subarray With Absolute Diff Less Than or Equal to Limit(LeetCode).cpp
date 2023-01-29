// C++ program to find the longest sub-array
// where the absolute difference between any
// two elements is not greater than X

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
long long mod=998244353;
#define lli long long int
#define INF 1000000000
#define pb push_back
void longestSubarray(int* A, int N, int X)
{
	int maxLen = 0;
	int beginning = 0;
	map<int, int> window;
	int start = 0, end = 0;
	for (; end < N; end++) {
		window[A[end]]++;
		auto minimum = window.begin()->first;
		auto maximum = (--window.end())->first;
		if (maximum - minimum <= X) {
			if (maxLen < end - start + 1) {
				maxLen = end - start + 1;
				beginning = start;
			}
		}
		// Decrease the size of the window
		else {
			while (start < end) {
				window[A[start]]--;
				if (window[A[start]] == 0) {

					window.erase(window.find(A[start]));
				}
				start++;

				auto minimum = window.begin()->first;
				auto maximum = window.rbegin()->first;
				if (maximum - minimum <= X)
					break;
			}
		}
	}
	for (int i = beginning; i < beginning + maxLen; i++)
		cout << A[i] << " ";
}
int main()
{
	int arr[] = { 15, 10, 1, 2, 4, 7, 2 }, X = 5;

	int n = sizeof(arr) / sizeof(arr[0]);

	longestSubarray(arr, n, X);

	return 0;
}

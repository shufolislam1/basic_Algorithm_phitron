#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

int binarySearch(int nums[], int n, int k) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == k) {
            return mid;
        } else if (nums[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int found = binarySearch(nums, n, k);

    if (found != false) {
        cout<< found << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}

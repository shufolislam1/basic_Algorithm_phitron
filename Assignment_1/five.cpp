#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int l, int r, int mid) {
    int left_size = mid - l + 1;
    int right_size = r - mid +1;
    int L[left_size];
    int R[right_size];

    for (int i = 0; i < left_size; i++) {
        L[i] = nums[l + i];
    }
    for (int i = 0; i < right_size; i++) {
        R[i] = nums[mid + 1 + i];
    }

    int lp = 0, rp = 0;
    int k = l;

    while (lp < left_size && rp < right_size) {
        if (L[lp] >= R[rp]) { 
            nums[k++] = L[lp++];
        } else {
            nums[k++] = R[rp++];
        }
    }

    while (lp < left_size) {
        nums[k++] = L[lp++];
    }

    while (rp < right_size) {
        nums[k++] = R[rp++];
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r, mid);
    }
}

int main() {
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }


    // arr1 ar arr2 duita eksathe jog kore nums arr banaisi jar length n+m;
    for (int i = 0; i < n; i++) {
        nums[i] = arr1[i];
    }
    for (int i = 0; i < m; i++) {
        nums[n + i] = arr2[i];
    }

    mergeSort(0, n + m - 1);

    for (int i = 0; i < n + m; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

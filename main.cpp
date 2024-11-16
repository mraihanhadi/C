#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // Urutkan nilai batu
    sort(v.begin(), v.end());

    int max_count = 0;
    int left = 0;

    // Sliding window
    for (int right = 0; right < n; ++right) {
        // Geser left hingga kondisi terpenuhi
        while (v[right] - v[left] > k) {
            ++left;
        }
        // Hitung jumlah batu dalam jendela saat ini
        max_count = max(max_count, right - left + 1);
    }

    cout << max_count << endl;

    return 0;
}

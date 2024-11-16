// Soal C
/*
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int freq[10] = {0}; // Frequency array for numbers % 10
    int c = 0;

    // Input numbers and calculate modulo 10 frequencies
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int mod = num % 10;
        int complement = (k - mod + 10) % 10; // Ensure non-negative complement
        c += freq[complement]; // Add pairs that satisfy the condition
        freq[mod]++;           // Update frequency
    }

    // Output the result
    cout << c << endl;
    return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk menghitung langkah rook
int rookMoves(int row, int col) {
    return (8 - row) + (row - 1) + (8 - col) + (col - 1);
}

// Fungsi untuk menghitung langkah bishop
int bishopMoves(int row, int col) {
    int d1 = min(8 - row, 8 - col); // Diagonal kanan atas
    int d2 = min(row - 1, col - 1); // Diagonal kiri bawah
    int d3 = min(8 - row, col - 1); // Diagonal kiri atas
    int d4 = min(row - 1, 8 - col); // Diagonal kanan bawah
    return d1 + d2 + d3 + d4;
}

// Fungsi untuk menghitung langkah queen
int queenMoves(int row, int col) {
    return rookMoves(row, col) + bishopMoves(row, col);
}

// Fungsi untuk menghitung langkah knight
int knightMoves(int row, int col) {
    int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8) {
            count++;
        }
    }
    return count;
}

//Soal H
/*
int main() {
    string piece, position;
    cin >> piece >> position;

    // Konversi posisi menjadi koordinat numerik
    int col = position[0] - 'a' + 1; // 'a' -> 1, 'b' -> 2, ...
    int row = position[1] - '0';     // '1' -> 1, '2' -> 2, ...

    int result = 0;

    // Hitung jumlah gerakan berdasarkan tipe bidak
    if (piece == "rook") {
        result = rookMoves(row, col);
    } else if (piece == "bishop") {
        result = bishopMoves(row, col);
    } else if (piece == "queen") {
        result = queenMoves(row, col);
    } else if (piece == "knight") {
        result = knightMoves(row, col);
    }

    // Cetak hasil
    cout << result << endl;

    return 0;
}*/

//Soal B
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Cari elemen terbesar
    int maxValue = *max_element(a.begin(), a.end());

    // Jika k >= n, ganti semua elemen menjadi maxValue
    if (k >= n) {
        cout << n * maxValue << endl;
        return 0;
    }

    // Jika k < n, lakukan penggantian pada elemen terkecil
    sort(a.begin(), a.end()); // Urutkan elemen
    long long currentSum = 0;
    for (int i = 0; i < n; i++) {
        currentSum += a[i];
    }

    // Ganti hingga k elemen terkecil dengan maxValue
    long long totalIncrease = 0;
    for (int i = 0; i < k; i++) {
        totalIncrease += (maxValue - a[i]);
    }

    // Hitung jumlah maksimum
    long long maxSum = currentSum + totalIncrease;

    cout << maxSum << endl;
    return 0;
}
*/
//Soal E
/*
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Fungsi untuk menghitung total rotasi
long long calculateTotalDistance(long long P, long long k) {
    long long totalDistance = 0;
    long long currentP = P;
    while (currentP > 0) {
        totalDistance += currentP;
        currentP /= k;
    }
    return totalDistance;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<string> names(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i];
    }

    int currentIndex = 0; // Awalnya petunjuk di nama pertama (index 0)

    for (int i = 0; i < Q; i++) {
        long long P, k;
        cin >> P >> k;

        // Hitung total jarak rotasi
        long long totalDistance = calculateTotalDistance(P, k);

        // Hitung posisi akhir dengan modulo
        long long effectiveDistance = totalDistance % N;
        currentIndex = (currentIndex - effectiveDistance + N) % N;

        // Output nama yang menerima hadiah
        cout << names[currentIndex] << endl;
    }

    return 0;
}
*/

//Soal K
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Hitung jumlah minimum dari bilangan unik 1 sampai k
    int minSum = k * (k + 1) / 2;

    // Jika n lebih kecil dari minSum, keluarkan "ga bisa"
    if (n < minSum) {
        cout << "ga bisa" << endl;
        return 0;
    }

    // Inisialisasi array hasil
    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = i + 1; // Mulai dengan 1, 2, ..., k
    }

    // Hitung sisa yang perlu ditambahkan
    int remaining = n - minSum;

    // Distribusikan sisa ke elemen terbesar sambil menjaga urutan
    int index = k - 1;
    while (remaining > 0) {
        result[index]++;
        remaining--;
        if (index > 0 && result[index] > result[index - 1] + 1) {
            index--; // Lanjutkan ke elemen sebelumnya
        } else {
            index = k - 1; // Kembali ke elemen terakhir
        }
    }

    // Cetak hasil
    for (int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//Soal I
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk memeriksa apakah batas ketinggian X memungkinkan
bool can_cut(long long X, const vector<int>& heights, long long M, int K) {
    vector<long long> woods;

    // Hitung panjang kayu yang didapatkan setelah menebang
    for (int h : heights) {
        if (h > X) {
            woods.push_back(h - X);
        }
    }

    // Jika jumlah kayu kurang dari K, tidak bisa dipotong
    if (woods.size() < K) return false;

    // Urutkan kayu dari yang terpanjang
    sort(woods.rbegin(), woods.rend());

    // Ambil K kayu terbesar untuk pajak
    long long tax = 0;
    for (int i = 0; i < K; ++i) {
        tax += woods[i];
    }

    // Hitung total kayu yang tersisa
    long long total_wood = 0;
    for (long long wood : woods) {
        total_wood += wood;
    }
    total_wood -= tax;

    // Periksa apakah kayu tersisa memenuhi kebutuhan M
    return total_wood >= M;
}

int main() {
    int N, K;
    long long M;
    cin >> N >> M >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    long long low = 0, high = *max_element(heights.begin(), heights.end());
    long long result = -1;

    // Binary search untuk mencari batas ketinggian maksimum
    while (low <= high) {
        long long mid = (low + high) / 2;

        if (can_cut(mid, heights, M, K)) {
            result = mid; // Simpan batas ketinggian yang valid
            low = mid + 1; // Cari kemungkinan batas yang lebih tinggi
        } else {
            high = mid - 1; // Kurangi ruang pencarian
        }
    }

    cout << result << endl;

    return 0;
}
*/

//Soal G
/*
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
*/

//unique paths grid
/*
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = (grid[0][0] == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePaths(grid) << endl;
    return 0;
}
*/

//Knight's Minimum Moves
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minKnightMoves(int n, int x1, int y1, int x2, int y2) {
    vector<vector<int>> directions = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = 1;

    int moves = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            if (x == x2 && y == y2) return moves;

            for (auto& d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        moves++;
    }
    return -1; // Tidak mungkin (tidak akan terjadi pada papan catur)
}

int main() {
    int n = 8, x1 = 0, y1 = 0, x2 = 7, y2 = 7;
    cout << minKnightMoves(n, x1, y1, x2, y2) << endl;
    return 0;
}
*/

//Split Array into equal sums
/*
#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) totalSum += num;

    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2, currentSum = 0;
    for (int num : arr) {
        currentSum += num;
        if (currentSum == target) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << (canSplit(arr) ? "YES" : "NO") << endl;
    return 0;
}
*/

//Matrix Spiral Traversal
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) result.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; ++i) result.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) result.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiralOrder(matrix);
    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}
*/
//longest Substring without repeating
/*
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLength = 0, start = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
*/

//Shortest path in weighted grid
/*
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (x == n - 1 && y == m - 1) return cost;

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}
*/

//Longest rectangle in histogram
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ++i) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
*/

//Binary tree path sum
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + max(maxPathSum(root->left), maxPathSum(root->right));
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    cout << maxPathSum(root) << endl;
    return 0;
}

*/

//Minimum steps to equal elements
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + max(maxPathSum(root->left), maxPathSum(root->right));
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    cout << maxPathSum(root) << endl;
    return 0;
}

*/
//array rotation checker
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isRotation(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return false;
    string strA, strB;
    for (int num : a) strA += to_string(num) + " ";
    for (int num : b) strB += to_string(num) + " ";
    return (strA + strA).find(strB) != string::npos;
}

int main() {
    int n = 5;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {3, 4, 5, 1, 2};
    cout << (isRotation(a, b) ? "YES" : "NO") << endl;
    return 0;
}
*/

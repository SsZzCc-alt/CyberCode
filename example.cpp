/*
//////2.完美立方
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 枚举 a
    for (int a = 2; a <= N; a++) {
        int a3 = a * a * a;
        // 枚举 b
        for (int b = 2; b < a; b++) {
            int b3 = b * b * b;
            // 枚举 c，满足 b <= c
            for (int c = b; c < a; c++) {
                int c3 = c * c * c;
                int d3 = a3 - b3 - c3;
                if (d3 < c * c * c) continue; // d < c 不满足 b<=c<=d
                // 枚举 d，满足 c <= d 且 d^3 == d3
                for (int d = c; d <= N; d++) {
                    if (d * d * d == d3) {
                        cout << "Cube = " << a
                             << ", Triple = (" << b << "," << c << "," << d << ")"
                             << endl;
                        break;
                    }
                    if (d * d * d > d3) break;
                }
            }
        }
    }
    return 0;
}
*/

/*
//////3.生理周期
#include <iostream>
using namespace std;

int main() {
    int p, e, i, d;
    int caseNo = 0;

    while (cin >> p >> e >> i >> d) {
        if (p == -1 && e == -1 && i == -1 && d == -1)
            break;

        caseNo++;

        int day;
        for (day = d + 1; day <= d + 21252; day++) {
            if ((day - p) % 23 == 0 &&
                (day - e) % 28 == 0 &&
                (day - i) % 33 == 0) {
                break;
            }
        }

        cout << "Case " << caseNo
             << ": the next triple peak occurs in "
             << day - d << " days." << endl;
    }

    return 0;
}
*/

/*
//////4.排序考试
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < N; i++) {
            if (i > 0) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}
*/

/*
//////双指针第一题：两数之和（有序数组）
#include <iostream>
using namespace std;

int a[1000005];  // 全局数组，能装下最多 100 万数据

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int target, n;
    cin >> target >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0;           // 左指针：指向最小的数
    int right = n - 1;      // 右指针：指向最大的数

    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == target) {
            cout << left << " " << right << endl;
            break;
        } else if (sum < target) {
            left++;          // 和太小 → 左指针右移，让和变大
        } else {
            right--;         // 和太大 → 右指针左移，让和变小
        }
    }

    return 0;
}
*/

/*
//////双指针第二题：三数之和
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int target, n;
    cin >> target >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);  // 先排好序，双指针的前提：升序

    for (int i = 0; i < n - 2; i++) {
        // x 去重：相同的 x 只处理第一次
        if (i > 0 && a[i] == a[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;
        int need = target - a[i];   // 剩下两个数需要凑出 need

        while (left < right) {
            int sum = a[left] + a[right];
            if (sum == need) {
                cout << a[i] << " " << a[left] << " " << a[right] << endl;
                // y 去重：相同的 y 只取第一个
                while (left < right && a[left] == a[left + 1]) left++;
                // z 去重：相同的 z 只取第一个
                while (left < right && a[right] == a[right - 1]) right--;
                left++;
                right--;
            } else if (sum < need) {
                left++;    // 和太小，左指针右移
            } else {
                right--;   // 和太大，右指针左移
            }
        }
    }

    return 0;
}
*/

/*
//////双指针第三题：四数之和
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int target, n;
    cin >> target >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);  // 排序，双指针的前提

    for (int i = 0; i < n - 3; i++) {                    // 固定 a
        if (i > 0 && a[i] == a[i - 1]) continue;         // a 去重
        for (int j = i + 1; j < n - 2; j++) {            // 固定 b
            if (j > i + 1 && a[j] == a[j - 1]) continue; // b 去重

            int left = j + 1;                  // c 从这里开始
            int right = n - 1;                 // d 从最右边开始
            int need = target - a[i] - a[j];   // 需要 c + d = need

            while (left < right) {
                int sum = a[left] + a[right];
                if (sum == need) {
                    cout << a[i] << " " << a[j] << " "
                         << a[left] << " " << a[right] << endl;
                    while (left < right && a[left] == a[left + 1]) left++;   // c 去重
                    while (left < right && a[right] == a[right - 1]) right--; // d 去重
                    left++;
                    right--;
                } else if (sum < need) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return 0;
}
*/

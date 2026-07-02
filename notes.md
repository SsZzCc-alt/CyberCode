# 枚举算法

> 枚举（Enumeration）也叫暴力枚举，核心思想：**列出所有可能情况，逐个判断是否满足条件。**

---

## 适用场景

- 数据范围较小
- 穷举所有解，找到符合条件的

## 常见技巧

- 多重循环
- 剪枝（提前排除不可能的路径）
- 缩小枚举范围，避免重复

---

## 例题 1：完美立方

> 给定 N，找出所有满足 a³ = b³ + c³ + d³ 的正整数解（a, b, c, d ≤ N），要求 b ≤ c ≤ d。

![题目/运行截图](images/image.png)

### 思路

- 四重循环枚举 a, b, c, d
- b ≤ c ≤ d 保证不重复
- 由 a³ - b³ - c³ 直接算出 d³，减少一层循环
- d³ 超出范围时 `break` 剪枝

### 代码

```cpp
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int a = 2; a <= N; a++) {
        int a3 = a * a * a;
        for (int b = 2; b < a; b++) {
            int b3 = b * b * b;
            for (int c = b; c < a; c++) {
                int c3 = c * c * c;
                int d3 = a3 - b3 - c3;
                if (d3 < c * c * c) continue; // 不满足 c ≤ d
                for (int d = c; d <= N; d++) {
                    if (d * d * d == d3) {
                        cout << "Cube = " << a
                             << ", Triple = (" << b << ","
                             << c << "," << d << ")" << endl;
                        break;
                    }
                    if (d * d * d > d3) break; // 剪枝
                }
            }
        }
    }
    return 0;
}
```

---

## 例题 2

> （待补充）

---

## 例题 3

> （待补充）

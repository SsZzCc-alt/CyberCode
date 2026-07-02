# 📘 C++ 学习笔记

> 用 Markdown 写笔记，代码自动高亮，还能贴图写注释，推送到 GitHub 也能完美显示。

---

## 示例：基础输入输出

**💡 知识点：** `cin` 和 `cout` 需要通过 `iostream` 引入。

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;          // 从键盘读入两个数
    cout << a + b << endl;  // 输出它们的和
    return 0;
}
```

> 📌 **易错提醒：** 注意 `>>` 和 `<<` 的方向不要写反！

---

## 示例：判断质数

**💡 思路：** 从 2 到 sqrt(n) 试除，能整除就不是质数。

```cpp
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;  // 找到了因数
    }
    return true;  // 没有因数，是质数
}
```

> 🔍 **复杂度分析：** O(√n)

---

![示例图片](images/example.png)

<!-- 
  贴图方法：
  1. 在项目里建一个 images 文件夹
  2. 把图片放进去
  3. 用 ![描述](images/文件名.png) 引用
-->

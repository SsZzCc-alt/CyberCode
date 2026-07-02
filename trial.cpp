#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char op;
    cin >> op;

    double a[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> a[i][j];
        }
    }

    double sum = 0.0;
    int cnt = 0;
   
    // 上方区域：九宫格上排，前4行 (i < 4)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 12; j++) {
            sum += a[i][j];
            cnt++;
        }
    }

    if (op == 'S') {
        printf("%.1f\n", sum);
    } else { // 'M'
        printf("%.1f\n", sum / cnt);
    }

    return 0;
}

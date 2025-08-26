#include <iostream>
#include <vector>
using namespace std;

int sumFibonacciHelper(int n, int a, int b, int sum) {
    if (n < 1) {
        return sum;
    }

    int next = a + b;
    sum = next + b;

    return sumFibonacciHelper(n-1, b, next, sum);
}

int sumFibonacci(int n) {
    return sumFibonacciHelper(n, 0, 1, 0);
}

int main() {
    int n;
    cin >> n;
    cout << sumFibonacci(n);

    return 0;
}
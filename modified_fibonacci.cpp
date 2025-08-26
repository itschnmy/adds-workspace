#include <iostream>
#include <vector>
using namespace std;

vector<int> modified(int n, int a, int b, vector<int> seq) {
    if (seq.size() >= n) {
        return seq;
    }
    int acc = a * b;
    seq.push_back(acc);

    return modified(n, b, acc, seq);
}

vector<int> modifiedFibonacci(int n) {
    vector<int> seq;

    if (n <= 0) return seq;
    seq.push_back(2);
    if (n == 1) return seq;
    seq.push_back(3);
    return modified(n, 2, 3, seq);
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<int> result = modifiedFibonacci(n);

    std::cout << "Modified Fibonacci sequence (" << n << " terms): ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
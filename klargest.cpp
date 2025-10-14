#include <queue>
#include <vector>
using namespace std;

int kth_largest(vector<int> vals, int k) {
    priority_queue<int> q;

    for (int v : vals) {
        q.push(v);
    }

    for (int i = 1; i < k; ++i) {
        q.pop();
    }

    return q.top();
}
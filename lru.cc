#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, capacity;
    cin >> n >> capacity;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    deque<int> q(capacity);
    int count = 0;
    int page_faults = 0, hit = 0;
    q.clear();
    for (int i = 0; i < n; i++) {
        auto itr = find(q.begin(), q.end(), arr[i]);
        if (itr == q.end()) {
            ++page_faults;
            if (q.size() == capacity) {
                q.erase(q.begin());
                q.push_back(i);
            } else {
                q.push_back(i);

            }
        } else {
            hit++;
            q.erase(itr);
            q.push_back(i);
        }

    }
    cout << "Page Faults -  " << page_faults << '\n' << "Hit - " << hit << '\n';

}
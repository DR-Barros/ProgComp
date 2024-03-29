#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector <int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    unordered_set<int> set;
    int left = 0, maxLength = 0;

    for (int right = 0; right < a; ++right) {
        while (set.find(v[right]) != set.end()) {
            set.erase(v[left]);
            left++;
        }
        set.insert(v[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;
}

#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	vector<int> ans;
	while (!q.empty()) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}


	int len = ans.size();
	cout << '<';
	for (int i = 0; i < len; i++) {
		cout << ans[i];
		if (i < len - 1) {
			cout << ", ";
		}
	}
	cout << '>';

	return 0;
}


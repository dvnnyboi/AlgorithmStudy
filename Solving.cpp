#include <bits/stdc++.h> 
using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int a, b;

	cin >> a >> b;

	set<int> s;
	int cnt = -1;

	queue<pair<int, int>> q;
	q.push({a, 0});
	s.insert(a);

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			pair<int, int> next;
			switch (i)
			{
			case 0:
				next = {curr.first * 2, curr.second + 1};
				break;
			case 1:
				next = {curr.first * 10 + 1, curr.second + 1};
				break;
			default:
				break;
			}
			if (next.first > b || s.find(next.first) != s.end()) continue;

			else if (next.first < b)
			{
				q.push(next);
				s.insert(next.first);
			}
			else if (next.first == b)
			{
				cnt = next.second + 1;
				break;
			}
		}
	}
	cout << cnt;



	return 0;
}


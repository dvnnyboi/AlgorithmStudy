//BKDG 0x01강 연습문제 2
#if 0
#include <bits/stdc++.h>

using namespace std;

bool Solve(vector<int>& inpt);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	vector<int> arr_1 = { 1, 52, 48 };
	vector<int> arr_2 = { 50, 42 };
	vector<int> arr_3 = { 4, 13, 63, 87 };

	cout << Solve(arr_1) << '\n';
	cout << Solve(arr_2) << '\n';
	cout << Solve(arr_3) << '\n';

	return 0;
}

bool Solve(vector<int>& inpt) {
	bool ret = false;

	bool checked[101] = { false, };

	for (int num : inpt) {
		if (checked[100 - num]) {
			ret = true;
			break;
		}
		checked[num] = true;
	}

	return ret;
}
#endif

//11659 : 구간 합 구하기 - 14분
#if 0
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	arr.resize(n + 1);
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
	}


	return 0;
}

#endif

//10026 : 적록색약 - 33분
#if 0
#include <bits/stdc++.h>
using namespace std;

int n, normal = 0, colorBlind = 0;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;

	vector<string> rgbs(n);
	for (int i = 0; i < n; i++) {
		cin >> rgbs[i];
	}

	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;

			char color = rgbs[i][j];
			queue<pair<int, int>> q;

			q.push({ i, j });
			visited[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;

				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (visited[nx][ny]) continue;
					if (rgbs[nx][ny] != color) continue;

					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
			normal++;
		}
	}

	visited.assign(n, vector<bool>(n, false));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;

			char color = rgbs[i][j];
			queue<pair<int, int>> q;

			q.push({ i, j });
			visited[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;

				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (visited[nx][ny]) continue;
					if (color == 'B') {
						if (rgbs[nx][ny] != 'B') continue;
					}
					else if (rgbs[nx][ny] == 'B') continue;

					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
			colorBlind++;
		}
	}

	cout << normal << " " << colorBlind;

	return 0;
}

#endif

//7562 : 나이트의 이동 - 35분
#if 0
#include <bits/stdc++.h>
using namespace std;

int t, l;
pair<int, int> start, target;
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;

	while (t--) {
		cin >> l;
		cin >> start.first >> start.second;
		cin >> target.first >> target.second;

		vector<vector<int>> board(l, vector<int>(l, 2e9));
		board[start.first][start.second] = 0;


		int moveCnt = 1;
		queue<pair<int, int>> q;
		q.push(start);
		while (!q.empty()) {
			int len = q.size();
			for (int k = 0; k < len; k++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 8; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;

					if (board[nx][ny] > moveCnt) {
						board[nx][ny] = moveCnt;
						q.push({ nx, ny });
					}
				}
			}

			moveCnt++;
		}

		cout << board[target.first][target.second] << '\n';
	}

	return 0;
}

#endif


//1966 : 프린터 큐
#if 0
#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n >> m;

		vector<int> nums(n, 0);
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			pq.push(nums[i]);
		}

		int idx = 0;
		int cnt = 0;
		bool targetPrinted = false;
		while (!pq.empty() && !targetPrinted) {
			if (nums[idx] > 0 && pq.top() == nums[idx]) {
				pq.pop();
				nums[idx] = -1;
				cnt++;
				if (idx == m) targetPrinted = true;
			}

			idx++;
			idx = idx % n;
		}
		cout << cnt << '\n';
	}

	return 0;
}

#endif

//17608 : 막대기
#if 0
#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	stack<int> nums;

	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		nums.push(temp);
	}

	int biggest = 0;
	int cnt = 0;

	while (!nums.empty()) {
		if (nums.top() > biggest) {
			biggest = nums.top();
			cnt++;
		}
		nums.pop();
	}

	cout << cnt;

	return 0;
}


#endif
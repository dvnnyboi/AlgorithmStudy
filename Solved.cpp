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

//
#if 0
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


#endif

// 18110 : solved.ac (수학)
#if 0
#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;

	int offsetVal = (int)round(n * 0.15f);
	int total = 0;
	vector<int> countScores(31, 0);
	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;
		countScores[score]++;
		total += score;
	}

	int temp = offsetVal;
	int idx = 1;
	while (temp) {
		if (countScores[idx] > 0) {
			countScores[idx]--;
			temp--;
			total -= idx;
		}
		else idx++;
	}

	temp = offsetVal;
	idx = 30;
	while (temp) {
		if (countScores[idx] > 0) {
			countScores[idx]--;
			temp--;
			total -= idx;
		}
		else idx--;
	}

	if (n == 0) cout << n;

	else cout << (int)round(total / (n - 2 * offsetVal * 1.00f));

	return 0;
}
#endif

// 9375 : 패션왕 신해빈 (수학 - 조합)
#if 0
#include <bits/stdc++.h> 
#include <unordered_map>	// stdc++.h 에 없음!
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t, n;

	cin >> t;

	while (t--) {
		cin >> n;

		unordered_map<string, int> outfits;
		pair<string, string> ootd;
		for (int i = 0; i < n; i++) {
			cin >> ootd.first >> ootd.second;
			outfits[ootd.second]++;
		}

		int combinations = 1;
		for (auto& iter : outfits) {
			combinations *= iter.second + 1;
		}
		combinations--;

		cout << combinations << '\n';
	}


	return 0;
}
#endif

// 17626 : Four Squares (DP)
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;

	cin >> n;

	vector<int> dp(n + 1, 4);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		int maxRoot = (int)sqrt(i);
		if (maxRoot * maxRoot == i) {
			dp[i] = 1;
		}
		else {
			int minCnt = 5;
			for (int j = maxRoot; j > 0; j--) {
				int remaining = i - j * j;
				minCnt = min(minCnt, dp[remaining]);
			}
			dp[i] = minCnt + 1;
		}
	}
	cout << dp[n];


	return 0;
}
#endif

// 21736 : 헌내기는 친구가 필요해 (BFS)
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { 1, 0, -1, 0 };

	// N, M 입력
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// 캠퍼스 정보 입력, 도연이 위치 기록
	vector<string> board(n);
	pair<int, int> doYeon;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		if (board[i].find("I") != -1) {
			doYeon = { i, board[i].find("I") };
		}
	}

	int friendCnt = 0;
	queue<pair<int, int>> q;

	q.push(doYeon);
	visited[doYeon.first][doYeon.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || board[nx][ny] == 'X') continue;

			if (board[nx][ny] == 'P') friendCnt++;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	if (friendCnt) cout << friendCnt;
	else cout << "TT";


	return 0;
}
#endif

// 1389 : 케빈 베이컨의 6단계 법칙 (Floyd-Warshall)
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> baconNums(n + 1, vector<int>(n + 1, 2e9));
	for (int i = 1; i <= n; i++) baconNums[i][i] = 0;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		baconNums[a][b] = 1;
		baconNums[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				if (baconNums[j][i] < 2e9 && baconNums[i][k] < 2e9)
					baconNums[j][k] = min(baconNums[j][k], baconNums[j][i] + baconNums[i][k]);
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (baconNums[i][j] == 2e9) baconNums[i][j] = 0;
		}
	}

	vector<int> sumBacon(n + 1);
	int smallest = 2e9;
	int idx;
	for (int i = 1; i <= n; i++) {
		int tmp = accumulate(baconNums[i].begin(), baconNums[i].end(), 0);
		if (tmp < smallest) {
			smallest = tmp;
			idx = i;
		}
	}

	cout << idx;

	return 0;
}
#endif

// 5525 : IOIOI (문자열)
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	string s;

	cin >> n >> m >> s;

	int cnt = 0;
	int repCnt = 0;
	int idx = 0;
	while (idx < m - 2) {
		if (s[idx] == 'O') idx++;
		else {
			if (s.substr(idx, 3) == "IOI") {
				repCnt++;
				if (repCnt == n) {
					cnt++;
					repCnt--;
				}
				idx += 2;
			}
			else {
				repCnt = 0;
				idx++;
			}
		}
	}

	// 50점 - 시간초과
	/*for (int i = 0; i < m ; i++) {
		if (i + n * 2 >= m) break;
		if (s[i] == 'O') continue;
		int left = i;
		int right = i + n * 2;
		char prev = 'O';
		while (left <= right && s[left] == s[right] && s[left] != prev) {
			prev = s[left];
			left++;
			right--;
		}
		if (left > right) cnt++;
	}*/

	cout << cnt;

	return 0;
}
#endif

// 11286 : 절댓값 힙
#if 0
#include <bits/stdc++.h> 
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<int, deque<int>, cmp> pq;
	while (n--) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) cout << '0' << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(temp);
	}

	return 0;
}
#endif
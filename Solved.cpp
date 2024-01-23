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

// 11286 : 절댓값 힙 (우선순위 큐)
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

// 11403 : 경로 찾기 (그래프 탐색 (Floyd-Warshall도 가능))
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<bool>> board(n, vector<bool>(n, false));
	vector<vector<int>> adjacent(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			board[i][j] = tmp;
			if (tmp) adjacent[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++) {
		vector<bool> visited(n, false);
		queue<int> q;
		for (int x : adjacent[i]) q.push(x);
		while (!q.empty()) {
			int nx = q.front();
			q.pop();
			visited[nx] = true;
			board[i][nx] = 1;
			for (int x : adjacent[nx]) {
				if (!visited[x]) q.push(x);
			}
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}
#endif

// 20529 : 가장 가까운 세 사람의 심리적 거리
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<string> mbti(n);
		for (int i = 0; i < n; i++) cin >> mbti[i];

		if (n > 32) cout << 0;
		else {
			vector<vector<int>> dist(n, vector<int>(n, 0));
			int minDist = 2e9;
			for (int i = 0; i < n - 2; i++) {
				for (int j = i + 1; j < n - 1; j++) {
					for (int k = j + 1; k < n; k++) {
						int personalDist = 0;
						for (int idx = 0; idx < 4; idx++) {
							if (mbti[i][idx] != mbti[j][idx]) personalDist++;
							if (mbti[i][idx] != mbti[k][idx]) personalDist++;
							if (mbti[j][idx] != mbti[k][idx]) personalDist++;
						}
						minDist = min(minDist, personalDist);
					}
				}
			}
			cout << minDist;
		}
		cout << '\n';
	}
	return 0;
}
#endif

// 22864 : 피로도
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int a, b, c, m;
	cin >> a >> b >> c >> m;

	int work = 0;
	int fatigue = 0;

	for (int i = 0; i < 24; i++) {
		if (fatigue <= m - a) {
			fatigue += a;
			work += b;
		}
		else {
			fatigue = max(fatigue - c, 0);
		}
	}

	cout << work;

	return 0;
}
#endif

// 1012 : 유기농배추
#if 0
#include <bits/stdc++.h> 
using namespace std;

int t, m, n, k;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;

	while (t--) {
		// 가로, 세로, 개수 입력
		cin >> m >> n >> k;

		// 배열 초기화
		vector<vector<int>> board(m, vector<int>(n, 0));
		// 방문여부 배열
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		// 배추 좌표입력받기, 표시하기
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		// 배추 그룹 = 필요한 지렁이 개수
		int wormCnt = 0;

		// 한칸씩 살펴보기
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 방문문한적이 있거나, 배추가 없는곳은 패스
				if (visited[i][j] || board[i][j] == 0) continue;

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

						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (visited[nx][ny] || board[nx][ny] == 0) continue;

						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}

				wormCnt++;
			}
		}

		cout << wormCnt << '\n';

	}


	return 0;
}
#endif

// 15652 : N과 M (4)
#if 0
#include <bits/stdc++.h> 
using namespace std;

int n, m;
vector<int> arr;

void Dfs(int cnt, int idx);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


	cin >> n >> m;

	Dfs(1, 1);


	return 0;
}

void Dfs(int cnt, int idx)
{
	if (cnt > m)
	{
		for (int x : arr)
		{
			cout << x << " ";
		}
		cout << '\n';
		return;
	}
	else
	{
		for (int i = idx; i <= n; i++)
		{
			arr.push_back(i);
			Dfs(cnt + 1, i);
			arr.pop_back();
		}
	}
}
#endif

// 17086 : 아기 상어 2
#if 0
#include <bits/stdc++.h> 
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	board.assign(n, vector<int>(m));
	dist.assign(n, vector<int>(m, 2e9));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) dist[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] != 0) continue;

			queue<pair<int, int>> q;
			q.push({ i, j });

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 8; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (dist[nx][ny] <= dist[x][y] + 1) continue;

					dist[nx][ny] = dist[x][y] + 1;

					q.push({ nx, ny });
				}

			}

		}
	}

	int biggest = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			biggest = max(biggest, dist[i][j]);
		}
	}

	cout << biggest;

	return 0;
}


#endif

// 16928 : 뱀과 사다리 게임
#if 0
#include <bits/stdc++.h> 
using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m;

	int board[101] = { 0, };
	int tries[101] = { 0, };

	iota(board, board + 101, 0);
	fill(tries + 2, tries + 101, 2e9);

	cin >> n >> m;
	int total = n + m;
	while (total--) {
		int u, v;
		cin >> u >> v;
		board[u] = v;
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 6; i > 0; i--) {
			if (curr + i > 100) continue;

			int next = board[curr + i];

			if (tries[next] == 2e9) {
				tries[next] = tries[curr] + 1;
				q.push(next);
			}

		}
	}

	cout << tries[100];

	return 0;
}


#endif

// 9019 : DSLR
#if 0
#include <bits/stdc++.h> 
using namespace std;

int t;
pair<int, string> OperationD(pair<int, string> x);
pair<int, string> OperationS(pair<int, string> x);
pair<int, string> OperationL(pair<int, string> x);
pair<int, string> OperationR(pair<int, string> x);
bool visited[10000] = { false, };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;

	while (t--)
	{
		memset(visited, false, sizeof(visited));
		int a, b;
		cin >> a >> b;
		pair<int, string> numA = { a, "" };

		queue<pair<int, string>> q;
		q.push(numA);
		visited[numA.first] = true;

		while (!q.empty())
		{
			pair<int, string> next = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				pair<int, string> candidate;
				switch (i)
				{
				case 0:
					candidate = OperationD(next);
					break;
				case 1:
					candidate = OperationS(next);
					break;
				case 2:
					candidate = OperationL(next);
					break;
				case 3:
					candidate = OperationR(next);
					break;
				default:
					break;
				}

				if (visited[candidate.first]) continue;
				if (candidate.first == b)
				{
					cout << candidate.second << '\n';
					q = queue<pair<int, string>>();
					break;
				}
				q.push(candidate);
				visited[candidate.first] = true;
			}
		}
	}

	return 0;
}

pair<int, string> OperationD(pair<int, string> x)
{
	int num = (x.first * 2) % 10000;
	string command = x.second + "D";
	return { num, command };
}

pair<int, string> OperationS(pair<int, string> x)
{
	int num = x.first - 1 < 0 ? 9999 : x.first - 1;
	string command = x.second + "S";
	return { num, command };
}

pair<int, string> OperationL(pair<int, string> x)
{
	int movingDigit = x.first / 1000;
	int num = x.first % 1000;
	num *= 10;
	num += movingDigit;
	string command = x.second + "L";
	return { num, command };
}

pair<int, string> OperationR(pair<int, string> x)
{
	int movingDigit = x.first % 10;
	int num = x.first / 10;
	num += movingDigit * 1000;

	string command = x.second + "R";
	return { num, command };
}


#endif

// 15666 : N과 M(12)
#if 0
#include <bits/stdc++.h> 
using namespace std;

int n, m;
vector<int> nums;
vector<int> outPut;
void Dfs(int nextIdx, int cnt);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


	cin >> n >> m;

	nums.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	auto newEnd = unique(nums.begin(), nums.end());
	nums.assign(nums.begin(), newEnd);

	Dfs(0, 0);

	return 0;
}

void Dfs(int nextIdx, int cnt)
{
	if (cnt == m)
	{
		for (int num : outPut)
		{
			cout << num << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = nextIdx; i < nums.size(); i++)
	{
		outPut.push_back(nums[i]);
		Dfs(i, cnt + 1);
		outPut.pop_back();
	}

}

#endif

// 16953 : A-->B
#if 0
#include <bits/stdc++.h> 
using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	long long a, b;

	cin >> a >> b;

	set<int> s;
	int cnt = -1;

	queue<pair<long long, int>> q;
	q.push({ a, 0 });
	s.insert(a);

	while (!q.empty())
	{
		pair<long long, int> curr = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			pair<long long, int> next;
			switch (i)
			{
			case 0:
				next = { curr.first * 2, curr.second + 1 };
				break;
			case 1:
				next = { curr.first * 10 + 1, curr.second + 1 };
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


#endif

// 1149: RGB거리
#if 0
#include <bits/stdc++.h> 
using namespace std;

typedef struct _Colors
{
	int r = 0, g = 0, b = 0;
} Colors;

int n;
vector<Colors> colorArr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	colorArr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> colorArr[i].r >> colorArr[i].g >> colorArr[i].b;
	}
	for (int i = 1; i < n; i++) {
		colorArr[i].r += min(colorArr[i - 1].g, colorArr[i - 1].b);
		colorArr[i].g += min(colorArr[i - 1].r, colorArr[i - 1].b);
		colorArr[i].b += min(colorArr[i - 1].r, colorArr[i - 1].g);
	}

	cout << min(colorArr[n - 1].r, min(colorArr[n - 1].g, colorArr[n - 1].b));


	return 0;
}


#endif

// 1991: 트리 순회
#if 0
#include <bits/stdc++.h>
using namespace std;

struct middle {
	char left;
	char right;
};

vector<middle> arr(26);
int n;
void pre(char r);
void in(char r);
void post(char r);

int main() {

	arr.resize(50);
	cin >> n;

	for (int i = 0; i < n; i++) {
		char m, l, r;
		cin >> m >> l >> r;
		arr[m - 'A'] = { l, r };
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';



	return 0;
}

void pre(char r) {
	if (r == '.') return;
	cout << r;
	pre(arr[r - 'A'].left);
	pre(arr[r - 'A'].right);
}
void in(char r) {
	if (r == '.') return;
	in(arr[r - 'A'].left);
	cout << r;
	in(arr[r - 'A'].right);
}
void post(char r) {
	if (r == '.') return;
	post(arr[r - 'A'].left);
	post(arr[r - 'A'].right);
	cout << r;
}

#endif

// 11660 : 구간 합 구하기 5
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> sumArr(n + 1, vector<int>(n + 1, 0));


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	sumArr[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		sumArr[1][i] = sumArr[1][i - 1] + arr[1][i];
		sumArr[i][1] = sumArr[i - 1][1] + arr[i][1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			sumArr[i][j] = sumArr[i][j - 1] + sumArr[i - 1][j] + arr[i][j] - sumArr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sumArr[x2][y2] - sumArr[x2][y1 - 1] - sumArr[x1 - 1][y2] + sumArr[x1 - 1][y1 - 1] << '\n';
	}


	return 0;
}

#endif

// 9465 : 스티커
#if 0
#include <bits/stdc++.h>
using namespace std;

int stickers[2][100001] = { 0, };
int dp[2][100001] = { 0, };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			memset(stickers[i], 0, sizeof(int) * 100001);
			memset(dp[i], 0, sizeof(int) * 100001);
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> stickers[i][j];
			}
		}


		int maxVal = -1;
		for (int i = 0; i < n; i++) {
			dp[1][i + 1] = max(dp[1][i + 1], dp[0][i] + stickers[1][i + 1]);
			dp[1][i + 2] = max(dp[1][i + 2], dp[0][i] + stickers[1][i + 2]);
			maxVal = max(maxVal, max(dp[1][i + 1], dp[1][i + 2]));

			dp[0][i + 1] = max(dp[0][i + 1], dp[1][i] + stickers[0][i + 1]);
			dp[0][i + 2] = max(dp[0][i + 2], dp[1][i] + stickers[0][i + 2]);
			maxVal = max(maxVal, max(dp[0][i + 1], dp[0][i + 2]));

		}
		cout << maxVal << '\n';
	}

	return 0;
}

#endif

// 1912: 연속합
#if 0
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	vector<int> iVals;
	vector<int> dp;
	int maxVal = -2e9;
	cin >> n;

	dp.resize(n);
	iVals.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> iVals[i];
		if (i == 0) {
			maxVal = iVals[i];
			dp[i] = iVals[i];
		}
		else {
			int factor = dp[i - 1] + iVals[i];
			if (factor < iVals[i]) dp[i] = iVals[i];
			else {
				dp[i] = factor;
			}
			maxVal = max(dp[i], maxVal);
		}
	}

	cout << maxVal;

	return 0;
}

#endif

// 11055: 가장 큰 증가하는 부분 수열
#if 0
#include <bits/stdc++.h>

using namespace std;

int nums[1000] = { 0, };
int dp[1000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		dp[i] = nums[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i] && dp[i] < dp[j] + nums[i]) {
				dp[i] = dp[j] + nums[i];
			}
		}
	}

	cout << *max_element(dp, dp + n);

	return 0;
}

#endif

// 1904: 01타일
#if 0
#include <bits/stdc++.h>
#define MOD 15746

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int pprev = 0, prev = 1, curr = 1;
	for (int i = 0; i < n; i++) {
		curr = (prev + pprev) % MOD;
		pprev = prev;
		prev = curr;
	}

	cout << curr % MOD;

	return 0;
}

#endif

// 1788: 피보나치 수의 확장
#if 0
#include <bits/stdc++.h>

#define MAX 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	long long pprev = 0, prev = 1, curr = 0;

	for (int i = 0; i < abs(n); i++) {
		pprev = prev;
		prev = curr;
		curr = (pprev + prev) % MAX;
	}

	if (n < 0 && n % 2 == 0) cout << -1;
	else if (n == 0) cout << 0;
	else cout << 1;

	cout << '\n';

	cout << curr;


	return 0;
}

#endif


// 1166: 선물
#if 0
#include <bits/stdc++.h>

using namespace std;

int n, l, w, h;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> l >> w >> h;

	long double right = min(min(l, w), h);
	long double left = right / n;
	long double middle = (left + right) / 2.0;
	long long cnt = (long long)(l / middle) * (long long)(w / middle) * (long long)(h / middle);

	int iterationCnt = 10000;
	while (iterationCnt--) {
		if (cnt < n) {
			right = middle;
		}
		else if (cnt >= n) {
			left = middle;
		}
		middle = (left + right) / 2;
		cnt = (long long)(l / middle) * (long long)(w / middle) * (long long)(h / middle);
	}
	cout << fixed;
	cout.precision(15);
	cout << left;


	return 0;
}

#endif

// 10844: 쉬운 계단 수
#if 0
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

long long dp[101][10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % MOD;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % MOD;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}


	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}

	cout << ans % MOD;

	return 0;
}

#endif

// 1026: 보물
#if 0
#include <bits/stdc++.h>

using namespace std;

int n;
int arrA[50] = {}, arrB[50] = {};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arrA[i];
	sort(arrA, arrA + n);
	for (int i = 0; i < n; i++) cin >> arrB[i];
	sort(arrB, arrB + n, greater<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arrA[i] * arrB[i];
	}

	cout << ans;

	return 0;
}

#endif

// 12865: 평범한 배낭
#if 0
#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[101][100001] = {};
int wv[2][101] = {};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> wv[0][i] >> wv[1][i];
	}

	for (int i = 1; i <= n; i++) {
		int weight = wv[0][i];
		int value = wv[1][i];
		for (int j = 1; j <= k; j++) {

			if (weight <= j) {
				if (value + dp[i - 1][j - weight] > dp[i - 1][j]) {
					dp[i][j] = value + dp[i - 1][j - weight];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];


	return 0;
}

#endif

// 15988: 1, 2, 3 더하기 3
#if 0
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009
#define MAX 1000000

int t;
long long dp[MAX + 1] = {};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= MAX; i++) {
		dp[i] = (dp[i - 3] % MOD + dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;
	}

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';

	}

	return 0;
}

#endif

// 9657: 돌 게임 3
#if 0
#include <bits/stdc++.h>

using namespace std;

int dp[1001] = {};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) {
			dp[i] = 1;
		}
		else dp[i] = 0;
	}

	if (dp[n] == 0) cout << "CY";
	else cout << "SK";

	return 0;
}

#endif

// 1753: 최단경로 - Dijkstra(다익스트라)
#if 0
#include <bits/stdc++.h>

using namespace std;


// 기존의 priority_queue에 pair<int, int> 자료형으로 한다면 pair의 first값이 큰 순으로 정렬됨.
// 아래 cmp구조체로 연산자 오버로딩을 통해 순서를 바꿔준다.
// 다른 자료구조(array,list 등) 에서는 우선순위를 바꿀 때는 a > b를 하면 큰 순서대로 정렬되지만, 여기선 a > b를 하면 작은 순서대로 정렬된다.
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int v, e, k;
	cin >> v >> e >> k;

	vector<pair<int, int>> edges[20001];
	vector<int> dist(v + 1, 2e9);
	vector<int> visited(v + 1, false);

	dist[k] = 0;

	for (int i = 1; i <= e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(v, w));
	}

	// pair의 first값이 작은순서대로 정렬되도록 cmp 위에서 정의했음.
	// first값이 같을경우 second값이 작은 순으로 정렬되도록 함.
	priority_queue<pair<int, int>, deque<pair<int, int>>, cmp> pq;
	pq.push(make_pair(0, k));

	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (int i = 0; i < edges[curr].size(); i++) {
			int next = edges[curr][i].first;
			int nWeight = edges[curr][i].second;

			if (dist[next] > weight + nWeight) {
				dist[next] = weight + nWeight;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 2e9) {
			cout << "INF";
		}
		else cout << dist[i];
		cout << '\n';
	}

	//배열사용하게되면 메모리초과 발생.
	// int 자료형으로 20000 * 20000 배열을 만들면 1.6GB 정도 나옴.
	/*
	int v, e, k;
	cin >> v >> e >> k;

	vector<int> dist(v + 1, 2e9);
	vector<bool> visited(v + 1, false);
	vector<vector<int>> edges(v + 1, vector<int>(v + 1, 2e9));

	dist[k] = 0;

	// 스스로에게 가는 가중치는 -1처리
	for(int i = 1; i <= v; i++) edges[i][i] = -1;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u][v] = w;
	}

	queue<int> q;
	q.push(k);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 1; i <= v; i++) {
			if (visited[i] || edges[curr][i] < 0 || edges[curr][i] == 2e9) continue;
			q.push(i);
			if (dist[i] > dist[curr] + edges[curr][i]) {
				dist[i] = dist[curr] + edges[curr][i];
			}
		}
		visited[curr] = true;
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 2e9) {
			cout << "INF";
		}
		else cout << dist[i];
		cout << '\n';
	}
	*/

	return 0;
}

#endif

// 18429: 근손실
#if 0
#include <bits/stdc++.h>

using namespace std;

int n, k;
int kits[8] = {};
bool visited[8] = {};
int pass = 0;

void DFS(int weight, int dayCnt);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> kits[i];

	DFS(0, 0);

	cout << pass;

	return 0;
}

void DFS(int weight, int dayCnt) {

	if (weight < 0) return;
	else if (dayCnt == n) {
		pass++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		DFS(weight + kits[i] - k, dayCnt + 1);
		visited[i] = false;
	}
}

#endif

// 10971: 외판원 순회 - BackTracking(DFS)
#if 0
#include <bits/stdc++.h>

using namespace std;

int n;
int costs[10][10] = {};
int visited[10] = {};
int minExpense = 2e9;
int startCity;

void Dfs(int currentCity, int cityCnt, int expense);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> costs[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		visited[i] = true;
		startCity = i;
		Dfs(i, 1, 0);
		visited[i] = false;
	}

	cout << minExpense;

	return 0;
}

void Dfs(int currentCity, int cityCnt, int expense) {
	if (cityCnt == n) {
		if (costs[currentCity][startCity] == 0) return;
		minExpense = min(minExpense, expense + costs[currentCity][startCity]);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] || costs[currentCity][i] == 0) continue;

		visited[i] = true;
		Dfs(i, cityCnt + 1, expense + costs[currentCity][i]);
		visited[i] = false;
	}

}

#endif

// 17266: 어두운 굴다리
#if 0
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	int maxVal = 0;
	int curr = 0;
	for (int i = 0; i < m; i++) {
		int next, dist;

		cin >> next;

		if (i == 0) dist = next;
		else dist = (next - curr) / 2 + (next - curr) % 2;
		maxVal = max(maxVal, dist);
		curr = next;
	}
	maxVal = max(maxVal, n - curr);
	cout << maxVal;

	return 0;
}

#endif

// 15723: n단 논법
#if 0
#include <bits/stdc++.h>

using namespace std;

int alphabets[26][26];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	char x, y;
	string s;

	// 초기화
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (i == j) continue;
			alphabets[i][j] = 2e9;
		}
	}
	// 전제 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> s >> y;
		alphabets[x - 'a'][y - 'a'] = 1;
	}
	// 플로이드-워셜 수행
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				if (j == k || alphabets[j][i] == 2e9 || alphabets[i][k] == 2e9) continue;

				if (alphabets[j][k] > alphabets[j][i] + alphabets[i][k]) {
					alphabets[j][k] = alphabets[j][i] + alphabets[i][k];
				}
			}
		}
	}
	// 결론 입력 및 판정
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> s >> y;

		if (alphabets[x - 'a'][y - 'a'] == 2e9) cout << "F";
		else cout << "T";
		cout << '\n';
	}



	return 0;
}
#endif

// 20053: 최소, 최대 2
#if 0
#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;

	while (t--) {
		int minVal = 2e9;
		int maxVal = -2e9;

		cin >> n;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			maxVal = max(temp, maxVal);
			minVal = min(temp, minVal);
		}

		cout << minVal << " " << maxVal << '\n';
	}

	return 0;
}
#endif
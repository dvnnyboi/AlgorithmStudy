//BKDG 0x01�� �������� 2
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

//11659 : ���� �� ���ϱ� - 14��
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

//10026 : ���ϻ��� - 33��
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

//7562 : ����Ʈ�� �̵� - 35��
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


//1966 : ������ ť
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

//17608 : �����
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

// 18110 : solved.ac (����)
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

// 9375 : �мǿ� ���غ� (���� - ����)
#if 0
#include <bits/stdc++.h> 
#include <unordered_map>	// stdc++.h �� ����!
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

// 21736 : �峻��� ģ���� �ʿ��� (BFS)
#if 0
#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { 1, 0, -1, 0 };

	// N, M �Է�
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// ķ�۽� ���� �Է�, ������ ��ġ ���
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

// 1389 : �ɺ� �������� 6�ܰ� ��Ģ (Floyd-Warshall)
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

// 5525 : IOIOI (���ڿ�)
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

	// 50�� - �ð��ʰ�
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

// 11286 : ���� �� (�켱���� ť)
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

// 11403 : ��� ã�� (�׷��� Ž�� (Floyd-Warshall�� ����))
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

// 20529 : ���� ����� �� ����� �ɸ��� �Ÿ�
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

// 22864 : �Ƿε�
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

// 1012 : ��������
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
		// ����, ����, ���� �Է�
		cin >> m >> n >> k;

		// �迭 �ʱ�ȭ
		vector<vector<int>> board(m, vector<int>(n, 0));
		// �湮���� �迭
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		// ���� ��ǥ�Է¹ޱ�, ǥ���ϱ�
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		// ���� �׷� = �ʿ��� ������ ����
		int wormCnt = 0;

		// ��ĭ�� ���캸��
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// �湮�������� �ְų�, ���߰� ���°��� �н�
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

// 15652 : N�� M (4)
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

// 17086 : �Ʊ� ��� 2
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

// 16928 : ��� ��ٸ� ����
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

// 15666 : N�� M(12)
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

// 1149: RGB�Ÿ�
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

// 1991: Ʈ�� ��ȸ
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

// 11660 : ���� �� ���ϱ� 5
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

// 9465 : ��ƼĿ
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

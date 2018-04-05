#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Q1. 
void S1() {
	int x, y, z, start, end;
	while (cin >> x >> y >> z >> start >> end) {
		int dp[end+1];
		for (int i = 0; i < end + 1; ++i) {
			dp[i] = 0;
		}

		int i = start + 2;
		while (i <= end) {
			// start == 0: 0 -> 2, only one choice left; 
			// start == 10, end == 16: z; 
			int x_cost, y_cost, z_cost;

			int mid = i / 2;
			if (mid % 2 == 0 && mid > 0) {
				x_cost = dp[i - 2] + x;
				y_cost = dp[mid] + y;
				z_cost = mid < start ? (start - mid) / 2 * z : 0;
				dp[i] = min(x_cost, z_cost + y_cost);
			}
			else {
				x_cost = dp[i - 2] + x;
				dp[i] = x_cost;
			}
			i += 2;
		}

		cout << dp[end] << endl;
	}

	return;
}

// Q2. 
void DFS(vector<vector<int>> &nums, int &reward_limit, int &time_limit,
	int &max_reward, int &min_time, int cur_idx, int cur_reward, int cur_time) {
	cur_reward += nums[cur_idx][0];
	cur_time += nums[cur_idx][1];

	int flag = 1, N = nums.size();
	for (int i = 2; i < N + 2; ++i) {
		if (nums[cur_idx][i + 2]) {
			flag = 0;
			DFS(nums, reward_limit, time_limit, max_reward, min_time, nums[cur_idx][i + 2], cur_reward, cur_time);
		}
	}

	if (flag) {
		if (cur_reward <= reward_limit && cur_time <= time_limit) {
			max_reward = max(max_reward, cur_reward);
			min_time = min(min_time, cur_time);
		}
	}

	return;
}
void S2() {
	int N, D;
	while (cin >> N >> D) {
		vector<vector<int>> info(N, vector<int>(N + 2, 0));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N + 2; ++j) {
				int temp;
				cin >> temp;
				info[i][j] = temp;
			}
		}

		int reward_limit = INT_MAX, time_limit = INT_MAX;
		int max_reward = 0, min_time = 0;
		DFS(info, reward_limit, time_limit, max_reward, min_time, 0, 0, 0);
		cout << max_reward << " " << min_time << endl;
	}

	return;
}

int main(int argc, char **argv) {
	// Q1 
	S1();

	// Q2
	S2();

	return 0;
}
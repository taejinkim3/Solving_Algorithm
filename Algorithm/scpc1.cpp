#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int T, testCase;
	cin >> T;
	for (testCase = 1; testCase <= T; testCase++)
	{
		int n, k,t;
		cin >> n >> k;
		vector<int>a;

		for (int i = 0; i < n; i++)
		{
			cin >> t;
			a.push_back(t);
		}
		sort(a.begin(), a.end());
		int result;
		result = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] - a[i - result] <= k)result++;
		}
		cout << "Case #" << testCase << '\n' << result << "\n";
	}
}
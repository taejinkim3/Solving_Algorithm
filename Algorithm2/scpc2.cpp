#include<iostream>
#include<sstream>

using namespace std;

int circular[10001];
int cnt = 0;

bool isPalindrome(int x) {
	stringstream ss;
	ss << x;
	string str = ss.str();

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != str[str.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int one(int x)
{
	for (int i = 0; i < cnt; i++) {
		if (circular[i] == x) {
			cout << 1 << ' ' << circular[i] << '\n';
			return true;
		}
	}
	return false;
}


int two(int x)
{
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++)
		{
			if (circular[i] + circular[j] == x)
			{
				cout << 2 << ' ' << circular[j] << ' ' << circular[i] << '\n';
				return true;
			}
		}
	}
	return false;
}

int three(int x)
{
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++)
		{
			for (int k = 0; k < cnt; k++) {
				if (circular[i] + circular[j]+circular[k] == x)
				{
					cout << 3 << ' ' <<circular[k]<<' '<<circular[j] << ' ' << circular[i] << '\n';
					return true;
				}
			}
		}
	}
	return false;
}


int main()
{
	int T,testCase;
	cin >> T;
	for (int i = 0; i <= 10000; i++)
	{
		if (isPalindrome(i))
		{
			circular[cnt] = i;
			cnt++;
		}
	}
	for (testCase = 1; testCase <= T; testCase++)
	{
		int n;
		cin >> n;
		cout << "Case #" << testCase << '\n';
		if (!one(n) && !two(n) && !three(n)) {
			cout << '0' << '\n';
		}
	}

	return 0;
}
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int FibRecursive(int n)
{
	if (n <= 1)
		return n;
	else
		return FibRecursive(n - 1) + FibRecursive(n - 2);
}

int FibDP(int n)
{
	vector<int> table;
	table.assign(n + 1, 0);
	table[1] = 1;

	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];

	return table[n];
}

int main()
{
	cout << FibRecursive(6) << endl;
	cout << FibDP(7) << endl;
}
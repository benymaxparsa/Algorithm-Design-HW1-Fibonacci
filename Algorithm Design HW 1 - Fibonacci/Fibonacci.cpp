/* 
			course : Algorithm Design
			professor : Dr. HajAhmadi
			Project by : Parsa KamaliPour
			Home Work 1 - Analyzing Fibonacci 
*/
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
	if (n > 0)
		table[1] = 1;

	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];

	return table[n];
}

void DoRecursive()
{
	cout << "enter your Nth number:" << endl;
	int n;
	cin >> n;
	auto start = high_resolution_clock::now();
	FibRecursive(n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;
}

void DoDP()
{
	cout << "enter your Nth number:" << endl;
	int n;
	cin >> n;
	auto start = high_resolution_clock::now();
	FibDP(n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;
}

void UI()
{
	cout << "Fibonacci Analyzer" << endl;
	cout << "by Parsa KamaliPour" << endl;
	int method;
	while (true)
	{
		cout << "Select your method: (1. Recursive, 2. Dynamic Programming, 0. Exit)" << endl;
		cin >> method;
		if (method == 1)
		{
			DoRecursive();
		}
		else if (method == 2)
		{
			DoDP();
		}
		else if (method == 0)
		{
			break;
		}
	}
	cin.get();
}

int main()
{
	UI();
}
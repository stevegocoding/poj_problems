#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

void find_dA()
{
	int num_cases = 0; 
	scanf("%d", &num_cases); 
	int n = 0; 
	while (num_cases-- && scanf("%d", &n))
	{
		vector<int> a(n); 
		scanf("%d", &a[0]); 
		vector<int> opts[2];
		opts[0].resize(a.size()); 
		opts[1].resize(a.size()); 

		int max_end = a[0]; 
		opts[0][0] = a[0]; 
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &a[i]); 
			max_end = max(a[i], max_end+a[i]); 
			opts[0][i] = max(opts[0][i-1], max_end);
		}

		int max_start = a[n-1]; 
		opts[1][n-1] = a[n-1]; 
		for (int j = n-2; j >= 0; --j)
		{
			max_start = max(a[j], max_start+a[j]); 
			opts[1][j] = max(opts[1][j+1], max_start); 
		}

		int sum = 0; 
		int da_max = opts[0][n-2] + opts[1][n-1]; 
		for (int k = n - 2; k > 0; --k)
		{
			sum = opts[0][k-1] + opts[1][k]; 
			da_max = max(da_max, sum);  
		}
		
		cout << da_max << std::endl; 
	}
}

void get_intput(istream& is, vector<vector<int> >& a) 
{
	int n_cases = 0; 
	is >> n_cases; 
	a.resize(n_cases);

	int c = 0; 
	bool is_count = true;
	int n = 0; 
	while (c < n_cases) 
	{
		string s; 
		if (getline(is, s) && s.empty())
			continue; 
		
		stringstream ss(s); 
		if (is_count) 
			ss >> n; 
		else
		{
			for (int i = 0; i < n; ++i)
			{
				int v = 0;
				ss >> v; 
				a[c].push_back(v); 
			}
			c++; 
		}
		is_count = !is_count; 
	}
}

int main(int argc, char **argv)
{
	find_dA();

	return 0;
}

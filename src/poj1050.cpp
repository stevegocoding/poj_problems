#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int max_subarray_sum(const vector<int>& a)
{
	int n = (int)a.size(); 
	int max_start = a[n-1]; 
	int opt = a[n-1]; 
	for (int i = n - 2; i >= 0; --i)
	{
		max_start = max(a[i], max_start+a[i]);
		opt = max(opt, max_start); 
	} 	
	return opt;
}

int max_submat_sum(const vector<vector<int> >& a) 
{
	int n = (int)a.size(); 
	vector<int> m(n); 
	int max_sum = 0; 
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
			m[k] = 0; 

		for (int j = i; j < n; ++j)
		{
			for (int c = 0; c < n; ++c) 
				m[c] += a[j][c];
		
			int max_sub = max_subarray_sum(m); 
			max_sum = max(max_sub, max_sum); 
		}
	} 
	return max_sum;
}

int main(int argc, char **argv)
{
	int n = 0;
	string s; 
	cin >> n; 
	vector<vector<int> > a; 
	a.resize(n);
	
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			int e = 0; 
			scanf_s("%d", &e); 
			a[row].push_back(e); 		
		}
	}
	
	int res = max_submat_sum(a); 
	cout << res << std::endl; 

	return 0; 
} 
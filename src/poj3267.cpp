#include <fstream>
#include <iostream>
#include <algorithm>

#include <vector>
#include <string>

using namespace std; 

typedef vector<string> dict_t;		// sorted by the length 

int min_remove(const string& str, const dict_t& dict)
{
	int n = (int)str.size(); 
	int nw = (int)dict.size(); 

	vector<int> opt(n+1);				// minimum number of chars need to be removed for str[j ... n-1]
	std::fill(opt.begin(), opt.end(), 0);  

	for (int j = n - 1; j >= 0; --j)
	{
		opt[j] = opt[j+1] + 1; 
		for (int w = 0; w < nw; ++w)
		{
			if (dict[w].length() <= n - j && dict[w].at(0) == str[j])
			{
				int t = j; 
				int m = 0; 
				while (t < n)
				{
					if (dict[w].at(m) == str[t++])
						m++;
					if (m == dict[w].length()) 
					{
						opt[j] = min(opt[t]+t-j-m, opt[j]); 
						break; 
					}
				} 	
			}
		}
	}

	return opt[0]; 
}

void get_input(istream& is, string& msg, dict_t& dict)
{
	int nw = 0; 
	int len = 0;
	is >> nw >> len; 
	is >> msg; 
	for (int i = 0; i < nw; ++i)
	{
		string word; 
		is >> word; 
		dict.push_back(word); 
	}
}

int main(int argc, char **argv)
{
	string msg; 
	dict_t dict;
	get_input(cin, msg, dict); 
	int res = min_remove(msg, dict);
	cout << res << std::endl; 
	
	return 0; 
}

//////////////////////////////////////////////////////////////////////////

/** 
	DP
 */ 
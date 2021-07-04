#include <iostream>
#include <vector>

using namespace std;

int test() 
{
	vector<string> vec;
	string s = "swsdfghjhk";
	s.insert(2, ".");
	cout << s << endl;

	vec.push_back(s);
	vec.push_back(s);
	vec.push_back(s);



	return 0;
}




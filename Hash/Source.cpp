#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(string file_name)
{
	ifstream fin(file_name);

	string ignore = "";

	if (!fin.is_open())
	{
		cout << "Cant open " << file_name << endl;
	}

	getline(fin, ignore, '\n');

	vector<Company> a;

	while (!fin.eof())
	{
		Company p;

		getline(fin, p.name, '|');
		getline(fin, p.profit_tax, '|');
		getline(fin, p.address, '\n');

		a.push_back(p);
	}

	return a;
}

void print(vector<Company> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i].name << endl;
	}
}

unsigned long long power(long long m, int n)
{
	if (n == 0) return 1;
	unsigned long long result = 1;
	for (int i = 1; i < n; i++)
	{
		result*=m;
	}
	return result;
}

long long hashName(string name)
{
	size_t end = name.length();
	size_t begin = (end > 20) ? end - 20 : 0;
	long long result = 0;
	unsigned long long m = power(10, 9) + 9;
	for (size_t i = begin; i < end; i++) {
		result += ((int)name[i] * power(31, i)) % (long long) m;
	}
	return result % (long long) m % 2000;
}

//Company* CreateHashTable(vector<Company> a) 
//{
//	Company* result = new Company[2000];
//	
//	for (int i = 0; i < 2000; i++)
//	{
//
//	}
//}

int main()
{
	vector<Company> a = ReadCompanyList("MST.txt");

	//print(a);

	char b = 'a';
	string c = "abcdefgh";

	/*cout << power(5, 2) << endl;

	cout << int(b)<<endl;
	cout << int(c[0]) << endl;*/

	for (int i = 0; i < a.size(); i++)
	{
		cout << hashName(a[i].name)<<endl;
	}



	return 0;
}
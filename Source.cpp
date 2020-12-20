#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct NODE {
	int key;
	NODE* l;
	NODE* r;
};

NODE* createNode(int key)
{
	NODE* p = new NODE;
	p->key = key;
	p->l = NULL;
	p->r = NULL;

	return p;
}

int height(NODE* root)
{
	if (!root)
		return 0;
	int h1 = height(root->l);
	int h2 = height(root->r);

	return max(h1, h2) + 1;
}

void rightRotate(NODE*& root)
{
	NODE* p = root->l;

	root->l = p->r;
	p->r = root;
	root = p;
}

void leftRotate(NODE*& root)
{
	NODE* x = root->r;
	NODE* t = x->l;

	root->r = t;
	x->l = root;
	root = x;
}

//void bal(NODE* root)
//{
//	int x = height(root->l) - height(root->r);
//	if (x >= 2)
//	{
//		if (height(root->l->l) >= height(root->l->r))
//		{
//			rightRotate(root);
//		}
//		else
//		{
//			leftRotate(root->l);
//			rightRotate(root);
//		}
//	}
//	else if (x <= -2)
//	{
//		if (height(root->r->r) >= height(root->r->l))
//		{
//			leftRotate(root);
//		}
//		else
//		{
//			rightRotate(root->r);
//			leftRotate(root);
//		}
//	}
//}

void insertNode(NODE*& root, int key)
{
	if (!root)
	{
		root = createNode(key);
	}

	if (root->key < key)
	{
		insertNode(root->r, key);
	}

	else if (root->key > key)
	{
		insertNode(root->l, key);
	}

	int x = height(root->l) - height(root->r);
	if (x >= 2)
	{
		if (height(root->l->l) >= height(root->l->r))
		{
			rightRotate(root);
		}
		else
		{
			leftRotate(root->l);
			rightRotate(root);
		}
	}
	else if (x <= -2)
	{
		if (height(root->r->r) >= height(root->r->l))
		{
			leftRotate(root);
		}
		else
		{
			rightRotate(root->r);
			leftRotate(root);
		}
	}
}

NODE* createTree(vector<int> a)
{
	NODE* root = createNode(a[0]);
	for (int i = 1; i < a.size(); i++)
	{
		insertNode(root, a[i]);
	}

	return root;
}

NODE* createTree2(vector<int> a)
{
	NODE* root = createNode(a[0]);
	for (int i = 1; i < a.size()-3; i++)
	{
		insertNode(root, a[i]);
	}

	return root;
}


void NLR(NODE* root)
{
	if (!root)
	{
		return;
	}

	cout << root->key << " ";
	cout << height(root)<<" - ";
	NLR(root->l);
	NLR(root->r);
}

void LNR(NODE* root)
{
	if (!root)
	{
		return;
	}

	LNR(root->l);
	cout << root->key << " ";
	cout << height(root) << " - ";
	LNR(root->r);
}

int getBalance(NODE* root)
{
	return height(root->l) - height(root->r);
}

//void balance(NODE* root)
//{
//	if (getBalance(root) < -1)
//	{
//		if (getBalance(root->r->l) > getBalance(root->r->r))
//		{
//			rightRotate(root);
//			leftRotate(root);
//		}
//
//		else if (getBalance(root->r->l) < getBalance(root->r->r))
//		{
//			leftRotate(root);
//		}
//	}
//
//	else if (getBalance(root) > 1)
//	{
//		if (getBalance(root->r->l) > getBalance(root->r->r))
//		{
//			leftRotate(root);
//			rightRotate(root);
//		}
//
//		else if (getBalance(root->r->l) < getBalance(root->r->r))
//		{
//			rightRotate(root);
//		}
//	}
//}

int findMax(NODE* root)
{
	if (root == NULL)
		return 0;
	int max = root->key;
	int lmax = findMax(root->l);
	int rmax = findMax(root->r);

	if (lmax > max)
		max = lmax;
	if (rmax > max)
		max = rmax;
	return max;
}

void remove(NODE*& root, int x)
{
	if (!root)
	{
		return;
	}

	if (root->key == x)
	{
		if (root->l == NULL && root->r == NULL)
		{
			delete root;
			root = NULL;
		}

		else if (root->r == NULL)
		{
			NODE* p = root;
			root = root->l;
			delete p;
		}
		else if (root->l == NULL)
		{
			NODE* p = root;
			root = root->r;
			delete p;
		}
		else
		{
			int max = findMax(root->l);
			root->key = max;
			remove(root->l, max);
		}
	}


	else if (root->key > x)
	{
		remove(root->l, x);
	}

	else if (root->key < x)
	{
		remove(root->r, x);
	}

	if (root)
	{
		int h = height(root->l) - height(root->r);
		if (h >= 2)
		{
			if (height(root->l->l) >= height(root->l->r))
			{
				rightRotate(root);
			}
			else
			{
				leftRotate(root->l);
				rightRotate(root);
			}
		}
		else if (h <= -2)
		{
			if (height(root->r->r) >= height(root->r->l))
			{
				leftRotate(root);
			}
			else
			{
				rightRotate(root->r);
				leftRotate(root);
			}
		}
	}
}

vector<int> readFromFile()
{
	ifstream fin("input.txt");
	string temp = "";
	string str = "";
	getline(fin, temp, '\n');

	vector<int> a;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == ' ')
		{
			stringstream ss;
			ss << str;
			int x;
			ss >> x;
			ss.str("");
			a.push_back(x);
			str = "";
		}
		else
			str += temp[i];
	}

	temp = "";
	stringstream ss,ss2,ss3;
	int x;

	getline(fin, temp, ' ');
	ss << temp[0];
	//ss << temp[1];
	ss >> x;
	a.push_back(x);
	ss.str("");
	temp = "";
	
	getline(fin, temp, '\n');
	ss2 << temp[0];
	ss2 << temp[1];
	ss2 >> x;
	ss2.str("");
	a.push_back(x);
	temp = "";

	getline(fin, temp, '\n');
	ss3 << temp[0];
	ss3 << temp[1];
	ss3 >> x;
	ss3.str("");
	a.push_back(x);

	return a;
}

int printSum(NODE* root, int h, int c)
{
	if (!root)
		return 0;
	else if (height(root) == h && root->key > c)
	{
		return root->key + printSum(root->l, h, c) + printSum(root->r, h, c);
	}
	return
		printSum(root->l, h, c) + printSum(root->r, h, c);
}

int main()
{
	//962, 455, 662, 367, 765, 58, 786, 938, 306, 123, 400, 500, 777, 1000, 19, 399, 450, 499, 550, 900, 451, 600
	/*vector<int> a;
	a.push_back(962);
	a.push_back(455);
	a.push_back(662);
	a.push_back(367);
	a.push_back(765);
	a.push_back(58);
	a.push_back(786);
	a.push_back(938);
	a.push_back(306);
	a.push_back(123);
	a.push_back(400);
	a.push_back(500);
	a.push_back(777);
	a.push_back(1000);
	a.push_back(19);
	a.push_back(399);
	a.push_back(450);
	a.push_back(499);
	a.push_back(550);
	a.push_back(900);
	a.push_back(451);
	a.push_back(600);


	NODE* root = createTree(a);
	LNR(root);
	cout << endl;


	remove(root, 367);
	remove(root, 765);

	LNR(root);
	cout << endl;

	cout<<getBalance(root);*/

	vector<int>a = readFromFile();

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	NODE* root = createTree2(a);

	LNR(root);
	cout << endl;

	cout<<"SUM: "<<printSum(root,a[a.size()-3], a[a.size()-2]);

	return 0;
}

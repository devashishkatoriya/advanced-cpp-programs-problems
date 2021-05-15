#include <iostream>

using namespace std;

class MyString
{
	string str;
public:
	MyString(string str2)
	{
		str = str2;
	}
	friend ostream& operator<<(ostream &o1, MyString& obj);
};

ostream& operator<<(ostream &o1, MyString& obj)
{
	o1 << obj.str;
	return o1;
}

int main()
{
	string s = "Hello";
	MyString obj(s);

	cout<<obj<<endl;

	return 0;
}
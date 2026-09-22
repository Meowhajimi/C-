#include <iostream>
#include <string> //string ≠ string.h, cstring

using namespace std;

struct stu
{
	string name;
	int age;
};

void add(int& a) //更方便改变变量了
{
	a += 1;
}
int main(void)
{
	stu student[10]; //比C语言结构体方便，不用typedef
	int n; // for (int i = 0; ...）在比较落后的C语言版本会报错 如C89
	      
	cin >> n;
	cin.ignore(1000, '\n'); //吞掉\n，避免被getline直接读取\n跳过读取
	cout << "wohao" << ++n << endl; //++n与n++是两个区别，++n输入前+

	bool flag = true;
	bool flag2 = -1;
	bool flag3 = 0;

	cout << flag << flag2 << flag3 << endl;

	const int MAX = 100; //在C++定义不可改变的常量 

	string s1 = "hello ";
	string s2 = "world";
	cout << s1 + s2 << endl; //方便的字符串操作  若在cin带来的界面输入 hello world 则会直接截断空格以及后面的world 可以用下面的操作避免问题

	getline(cin, s1);

	cout << s1.length() << endl;

	string s_ = "Hello world";
	string s_sub = s_.substr(4, 3); //从第5个字符开始取，向后取3个字符
	string s_cops = s_.substr(6); //把第七个字符以及后面的字符全部取出
	cout << s_cops << s_sub << endl;

	int a = 0;
	add(a);
	cout << a << endl;
	return 0;
}
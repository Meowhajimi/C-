#include <iostream>
#include<vector>
#include<set>
#include<map> 
#include<stack>
#include<queue>
using namespace std;

int main(void)
{   //下面是动态数组的操作
	vector <int> v; //创建动态数组 v(10, 1)相当于开辟十个空间，对每一个空间赋值为1，若不填1，则自动初始化为一堆0，resize也是初始化一堆0

	v.resize(10); //规划动态数组的大小

	for (int i = 0; i < 10; i++)
		v[i] = i; //一句话不用花括号
    v.push_back(10); //自动扩容到后面

	for (int j = 0; j < 11; j++)
		cout << v[j] << " ";

	for (auto p = v.begin(); p != v.end(); p++) //智慧遍历 v.end为数组最后一个元素的下一个位置
		cout << *p << " ";
	cout << "\n";


    // 下面是set（集合）的部分
	//set不可以初始分配空间，且元素具有互异性,set内的元素会自动排序
	set <int> s = { 1, 2 }; //只能进行初始化
	s.insert(3);
	for (auto p = s.begin(); p != s.end(); p++) //遍历
		cout << *p << " ";
	//查询
	cout << (s.find(2) != s.end()) << endl; //别少了括号 s.find返回值为一个指针 返回1 false
	cout << (s.find(4) != s.end()) << endl; //返回0 true 指针会指向最后一个空位，刚刚好是end
	//删除
	s.erase(2);


	//下面是键值对（map）的部分 map会将所有键值对按照键从小到大排序，若为string则按照ASCII码排序 如hello:2, world:3,由于h < w，所以h在前面

	map <string, int> m;

	m["hello"] = 2;
	m["world"] = 3;

	cout << "hello" << ":" << m["hello"] << endl;

	for (auto p = m.begin(); p != m.end(); p++) //结构体指针
		cout << p->first << ":" << (*p).second << " ";
	cout << "\n";
    //计算长度
	cout << "m的大小是:" << m.size() << endl;


	//下面是stack(栈) 原则：后面进的最先出去

	stack <int> St;

	St.push(1);
	St.push(2);
	St.push(3);

	St.pop(); // 让栈顶元素出栈 栈顶 3
	cout << St.top() << endl;
	cout << "St的长度是" << St.size() << endl;
	//注意，栈只能操作栈顶元素，其他元素无法被操作，所以栈无法被auto遍历

	
	//下面是队列 入队 push() 出队 pop() 

	queue <int> Qu;

	for (int i = 0; i < 10; i++)
		Qu.push(i);
	
	cout << "队首是: " << Qu.front() << " 队尾是: " << Qu.back() << endl;

	Qu.pop(); //在队首出队
	
	cout << "队首是: " << Qu.front() << " 队尾是: " << Qu.back() << endl;

	Qu.push(11);

	cout << "队首是: " << Qu.front() << " 队尾是: " << Qu.back() << endl;

	cout << "队列长度: " << Qu.size() << endl;
	//下面是unordered_map 与unordered_set 这两不会进行排序，节省时间 操作不与展示，因为与前面的map set完全相同
	//注意 插入的元素没用任何顺序可言！这是为了极致的效率

	return 0;
}
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <list>
#include <vector>

using namespace std;
const int N = 10086; //自定义预设值
const int M = 100; //自定义重复次数

int CurrentTime() //生成毫秒级时间，并返回时间数值
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return sys.wSecond * 1000 + sys.wMilliseconds;
}

int RandNum(int currentTime)
{
	unsigned seed;
	seed = currentTime;
	srand(seed); //生成随机数
	int randRes = 0; //保存随机数结果的变量
reRand:
	randRes = rand();
	if (randRes > N) //如果随机数大于预设值，则重新生成
	{
		goto reRand;
	}
	return randRes; //返回随机数结果
}

int RunList(int randRes)
{
	list<int> List(N , 0); //创建一个list容器
	list<int>::iterator i;
	int tmp = 0;
	int startTime = CurrentTime(); //记录开始时间
	for (i = List.begin(); i != List.end(); i++) //遍历容器
	{
		if (tmp == randRes) //当遍历到目标位置时插入数据
		{
			List.insert(i, 1);
			break; //插入完成后跳出循环
		}
		tmp++;
	}
	int endTime = CurrentTime(); //记录结束时间
	int deltaTime = endTime - startTime; //计算时间差
	return deltaTime; //返回时间差
}

int RunVector(int randRes) //注释同RunList函数
{
	vector<int> Vector(N, 0);
	vector<int>::iterator i;
	int tmp = 0;
	int startTime = CurrentTime();
	for (i = Vector.begin(); i != Vector.end(); i++) {
		if (tmp == randRes)
		{
			Vector.insert(i, 1);
			break;
		}
		tmp++;
	}
	int endTime = CurrentTime();
	int deltaTime = endTime - startTime;
	return deltaTime;
}

int main()
{
	int listTime = 0;
	int vectorTime = 0;
Again:
	for (int i = 0; i < M; i++) //多次运行，记录总时间，避免偶然性
	{
		int currentTime = CurrentTime();
		int randRes = RandNum(currentTime); //将 生成随机数的函数返回值 赋给一个变量
		int listTimeTmp = RunList(randRes);
		int vectorTimeTmp = RunVector(randRes);
		listTime += listTimeTmp;
		vectorTime += vectorTimeTmp;
	}
	cout << "list执行" << M << "次总速度为：" << listTime << endl << "vector执行" << M << "次总速度为：" << vectorTime << endl << "单位：毫秒" << endl;
	if (listTime > vectorTime) cout << "vector执行速度较快" << endl;
	else if (listTime < vectorTime) cout << "list执行速度较快" << endl;
	else cout << "两者速度刚好一样" << endl;
	cout << endl;
	int a = 0;
	cout << "是否重试，按1继续：" << endl;
	cin >> a;
	if (a == 1) goto Again;
	return 0;
}
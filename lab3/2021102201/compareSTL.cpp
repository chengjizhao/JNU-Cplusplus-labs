#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <list>
#include <vector>

using namespace std;
const int N = 10086; //�Զ���Ԥ��ֵ
const int M = 100; //�Զ����ظ�����

int CurrentTime() //���ɺ��뼶ʱ�䣬������ʱ����ֵ
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return sys.wSecond * 1000 + sys.wMilliseconds;
}

int RandNum(int currentTime)
{
	unsigned seed;
	seed = currentTime;
	srand(seed); //���������
	int randRes = 0; //�������������ı���
reRand:
	randRes = rand();
	if (randRes > N) //������������Ԥ��ֵ������������
	{
		goto reRand;
	}
	return randRes; //������������
}

int RunList(int randRes)
{
	list<int> List(N , 0); //����һ��list����
	list<int>::iterator i;
	int tmp = 0;
	int startTime = CurrentTime(); //��¼��ʼʱ��
	for (i = List.begin(); i != List.end(); i++) //��������
	{
		if (tmp == randRes) //��������Ŀ��λ��ʱ��������
		{
			List.insert(i, 1);
			break; //������ɺ�����ѭ��
		}
		tmp++;
	}
	int endTime = CurrentTime(); //��¼����ʱ��
	int deltaTime = endTime - startTime; //����ʱ���
	return deltaTime; //����ʱ���
}

int RunVector(int randRes) //ע��ͬRunList����
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
	for (int i = 0; i < M; i++) //������У���¼��ʱ�䣬����żȻ��
	{
		int currentTime = CurrentTime();
		int randRes = RandNum(currentTime); //�� ����������ĺ�������ֵ ����һ������
		int listTimeTmp = RunList(randRes);
		int vectorTimeTmp = RunVector(randRes);
		listTime += listTimeTmp;
		vectorTime += vectorTimeTmp;
	}
	cout << "listִ��" << M << "�����ٶ�Ϊ��" << listTime << endl << "vectorִ��" << M << "�����ٶ�Ϊ��" << vectorTime << endl << "��λ������" << endl;
	if (listTime > vectorTime) cout << "vectorִ���ٶȽϿ�" << endl;
	else if (listTime < vectorTime) cout << "listִ���ٶȽϿ�" << endl;
	else cout << "�����ٶȸպ�һ��" << endl;
	cout << endl;
	int a = 0;
	cout << "�Ƿ����ԣ���1������" << endl;
	cin >> a;
	if (a == 1) goto Again;
	return 0;
}
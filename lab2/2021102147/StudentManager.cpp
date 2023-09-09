#include "ManagerSystem.h"
#include "Student.h"

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

void printMenu();

int main()
{
	
	ManagerSystem ms;
	if (!ms.isReady())
	{
		cout << "程序即将退出\n";
		system("pause");
		return 1;
	}
	
	std::string number;
	size_t times;
	int score;
	int choice;
	std::string yn;

	while (true)
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入学号：";
			cin >> number;
			cout << "请输入实验次数：";
			cin >> times;
			int score = ms.queryScore(number, times - 1);
			if (score <= 0)
			{
				cout << "查询失败\n\n";
			}
			else
			{
				cout << "查询成功，成绩为：" << score << "\n\n";
			}
			break;
		}
		case 2:
			cout << "请输入学号：";
			cin >> number;
			cout << "请输入实验次数：";
			cin >> times;
			cout << "请输入分数：";
			cin >> score;
			if (ms.addScoreToStudent(number, times - 1, score))
			{
				cout << "添加成功\n\n";
			}
			else
			{
				cout << "添加失败\n\n";
			}
			break;
		case 3:
			if (ms.save())
			{
				cout << "保存成功\n";
			}
			else
			{
				cout << "保存失败\n\n";
			}
			break;
		case 4:
			if (ms.isModified())
			{
				while (true)
				{
					cout << "发生了修改，是否保存？(y/n)";
					cin >> yn;
					if ((yn == "y" || yn == "Y"))
					{
						if (ms.save())
						{
							cout << "程序将退出...\n";
							system("pause");
							return 0;
						}
						else
						{
							cout << "保存失败\n\n";
							break;
						}
					}
					else if ((yn == "n" || yn == "N"))
					{
						cout << "程序将退出...\n";
						system("pause");
						return 0;
					}
				}
				break;
			}
			else
			{
				cout << "程序将退出...\n";
				system("pause");
				return 0;
			}
		default:
			cout << "无效的选择\n";
			break;
		}	
	}
	return 0;
}


void printMenu()
{
	cout << "1. 查询成绩\n";
	cout << "2. 录入成绩\n";
	cout << "3. 保存数据到文件\n";
	cout << "4. 退出系统\n";
	cout << "请输入您的选择：";
}

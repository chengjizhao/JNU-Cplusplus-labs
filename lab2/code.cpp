#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

void enter()
{
	char sNum[20];
	char sScore[10];
	cout << "������ѧ�ţ�";
	cin >> sNum;
	cout << "�����������";
	cin >> sScore;
	
	ifstream csv_data("student.csv", ios::in);
	string line;
	
	if (!csv_data.is_open())
	{
		cout << "Error: opening file fail" << endl;
		exit(1);
	}
	
	istringstream sin;
	vector<vector<string> > datas;
	string word;
	vector<string> words;
	
	while (getline(csv_data, line))
	{
		sin.clear();
		sin.str(line);
		words.clear();
		int flag = 0;
		while (getline(sin, word, ','))
		{
			flag += 1;
			words.push_back(word);
		}
		if (flag == 10) words.push_back("--");
		if (words[0] == sNum) words.push_back(sScore);
		datas.push_back(words);
	}
	csv_data.close();
	
	ofstream outFile;
	outFile.open("student.csv", ios::out | ios::trunc);
	for (int i = 0; i < datas.size(); i ++)
	{
		for (int j = 0; j < datas[i].size(); j ++)
		{
			outFile << datas[i][j] << ',';
		}
		outFile << endl;
	}
	outFile.close();
	
	cout << "��¼��ɹ�\n" << endl;
}

void search()
{
	char sNum[20];
	cout << "������ѧ�ţ�";
	cin >> sNum;
	
	ifstream csv_data("student.csv", ios::in);
	string line;
	
	if (!csv_data.is_open())
	{
		cout << "Error: opening file fail" << endl;
		exit(1);
	}
	
	istringstream sin;
	vector<string> words;
	string word;
	
	while (getline(csv_data, line))
	{
		sin.clear();
		sin.str(line);
		words.clear();
		while (getline(sin, word, ',')) words.push_back(word);

		if (words[0] == sNum)
		{
			cout << "\nѧ�ţ�" << words[0]
				 << "\n������" << words[1]
				 << "\nרҵ��" << words[4]
				 << "\n�ɼ���";
			for (int k = 11; k < words.size(); k ++) cout << words[k] << " ";
			cout << endl;
		}
	}
	csv_data.close();	
}

int main()
{
	struct student
	{
		char num[20];
		char name[10];
		char spec[20];
		int score;
	}s1;
	int q = 1;
	char choice;
	while (q)
	{
		cout << "-------------------------\n";
		cout << "��ѡ���ѯ�ɼ���¼��ɼ���1����ѯ��2��¼�룻q���˳�����";
		cin >> choice;
		switch (choice)
		{
			case '1': search(); break;
			case '2': enter(); break;
			case 'q': q = 0; break;
		}
	}
	return 0;
}

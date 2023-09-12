#include <string.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <streambuf>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct S_Student
{
    string studentId;
    string name;
    string major;
    double score[16];
	double sum_score;
};

vector<S_Student> V_Student;

void ReadCSV(const string& csvfilename)
{
	ifstream csvfile(csvfilename);
	string line;

	if (!csvfile.is_open()){
		cout << "未读取csv数据文件" << endl;
		exit(1);
	}

	while (getline(csvfile, line))
    {
		stringstream ss(line);
		string word;
		vector<string> words;
		while (getline(ss, word, ','))
		{ 	
			words.push_back(word);
		}
		
        S_Student student;

        student.studentId = words[0];
        student.name = words[1];
        student.major = words[2];
		student.sum_score = 0;
		for(int k=0;k<16;k++)
		{
			student.score[k] = stod(words[k+3]);
			student.sum_score = student.sum_score + student.score[k];			
		}
        V_Student.push_back(student);
		
	}
	csvfile.close();
}

void WriteCSV(const string& csvfilename) 
{
    ofstream csvfile(csvfilename);
    if (!csvfile.is_open())
	{
        cout << "未写入csv数据文件" << endl;
        return;
    }

    for (const auto &student : V_Student)
    {
        csvfile << student.studentId << "," << student.name << "," << student.major << "," ;
		for(int k=0;k<16;k++)
		{
			csvfile << student.score[k] << ",";				
		}
		csvfile << student.sum_score << endl;
    }

    csvfile.close();
}

void PrintScore(const string& studentId)
{
	for (const auto& student : V_Student) 
	{
		if (student.studentId == studentId) 
		{
			cout << "--------------------" << endl;
			cout << "姓名："<< student.name << endl;
			cout << "学号："<< student.studentId << endl;
			cout << "专业："<< student.major << endl;
			for(int k=0;k<16;k++)
			{
				cout << "第" << k+1 << "次平时成绩：";
				cout << student.score[k] << endl;				
			}
			cout << "期末成绩："<< student.sum_score << endl << "--------------------" << endl;
			return;
		}
 	}
	cout <<"未找到对应学号学生，请重新输入" << endl << endl;
}

void ChangeScore(const string& studentId, int k ,double score) 
{
	for (auto& student : V_Student) 
	{
		if (student.studentId == studentId) 
		{
			student.sum_score = student.sum_score + score - student.score[k-1];
			student.score[k-1] = score;
			PrintScore(studentId);
			cout << "输入成功" << endl << endl;
			return;
		}
	}	
	cout <<"未找到对应学号学生，请重新输入" << endl << endl;
}

int main()
{
	string studentId;
    string name;
    string major;
	double score;
	int Choose;
    string csvfilename = "studentscores.csv";

    ReadCSV(csvfilename);

	do
	{
		cout << "查询成绩输入1,录入成绩输入2,退出系统输入3" << endl;
		cin >> Choose;

		if ( Choose== 1){
			cout << "请输入查询学号" << endl;
			cin >> studentId;
			PrintScore(studentId);
		}

		else if ( Choose == 2)
		{
			cout << "请输入学号" << endl;
			cin >> studentId;

			cout << "第几次作业" << endl;
			int k;
			cin >> k;
			while(k<1||k>16)
			{
				cout<<"输入错误，请重新输入" << endl;
				cin >> k;					
			}

			cout << "成绩多少分";
			cin >> score;
			while(score<0||score>3)
			{
				cout<<"输入错误，请重新输入" << endl;
				cin >> score;					
			}
			ChangeScore(studentId, k, score);
		}

		else if (!Choose == 3)
		{
			cout << "输入错误，请重新输入" << endl;
		}
	}while (!Choose == 3);
	WriteCSV(csvfilename);
}
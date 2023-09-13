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

struct S_Student{
    string studentId;
    string name;
    string major;
    double score[16];
	double sum_score;
};

vector<S_Student> V_Student;

void ReadCSV(const string& csvfilename){
	ifstream csvfile(csvfilename);
	string line;

	if (!csvfile.is_open()){
		cout << "！！！错误:未正确读取csv数据文件！！！" << endl;
		exit(1);
	}

	while (getline(csvfile, line)){	//将文件整行读取到字符串line
		stringstream ss(line);
		string word;
		vector<string> words;
		while (getline(ss, word, ',')){ //将字符串流iss中的字符读到word字符串中，以逗号为分隔符		
			words.push_back(word);
		}
		
        S_Student student;//依照结构体格式读取文件并存于vector中

        student.studentId = words[0];
        student.name = words[1];
        student.major = words[2];
		student.sum_score = 0;
		for(int i=0;i<16;i++){
			student.score[i] = stod(words[i+3]);
			student.sum_score = student.sum_score + student.score[i];			
		}
        V_Student.push_back(student);
		
	}
	csvfile.close();
}

void WriteCSV(const string& csvfilename) {
    ofstream csvfile(csvfilename);
    if (!csvfile.is_open()){
        cout << "！！！错误:未正确写入csv数据文件！！！" << endl;
        return;
    }

    for (const auto &student : V_Student){//逐行输出数据
        csvfile << student.studentId << "," << student.name << "," << student.major << "," ;
		for(int i=0;i<16;i++){
			csvfile << student.score[i] << ",";				
		}
		csvfile << student.sum_score << endl;
    }

    csvfile.close();
}

void PrintScore(const string& studentId){
	for (const auto& student : V_Student) {
		if (student.studentId == studentId) {
			cout << "--------------------" << endl;
			cout << "姓名："<< student.name << endl;
			cout << "学号："<< student.studentId << endl;
			cout << "专业："<< student.major << endl;
			for(int i=0;i<16;i++){
				cout << "第" << i+1 << "次平时成绩：";
				cout << student.score[i] << endl;				
			}
			cout << "期末成绩："<< student.sum_score << endl << "--------------------" << endl;
			return;
		}
 	}
	cout <<"！！！未找到对应学号学生，请检查输入是否出现错误！！！" << endl << endl;
}

void ChangeScore(const string& studentId, int i ,double score) {
	for (auto& student : V_Student) {
		if (student.studentId == studentId) {
			student.sum_score = student.sum_score + score - student.score[i-1];
			student.score[i-1] = score;
			PrintScore(studentId);
			cout << "！！！输入成绩成功！！！" << endl << endl;
			return;
		}
	}	
	cout <<"！！！未找到对应学号学生，请检查输入是否出现错误！！！" << endl << endl;
}

int main(){
	string studentId;
    string name;
    string major;
	double score;
	int Choose;
    string csvfilename = "D:/test.csv";

    ReadCSV(csvfilename);

	cout << "*******欢迎使用学生成绩查询录入系统*******" << endl << endl;
	do{
		cout << "查询成绩输入1,录入成绩输入2,退出系统输入0：" << endl;
		cin >> Choose;

		if ( Choose== 1){
			cout << "请输入查询学号：" << endl;
			cin >> studentId;
			PrintScore(studentId);
		}

		else if ( Choose == 2){
			cout << "请输入学号：" << endl;
			cin >> studentId;

			cout << "录入第几次作业(1~16)：" << endl;
			int i;
			cin >> i;
			while(i<1||i>16){
				cout<<"输入错误请重新输入(1~16)：" << endl;
				cin >> i;					
			}

			cout << "成绩为多少(0~3)：";
			cin >> score;
			while(score<0||score>3){
				cout<<"输入错误请重新输入(0~3)：" << endl;
				cin >> score;					
			}
			ChangeScore(studentId, i, score);
		}

		else if (!Choose == 0){
			cout << "！！！输入无效请重新输入！！！" << endl;
		}
	}while (!Choose == 0);
	WriteCSV(csvfilename);
}
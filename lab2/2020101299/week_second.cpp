#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
void load_information(const string& filename) {
    ifstream file(filename);//检查文件是否打开
    if (!file.is_open()) {
        cout << "无法打开文件" << endl;
    }
    vector <vector <string> > Students_Data;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector <string> row;
        string cell;
        while (getline(iss, cell, ',')) {
            row.push_back(cell);
        }
        Students_Data.push_back(row);
    }
    file.close();
    vector<int> columns_save = {0, 1, 4, 11};
    ofstream ofs("Students_Data_new.csv");
    for (const auto& row : Students_Data) {
        for (int i = 0; i < 4; i++) {
            int save = columns_save[i];// 检查列的索引是否在有效范围内 
            if (save >= 0 && save < static_cast<int>(row.size())) {
                ofs << row[save];
            }
            if (i != 3) {
                ofs << ",";
            }
        }
        ofs << "\n";
    }
    ofs.close();
}
void read_information(const string& student_ID) {
    ifstream ifs("Students_Data_new.csv");
    vector <vector <string> > Students_Data;
    if (ifs.is_open()) {
        string line;
        while (getline(ifs, line)) {
            vector <string> row;
            string cell;
            size_t pos = 0;
            while ((pos = line.find(',')) !=string::npos) {
                cell = line.substr(0, pos);
                row.push_back(cell);
                line.erase(0, pos + 1);
            }
            row.push_back(line);// 将row添加到Students_Data中，以便之后使用  
            Students_Data.push_back(row);
        }
        ifs.close();
    } 
    float score_sum = 0;// 定义一个浮点数变量，用于计算总成绩  
    for (auto& row : Students_Data) {
        if (row[0] == student_ID) {
            cout << "学号：" << row[0] << endl; // 如果是匹配的学生，则输出学生的学号
            cout << "姓名：" << row[1] << endl;
            cout << "专业：" << row[2] << endl;
            cout << "成绩：";
            for(int i = 3; i < row.size(); i++) {
                cout << row[i] << ' ';
                if(row[i].empty()) {
                    row[i] = '0';
                }
                float score = stof(row[i]);
                score_sum = score_sum + score;
            }
            cout << endl;
            cout << "总成绩："<< score_sum << endl;
        }
    }}
void write_information(const string& student_ID, const string& score) {
    ifstream ifs("Students_Data_new.csv");
    vector <vector <string> > Students_Data;
    if (ifs.is_open()) {
        string line;
        while (getline(ifs, line)) {
            vector <string> row;
            string cell;
            size_t pos = 0;
            while ((pos = line.find(',')) !=string::npos) {
                cell = line.substr(0, pos);
                row.push_back(cell);
                line.erase(0, pos + 1);
            }
            row.push_back(line);
            Students_Data.push_back(row);
        }
        ifs.close();
    }
    for (auto& row : Students_Data) {
        if (row[0] == student_ID) {
            row.insert(row.begin() + 3, score);
        }
    }
    ofstream ofs("Students_Data_new.csv");
    if (ofs.is_open()) {
        for (const auto& row : Students_Data) {
            for (int i = 0; i < row.size(); i++) {
                ofs<< row[i];
                if (i != row.size() - 1) {
                    ofs << ",";
                }
            }
            ofs << "\n";
        }
        ofs.close();
        for (const auto& row : Students_Data) {
              if (row[0] == student_ID) {
                int num = row.size() - 4;
                cout << "第" << num << "次成绩已保存" << endl;
                break;
              }
        }
    } 
    else {cout << "学生不存在" << endl;}
}
int main(){
    load_information("Students_Data.csv"); 
    while(true) {
        string student_ID;
        cout << endl;
        cout << "请输入学号：";
        cin >> student_ID;
        int choice;
        cout << "请选择您要进行的操作：" << endl;
        cout << "1、查询成绩" << endl;
        cout << "2、输入成绩" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
            read_information(student_ID);//调用read_information函数，查询指定学号的成绩信息
            break;
            case 2:
            string score;
            cout << "请输入成绩：";
            cin >> score;
            write_information(student_ID, score);
            break;
            }
        int exit;
        cout << "是否继续操作？" << endl;
        cout << "1、继续" << endl;
        cout << "2、停止" << endl;
        cin >> exit;
        if(exit == 2) { return 0; }
    }
}
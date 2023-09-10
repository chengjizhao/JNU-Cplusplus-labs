#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
using namespace std;


//定义Student类
struct Student {
    std::string name;//std::string是C++标准库中的一个类，用于表示可变长度的字符串
    std::string major;
    std::map<std::string, int> scores;// 声明 表scores,存储分数
};



/******************************************************************************
* 函 数 名       : ReadCSV
* 函数功能       : 读取CSV文件
* 输    入       : 文件名
* 输    出       : 无
******************************************************************************/

std::map<int, Student> ReadCSV(const std::string& filename) {
    string fname = "D:\\test.csv";
    //以读入方式打开文件
    ifstream csv_data(fname, ios::in);

    if (!csv_data.is_open())
    {
        cout << "打开文件失败" << endl;
        exit(1);
    }
    else {
        string line;
        std::map<int, Student> students;
        //getline(csv_data, line);// 读取标题行

        // 按行读取数据
        while (getline(csv_data, line))
        {
            istringstream iss(line);
            vector<string> tokens;
            string token;

            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            Student student;
            int studentID = std::stoi(tokens[0]);
            student.name = tokens[1];
            student.major = tokens[2];
            students[studentID] = student;


            if (tokens.size() > 3) {
                int i = 0;
                for (i = 3;i < tokens.size();i++)
                {
                    students[studentID].scores["实验" + to_string(i - 2)] = std::stoi(tokens[i]);
                }
            }
           


        }
        return students;
        csv_data.close();
    }
}


void WriteCSV(const std::string& filename, const std::map<int, Student>& students) {
    std::ofstream file(filename);

    // 写入学生数据
    for (const auto& entry : students) {
        file << entry.first << "," << entry.second.name << "," << entry.second.major;

        for (const auto& score : entry.second.scores) {
            file << "," << score.second;
        }
        file << std::endl;
    }

    file.close();
}



void AddScore(std::map<int, Student>& students, int studentID, const std::string& experiment, int score) {
    if (students.find(studentID) != students.end()) {
        students[studentID].scores[experiment] = score;

        WriteCSV("D:\\test.csv", students);  // 将成绩写入CSV文件
    }
}



void CalSco()
{
    std::string filename = "D:\\test.csv";
    std::map<int, Student> students = ReadCSV(filename);
    int Cal = 0,studentID;
    std::cout << "输入学生ID：";
    std::cin >> studentID;
    if (students.find(studentID) != students.end()) {
        for (const auto& score : students[studentID].scores) {
            Cal += score.second;
        }
        cout << "该学生总成绩为" << Cal << endl;
    }
}



/******************************************************************************
* 函 数 名       : main
* 函数功能       : 主函数
* 输    入       : 无
* 输    出       : 无
******************************************************************************/
int main() {
    std::string filename = "D:\\test.csv";
    std::map<int, Student> students = ReadCSV(filename);

    int choice;
    do {
        std::cout << "1.按学号查询分数" << std::endl;
        std::cout << "2.按学号添加成绩" << std::endl;
        std::cout << "3.按学号计算总成绩" << std::endl;
        std::cout << "4.退出" << std::endl;
        std::cout << "输入您的选择：";
        std::cin >> choice;

        //按学生ID查询分数
        if (choice == 1) {
            int studentID;
            std::cout << "输入学生ID：";
            std::cin >> studentID;

            if (students.find(studentID) != students.end()) {
                std::cout << "学生姓名： " << students[studentID].name << std::endl;
                std::cout << "专业： " << students[studentID].major << std::endl;
                for (const auto& score : students[studentID].scores) {
                    std::cout << score.first << ": " << score.second << std::endl;//输出各次实验成绩
                }
            }
            else {
                std::cout << "未找到学生！" << std::endl;
            }
        }

        //按学号添加成绩
        else if (choice == 2) {
            int studentID;
            std::cout << "输入学生ID： ";
            std::cin >> studentID;

            std::string experiment;
            std::cout << "输入实验名称（以“实验+实验序号”命名）：";
            std::cin.ignore();
            std::getline(std::cin, experiment);

            int score;
            std::cout << "输入分数： ";
            std::cin >> score;

            AddScore(students, studentID, experiment, score);//加到结构
            WriteCSV(filename, students);//写进文件
        }

        else if (choice == 3)
        {
            CalSco();
        }

        std::cout << std::endl;

    } while (choice != 4);
    WriteCSV(filename, students);
    return 0;
}

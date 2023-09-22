#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>


using namespace std;

//定义结构体
struct Student {
    std::string name;
    std::string major;
    std::map<std::string, int> scores;
};



std::map<int, Student> ReadCSV(const std::string& filename) {
    string fname = "D:\\test.csv";
    //打开文件
    ifstream csv_data(fname, ios::in);

    if (!csv_data.is_open())
    {
        cout << "打开文件失败" << endl;
        exit(1);
    }
    else {
        string line;
        std::map<int, Student> students;
        // 读取标题行

        // 读取数据
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

    // 写入数据
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
        //写入CSV文件
        WriteCSV("D:\\test.csv", students);  
    }
}



void SumScore()
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

enum
{
    Exit,
    Scoresearch,
    Scoreadd,
    Scoresum

};
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

        if (choice == Scoresearch) {
            int studentID;
            std::cout << "输入学生ID：";
            std::cin >> studentID;

            if (students.find(studentID) != students.end()) {
                std::cout << "学生姓名： " << students[studentID].name << std::endl;
                std::cout << "专业： " << students[studentID].major << std::endl;
                for (const auto& score : students[studentID].scores) {
                    //输出各次实验成绩
                    std::cout << score.first << ": " << score.second << std::endl;
                }
            }
            else {
                std::cout << "未找到学生！" << std::endl;
            }
        }

        //按学号添加成绩
        else if (choice == Scoreadd) {
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
            //加到结构
            AddScore(students, studentID, experiment, score);
            //写进文件
            WriteCSV(filename, students);
        }

        else if (choice == Scoresum)
        {
            SumScore();
        }

        std::cout << std::endl;

    } while (choice != Exit);
    WriteCSV(filename, students);
    return 0;
}
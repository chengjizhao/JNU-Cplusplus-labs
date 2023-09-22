#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

struct Student
{
    std::string studentID;
    std::string name;
    std::string major;
    std::vector<int> scores;

    Student(std::string id, std::string n, std::string m)
        : studentID(id), name(n), major(m)
    {
        scores.resize(18, 0); 
    }

    double cal_score() const
    {
        double total = 0.0;
        for (int score : scores)
        {
            if (score >= 0)
            {
                total += score;
            }
        }
        return total;
    }
};

std::map<std::string, Student> load_data(const std::string &filename)
{
    std::map<std::string, Student> students;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "无法打开文件 " << filename << std::endl;
        return students;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string studentID, name, major;
        iss >> studentID >> name >> major;

        students[studentID] = Student(studentID, name, major);
    }
    return students;
}

void save_data(const std::string &filename, const std::map<std::string, Student> &students)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "无法打开文件 " << filename << " 进行保存" << std::endl;
        return;
    }

    for (const auto &pair : students)
    {
        const Student &student = pair.second;
        file << student.studentID << " " << student.name << " " << student.major;
        for (int score : student.scores)
        {
            file << " " << score;
        }
        file << "\n";
    }
    std::cout << "数据已保存到 " << filename << std::endl;
}

int main()
{
    std::string filename = "student_data.csv";
    std::map<std::string, Student> students = load_data(filename);

    while (true)
    {
        std::cout << "选择操作:\n1. 录入成绩\n2. 查询成绩\n3. 计算总成绩\n4. 退出\n";
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "输入学号: ";
            std::string studentID;
            std::cin >> studentID;

            if (students.find(studentID) != students.end())
            {
                std::cout << "输入第几次实验成绩 (1-18): ";
                int experiment_number;
                std::cin >> experiment_number;

                if (experiment_number >= 1 && experiment_number <= 18)
                {
                    std::cout << "输入成绩: ";
                    int score;
                    std::cin >> score;
                    students[studentID].scores[experiment_number - 1] = score;
                    save_data(filename, students);
                }
                else
                {
                    std::cerr << "无效的实验次数\n";
                }
            }
            else
            {
                std::cerr << "学号不存在\n";
            }
        }
        else if (choice == 2)
        {
            std::cout << "输入学号以查询成绩: ";
            std::string studentID;
            std::cin >> studentID;

            if (students.find(studentID) != students.end())
            {
                const Student &student = students[studentID];
                std::cout << "学号: " << student.studentID << "\n";
                std::cout << "姓名: " << student.name << "\n";
                std::cout << "专业: " << student.major << "\n";
                for (int i = 0; i < 18; ++i)
                {
                    if (student.scores[i] >= 0)
                    {
                        std::cout << "实验" << (i + 1) << "成绩: " << student.scores[i] << "\n";
                    }
                    else
                    {
                        std::cout << "实验" << (i + 1) << "成绩: 未录入\n";
                    }
                }
            }
            else
            {
                std::cerr << "学号不存在\n";
            }
        }
        else if (choice == 3)
        {
            std::cout << "计算总成绩并显示:\n";
            for (const auto &pair : students)
            {
                const Student &student = pair.second;
                double total_score = student.cal_score();
                std::cout << "学号: " << student.studentID << " 总成绩: " << total_score << "\n";
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cerr << "无效的选项\n";
        }
    }

    return 0;
}
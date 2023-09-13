#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

struct Student {
    std::string id;
    std::string name;
    std::string major;
    std::map<std::string, float> scores;
};

class Database {
private:
    std::vector<Student> students;
public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "文件不存在。正在创建新文件。" << std::endl;
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if (tokens.size() >= 3) {
                Student student;
                student.id = tokens[0];
                student.name = tokens[1];
                student.major = tokens[2];
                for (size_t i = 3; i + 1 < tokens.size(); i += 2) {
                    std::string subject = tokens[i];
                    float score = std::stof(tokens[i + 1]);
                    student.scores[subject] = score;
                }
                students.push_back(student);
            }
        }
        file.close();
    }

   void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& student : students) {
            file << student.id << "," << student.name << ","
                 << student.major << "";
             for (const auto& score : student.scores) {
                file << "," << score.first << "," << score.second;
            }
            file << "\n";
        }
        file.close();
    }

    void addScore(const std::string& id, const std::string& subject, float score) {
        for (auto& student : students) {
            if (student.id == id) {
                student.scores[subject] = score;
                break;
            }
        }
    }

    float calcTotalScore(const std::string& id) {
        for (const auto& student : students) {
            if (student.id == id) {
                float totalScore = 0.0;
                for (const auto& score : student.scores) {
                    totalScore += score.second;
                }
                return totalScore;
            }
        }
        return 0.0;
    }

    void printStudentInfo(const std::string& id) {
        for (const auto& student : students) {
            if (student.id == id) {
                std::cout << "学号: " << student.id << std::endl;
                std::cout << "姓名: " << student.name << std::endl;
                std::cout << "专业: " << student.major << std::endl;
                std::cout << "成绩:" << std::endl;
                for (const auto& score : student.scores) {
                    std::cout << score.first << ": " << score.second << std::endl;
                }
                std::cout << "总成绩: " << calcTotalScore(id) << std::endl;
                return;
            }
        }
        std::cout << "未找到该学生信息" << std::endl;
    }
};

int main() {
    Database db;
    db.loadFromFile("students.csv");

    while (true) {
        std::cout << "1. 查询成绩" << std::endl;
        std::cout << "2. 录入实验课成绩" << std::endl;
        std::cout << "3. 退出" << std::endl;
        std::cout << "请选择操作：";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string id;
                std::cout << "请输入学号：";
                std::cin >> id;
                db.printStudentInfo(id);
                break;
            }
            case 2: {
                std::string id;
                std::cout << "请输入学号：";
                std::cin >> id;

                std::string subject;
                std::cout << "请输入实验课名称：";
                std::cin.ignore();
                std::getline(std::cin, subject);

                float score;
std::cout << "请输入成绩：";
                std::cin >> score;

                db.addScore(id, subject, score);
                db.saveToFile("students.csv");
                std::cout << "成绩录入成功" << std::endl;

                break;
            }
            case 3:
                return 0;
            default:
                std::cout << "无效的选项，请重新选择" << std::endl;
        }
    }

    return 0;
}

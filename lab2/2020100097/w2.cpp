#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

struct Student {
    std::string student_id;
    std::string name;
    std::string major;
    std::map<std::string, float> scores;
};

class StudentDatabase {
private:
    std::vector<Student> students;
public:
    void loadStudentsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "File does not exist. Creating a new file." << std::endl;
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
                student.student_id = tokens[0];
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

   void saveStudentsToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& student : students) {
            file << student.student_id << "," << student.name << ","
                 << student.major << "";
             for (const auto& score : student.scores) {
                file << "," << score.first << "," << score.second;
            }
            file << "\n";
        }
        file.close();
    }

    void addScore(const std::string& studentId, const std::string& subject, float score) {
        for (auto& student : students) {
            if (student.student_id == studentId) {
                student.scores[subject] = score;
                break;
            }
        }
    }

    float calculateTotalScore(const std::string& studentId) {
        for (const auto& student : students) {
            if (student.student_id == studentId) {
                float totalScore = 0.0;
                for (const auto& score : student.scores) {
                    totalScore += score.second;
                }
                return totalScore;
            }
        }
        return 0.0;
    }

    void printStudentInfo(const std::string& studentId) {
        for (const auto& student : students) {
            if (student.student_id == studentId) {
                std::cout << "xuehao: " << student.student_id << std::endl;
                std::cout << "xingming: " << student.name << std::endl;
                std::cout << "zhuanye: " << student.major << std::endl;
                std::cout << "chengji:" << std::endl;
                for (const auto& score : student.scores) {
                    std::cout << score.first << ": " << score.second << std::endl;
                }
                std::cout << "zongchengji: " << calculateTotalScore(studentId) << std::endl;
                return;
            }
        }
        std::cout << "weizhaodao" << std::endl;
    }


};

int main() {
    StudentDatabase database;
    database.loadStudentsFromFile("students.csv");

    while (true) {
        std::cout << "1. chaxunchengji" << std::endl;
        std::cout << "2. luru" << std::endl;
        std::cout << "3. tuichu" << std::endl;
        std::cout << "xuanzhe";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string studentId;
                std::cout << "shuruxuehao";
                std::cin >> studentId;
                database.printStudentInfo(studentId);
                break;
            }
            case 2: {
                std::string studentId;
                std::cout << "shuruxuehao";
                std::cin >> studentId;

                std::string subject;
                std::cout << "shiyankemingcheng";
                std::cin.ignore();
                std::getline(std::cin, subject);

                float score;
                std::cout << "shuruchengji";
                std::cin >> score;

                database.addScore(studentId, subject, score);
                database.saveStudentsToFile("students.csv");
                std::cout << "luruchengjichenggong" << std::endl;

                break;
            }
            case 3:
                return 0;
            default:
                std::cout << "error" << std::endl;
        }
    }

    return 0;
}

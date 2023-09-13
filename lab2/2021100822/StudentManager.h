#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <string>
#include <vector>

class StudentManager {
public:
    struct Student {
        int studentID;
        std::string name;
        std::string major;
        double score;
    };//定义了数据的类型

    StudentManager();
    void LoadDataFromFile(const std::string& filename);
    void SaveDataToFile(const std::string& filename);
    void AddScore(int studentID, double newScore);
    double CalculateTotalScore(int studentID);
    void Run();//程序需要运行的主要函数

private:
    std::vector<Student> students;
};

#endif // STUDENTMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// 定义学生结构体
struct Student {
    std::string student_id;
    std::string name;
    std::string major;
    std::vector<int> scores; // 存储学生的分数
};

// 从CSV文件中读取学生信息并返回一个包含学生信息的映射表
std::map<std::string, Student> readStudentInfo(const std::string& filename) {
    std::map<std::string, Student> students; // 使用映射表存储学生信息
    std::ifstream ifs("test.csv");
    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << line << std::endl;
    }
    ifs.close();
    while (std::getline(ifs, line)) { // 逐行读取文件内容
        std::stringstream ss(line); // 将每行数据转换为字符串流
        std::string student_id, name, major, score_str;
        std::getline(ss, student_id, ','); // 使用逗号作为分隔符提取学号
        std::getline(ss, name, ','); // 使用逗号作为分隔符提取姓名
        std::getline(ss, major, ','); // 使用逗号作为分隔符提取专业
        Student student{ student_id, name, major }; // 创建学生对象
        while (std::getline(ss, score_str, ',')) { // 使用逗号作为分隔符提取分数
            int score = std::stoi(score_str); // 将字符串转换为整数
            student.scores.push_back(score); // 存储分数到学生对象中
        }
        students[student_id] = student; // 将学生对象存储到映射表中
    }
    return students; // 返回包含学生信息的映射表
}
// 将学生信息保存到CSV文件中
void saveStudentInfo(const std::string& filename, const std::map<std::string, Student>& students) {
    std::ofstream file(filename); // 打开CSV文件
    for (const auto& pair : students) { // 遍历映射表中的学生信息
        const Student& student = pair.second; // 获取学生对象
        file << student.student_id << "," << student.name << "," << student.major; // 写入学号、姓名和专业
        for (int score : student.scores) { // 遍历学生的分数列表
            file << "," << score; // 使用逗号分隔分数并写入文件
        }
        file << "\n"; // 写入换行符表示一行结束
    }
}

int main() {
    std::map<std::string, Student> students = readStudentInfo("students.csv"); // 读取学生信息文件，并获取学生信息的映射表

    // 按学号查询成绩
    std::string student_id;
    std::cout << "请输入学号：";
    std::cin >> student_id;
    auto it = students.find(student_id);
    if (it != students.end()) { // 判断学生信息映射表中是否包含输入的学号
        const Student& student = it->second; // 获取学生对象
        std::cout << "学号：" << student.student_id << std::endl;
        std::cout << "姓名：" << student.name << std::endl;
        std::cout << "专业：" << student.major << std::endl;
        std::cout << "实验课成绩：";
        for (int score : student.scores) { // 遍历学生的分数列表
            std::cout << score << " "; // 输出分数
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "该学生不存在。" << std::endl; // 学生信息映射表中不包含输入的学号，提示学生不存在
    }

    // 录入每次实验课的成绩
    std::cout << "请输入学号：";
    std::cin >> student_id;
    it = students.find(student_id);
    if (it != students.end()) { // 判断学生信息映射表中是否包含输入的学号
        int score;
        std::cout << "请输入实验课成绩：";
        std::cin >> score;
        it->second.scores.push_back(score); // 将分数添加到学生对象的分数列表中
        saveStudentInfo("students.csv", students); // 将更新后的学生信息保存到文件
        std::cout << "成绩已保存。" << std::endl;
    }
    else {
        std::cout << "该学生不存在。" << std::endl; // 学生信息映射表中不包含输入的学号，提示学生不存在
    }

    return 0;
}
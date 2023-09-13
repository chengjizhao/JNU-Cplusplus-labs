#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// ����ѧ���ṹ��
struct Student {
    std::string student_id;
    std::string name;
    std::string major;
    std::vector<int> scores; // �洢ѧ���ķ���
};

// ��CSV�ļ��ж�ȡѧ����Ϣ������һ������ѧ����Ϣ��ӳ���
std::map<std::string, Student> readStudentInfo(const std::string& filename) {
    std::map<std::string, Student> students; // ʹ��ӳ���洢ѧ����Ϣ
    std::ifstream ifs("test.csv");
    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << line << std::endl;
    }
    ifs.close();
    while (std::getline(ifs, line)) { // ���ж�ȡ�ļ�����
        std::stringstream ss(line); // ��ÿ������ת��Ϊ�ַ�����
        std::string student_id, name, major, score_str;
        std::getline(ss, student_id, ','); // ʹ�ö�����Ϊ�ָ�����ȡѧ��
        std::getline(ss, name, ','); // ʹ�ö�����Ϊ�ָ�����ȡ����
        std::getline(ss, major, ','); // ʹ�ö�����Ϊ�ָ�����ȡרҵ
        Student student{ student_id, name, major }; // ����ѧ������
        while (std::getline(ss, score_str, ',')) { // ʹ�ö�����Ϊ�ָ�����ȡ����
            int score = std::stoi(score_str); // ���ַ���ת��Ϊ����
            student.scores.push_back(score); // �洢������ѧ��������
        }
        students[student_id] = student; // ��ѧ������洢��ӳ�����
    }
    return students; // ���ذ���ѧ����Ϣ��ӳ���
}
// ��ѧ����Ϣ���浽CSV�ļ���
void saveStudentInfo(const std::string& filename, const std::map<std::string, Student>& students) {
    std::ofstream file(filename); // ��CSV�ļ�
    for (const auto& pair : students) { // ����ӳ����е�ѧ����Ϣ
        const Student& student = pair.second; // ��ȡѧ������
        file << student.student_id << "," << student.name << "," << student.major; // д��ѧ�š�������רҵ
        for (int score : student.scores) { // ����ѧ���ķ����б�
            file << "," << score; // ʹ�ö��ŷָ�������д���ļ�
        }
        file << "\n"; // д�뻻�з���ʾһ�н���
    }
}

int main() {
    std::map<std::string, Student> students = readStudentInfo("students.csv"); // ��ȡѧ����Ϣ�ļ�������ȡѧ����Ϣ��ӳ���

    // ��ѧ�Ų�ѯ�ɼ�
    std::string student_id;
    std::cout << "������ѧ�ţ�";
    std::cin >> student_id;
    auto it = students.find(student_id);
    if (it != students.end()) { // �ж�ѧ����Ϣӳ������Ƿ���������ѧ��
        const Student& student = it->second; // ��ȡѧ������
        std::cout << "ѧ�ţ�" << student.student_id << std::endl;
        std::cout << "������" << student.name << std::endl;
        std::cout << "רҵ��" << student.major << std::endl;
        std::cout << "ʵ��γɼ���";
        for (int score : student.scores) { // ����ѧ���ķ����б�
            std::cout << score << " "; // �������
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "��ѧ�������ڡ�" << std::endl; // ѧ����Ϣӳ����в����������ѧ�ţ���ʾѧ��������
    }

    // ¼��ÿ��ʵ��εĳɼ�
    std::cout << "������ѧ�ţ�";
    std::cin >> student_id;
    it = students.find(student_id);
    if (it != students.end()) { // �ж�ѧ����Ϣӳ������Ƿ���������ѧ��
        int score;
        std::cout << "������ʵ��γɼ���";
        std::cin >> score;
        it->second.scores.push_back(score); // ��������ӵ�ѧ������ķ����б���
        saveStudentInfo("students.csv", students); // �����º��ѧ����Ϣ���浽�ļ�
        std::cout << "�ɼ��ѱ��档" << std::endl;
    }
    else {
        std::cout << "��ѧ�������ڡ�" << std::endl; // ѧ����Ϣӳ����в����������ѧ�ţ���ʾѧ��������
    }

    return 0;
}
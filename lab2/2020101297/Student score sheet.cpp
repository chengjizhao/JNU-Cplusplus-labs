#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>


using namespace std;

//����ṹ��
struct Student {
    std::string name;
    std::string major;
    std::map<std::string, int> scores;
};



std::map<int, Student> ReadCSV(const std::string& filename) {
    string fname = "D:\\test.csv";
    //���ļ�
    ifstream csv_data(fname, ios::in);

    if (!csv_data.is_open())
    {
        cout << "���ļ�ʧ��" << endl;
        exit(1);
    }
    else {
        string line;
        std::map<int, Student> students;
        // ��ȡ������

        // ��ȡ����
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
                    students[studentID].scores["ʵ��" + to_string(i - 2)] = std::stoi(tokens[i]);
                }
            }
           


        }
        return students;
        csv_data.close();
    }
}


void WriteCSV(const std::string& filename, const std::map<int, Student>& students) {
    std::ofstream file(filename);

    // д������
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
        //д��CSV�ļ�
        WriteCSV("D:\\test.csv", students);  
    }
}



void SumScore()
{
    std::string filename = "D:\\test.csv";
    std::map<int, Student> students = ReadCSV(filename);
    int Cal = 0,studentID;
    std::cout << "����ѧ��ID��";
    std::cin >> studentID;
    if (students.find(studentID) != students.end()) {
        for (const auto& score : students[studentID].scores) {
            Cal += score.second;
        }
        cout << "��ѧ���ܳɼ�Ϊ" << Cal << endl;
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
        std::cout << "1.��ѧ�Ų�ѯ����" << std::endl;
        std::cout << "2.��ѧ����ӳɼ�" << std::endl;
        std::cout << "3.��ѧ�ż����ܳɼ�" << std::endl;
        std::cout << "4.�˳�" << std::endl;
        std::cout << "��������ѡ��";
        std::cin >> choice;

        if (choice == Scoresearch) {
            int studentID;
            std::cout << "����ѧ��ID��";
            std::cin >> studentID;

            if (students.find(studentID) != students.end()) {
                std::cout << "ѧ�������� " << students[studentID].name << std::endl;
                std::cout << "רҵ�� " << students[studentID].major << std::endl;
                for (const auto& score : students[studentID].scores) {
                    //�������ʵ��ɼ�
                    std::cout << score.first << ": " << score.second << std::endl;
                }
            }
            else {
                std::cout << "δ�ҵ�ѧ����" << std::endl;
            }
        }

        //��ѧ����ӳɼ�
        else if (choice == Scoreadd) {
            int studentID;
            std::cout << "����ѧ��ID�� ";
            std::cin >> studentID;

            std::string experiment;
            std::cout << "����ʵ�����ƣ��ԡ�ʵ��+ʵ����š���������";
            std::cin.ignore();
            std::getline(std::cin, experiment);

            int score;
            std::cout << "��������� ";
            std::cin >> score;
            //�ӵ��ṹ
            AddScore(students, studentID, experiment, score);
            //д���ļ�
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
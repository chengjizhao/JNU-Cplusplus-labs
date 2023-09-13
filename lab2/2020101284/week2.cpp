#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string studentID;
    string name;
    string major;
    vector<string> scores;
};

void displayData(const vector<Student>& data) {
    for (const auto& student : data) {
        cout << "Student ID: " << student.studentID << endl;
        cout << "Name: " << student.name << endl;
        cout << "Major: " << student.major << endl;
        cout << "Scores:" << endl;
        for (const auto& score : student.scores) {
            cout << score << " ";
        }
        cout << endl << endl;
    }
}

void searchScore(const vector<Student>& data, const string& studentID) {
    bool found = false;
    for (const auto& student : data) {
        if (student.studentID == studentID) {
            cout << "Student ID: " << student.studentID << endl;
            cout << "Name: " << student.name << endl;
            cout << "Major: " << student.major << endl;
            cout << "Scores:" << endl;
            for (const auto& score : student.scores) {
                cout << score << " ";
            }
            cout << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No score found for the given student ID." << endl;
    }
}

void updateScore(vector<Student>& data, const string& studentID) {

    bool found = false;
    for (auto& student : data) {
        if (student.studentID == studentID) {
            cout << "Student ID: " << student.studentID << endl;
            cout << "Name: " << student.name << endl;
            cout << "Major: " << student.major << endl;

            int choice;
            cout << "Do you want to enter the scores? (Enter a non-zero number for yes): ";
            cin >> choice;

            if (choice != 0) {
                student.scores.clear();
                for (int i = 0; i < 20; ++i) {
                    cout << "Enter score " << i + 1 << ": ";
                    string score;
                    cin >> score;
                    student.scores.push_back(score);
                }
            }

            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No student found with the given student ID." << endl;
    }
}

int main() {
    ifstream file("C:\\A\\test.csv");

    vector<Student> data;
    string line;
    while (getline(file, line)) {
        vector<string> row;
        size_t pos = 0;
        string token;
        while ((pos = line.find(",")) != string::npos) {
            token = line.substr(0, pos);
            row.push_back(token);
            line.erase(0, pos + 1);
        }
        row.push_back(line);

        if (row.size() >= 4) {
            Student student;
            student.studentID = row[0];
            student.name = row[1];
            student.major = row[2];
            for (int i = 3; i < row.size(); i++) {
                student.scores.push_back(row[i]);
            }
            data.push_back(student);
        }
    }

    // 输出data数组的内容
    displayData(data);

    string searchID;
    cout << "Enter the student ID to search for score: ";
    cin >> searchID;
    searchScore(data, searchID);

    string updateID;
    cout << "Enter the student ID to update score: ";
    cin >> updateID;
    updateScore(data, updateID);

    // 更新后的data数组的内容
    displayData(data);

    // 将更新后的数据保存到文件
    ofstream outputFile("C:\\A\\updated_scores.csv");
    if (outputFile.is_open()) {
        for (const auto& student : data) {
            outputFile << student.studentID << "," << student.name << "," << student.major;
            for (const auto& score : student.scores) {
                outputFile << "," << score;
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Data saved to 'C:\\A\\updated_scores.csv'." << endl;
    }
    else {
        cout << "Unable to open the file for writing." << endl;
    }

    return 0;
}
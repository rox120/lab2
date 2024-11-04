#include <iostream>
#include <map>
#include <string>

struct Student {
    int midterm;
    int final;
};

int main() {
    int studentCount;
    std::cout << "Enter the number of students: ";
    std::cin >> studentCount;

    // 학생 이름을 키로 하고 Student 구조체를 값으로 가지는 map 생성
    std::map<std::string, Student> studentMap;

    // 학생 정보 입력 및 map에 삽입
    for (int i = 0; i < studentCount; i++) {
        std::string name;
        int midterm, final;
        std::cout << "Enter name, midterm score, and final score for student " << i + 1 << ": ";
        std::cin >> name >> midterm >> final;
        studentMap[name] = {midterm, final};  // map에 이름을 키로, 성적을 값으로 저장
    }

    // 모든 학생 정보를 이름 순으로 출력
    std::cout << "\nAll students in alphabetical order:\n";
    for (const auto& entry : studentMap) {
        std::cout << "Name: " << entry.first << ", Midterm: " << entry.second.midterm
                  << ", Final: " << entry.second.final << "\n";
    }

    // 이름을 기준으로 학생 검색
    std::string searchName;
    std::cout << "\nEnter student name to search: ";
    std::cin >> searchName;

    auto it = studentMap.find(searchName);
    if (it != studentMap.end()) {
        std::cout << "Found student - Name: " << it->first
                  << ", Midterm: " << it->second.midterm
                  << ", Final: " << it->second.final << "\n";
    } else {
        std::cout << "Student not found.\n";
    }

    return 0;
}


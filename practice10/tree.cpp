#include <iostream>
#include <string>

struct Student {
    std::string name;
    int midterm;
    int final;
    Student* left;
    Student* right;
};

// 트리에 학생 정보를 삽입하는 함수
Student* insert(Student* root, const std::string& name, int midterm, int final) {
    if (root == nullptr) {
        Student* newStudent = new Student{name, midterm, final, nullptr, nullptr};
        return newStudent;
    }
    if (name < root->name) {
        root->left = insert(root->left, name, midterm, final);
    } else if (name > root->name) {
        root->right = insert(root->right, name, midterm, final);
    }
    return root;
}

// 트리에서 학생을 이름으로 검색하는 함수
Student* search(Student* root, const std::string& name) {
    if (root == nullptr || root->name == name) {
        return root;
    }
    if (name < root->name) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// 트리를 중위 순회하며 학생 정보를 출력하는 함수
void inorderPrint(Student* root) {
    if (root != nullptr) {
        inorderPrint(root->left);
        std::cout << "Name: " << root->name << ", Midterm: " << root->midterm
                  << ", Final: " << root->final << "\n";
        inorderPrint(root->right);
    }
}

// 트리의 모든 노드를 삭제하여 메모리를 해제하는 함수
void deleteTree(Student* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    int studentCount;
    std::cout << "Enter the number of students: ";
    std::cin >> studentCount;

    Student* root = nullptr;

    // 학생 정보 입력 및 트리에 삽입
    for (int i = 0; i < studentCount; i++) {
        std::string name;
        int midterm, final;
        std::cout << "Enter name, midterm score, and final score for student " << i + 1 << ": ";
        std::cin >> name >> midterm >> final;
        root = insert(root, name, midterm, final);
    }

    // 트리 중위 순회 출력
    std::cout << "\nAll students in alphabetical order:\n";
    inorderPrint(root);

    // 이름을 기준으로 학생 검색
    std::string searchName;
    std::cout << "\nEnter student name to search: ";
    std::cin >> searchName;
    Student* found = search(root, searchName);
    if (found) {
        std::cout << "Found student - Name: " << found->name
                  << ", Midterm: " << found->midterm
                  << ", Final: " << found->final << "\n";
    } else {
        std::cout << "Student not found.\n";
    }

    // 메모리 해제
    deleteTree(root);
    return 0;
}


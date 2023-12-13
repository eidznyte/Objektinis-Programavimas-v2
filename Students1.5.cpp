#include "Students.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <chrono>

// Global variables for time measurement
std::chrono::high_resolution_clock::time_point start;
std::chrono::high_resolution_clock::time_point end;

void displayDuration(const std::chrono::high_resolution_clock::time_point& start,
    const std::chrono::high_resolution_clock::time_point& end,
    const std::string& operationName) {
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << operationName << " took " << duration << " milliseconds." << std::endl;
}

double calculateAverage(const std::vector<int>& grades) {
    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return grades.empty() ? 0 : sum / grades.size();
}

double calculateMedian(std::vector<int> grades) {
    size_t size = grades.size();
    if (size == 0) return 0;

    sort(grades.begin(), grades.end());
    size_t mid = size / 2;

    return size % 2 == 0 ? (grades[mid - 1] + grades[mid]) / 2.0 : grades[mid];
}

void readFromFile(std::vector<Student>& students, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file '" << filename << "'\n";
        return;
    }

    Student student;
    while (file >> student) {
        students.push_back(student);
    }

    file.close();
}

void inputStudentsManually(std::vector<Student>& students) {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cin >> student;  // This will call the overloaded operator>> for Student
        students.push_back(student);
    }
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Name: " << student.getName()
        << ", Surname: " << student.getSurname()
        << ", Exam: " << student.getExam()
        << ", Average Score: " << student.getFinalScoreAvg()
        << ", Median Score: " << student.getFinalScoreMed();
    // You can format the output as needed and include other student details
    return out;
}

std::istream& operator>>(std::istream& in, Student& student) {
    std::string name, surname;
    int homeworkScore, examScore;
    std::vector<int> homeworks;

    in >> name >> surname;
    student.setName(name);
    student.setSurname(surname);

    // Example reading format, adjust based on your actual data format
    while (in >> homeworkScore) {
        homeworks.push_back(homeworkScore);
    }

    in.clear(); // Clear any error flags
    in >> examScore; // Read the exam score

    student.setHomeworks(homeworks);
    student.setExam(examScore);
    student.setFinalScoreAvg(calculateAverage(homeworks));
    student.setFinalScoreMed(calculateMedian(homeworks));

    return in;
}

void generateFile(const std::string& filename, int numStudents) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to create file: " << filename << std::endl;
        return;
    }

    outFile << std::setw(15) << "Vardas"
        << std::setw(15) << "Pavarde"
        << std::setw(25) << "ND scores"
        << std::setw(30) << "Egz." << std::endl;

    for (int i = 1; i <= numStudents; i++) {
        outFile << std::setw(15) << ("Vardas" + std::to_string(i))
            << std::setw(15) << ("Pavarde" + std::to_string(i));

        for (int j = 0; j < 14; j++) {
            outFile << std::setw(3) << (rand() % 10 + 1);
        }

        outFile << std::setw(10) << (rand() % 10 + 1) << std::endl;
    }

    outFile.close();
}

void writeToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file " + filename + " for writing.");
    }

    outFile << std::left
        << std::setw(15) << "Name"
        << std::setw(15) << "Surname"
        << std::setw(15) << "Final(Avg)"
        << std::setw(15) << "Final(Med)" << std::endl;
    outFile << std::string(60, '-') << std::endl;

    for (const Student& student : students) {
        outFile << std::left
            << std::setw(15) << student.getName()
            << std::setw(15) << student.getSurname()
            << std::setw(15) << std::fixed << std::setprecision(2) << student.getFinalScoreAvg()
            << std::setw(15) << std::fixed << std::setprecision(2) << student.getFinalScoreMed() << std::endl;
    }
    outFile.close();
}

void Student::displayInfo() const {
    std::cout << "Student Name: " << name << ", Surname: " << surname << std::endl;
    std::cout << "Homework Scores: ";
    for (const auto& score : homeworks) {
        std::cout << score << " ";
    }
    std::cout << "\nExam Score: " << exam << std::endl;
    std::cout << "Average Score: " << finalScoreAvg << ", Median Score: " << finalScoreMed << std::endl;
}

void generateRandomScores(Student& student) {
    const int numHomeworks = rand() % 20 + 1;
    std::vector<int> homeworks;
    for (int i = 0; i < numHomeworks; ++i) {
        homeworks.push_back(rand() % 10 + 1);
    }
    student.setHomeworks(homeworks);
    student.setExam(rand() % 10 + 1);
}

void categorizeStudents(std::vector<Student>& students, std::vector<Student>& dummies) {
    auto start = std::chrono::high_resolution_clock::now();

    for (auto it = students.begin(); it != students.end();) {
        if (it->getFinalScoreAvg() < 5.0) {
            dummies.push_back(*it);
            it = students.erase(it);
        }
        else {
            ++it;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    displayDuration(start, end, "Categorizing students with vectors");
}

void categorizeStudentsremove(std::vector<Student>& students, std::vector<Student>& dummies) {
    auto start = std::chrono::high_resolution_clock::now();

    auto newEnd = std::remove_if(students.begin(), students.end(),
        [&dummies](const Student& student) {
            bool isDummie = student.getFinalScoreAvg() < 5.0;
            if (isDummie) {
                dummies.push_back(student);
            }
            return isDummie;
        });
    students.erase(newEnd, students.end());

    auto end = std::chrono::high_resolution_clock::now();

}
#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <random> 

struct Student {
    std::string name;
    std::string surname;
    std::vector<int> homeworks;
    int exam = 0;
    double finalScoreAvg = 0;
    double finalScoreMed = 0;
};

class GradeStatistics {
public:
    static double calculateAverage(const std::vector<int>& grades);
    static double calculateMedian(std::vector<int> grades);
};

class StudentFileManager {
public:
    static void readFromFile(std::vector<Student>& students, const std::string& filename); 
    static void writeToFile(const std::vector<Student>& students, const std::string& filename);
    static void generateFile(const std::string& filename, int numStudents);
private:
    static void displayDuration(const std::chrono::high_resolution_clock::time_point& start,
        const std::chrono::high_resolution_clock::time_point& end,
        const std::string& operationName);
};

class StudentDataInput {
public:
    static void inputStudentsManually(std::vector<Student>& students);
private:
    static void generateRandomScores(Student& student);
    static void inputHomeworkScores(Student& student);
};

class StudentManager {
public:
    static void categorizeStudents(std::vector<Student>& students, std::vector<Student>& dummies);
    static void categorizeStudentsRemove(std::vector<Student>& students, std::vector<Student>& dummies);
    static void displayStudents(const std::vector<Student>& students);
private:
    static void displayDuration(const std::chrono::high_resolution_clock::time_point& start,
        const std::chrono::high_resolution_clock::time_point& end,
        const std::string& operationName);
};

#endif // STUDENTS_H

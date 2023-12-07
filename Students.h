#ifndef STUDENTS_H
#define STUDENTS_H
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <chrono>

class Student {
private:
    std::string name;
    std::string surname;
    std::vector<int> homeworks;
    int exam = 0;
    double finalScoreAvg = 0;
    double finalScoreMed = 0;

public:
    
    Student() = default;

    const std::string& getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    const std::string& getSurname() const { return surname; }
    void setSurname(const std::string& newSurname) { surname = newSurname; }

    const std::vector<int>& getHomeworks() const { return homeworks; }
    void setHomeworks(const std::vector<int>& newHomeworks) { homeworks = newHomeworks; }
    void addHomework(int score) { homeworks.push_back(score); }

    int getExam() const { return exam; }
    void setExam(int newExam) { exam = newExam; }

    double getFinalScoreAvg() const { return finalScoreAvg; }
    void setFinalScoreAvg(double newFinalScoreAvg) { finalScoreAvg = newFinalScoreAvg; }

    double getFinalScoreMed() const { return finalScoreMed; }
    void setFinalScoreMed(double newFinalScoreMed) { finalScoreMed = newFinalScoreMed; }

    
    friend void readFromFile(std::vector<Student>& students, const std::string& filename);
    friend void writeToFile(const std::vector<Student>& students, const std::string& filename);
    friend void displayStudents(const std::vector<Student>& students);
    friend void inputStudentsManually(std::vector<Student>& students);
    friend void generateRandomScores(Student& student);
    friend void categorizeStudents(std::vector<Student>& students, std::vector<Student>& dummies);
    friend void categorizeStudentsremove(std::vector<Student>& students, std::vector<Student>& dummies);
};


void displayDuration(const std::chrono::high_resolution_clock::time_point& start,
    const std::chrono::high_resolution_clock::time_point& end,
    const std::string& operationName);

double calculateAverage(const std::vector<int>& grades);
double calculateMedian(std::vector<int> grades);

void generateFile(const std::string& filename, int numStudents);

#endif // STUDENTS_H

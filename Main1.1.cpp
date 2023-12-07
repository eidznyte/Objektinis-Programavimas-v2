#include "students.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

int main() {
    std::vector<Student> studentsVector, dummiesVector, smartVector;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end, startVector, endVector;
    std::chrono::duration<double> readingDuration, vectorDuration;

    std::cout << "Would you like to: \n"
        << "1. Input data manually \n"
        << "2. Read data from a file \n"
        << "3. Generate a random student list file\n"
        << "Choose an option (1/2/3): ";
    int choice;
    std::cin >> choice;

    std::string filename;
    start = std::chrono::high_resolution_clock::now();
    switch (choice) {
    case 1:
        inputStudentsManually(studentsVector);
        break;
    case 2:
        std::cout << "Enter the filename to read from (including extension, e.g., 'data.txt'): ";
        std::cin >> filename;
        readFromFile(studentsVector, filename);
        break;
    case 3:
        std::cout << "How many records would you like to generate? \n"
            << "1. 1,000 \n"
            << "2. 10,000 \n"
            << "3. 100,000 \n"
            << "4. 1,000,000 \n"
            << "5. 10,000,000 \n"
            << "Choose an option (1/2/3/4/5): ";
        int subChoice;
        std::cin >> subChoice;
        size_t records;
        switch (subChoice) {
        case 1: records = 1'000; break;
        case 2: records = 10'000; break;
        case 3: records = 100'000; break;
        case 4: records = 1'000'000; break;
        case 5: records = 10'000'000; break;
        default:
            std::cerr << "Invalid option!" << std::endl;
            return 1;
        }
        filename = "random_students_" + std::to_string(records) + ".txt";
        generateFile(filename, records);
        readFromFile(studentsVector, filename);
        break;
    default:
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }
    end = std::chrono::high_resolution_clock::now();
    readingDuration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    startVector = std::chrono::high_resolution_clock::now();
    categorizeStudents(studentsVector, dummiesVector);
    writeToFile(dummiesVector, "dummies_vector.txt");
    writeToFile(studentsVector, "smart_vector.txt");
    endVector = std::chrono::high_resolution_clock::now();
    vectorDuration = std::chrono::duration_cast<std::chrono::seconds>(endVector - startVector);

    std::cout << "\nTime taken using std::vector: " << vectorDuration.count() << " seconds." << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\nTime taken for reading data: " << readingDuration.count() << " seconds." << std::endl;

    return 0;
}

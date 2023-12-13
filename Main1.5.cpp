#include "Students.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<Student> studentsVector, dummiesVector;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> duration;

    std::cout << "Would you like to: \n"
        << "1. Input data manually \n"
        << "2. Read data from a file \n"
        << "3. Generate a random student list file\n"
        << "Choose an option (1/2/3): ";
    int choice;
    std::cin >> choice;

    std::string filename;
    start = std::chrono::high_resolution_clock::now();
    try {
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
                throw std::invalid_argument("Invalid option!");
            }
            filename = "random_students_" + std::to_string(records) + ".txt";
            generateFile(filename, records);
            readFromFile(studentsVector, filename);
            break;
        default:
            throw std::invalid_argument("Invalid choice!");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "\nTime taken for operation: " << duration.count() << " seconds." << std::endl;

    return 0;
}

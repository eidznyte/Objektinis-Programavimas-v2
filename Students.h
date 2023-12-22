/**
*
*@file Students.h
*@brief Header failas klasei "Studentas" ir kitoms susijusioms funkcijoms
*
*/

#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
/**
*
*@class Person
*@brief Bazinė abstrakti klasė, kuri aprašo asmenį
*
*Šioje klasėje pateiktos funkcijos, kuriomis valdomas asmens vardas bei pavardė
*
*/



class Person {
protected:
    std::string name;  ///<Asmens varas
    std::string surname; ///<Asmens pavardė

public:
    Person() = default;
    Person(const std::string& name, const std::string& surname)
        : name(name), surname(surname) {}
    virtual ~Person() = default;

    const std::string& getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    const std::string& getSurname() const { return surname; }
    void setSurname(const std::string& newSurname) { surname = newSurname; }

    virtual void displayInfo() const = 0; ///<Virtuali funkcija, kuri parodo asmens informaciją
};

/**
*
*@class Student
*@brief Klasė, reprezentuojanti studentą, išvesta iš Person
*
*Šioje klasėje laikoma informacija apie studentą, namų darbų bet egzamino pažymiai,
*taip pat joje yra medianos ir vidurkio apskaičiavimo metodai
*
*/

class Student : public Person {
private:
    std::vector<int> homeworks; ///< Namų darbų pažymių vektoriai
    int exam = 0; ///< Egzamino rezultatas
    double finalScoreAvg = 0; ///< Vidurkis
    double finalScoreMed = 0; ///< Mediana

public:
    Student() = default;
    Student(const std::string& name, const std::string& surname)
        : Person(name, surname) {}
    Student(const Student& other) = default;
    Student& operator=(const Student& other) = default;
    virtual ~Student() = default;

    void displayInfo() const override;

    const std::vector<int>& getHomeworks() const { return homeworks; }
    void setHomeworks(const std::vector<int>& newHomeworks) { homeworks = newHomeworks; }
    void addHomework(int score) { homeworks.push_back(score); }

    int getExam() const { return exam; }
    void setExam(int newExam) { exam = newExam; }

    double getFinalScoreAvg() const { return finalScoreAvg; }
    void setFinalScoreAvg(double newFinalScoreAvg) { finalScoreAvg = newFinalScoreAvg; }

    double getFinalScoreMed() const { return finalScoreMed; }
    void setFinalScoreMed(double newFinalScoreMed) { finalScoreMed = newFinalScoreMed; }

    friend std::istream& operator>>(std::istream& in, Student& student);
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};
/**
*@brief Operatorius "Students" klasės objektams įvesti
*
*Šiuo operatoriumi perskaitomi studentų duomenis (vardas, pavardė, namų darbų ir egzamino rezultatai) iš input stream
*
*@param Nuoroda į input stream.
*@param Nuoroda iš studento į Student objektą, kad į jį būtų įvesti duomenys
*@return std::istream& Nuoroda į input stream perskaičius duomenis
*
*/
std::istream& operator>>(std::istream& in, Student& student);

/**
*@brief Operatorius "Students" klasės objektams išvesti
*
*Šiuo operatoriumi surašomi studentų duomenis (vardas, pavardė, namų darbų ir egzamino rezultatai) į output stream
*
*@param Nuoroda į output stream.
*@param Nuoroda iš studento į Student objektą, kad į jį būtų i6vesti duomenys
*@return std::ostream& Nuoroda į input stream perskaičius duomenis
*
*/
std::ostream& operator<<(std::ostream& out, const Student& student);

/**
 * @brief Rodo operacijos veikimo laiką.
 *
 * @param start pradeda skaičiuoti laika.
 * @param end baigia skaičiuoti laiką.
 * @param operationName operacijos pavadinimas.
 */
void displayDuration(const std::chrono::high_resolution_clock::time_point& start,
    const std::chrono::high_resolution_clock::time_point& end,
    const std::string& operationName);

/**
 * @brief Apskaičiuoja pažymių vidurki.
 *
 * @param grades pažymių vektorius.
 * @return double pažymių vidurkio vektorius.
 */
double calculateAverage(const std::vector<int>& grades);
/**
 * @brief Apskaičiuoja pažymių medianą.
 *
 * @param grades pažymių vektorius.
 * @return double pažymių vidurkio vektorius.
 */
double calculateMedian(std::vector<int> grades);

/**
 * @brief Perskaito studentų duomenis iš failo.
 *
 * @param students vektorius į kurį surašomi Student objekto duomenys.
 * @param filename failo iš kurio skaitomi duomenys pavadinimas.
 */

void readFromFile(std::vector<Student>& students, const std::string& filename);
/**
 * @brief Surašo studentų duomenis į failą.
 *
 * @param students vektorius iš kurio surašomi Students objekto duomenys į failą.
 * @param filename failo į kurį rašomi duomenys pavadinimas.
 */

void writeToFile(const std::vector<Student>& students, const std::string& filename);
/**
 * @brief parodo studentų duomenis ekrane.
 *
 * @param students vektorius kurio duomenys parodomi ekrane.
 */

void displayStudents(const std::vector<Student>& students);
/**
 * @brief Duomenys įvedami rankiniu būdu.
 *
 * @param students vektorius į kurį ranka surašomi Student objekto duomenys.
 */
void inputStudentsManually(std::vector<Student>& students);
/**
 * @brief Sugeneruoja atsitiktinius duomenis.
 *
 * @param students vektorius į kurį surašomi Student objekto sugeneruoti duomenys.
 */
void generateRandomScores(Student& student);

/**
 * @brief Sugeneruoja failą į kurį surašomi atsitiktiniai studentų duomenys.
 *
 * @param filename failo į kurį generuojami duomenys pavadinimas.
 * @param numStudents skaičius studentų, kuriems generuojami duomenys.
 */
void generateFile(const std::string& filename, int numStudents);
/**
 * @brief Suskirsto studentus į dvi grupes pagal pažymių vidurkį .
 *
 * Studentai, kurių pažymių vidurkis 5.0 yra dedami į 'dummies' vektorių.
 *
 * @param students vektorius į kurį surašomi paskirstyti duomenys.
 * @param dummies Student objekto vektorius, paskirtas į 'dummies' .
 */
void categorizeStudents(std::vector<Student>& students, std::vector<Student>& dummies);

#endif // STUDENTS_H

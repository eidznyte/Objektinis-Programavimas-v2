#include "pch.h"
#include "CppUnitTest.h"
#include "Students.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testavimas
{
	TEST_CLASS(Testavimas)
	{
    public:

        TEST_METHOD(TestStudentConstructor)
        {
            // Arrange & Act
            Student s("John", "Doe");

            // Assert
            Assert::AreEqual(std::string("John"), s.getName());
            Assert::AreEqual(std::string("Doe"), s.getSurname());
        }

        TEST_METHOD(TestSetNameGetName)
        {
            // Arrange
            Student s;
            std::string expectedName = "Alice";

            // Act
            s.setName(expectedName);

            // Assert
            Assert::AreEqual(expectedName, s.getName());
        }

        TEST_METHOD(TestSetSurnameGetSurname)
        {
            // Arrange
            Student s;
            std::string expectedSurname = "Smith";

            // Act
            s.setSurname(expectedSurname);

            // Assert
            Assert::AreEqual(expectedSurname, s.getSurname());
        }

        TEST_METHOD(TestAddHomeworkGetHomeworks)
        {
            // Arrange
            Student s;
            std::vector<int> expectedHomeworks = { 90, 85, 100 };

            // Act
            for (int score : expectedHomeworks)
            {
                s.addHomework(score);
            }

            // Assert
            std::vector<int> actualHomeworks = s.getHomeworks();
            Assert::IsTrue(expectedHomeworks == actualHomeworks);
        }
    };
}

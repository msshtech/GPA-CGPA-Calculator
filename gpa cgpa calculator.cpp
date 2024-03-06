#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Function to calculate GPA for a single course
float calculateGPA(float gradePoints, int creditHours) {
    return gradePoints / creditHours;
}

int main() {
    // Map to store grade points corresponding to grades
    map<char, float> gradePointMap = {
        {'A', 4.0},
        {'B', 3.5},
        {'C', 3.0},
        {'D', 2.5},
        {'F', 0.0}
    };

    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Validate input for the number of courses
    if (numCourses <= 0) {
        cout << "Invalid input. Number of courses must be positive." << endl;
        return 1;
    }

    float totalGradePoints = 0.0;
    int totalCreditHours = 0;

    // Input grades and credit hours for each course
    for (int i = 0; i < numCourses; ++i) {
        char grade;
        int creditHours;

        cout << "Enter grade for course {'A', 4.0},{''B, 3.5},{'C', 3.0},{'D', 2.5},{'F', 0.0} " << i + 1 << ": ";
        cin >> grade;

        // Convert grade to uppercase
        grade = toupper(grade);

        // Validate input grade
        if (gradePointMap.find(grade) == gradePointMap.end()) {
            cout << "Invalid grade entered for course " << i + 1 << endl;
            return 1;
        }

        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> creditHours;

        // Validate input credit hours
        if (creditHours <= 0) {
            cout << "Invalid input. Credit hours must be positive." << endl;
            return 1;
        }

        // Look up grade point from map
        float gradePoint = gradePointMap[grade];

        // Calculate grade points for this course
        float gradePoints = gradePoint * creditHours;

        // Accumulate total grade points and credit hours
        totalGradePoints += gradePoints;
        totalCreditHours += creditHours;
    }

    // Calculate GPA
    float GPA = totalGradePoints / totalCreditHours;

    cout << "GPA: " << GPA << endl;

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable: 4996)

struct Students {
    int mathDegrees[7];
    int bioDegrees[7];
    int engDegrees[7];
    float mathAve;
    float bioAve;
    float engAve;
    char mathGrade;
    char bioGrade;
    char engGrade;
    float allAve;
    bool isScholar;

};
struct Students student[5];

void randGrades() {
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            student[i].mathDegrees[j] = rand() % 101;
            student[i].bioDegrees[j] = rand() % 101;
            student[i].engDegrees[j] = rand() % 101;
        }

    }

}

void createGenius() {
    for (int j = 0; j < 7; j++) {
        student[4].mathDegrees[j] = rand() % 6 + 95;
        student[4].bioDegrees[j] = rand() % 6 + 95;
        student[4].engDegrees[j] = rand() % 6 + 95;
    }

}

void calculateAve() {
    int sumOfMath = 0;
    int sumOfBio = 0;
    int sumOfEng = 0;
    for (int i = 0; i < 5; i++) {
        sumOfMath = 0;
        sumOfBio = 0;
        sumOfEng = 0;
        for (int j = 0; j < 7; j++) {
            sumOfMath = sumOfMath + student[i].mathDegrees[j];
            sumOfBio = sumOfBio + student[i].bioDegrees[j];
            sumOfEng = sumOfEng + student[i].engDegrees[j];
        }
        student[i].mathAve = sumOfMath / 7.0f;
        student[i].bioAve = sumOfBio / 7.0f;
        student[i].engAve = sumOfEng / 7.0f;
    }

}
void giveGrades() {
    for (int i = 0; i < 5; i++) {
        if (student[i].mathAve > 90.1)
            student[i].mathGrade = 'A';
        else if (student[i].mathAve > 80.1)
            student[i].mathGrade = 'B';
        else if (student[i].mathAve > 70.1)
            student[i].mathGrade = 'C';
        else if (student[i].mathAve > 60.1)
            student[i].mathGrade = 'D';
        else if (student[i].mathAve > 50.1)
            student[i].mathGrade = 'E';
        else
            student[i].mathGrade = 'F';

    }
    for (int i = 0; i < 5; i++) {
        if (student[i].bioAve > 90.1)
            student[i].bioGrade = 'A';
        else if (student[i].bioAve > 80.1)
            student[i].bioGrade = 'B';
        else if (student[i].bioAve > 70.1)
            student[i].bioGrade = 'C';
        else if (student[i].bioAve > 60.1)
            student[i].bioGrade = 'D';
        else if (student[i].bioAve > 50.1)
            student[i].bioGrade = 'E';
        else
            student[i].bioGrade = 'F';

    }
    for (int i = 0; i < 5; i++) {
        if (student[i].engAve > 90.1)
            student[i].engGrade = 'A';
        else if (student[i].engAve > 80.1)
            student[i].engGrade = 'B';
        else if (student[i].engAve > 70.1)
            student[i].engGrade = 'C';
        else if (student[i].engAve > 60.1)
            student[i].engGrade = 'D';
        else if (student[i].engAve > 50.1)
            student[i].engGrade = 'E';
        else
            student[i].engGrade = 'F';

    }

}

void checkScholarshhip() {

    for (int i = 0; i < 5; i++) {
        student[i].allAve = (student[i].mathAve + student[i].bioAve + student[i].engAve) / 3.0f;
        if (student[i].allAve > 95.0f)
            student[i].isScholar = true;
    }

}
void printStudentInfo(int studentNumber) {
    printf("\nMath degrees: ");
    for (int j = 0; j < 7; j++) {
        printf("%d%% ", student[studentNumber].mathDegrees[j]);

    }
    printf("\nBio degrees: ");
    for (int j = 0; j < 7; j++) {
        printf("%d%% ", student[studentNumber].bioDegrees[j]);

    }
    printf("\nEnglish degrees: ");
    for (int j = 0; j < 7; j++) {
        printf("%d%% ", student[studentNumber].engDegrees[j]);

    }

    printf("\n\nMath Average: %f%% Math grade: %c ", student[studentNumber].mathAve, student[studentNumber].mathGrade);
    printf("\nBio Average: %f%% Bio grade: %c ", student[studentNumber].bioAve, student[studentNumber].bioGrade);
    printf("\nEng Average: %f%% Eng grade: %c ", student[studentNumber].engAve, student[studentNumber].engGrade);
    printf("\n\nAll subjects ave: %f", student[studentNumber].allAve);
    if (student[studentNumber].isScholar == true)
        printf("\nStudent is eligible for a scholarship\n\n");
    else
        printf("\nStudent isn't eligible for a scholarship\n\n");
}

int my_compare(const void* a,
    const void* b) {
    int _a = *(int*)a;
    int _b = *(int*)b;
    if (_a < _b) return -1;
    else if (_a == _b) return 0;
    else return 1;
}

void printClassStats() {
    int numberOfScholarStudents = 0;

    float sumOfClassMath = 0.0f;
    float sumOfClassBio = 0.0f;
    float sumOfClassEng = 0.0f;

    int allMathScores[35];
    int allBioScores[35];
    int allEngScores[35];

    for (int i = 0; i < 5; i++) {
        sumOfClassMath = sumOfClassMath + student[i].mathAve;
        sumOfClassBio = sumOfClassBio + student[i].bioAve;
        sumOfClassEng = sumOfClassEng + student[i].engAve;
        if (student[i].isScholar == true)
            numberOfScholarStudents++;

        for (int j = 0; j < 7; j++) {
            allMathScores[j + i * 7] = student[i].mathDegrees[j];
            allBioScores[j + i * 7] = student[i].bioDegrees[j];
            allEngScores[j + i * 7] = student[i].engDegrees[j];
        }

    }
    qsort(allMathScores, 35, sizeof(int), my_compare);
    qsort(allBioScores, 35, sizeof(int), my_compare);
    qsort(allEngScores, 35, sizeof(int), my_compare);

    printf("\n\nAve class Math score: %f%%\nAve class Bio score: %f%%\nAve class Eng score: %f%%\nNumber of students eligible"
        " for scholarship: %d\n\n", sumOfClassMath / 5, sumOfClassBio / 5, sumOfClassEng / 5, numberOfScholarStudents);

    printf("Lowest Math note are %d%% %d%% %d%%  Highest Math note are %d%% %d%% %d%% \n", allMathScores[0], allMathScores[1],
        allMathScores[2], allMathScores[32], allMathScores[33], allMathScores[34]);
    printf("Lowest Bio note are %d%% %d%% %d%%  Highest Bio note are %d%% %d%% %d%% \n", allBioScores[0], allBioScores[1],
        allBioScores[2], allBioScores[32], allBioScores[33], allBioScores[34]);
    printf("Lowest Eng note are %d%% %d%% %d%%  Highest Eng note are %d%% %d%% %d%% \n\n", allEngScores[0], allEngScores[1],
        allEngScores[2], allEngScores[32], allEngScores[33], allEngScores[34]);
}

int main() {
    randGrades();
    createGenius();
    calculateAve();
    giveGrades();
    checkScholarshhip();

    while (true) {
        int menuChoice;
        printf("1 Harper Eland\n2 Celement Hayes\n3 Belinsa Jacobs\n4 Cedric Santos"
            "\n5 Fiona Wilcher\n6 Stats\n7 QUIT\nEnter the number: ");
        scanf_s("%d", &menuChoice);
        if (menuChoice < 6)
            printStudentInfo(menuChoice - 1);
        else if (menuChoice == 6)
            printClassStats();
        else
            exit(0);

    }

    return 0;
}

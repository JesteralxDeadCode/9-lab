#include <iostream>
using namespace std;

struct  Student
{
    char FIO[50];
    int numberGroup = NULL;
    int grade[5];
};

void cinStudents(Student* st) {
    cout << "FIO: ";
    cin.getline(st->FIO, 50);
    cout << "Group number: ";
    cin >> st->numberGroup;
    cout << "Grade: ";
    for (int j = 0; j < 5; j++) {
        cin >> st->grade[j];
    }
    cin.ignore();
}


void coutStudent(Student st) {
    cout << "FIO: " << st.FIO << endl;
    cout << "Group - " << st.numberGroup << endl;
    cout << "Grade: ";
    for (int i = 0; i < 5; i++) {
        cout << st.grade[i] << " ";
    }
    cout << endl;
}


void sortUpNumberGroup(Student* st, int n) {
    for (int i = 0, buff; i < n && st[i].numberGroup != NULL; i++) {
        buff = i;
        for (int j = i + 1; j < n && st[j].numberGroup != NULL; j++) {
            if (st[buff].numberGroup > st[j].numberGroup)
                buff = j;
        }
        swap(st[buff], st[i]);
    }
}


void coutAvGrade4(Student* st, int n) {
    bool avGrade4 = false;
    for (int i = 0, buff; i < n && st[i].numberGroup != NULL; i++) {
        buff = 0;
        for (int j = 0; j < 5; j++) {
            buff += st[i].grade[j];
        }
        if ((buff / 5.0) > 4.0) {
            cout << "FIO: " << st[i].FIO << endl;
            cout << "Group - " << st[i].numberGroup << endl;
            avGrade4 = true;
        }
    }
    if (!avGrade4) {
        cout << "Студентов с среднем баллом болше 4.0 нет" << endl;
    }
}


Student* ptrMinAvGrade(Student* st, int n) {
    int minAvgrade = 0;
    double* buffAvGrade = new double[n];
    for (int i = 0; i < n && st[i].numberGroup != NULL; i++) {
        buffAvGrade[i] = 0;
        for (int j = 0; j < 5; j++) {
            buffAvGrade[i] += st[i].grade[j];
        }
        buffAvGrade[i] /= 5.0;
    }
    for (int i = 1; i < n && st[i].numberGroup != NULL; i++) {
        if (buffAvGrade[minAvgrade] > buffAvGrade[i]) {
            minAvgrade = i;
        }
    }
    return &st[minAvgrade];
}


int main()
{
    setlocale(LC_ALL, "ru");
    int n = 10;
    Student* st = new Student[n];
    for (int i = 0; i < n; i++) {
        cinStudents(&st[i]);
    }
    sortUpNumberGroup(st, n);
    coutAvGrade4(st, n);
    for (int i = 0; i < n && st[i].numberGroup != NULL; i++) {
        coutStudent(st[i]);
    }
    Student* ptrMAG = ptrMinAvGrade(st, n);
    coutStudent(*ptrMAG);
    system("pause");
}


















































/*void zad1()
{

}

int main()
{
    setlocale(LC_ALL, "ru");
    


}*/
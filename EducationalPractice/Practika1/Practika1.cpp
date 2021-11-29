#include <iostream>
#include <ctime>
#include <string>
#include <random>
#include <fstream>
#include <algorithm>
#include <windows.h>

#pragma warning(disable : 4996)

using namespace std;

    HANDLE Ride, write;
    HANDLE SemaF;
    string str0;
    string str[10];

string& replace_all(string& str, string Old, string New) {
    for (string::size_type pos(0); pos != string::npos; pos += New.length()) {
        if ((pos = str.find(Old, pos)) != string::npos) {
            str.replace(pos, Old.length(), New);
        }
        else break;
    }
    return str;
}

DWORD WINAPI Thed1proc(LPVOID I) {

    cout << "\n|| ЗАМЕНА СИМВОЛА ||\n" << endl;

    int Index = (int)I;
    string s1;

    for (Index = 0; Index < 10; Index++) {
        s1 = Index + 33;
        str[Index] = replace_all(str[Index], to_string(Index), s1);
        cout << "Строка " << Index << ": " << str[Index] << endl;
    }
    WriteFile(write,str,100,NULL,NULL);
    ReleaseSemaphore(SemaF, 1, NULL);
    return 0;
}

int main()
{
    int A[100];
    char buf;

    setlocale(LC_ALL, "1251");
    cout << "Муравьёв Арсений\nГруппа 502" << endl;
    time_t seconds = time(NULL);
    tm* ti = localtime(&seconds);
    printf("Текущее дата: %i.%i.%i\nВремя: %i:%i:%i\n", ti->tm_year + 1900, ti->tm_mon + 1, ti->tm_mday, ti->tm_hour, ti->tm_min, ti->tm_sec);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    srand(time(0));
    ofstream F1("File1.txt");
    for (int i = 0; i < 100; i++) {
        A[i] = rand() % 10;
        F1 << A[i];
    }
    F1.close();
    ifstream F2("File1.txt");

    if (F2.is_open()) {
        getline(F2, str0);
        cout << "Все символы: " << str0 << endl;
    }
    else cout << "Не удалось открыть";
    F2.close();

    /////////////////////////////////////////////////////////////////////////////////////////////////

    int n = 0, Index = 0, m = 10;

    for (int i = 1; i < 101; i++) {
        str[Index] += str0[i - 1];
        if (i % 10 == 0) {
            Index++;
        }
    }
    for (Index = 0; Index < 10; Index++) {
        cout << "Строка " << Index << ": " << str[Index] << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    SemaF = CreateSemaphore(NULL, 0, 1, NULL);
    
    CreatePipe(&Ride, &write,NULL,100);
    CreateThread(NULL, 0, Thed1proc, (LPVOID)Index, 0, NULL);
    WaitForSingleObject(SemaF, INFINITE);
    ReadFile(Ride,str,100,NULL,NULL);

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    ofstream F3("File2.csv");
    for (Index = 0; Index < 10; Index++) {
        F3 << str[Index];
        if (Index == 9) break;
        F3 << ";";
    }
}


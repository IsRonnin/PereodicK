#include <iostream>
#include <string> // можно было не добавлять - но мне так визуально проще.
#include "CMP.h" // дёрнул алгоритм кнута-морисса-пратта из 12.
#include "perFinder.h" // вынес вам его - если вдруг! у вас есть авто тесты - я-ж не варвар какой ;3

using namespace std;


int main()
{
    string txt = "abcabcabc"; // сюда строку пихать - если не лень - если есть тесты - можете в
    int res = find_pereodic(txt);
    if (res) {
        cout << res << endl;
    }
    else {
        cout << "Weired" << endl;
    }
    
    return 0;
}
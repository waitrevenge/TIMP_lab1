#include "modRoutingCipher.h"
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int a;
    int b = 0;
    string s;
    cout << "\t\t\t\t-----MENU-----"<< endl;
    cout << "\t\tПРОГРАММА ДЛЯ ШИФРОВАНИЯ МЕТОДОМ МАРШРУТНОЙ КАРТЫ" << endl;
    cout << "Введите ключ: ";
    cin >> a;
    cout << endl;
    modRoutingCipher c{a};
    cout << "1) Зашифровать сообщение" << endl;
    cout << "2) Дешифровать сообщение" << endl;
    cin >> b;
    cout << "Введите сообщение: " << endl;
    cin >> s;
    if (b == 1) {
        string s1 = c.encrypt(s);
        cout << "Зашифрованное сообщение: " << s1 << endl;
    }
    if (b == 2) {
        string s2 = c.decrypt(s);
        cout << "Дешифрованное сообщение: " << s2 << endl;
    }
    return 0;
}

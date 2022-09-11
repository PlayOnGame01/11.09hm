#include <iostream>
#include <windows.h>
using namespace std;

class MyString
{

    private:
    char* str; // указатель на строку
    int length ; // длина строки
public:
    MyString() // конструктор по умолчанию
    {
        cout << "Constructor by Cord\n";
        char* str = nullptr;
        int length = 0;
    }
    // методы класса
    MyString() //По умолчанию.
    {
        int size = 80;
        str = new char[size];

    }
    MyString(char* string, int len)
    {
        string = new char[];
        str = new char[strlen(string) + 1];
        strcpy_s(str, strlen(string) + 1, string);

        length = len;
    }
     void Print()
     {
         cout << "Enter line : " << str << endl;
     }
     void Input() {
         char buf[200];
         cout << "Enter Line : ";
         cin.getline(buf, 200);
         if (str != nullptr) {
             cout << str << " is removed! \n";
             delete[]str;
         }
         str = new char[strlen(buf) + 1];
         strcpy_s(str, strlen(buf) + 1, buf);
         cout << "Enter coll line : ";
         cin >> length;
     }
     ~MyString() // деструктор
     {
        cout << "Destructor\n";
        delete[]str;
     }
     void Setstr(char* string)
     {
         str = string;
     }
     char* Getstr()
     {
        return str;
     }
     void Setyear(int len)
     {
         length = len;
     }
     int Getyear()
     {
         return length;
     }
};



void main()
{
    setlocale(LC_ALL, "RUS");
    MyString obj1("200", "80");
    obj1.Print();
    obj1.Input();
    obj1.Print();

}
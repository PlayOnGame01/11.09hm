#include <iostream>
#include <windows.h>
using namespace std;

class MyString
{

    private:
    char* str; // указатель на строку
    int length ; // длина строки
    static int count;
public:
    MyString() // конструктор по умолчанию
    {
        cout << "Constructor by Cord\n";
        char* str = nullptr;
        int length = 0;
    }
    MyString(char* string,int len)
    {
        this->str = string;
        this->length = len;
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
     MyString& GetObj(int, int);
     ~MyString() // деструктор
     {
        cout << "Destructor\n";
        count--;
        delete[]str;
     }
     static int GetCount()  // static метод класса, для работы со static полем класса
     {
         return count;
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
int MyString::count = 0;

MyString::MyString()
{
    length = 0;
    count++;
}
MyString::MyString(const char* str, int length, int a, int b)
{
    str = a;
    length = b;
    count++;
}
void MyString::Print()
{
    cout << this->str << "\t" << this->length << endl;
}
MyString& MyString::GetObj(int a, int b,const char* str, int length)
{
    str += a;
    length += b;
    return *this;
}

void main()
{
    setlocale(LC_ALL, "RUS");
    cout << MyString::GetCount() << endl;

    MyString a(5, 10);
    a.Print();
    cout << a.GetCount() << endl;
}
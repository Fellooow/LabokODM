//#include <iostream>
//
//using namespace std;
//
//class Set
//{
//private:
//    unsigned int size;
//    unsigned int* array;
//public:
//    Set() { size = 0; array = new unsigned int[size]; } // конструктор
//
//    Set(int s) {
//        size = s; array = new unsigned int[size]; // конструктор с аргументами
//        for (unsigned i = 0; i < size; i++)
//            array[i] = 0;
//    }
//
//    Set(const Set& objectject) // конструктор копии
//    {
//        size = object.size;
//        array = new unsigned  int[size];
//        for (unsigned int i = 0; i < size; i++)
//            array[i] = object.array[i];
//    }
//
//    ~Set() { delete[] array; }  // деструктор
//    void Enter(); // ввод
//    void Show(); // вывод
//    void Union(Set, Set); // объединение
//    void intersection(Set a, Set b, bool&f);
//    //void intersection(Set, Set); // пересечение
// 
//    void operator = (Set); // перегрузки
//    int operator [] (int i);
//    void operator ->();
//};
//
//void Set::Enter()
//{
//    cout << "Введите размер " <<  endl;
//    cin >> size;
//    array = new unsigned int[size];
//    for (unsigned int i = 0; i < size; i++)
//    {
//        cout << "Введите элемент " << i + 1 << ")   ";
//        cin >> array[i];
//    }
//}
//
//void Set::Show()
//{
//    cout << "Множество " <<  endl;
//    for (unsigned int i = 0; i < size; i++)
//        cout << array[i] << " ";
//    cout <<  endl;
//}
//
//void Set::Union(Set a, Set b)
//{
//    this->size = a.size + b.size;
//    this->array = new unsigned int[size];
//    unsigned i, j, count = 0;
//    unsigned int n = a.size;
//
//
//    for (i = 0; i < a.size; i++)
//        array[i] = a.array[i];
//
//    for (i = 0; i < b.size; i++)
//    {
//        for (j = 0; j < a.size; j++)
//            if (b.array[i] == a.array[j])
//                continue;
//            else
//                count++;
//        if (count == a.size)
//            array[n++] = b.array[i];
//        count = 0;
//    }
//    size = n;
//}
//
//void Set::intersection(Set a, Set b,bool&f)
//{
//    size = a.size + b.size;
//    array = new unsigned int[size];
//    unsigned int i, j, n = 0;
//   
//   
//    for (i = 0; i < a.size; i++)
//        for (j = 0; j < b.size; j++)
//        {
//            if (a.array[i] == b.array[j])
//            {
//                array[n++] = a.array[i];
//                continue;
//                f = true;
//            }
//            else
//            { 
//               
//                f = false;
//              continue;
//            }
//        }
//    
//    size = n;
//}
//
//void Set :: operator->()
//{
//}
//
//void Set::operator = (Set a)
//{
//    unsigned int i;
//    delete[] this->array;
//
//    this->size = a.size;
//    this->array = new unsigned int[size];
//    for (i = 0; i < size; i++)
//        array[i] = a.array[i];
//
//}
//
//int Set::operator[](int i)
//{
//    return array[i];
//}
//
//int main()
//{
//    bool pFlag;
//    setlocale(0, "rus");
//    Set a;
//    cout << "Ввод и вывод 1 множества " << endl;
//    a.Enter();
//    a.Show();
//    Set b = a;
//    cout << "инициализация множества 2 с помощью конструктора копии " <<  endl;
//    b.Show();
//     cout << "Ввод множества 2 " <<  endl;
//    b.Enter();
//    Set c;
//     cout << "Объединение множеств " <<  endl;
//    c.Union(a, b);
//    c.Show();
//    Set d;
//    d.intersection(a, b,pFlag);
//    if (pFlag == true)
//    {   
//        cout << "Пересечение множеств" << endl;
//         d.Show();
//    }
//    else
//    {
//        cout << " Пересечения нет :( " << endl;
//    }
//}

#include <iostream>

using namespace std;

class Set
{
private:
    unsigned int size;
    unsigned int* array;
public:
    Set() { size = 0; array = new unsigned int[size]; } // конструктор

    Set(int s) {
        size = s; array = new unsigned int[size]; // конструктор с аргументами
        for (unsigned i = 0; i < size; i++)
            array[i] = 0;
    }

    Set(const Set& object) // конструктор копии
    {
        size = object.size;
        array = new unsigned  int[size];
        for (unsigned int i = 0; i < size; i++)
            array[i] = object.array[i];
    }

    ~Set() { delete[] array; }  // деструктор
    void Enter(); // ввод
    void Show(); // вывод
    void Union(Set, Set); // объединение
    void intersection(Set, Set); // пересечение
    void operator = (Set); // перегрузки
    int operator [] (int i);
    void operator ->();
};

void Set::Enter()
{
    cout << "Введите размер " << endl;
    cin >> size;
    array = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++)
    {
        cout << "Введите элемент " << i + 1 << ")   ";
        cin >> array[i];
 
    }
}

void Set::Show()
{
    cout << "Множество " << endl;
    for (unsigned int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Set::Union(Set a, Set b)
{
    this->size = a.size + b.size;
    this->array = new unsigned int[size];
    unsigned i, j, count = 0;
    unsigned int n = a.size;


    for (i = 0; i < a.size; i++)
        array[i] = a.array[i];

    for (i = 0; i < b.size; i++)
    {
        for (j = 0; j < a.size; j++)
            if (b.array[i] == a.array[j])
                continue;
            else
                count++;
        if (count == a.size)
            array[n++] = b.array[i];
        count = 0;
    }
    size = n;
}

void Set::intersection(Set a, Set b)
{
    size = a.size + b.size;
    array = new unsigned int[size];
    unsigned int i, j, n = 0;

    for (i = 0; i < a.size; i++)
        for (j = 0; j < b.size; j++)
        {
            if (a.array[i] == b.array[j])
            {
                array[n++] = a.array[i];
                continue;
            }
        }

    size = n;
}

void Set :: operator->()
{
}

void Set::operator = (Set a)
{
    unsigned int i;
    delete[] this->array;

    this->size = a.size;
    this->array = new unsigned int[size];
    for (i = 0; i < size; i++)
        array[i] = a.array[i];

}

int Set::operator[](int i)
{
    return array[i];
}

int main()
{
    setlocale(0, "rus");
    Set a;
    cout << "Ввод и вывод 1 множества " << endl;
    a.Enter();
    a.Show();
    Set b = a;
    cout << "Ввод и вывод 2 множества  " << endl;
    b.Enter();
    Set c;
    cout << "Объединение множеств " << endl;
    c.Union(a, b);
    c.Show();
    Set d;
    d.intersection(a, b);
    cout << "Пересечение множеств" << endl;
    d.Show();
}
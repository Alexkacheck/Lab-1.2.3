//1 Лаба 
/*#include <iostream>
#include <ctime>
using namespace std;
void dispatch_array_to_arrays_neg_zer_pos(
    int* arr, size_t arr_len,
    int*& neg, size_t& neg_len,
    int*& zer, size_t& zer_len,
    int*& pos, size_t& pos_len
)
{
    neg_len = zer_len = pos_len = 0;
    for (size_t i = 0; i < arr_len; ++i)
        if (arr[i] < 0)neg_len++;
        else
            if (!arr[i])zer_len++;
            else pos_len++;

    neg = new int[neg_len];
    zer = new int[zer_len];
    pos = new int[pos_len];

    size_t neg_ind = 0, zer_ind = 0, pos_ind = 0;
    for (size_t i = 0; i < arr_len; ++i)
        if (arr[i] < 0)neg[neg_ind++] = arr[i];
        else
            if (!arr[i])zer[zer_ind++] = arr[i];
            else pos[pos_ind++] = arr[i];
}
void print(int* a, size_t n)
{
    for (size_t i = 0; i < n; ++i)cout << a[i] << " ";
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const size_t n = 30;
    int A[n];
    //создаём массив
    for (int i = 0; i < n; i++)
        A[i] = rand() % 32 - 16;
    cout << "Наш массив:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    int* neg, * zer, * pos;//remember to delete!!!!!!!!!!!!!!!
    size_t
        neg_len(0), zer_len(0), pos_len(0),
        & rneg_len(neg_len), & rzer_len(zer_len), & rpos_len(pos_len);
    dispatch_array_to_arrays_neg_zer_pos(A, n, neg, rneg_len, zer, rzer_len, pos, rpos_len);
    cout << "negative" << endl;
    print(neg, rneg_len);
    cout << "zero" << endl;
    print(zer, rzer_len);
    cout << "positive" << endl;
    print(pos, rpos_len);
    delete[]neg;
    delete[]zer;
    delete[]pos;
    system("pause");
    return 0;
}*/

//2 Лаба
//#include "stdafx.h"

/*#include <iostream>
#include <string>
using namespace std;
class Worker
{
    string surname;
    string name;
    string post;
    int year;
    int salary;
public:
    Worker() {}
    void Set();
    void Show();
    void PostList(string p);
    void SalaryList(int s);
    void ExperienceList(int y, int current);
};
void Worker::Set()
{
    cout << "Введите фамилию: "; cin >> surname;
    cout << "Введите имя: "; cin >> name;
    cout << "Введите должность: "; cin >> post;
    cout << "Введите год поступления: "; cin >> year;
    cout << "Введите зарплату: "; cin >> salary;
}
void Worker::Show()
{
    cout << "Имя :" << surname << " " << name << endl;
    cout << "Должность:" << post << endl;
    cout << "Год :" << year << endl;
    cout << "Зарплата:" << salary << endl;
}
void Worker::PostList(string p)
{
    if (post == p) cout << surname << " " << name << endl;
}
void Worker::SalaryList(int s)
{
    if (salary > s) cout << surname << " " << name << endl;
}
void Worker::ExperienceList(int y, int current)
{
    int Year = year - current;
    if (Year > y) cout << surname << " " << name << endl;
}

int main()
{
    setlocale(0, "rus");
    int n;
    cout << "Введите кол-во сотрудников: "; cin >> n;
    Worker* worker = new Worker[n];
    for (int i = 0; i < n; i++)
        worker[i].Set();
    cout << "Список сотрудников: " << endl;
    for (int i = 0; i < n; i++)
        worker[i].Show();
    string post;
    cout << "Введите должность: "; cin >> post;
    for (int i = 0; i < n; i++)
        worker[i].PostList(post);
    int salary;
    cout << "Введите зарплату: "; cin >> salary;
    for (int i = 0; i < n; i++)
        worker[i].SalaryList(salary);
    int current, year;
    cout << "Введите текущий год: "; cin >> current;
    cout << "Введите кол-во рабочих лет: "; cin >> year;
    for (int i = 0; i < n; i++)
        worker[i].ExperienceList(year, current);
    delete[] worker;
    system("pause");
    return 0;
}
*/





//3 Лаба


/*#include <iostream>

using namespace std;


float pi = 3.14; // для изменнения рвзмеров окружноси,постоянная пи

class Circle
{
public:
    // тут конструктор
    Circle(int pRadius, float pLength)
    {
        radius = pRadius;
        length = pLength;
    }

    // здесь создаю прототипы
    bool operator==(Circle& s2);
    bool operator>(Circle& s2);

    // тут перегрузка оператора +=
    Circle& operator+=(int num) {
        this->radius += num;
        this->length = 2 * pi * this->radius;
        return *this;
    }

    // а тут перегрузка оператора -=
    Circle& operator-=(int num) {
        // проверка, чтобы нам не оказался больше радиуса
        if (num > radius)
        {
            cout << "если нам>радиуса,вычитание невозмодно" << endl;
        }
        else {
            this->radius -= num;
            this->length = 2 * pi * this->radius;
            return *this;
        }
    }

    //тут функция класса для вывода показателя длинны
    //члены класса должны быть скрыты, но тут это для демоснтрации
    void display()
    {
        cout << length << endl;
    }
protected:
    int radius;
    float length;
};

//тут оператор сравнения ==
bool Circle::operator==(Circle& s2)
{
    if (this->radius == s2.radius) // сравнениваю радиусы
    {
        return true;
    }
    else {
        return false;
    }
}

//тут оператор сравнения ">"
bool Circle::operator>(Circle& s2) // тут сравнение длин
{
    if (this->length > s2.length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Circle s1(9, 13.5);
    Circle s2(9, 13.5);
    cout << (s1 == s2) << endl; // выводит ответ: 1
    cout << (s1 > s2) << endl; // а тут: 2
    s1 += 9;
    s1.display(); // 37.68
    s2 -= 4; // Num > radius, Subtraction impossible
    s2 -= 2; // 6.28
    s2.display();

}
*/


//Лаба 4
#include <iostream> 

#include <vector> 

using namespace std;

template<typename T>

void merge(vector<T>& vec, vector<T>& v1, vector<T>& v2) {

    auto siz1 = v1.size();

    auto siz2 = v2.size();

    size_t p1 = 0;

    size_t p2 = 0;

    while (p1 < siz1 && p2 < siz2) {

        if (v1.at(p1) < v2.at(p2))

            vec.push_back(v1.at(p1++));

        else

            vec.push_back(v2.at(p2++));

    }

    while (p1 < siz1) vec.push_back(v1.at(p1++));

    while (p2 < siz2) vec.push_back(v2.at(p2++));

}



template<typename T>

void mergeSort(vector<T>& vec) {

    if (vec.size() <= 2)

        return;



    auto iter = vec.begin() + vec.size() / 2;

    vector<T> v1(vec.begin(), iter);

    vector<T> v2(iter, vec.end());



    mergeSort(v1);

    mergeSort(v2);



    vec.clear();

    merge(vec, v1, v2);

}

int main() {

    srand(time(NULL));

    int size;

    cin >> size;

    vector<int> arr;

    for (int i = 0; i < size; i++) {

        arr.push_back(rand() % 90 + 10);

    }

    for (int i = 0; i < size; i++) {

        cout << arr.at(i) << " ";

    }

    cout << endl;
      
    mergeSort(arr);
     
    for (int i = 0; i < size; i++) {

        cout << arr.at(i) << " ";

    }

    cout << endl;



    return 0;

}
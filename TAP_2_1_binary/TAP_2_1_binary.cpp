#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>
#include<ctime>
#include<string>
#include<Windows.h>


using namespace std;

bool BinarySearch(vector<int> arr, int num)
{
    int left = 0;
    int right = arr.size() - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (arr[middle]== num)
        {
            return 1;
        }
        if (arr[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}

int writeFile()
{   
    ofstream out;
    out.open("File.txt", ios::app);
    cout << "Таблица идентификаторов:";
    cout << ifstream("File.txt").rdbuf()<<endl<<endl;
    int id;
    char choice;
    while (true)
    {


        cout << "Хотите добавить идентификатор? (y/n) ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Добавьте идентификатор в таблицу: ";
            cin >> id;
            out << endl << id;
            cout << "Таблица идентификаторов:";
            cout << ifstream("File.txt").rdbuf() << id << endl;
        }
        else if (choice == 'n')
        {
            break;
        }
        else
        {
            cout << "Введите 'y' или 'n' ";
        }
    }
    out.close();
    return 0;
}

int vectorCreate(vector<int>& arr)
{
    ifstream fin("File.txt");

    int n;

    if (!fin.good()) 
    {
        cout << "Файл File.txt не найден!\n";
    }
    else {
        while (fin >> n) 
        {
            arr.push_back(n);
        }
        cout << "Данные из File.txt получены!:\n";
        for (int i = 0; i < arr.size(); i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    fin.close();
    return 0;
}


int main()
{
    setlocale(LC_ALL, "rus");
    vector<int> arr;
    writeFile();
    vectorCreate(arr);
    sort(arr.begin(), arr.end());
    cout << "Данные отсортированны!:\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<"Введите идентификатр для поиска: " <<endl;
    int search;
    cin >> search;
    if (BinarySearch(arr, search))
    {
        cout << "Идентификатор присутствует в таблице!" << endl;
    }
    else
    {
        cout<< "Идентификатор отсутствует в таблице!" << endl;
    }


}


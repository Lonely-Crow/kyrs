#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
ofstream fout("answer.txt");

void comparison(vector<int>& v1, vector<int>& v2) {

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int>::iterator it1 = v1.begin();
    vector<int>::iterator it2 = v2.begin();

    while ((it1 != v1.end()) && (it2 != v2.end())) {
        if (*it1 < *it2) {
            it1 = v1.erase(it1);
        }
        else if (*it2 < *it1) {
            ++it2;
        }
        else { // *it1 == *it2
            ++it1;
            ++it2;
        }
    }
    v1.erase(it1, v1.end());

}

void dropDup(vector<int>& v) // удаление дубликатов(защита от дураков)
{
    for (auto base = v.begin(); base != v.end(); ++base)
    {
        for (auto it = base + 1; it != v.end(); )
        {
            if (*base == *it)
            {
                it = v.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

int main()
{
    setlocale(0, "");
    srand(time(0));

    vector<int> start; // первое множество
    vector<int> answer; //все остальные поступающие множества

    while (true)
    {
        start.clear();
        answer.clear();
     int n, z;
        while (true) {
            system("cls");
            cout << "Введите кол-во множест: "; cin >> z;
            if (z >= 2) break;
            else { cout << "Ошибка. Число должно быть больше или равно 2\n"; }
            system("pause");
        }
        cout << "\n\n Выберете способ заполнения множеств: \n 1. Случайное заполнение \n" << " 2. Заполнить самому \n 3. Выход\n Введите: ";
        cin >> n;

        if (n == 1) {
            cout << endl << "Результат:";
            fout << endl << "Результат:";
            for (int i = 0; i <= rand() % 20; i++)
                start.push_back(rand() % 20); // заполнение первого множества
            dropDup(start);

            cout << endl << "Множество номер 1: ";
            fout << endl << "Множество номер 1: ";
            for (int i = 0; i < start.size(); ++i) {
                cout << start[i] << ' ';
                fout << start[i] << ' ';
            }

            for (int i = 1; i < z; i++)
            {
                answer.clear();
                for (int j = 0; j <= rand() % 20; j++)
                    answer.push_back(rand() % 20);
                dropDup(answer);

                cout << endl << "Множество номер " << i + 1 << ": ";
                fout << endl << "Множество номер " << i + 1 << ": ";
                for (int i = 0; i < answer.size(); ++i) {
                    cout << answer[i] << ' ';
                    fout << answer[i] << ' ';
                }
                comparison(start, answer);
            }

            cout << endl << "Пересечение множеств: ";
            fout << endl << "Пересечение множеств: ";
            for (int i = 0; i < start.size(); ++i) {
                cout << start[i] << ' ';
                fout << start[i] << ' ';
            }
            cout << endl;
            fout << endl;
            system("pause");
        }

        if (n == 2) {
            string s;
            cout << endl << "Результат:";
            fout << endl << "Результат:";
            cout << "\n\nЗаполните ваши множества(чтобы закончить ввод, введите *)\n";
            cout << " 1) множество: ";
            while (true) {
                cin >> s;
                if (s == "*") break;
                else start.push_back(atoi(s.c_str()));
            }
            dropDup(start);

            fout << endl << "Множество номер 1: ";
            for (int i = 0; i < start.size(); ++i) {
                fout << start[i] << ' ';
            }

            for (int i = 1; i < z; i++) {
                cout << " " << i + 1 << ") множество: ";
                while (true) {
                    cin >> s;
                    if (s == "*") break;
                    else answer.push_back(atoi(s.c_str()));
                }
                dropDup(answer);

                fout << endl << "Множество номер " << i + 1 << ": ";
                for (int i = 0; i < answer.size(); ++i) {
                    fout << answer[i] << ' ';
                }

                comparison(start, answer);
            }

            cout << endl << "Пересечение множеств: ";
            fout << endl << "Пересечение множеств: ";
            for (int i = 0; i < start.size(); ++i) {
                cout << start[i] << ' ';
                fout << start[i] << ' ';
            }
            cout << endl;
            fout << endl;
            system("pause");
        }
        if (n == 3) {
            exit(0);
        }

    }
    fout.close();
    return 0;
}

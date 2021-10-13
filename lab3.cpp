// lab3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;

void display(const vector<vector<int> >& vy);
void wypisz(vector<string> v);
void wypisz_int(vector<int> v);

bool IsOdd(int i) { return ((i % 2) == 1); }

vector<vector<int>> fill_matrix(int n, int m);

vector<string> tokenizer(const string& str, const string& sep);

void zadanie1();
void zadanie2();
void zadanie3(int n);
void zadanie4(int n_1, int p_1, int n_2, int p_2);
void zadanie5();
void zadanie6();

int main()
{
    //zadanie1();
    //zadanie5();
    //zadanie6();
    //zadanie4(2,3,3,4);
    //zadanie3(6);
    zadanie2();

    return 0;
}

//------------------------------------------------------------------------------------------------------------------------ZADANIE 1
void zadanie1() {
    //a.Utwórz pusty wektor obiektów klasy string.Wypisz wektor na ekranie.
    vector<string> v;
    wypisz(v);

    //b.Dodaj do wektora obiekty “wino”, “buraki”, “banany”, “cukier”, “czekolada”, marchew”.
    v.insert(v.end(), { "wino", "buraki", "cukier", "czekolada", "marchew" });


    //c.Usuń ostatni element z wektora i wypisz go na ekranie.
    v.erase(v.end() - 1);
    wypisz(v);

    //d.Dodaj obiekt “kawa” jako trzeci w kolejności element w wektorze.
    v.insert(v.begin() + 2, "kawa");

    //e.Napisz pętlę, która znajduje w wektorze obiekt “cukier” a następnie zastępuje go obiektem “cukierki”.

    cout << endl;

    v.push_back("cukier");
    v.push_back("czekolada");

    auto it = find(v.begin(), v.end(), "cukier");

    while (it != v.end()) {
        int index = distance(v.begin(), it);
        v[index] = "cukierki";
        it = find(it + 1, v.end(), "cukier");
    }
    wypisz(v);

    //f.Napisz pętlę, która znajduje w wektorze obiekt “czekolada” a następnie usuwa go.
    cout << endl;
    auto it2 = find(v.begin(), v.end(), "czekolada");

    while (it2 != v.end()) {
        v.erase(it2);

        it2 = find(v.begin(), v.end(), "czekolada");

    }
    wypisz(v);

    //g.Posortuj wektor za pomocą funkcji sort z pliku nagłówkowego algorithm .
    cout << endl << "Posortowane: " << endl;
    sort(v.begin(), v.end());
    wypisz(v);
};

//------------------------------------------------------------------------------------------------------------------------ZADANIE 2
void zadanie2() {
    vector<int> v1{2,3,5,8,4,3};
    vector<int> v2{ 1,1,1,1,1,1};

    for (int i = 0; i < v1.size(); i++) {

        v1[i] += v2[i];
    }
    wypisz_int(v1);
};

//------------------------------------------------------------------------------------------------------------------------ZADANIE 3
void zadanie3(int n) {

    vector<string> v1{ "0" , "1" };
    vector<string> v2;

    for (int i = 0; i < n - 1; i++) {

        v2 = v1;
        reverse(v1.begin(), v1.end());

        for (int j = 0; j < v1.size(); j++) {

            v1[j].insert(0, "1"); //dodanie 1
            v2[j].insert(0, "0"); //dodanie 0

        }

        for (int k = v2.size() - 1; k >= 0; k--) {

            v1.insert(v1.begin(), 1, v2[k]);

        }

        v2.clear();
    }

    wypisz(v1);

};

//------------------------------------------------------------------------------------------------------------------------ZADANIE 4
void zadanie4(int n_1, int p_1, int n_2, int p_2) {

    vector<vector<int>> matrix_1;
    vector<vector<int>> matrix_2;

    matrix_1 = fill_matrix(n_1, p_1);
    matrix_2 = fill_matrix(n_2, p_2);

    display(matrix_1);
    display(matrix_2);

    //mnozenie matrix_1 x matrix_2 W TEJ KOLEJNOŚCi
    
    if (p_1 == n_2) {
        vector<int> v(p_2);
        vector<vector<int> >  matrix_12(n_1, v);

        for (int n = 0; n < n_1; n++) {
            for (int p = 0; p< p_2; p++) {
                int sum = 0;
                for (int m = 0; m < n_2; m++) {
                    sum += matrix_1[n][m] * matrix_2[m][p];
                }
                matrix_12[n][p] = sum;

            }
        }
        display(matrix_12);
    }
};

//------------------------------------------------------------------------------------------------------------------------ZADANIE 5
void zadanie5() {
    int c;
    vector<int> int_v;

    cout << "Wpisuj liczby calkowite. Jesli chesz zakonczyc podaj -1." << endl;;
    do {
        cin >> c;
        if (c != -1) { int_v.push_back(c); cout << "Kolejna: " << endl; };
    } while (c != -1);

    wypisz_int(int_v);

    //a.usuń z wektora powtarzające się wartości,
    cout << "Usuwanie: " << endl;
    sort(int_v.begin(), int_v.end());

    vector< int >::iterator it_;
    it_ = unique(int_v.begin(), int_v.end());
    int_v.resize(distance(int_v.begin(), it_));
    wypisz_int(int_v);

    //b.policz i wyświetl na ekranie liczbę nieparzystych elementów wektora,
    int counter = 0;
    vector< int >::iterator it = find_if(int_v.begin(), int_v.end(), IsOdd);
    while (it != int_v.end()) {
        counter++;
        it = find_if(it + 1, int_v.end(), IsOdd);
    }
    cout << "Jest " << counter << " liczb nieparzystych." << endl;

    //c.Zmień znak każdego elementu wektora na przeciwny,
    cout << "Zmiana znaku: " << endl;
    transform(int_v.begin(), int_v.end(), int_v.begin(), [](int x)->int { return x * (-1); });
    wypisz_int(int_v);

    //d.posortuj wszystkie elementy wektora w malejącej kolejności.
    cout << "Sorowanie w kolejności malejącej: " << endl;
    sort(int_v.begin(), int_v.end()); //rosnąco
    reverse(int_v.begin(), int_v.end()); //malejąco
    wypisz_int(int_v);
};

//------------------------------------------------------------------------------------------------------------------------ZADANIE 6
void zadanie6() {
    string str, sep;
    cout << "Podaj wyrazenie: " << endl;
    getline(cin, str);
    cout << "Podaj separator: " << endl;
    cin >> sep;


    cout << "ZADANIE 6";
    vector<string> v = tokenizer(str, sep);
    wypisz(v);
};

vector<string> tokenizer(const string& str, const string& sep) {
    vector<string> v;

    string str_temp = str;
    int size = sep.size();

    size_t pozycja = str.find(sep, 0);
    if (pozycja == string::npos) {
        return v;
    }
    while (pozycja != string::npos) {
        string temp;
        temp.insert(0, str_temp, 0, pozycja);
        if (temp.size()) v.push_back(temp);
        str_temp.erase(0, pozycja + size);
        pozycja = str_temp.find(sep, 0);
    }
    if (str_temp.size() != 0) v.push_back(str_temp);
    return v;
};

vector<vector<int>> fill_matrix(int n, int m) {
    vector<vector<int>> out;
    vector<int> temp;
    for (int i = 0; i < n; i++) {


        for (int j = 0; j < m; j++) {

            int r = rand() % 10 + 1;
            temp.push_back(r);
        }

        out.push_back(temp);
        temp.clear();
    }


    return out;
}

void display(const vector<vector<int> >& vy)
{
    /*    for (int i = 0; i < vy.size(); i++)       // loops through each row of vy
        {
            for (int j = 0; j < vy[i].size(); j++) // loops through each element of each row
                cout << " " << vy[i][j];           // prints the jth element of the ith row
            cout << endl;
        } */
    for (auto i : vy)
    {
        for (auto j : i)
        {
            cout << setw(4) << j; //setw justowanie zeby bylo rownie
        }
        cout << endl;
    }
}
void wypisz(vector<string> v) {
    for (auto i : v) {
        cout << i << endl;
    }
}

void wypisz_int(vector<int> v) {
    for (auto i : v) {
        cout << i << endl;
    }
}
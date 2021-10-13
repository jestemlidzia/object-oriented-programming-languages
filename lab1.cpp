// LAB1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
uniform_real_distribution<double> distribution{ -1.0,1.0 };
uniform_real_distribution<double> rand_numb{ -10.0,10.0 };

class Point2D {

private:
    float m_x;
    float m_y;
public:
    Point2D(float x = 0, float y = 0) : m_x{ x }, m_y{ y }
    {};

    float get_x(void) const { return m_x; }
    float get_y(void) const { return m_y; }

    void set_x(float x) { m_x = x; }
    void set_y(float y) { m_y = y; }

    ~Point2D() {}
   
};

class Circle {
private:
    Point2D m_xy;
    float m_r;
public:
    Circle(const Point2D& p = Point2D(0,0), float r = 1) : m_xy{ p }, m_r{ r }
    {}
    
    bool is_inside(Point2D& p) {
        float x = p.get_x();
        float y = p.get_y();

        float temp = (m_xy.get_x() - x) * (m_xy.get_x() - x) + (m_xy.get_y() - y) * (m_xy.get_y() - y);

        if (temp < m_r*m_r)
            return true;
        else
            return false;
    }

    ~Circle() {}
};

class SmartArray {
private:
    float* m_tab = new float[100];
    int m_size;
public:
    SmartArray(int tab_size) : m_size{tab_size}
    {
        for (int i = 0; i < tab_size; i++)
        {
            m_tab[i] = rand_numb(gen);
        }

        cout << "Zostal utorzony obiekt SmartArray." << endl;
        cout << "Dlugosc tablicy wynosi: " << tab_size << endl;
    }

    SmartArray(const SmartArray& sm) {
        
        m_tab = new float[sm.m_size];
        m_size = sm.m_size;;

        for (int i = 0; i < m_size; ++i)
        {
            m_tab[i] = sm.m_tab[i];
        }

        cout << "Zostal utorzony obiekt SmartArray." << endl;
    }

    ~SmartArray() {
        cout << "Wywolanie destruktora klasy SmartArray." << endl;
    }

    float at(int idx) {
        assert(idx);
        assert(idx >= 0 && idx <= m_size);
        return m_tab[idx];
    }

    void setValue(int idx, float value) {
        m_tab[idx] = value;
    }

    float maximum() {
        float temp = m_tab[0];
        for (int i = 1; i < m_size; i++) {
            if (temp < m_tab[i]) temp = m_tab[i];
        }
        return temp;
    }

    void print() {
        cout << "Elementy tablicy: " << endl;
        for (int i = 0; i < m_size; i++) cout << m_tab[i] << " " << endl;
    }

};

int main()
{
    cout << "Hello World!\n" << endl;
   // Point2D p(0, 0);

    //LICZBA PI
    int n = 10000;
    int ni = 0;
    Circle circle = Circle();

    for (size_t i = 0; i < n; i++)
    {
        Point2D p = Point2D();
        p.set_x(distribution(gen));
        p.set_y(distribution(gen));

        if (circle.is_inside(p)) ni++;

        p.~Point2D();
        
    }
    circle.~Circle();

   float pi = 4.0 * ni / n;
   cout << "Dla n = " << n << " przyblizenie pi wynosi " << pi << endl;

   SmartArray arr = SmartArray(16);
   arr.print();
   arr.setValue(15, 10.4243);
   arr.print();
   cout << "Element pod indeksem 4" << ": " << arr.at(4) << endl;
   cout << "Maksymalna wartosc w tablic: " << arr.maximum() << endl;
   SmartArray arr2 = SmartArray(arr);
   arr2.print();


}
// lab6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector<string> res;
void reverseString(string &a, int idx);
bool prime(int n, int i);
void perm(string str, int start_idx, int end_idx, vector<string>& a);
vector<string> permutations(string s);

class Zespolona {
private:
	int x;
	int j;
public:
	Zespolona(int lx = 1, int li = 1) : x(lx), j(li) {}

	int get_x() const { return x; }
	void set_x(int value) { x = value; }
	int get_j() const { return j; }
	void set_j(int value) { j = value; }

	Zespolona& operator= (const Zespolona& a)
	{
		if (this != &a)
		{
			x = a.x;
			j = a.j;
		}
		return *this;
	}

	Zespolona& operator++ () //pre-inkrementacja
	{
		++x;
		++j;
		return *this;
	}

};

ostream& operator<<(ostream& out, const Zespolona& a)
{// operator wyjścia
	out << a.get_x() << " + " << a.get_j()  << "j"<< endl;
	return out;
}
istream& operator >>(istream& in, Zespolona& a)
{// operator wejścia
	int v, f;
	in >> v;
	a.set_x(v);
	in >> f;
	a.set_j(f);

	return in;
}
Zespolona operator + (const Zespolona& a, const Zespolona& b)
{
	return Zespolona(a.get_x() + b.get_x(), a.get_j() + b.get_j());
}
bool operator==(const Zespolona& a, const Zespolona& b)
{
	return a.get_x() == b.get_x() ? a.get_j() == b.get_j() : false;
}


int main()
{
	//-----------------------------------------ZADANIE 1
	/*
	Zespolona a(1, -2);
	Zespolona b(5, 3);
	cout << a;
	cout << b;

	cout << "podaj nowe wartości Re i Im: " << endl;
	cin >> b;

	cout << b;

	Zespolona c;<
	c = a + b;
	cout  << "C: " << c;
	++c;
	cout << "++C " << c;
	if (a == b) cout << "Rowne." << endl;
	else cout << "Nie rowne." << endl;
	*/
	//-----------------------------------------ZADANIE 2
	/*
	string str = "";
	cout << "Podaj napis: " << endl;
	getline(cin, str);
	reverseString(str, 0);
	cout << str;
	*/
	//-----------------------------------------ZADANIE 3

	//cout << prime(27, 2);

	string str = "";
	vector<string> s = permutations(str);

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
}

void reverseString(string &a, int idx) {

	int size = a.size();
	if (idx == size/2) return;

	swap(a[idx], a[size - 1 - idx]);
	reverseString(a, idx + 1);
};

bool prime(int n, int i) {

	if (n <= 2) return n == 2 ? true : false;
	if (n % i == 0) return false;
	if (i * i > n) return true;

	return prime(n, i + 1);
}


void perm(string str, int start_idx, int end_idx, vector<string>& a) {
	if (start_idx == end_idx - 1) {
		a.push_back(str);
	}
	else {
		for (int i = 0; i < end_idx - start_idx; i++) {
			swap(str[start_idx], str[start_idx + i]);
			perm(str, start_idx + 1, end_idx, a);
			swap(str[start_idx], str[start_idx + i]);
		}
	}
}

vector<string> permutations(string s) {
	vector<string> results;

	if (s.size() == 0) results.push_back("");
	else {
		perm(s, 0, s.size(), results);
		sort(results.begin(), results.end());
		auto last = unique(results.begin(), results.end());
		results.erase(last, results.end());
	}
	


	return results;
}
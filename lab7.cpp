#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Person {
private:
		string _imie;
		string _nazwisko;
		int _pesel;
public:
	Person(string imie, string nazwisko, int pesel) : _imie(imie), _nazwisko(nazwisko), _pesel(pesel){};
	string getImie() { return _imie; };
	string getNazwisko() { return _nazwisko; };
	int getPesel() { return _pesel; };
	void setImie(string imie) { _imie = imie; }
	void setNazwisko(string nazwisko) { _nazwisko = nazwisko; }
	void setPesel(int pesel) { _pesel = pesel; }

	string to_string() { 
		stringstream ss;
		ss << "Imie: "<< _imie << ", Nazwisko: " << _nazwisko << ", Pesel: " << _pesel;
		string str = ss.str();
		return str;
	}
};

class Student : public Person {
private:
	string _kierunek;
	int _indeks;
public:
	Student(string imie, string nazwisko, int pesel, string kierunek, int indeks) : Person(imie, nazwisko, pesel), _kierunek(kierunek), _indeks(indeks){}
	string getKierunek() { return _kierunek; };
	int getIndeks() { return _indeks; };
	void setKierunek(string kierunek) { _kierunek = kierunek; }
	void setIndeks(int indeks) { _indeks = indeks; }

	virtual string to_string() {
		stringstream ss;
		ss << "Imie: " << getImie() << ", Nazwisko: " << getNazwisko() << ", Pesel: " << getPesel() << ", Kierunek: " << _kierunek << ", Indeks: " << _indeks;
		string str = ss.str();
		return str;
	}
	
};

ostream& operator<<(ostream& out, Student student)
{// operator wyjścia
	out << "kierunek: " <<student.getKierunek() << ", Indeks: " << student.getIndeks() << endl;
	return out;
}
int main() {
	Person person("Kasia", "Nowak", 900828);
	Student student("Jakub", "Nowak", 950818, "EiT", 228435);

	cout << person.to_string() << endl;
	cout << student.to_string() << endl;
	cout << student << endl << endl;
	
	Person person2("Ola", "Kwiatek", 990816);
	vector<Person> vecPers{ person, person2, student };

	for (auto i : vecPers) cout << i.to_string() << endl;

	cout << endl;

	Student* student2 = new Student("Michal", "Kowalski",990716,"Informatyka",305245);
	Student* student3 = new Student("Basia", "Kot", 990716, "Informatyka", 305689);
	Person* person3 = new Person("Ola", "Kot", 968942);

	vector<Person*> vec{student2, student3, person3};

	for (auto i : vec) cout << i->to_string() << endl;

}
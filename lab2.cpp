#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string string_reverse(const string& in) {
	int size = in.size();
	string new_string = "";

	for (int i = 0; i < size; i++) {
		new_string += in[size - 1 - i];
	}
	return new_string;
}

void wyszukiwanie(std::string& tekst, string szukana_fraza, int type)
{
	size_t pozycja = tekst.find(szukana_fraza);
	size_t pozycja_x;
	if (pozycja == string::npos)
	{
		cout << "Nie ma." << endl;
		return;
	}

	do
	{
		//cout << "Fraza na pozycji: " << pozycja << endl;

		switch (type)
		{
		case 1: //smith
			tekst.erase(pozycja, 6);
			tekst.insert(pozycja, "Smith");
			pozycja = tekst.find(szukana_fraza, pozycja + szukana_fraza.size());
			break;
	
		case 2: //xx
			pozycja_x = tekst.find(" ", pozycja);
			//cout << pozycja << " , " << pozycja_x - pozycja << endl;
			tekst.erase(pozycja, pozycja_x-pozycja);
			tekst.insert(pozycja, "Siberia");
			//cout << pozycja_x << " pozycja x" << endl;

			pozycja = tekst.find(szukana_fraza, pozycja_x);
			break;
			
		case 3: //lucky
			tekst.insert(pozycja, "un");
			pozycja = tekst.find(szukana_fraza, pozycja + szukana_fraza.size());
			break;
	
		}
		
	} while (pozycja != string::npos);

}

int main()
{
	//----------------------------------Zadanie 1.
	string text;
	cout << "Podaj tekst: " << endl;
	cin >> text;

	int size = text.size();
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (text[i] >= '0' && text[i] <= '9') counter++;
	}

	cout << "Ilosc liczb: " << counter << endl;

	//----------------------------------Zadanie 2.
	fstream file("C:/Users/Lidia/Documents/cpp/plik.txt");
	string line;
	if (file.is_open())
	{
		getline(file, line);
		file.close();
	}
	cout << line << endl;
	cout << string_reverse(line)<< endl;

	//----------------------------------Zadanie 3.
	string txt = "Congratulations Mrs. <name>, youand Mr. <name> are the lucky recipients of a trip for two to XXXXXX. Your trip to XXX is already scheduled.";
	wyszukiwanie(txt, "<name>",1);
	wyszukiwanie(txt, "lucky", 3);
	wyszukiwanie(txt, "X", 2);

	txt.insert(txt.size()-1," in December");

	cout << txt << endl;

	//-----------------------------------Zadanie 4. WERSJA GORSZA
	fstream file2("C:/Users/Lidia/Documents/cpp/zad4.txt");
	string line2_;
	string line2;
	if (file2.is_open())
	{
		getline(file2, line2_);
		getline(file2, line2);
		file2.close();
	}
	cout << line2_ << endl;
	cout << line2 << endl;
	
	
	//size_t pozycja;
	string temp = line2;
	bool is_it_cyclic = false;

	if (line2.size() == line2_.size()) {
		for (int i = 0; i < line2_.size(); i++) {

			if (line2_ == temp) {
				is_it_cyclic = true;
				break;
			}

			temp.insert(0, temp, temp.size() - 1, 1);
			temp.erase(temp.size() - 1, 1);
			cout << temp << endl;
		}
	}
	else cout << "Napisy różnej długości." << endl;
 
	if(is_it_cyclic) cout << "Sa wzajemnie przesuniete cyklicznie." << endl;
	else cout << "Nie sa wzajemnie przesuniete cyklicznie." << endl;

	//-----------------------------------Zadanie 4. WERSJA LEPSZA // podwojenie stringa

	string double_string = line2;
	double_string.insert(line2.size(), line2, 0, line2.size());

	int p = double_string.find(line2_);
	if(p != string::npos) cout << "Sa wzajemnie przesuniete cyklicznie." << endl;
	else cout << "Nie sa wzajemnie przesuniete cyklicznie." << endl;

	return 0;
}

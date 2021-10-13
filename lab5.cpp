// lab5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
using namespace std;


int main()
{

	//--------------------------------------------------------------------------------------------ZADANIE 1
  /*  map<string, int> book;
   // map<string, int>::iterator iter;
	string name;

	while (true)
	{
		cout << "Podaj imie: " << endl;
		cin >> name;

		if (name == "exit") break;

		if (book.find(name) != book.end()) cout << "Numer: " << book[name] << endl;
		else {
			cout << "Podaj numer telefonu: " << endl;
			cin >> book[name];
		}

		
	}*/
	//--------------------------------------------------------------------------------------------ZADANIE 2
	
		map<string, int> lettersCounter;

		string str;

		cout << "Prosze podac napis: " << endl;
		getline(cin, str);
		string temp = "";
		for (auto x : str) {
			temp.push_back(x);
			lettersCounter[temp]++;
			temp = "";
		}

		for (pair<string, int> element : lettersCounter)
		{
			string word = element.first;
			int count = element.second;
			cout << word << "::" << count << '\n';
		}
	
		
		//--------------------------------------------------------------------------------------------ZADANIE 3
/*
map<string, vector<int>> lines;
		string word;
		int i = 1;
		while (true)
		{
			cout << "Linia: " << i << " " << endl;
			cin >> word;

			if (word == "end") break;

			lines[word].push_back(i);
			i++;
		}
		for (pair<string, vector<int>> element : lines)
		{
			string word = element.first;
			vector<int> count = element.second;
			cout << word << ' ';
			for (auto i : count)
					cout << i << " ";
			cout << endl;
		}
*/
		

		//--------------------------------------------------------------------------------------------ZADANIE 4
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

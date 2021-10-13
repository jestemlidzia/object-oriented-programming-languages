// lab3_zadanie3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double transfer(double f, double s, double value) {
	
	double result = (value*s) / f;
	return result;
}

int main()
{
    std::cout << "Hello World!\n";

	fstream file("C:/Users/Lidia/Documents/cpp/waluty.txt");
	double USD;
	double PLN;
	double EUR;
	if (file.is_open())
	{
		file >> USD >> PLN >> EUR;
		file.close();
	}
	int option;
	double value;

	cout << "Wybierz: 1 - USD => PLN, 2 - USD => EUR, 3 - PLN => USD, 4 - PLN => EUR, 5 - EUR => USD, 6 - EUR => PLN." << endl;
	cin >> option;

	cout << "Podaj kwote: " << endl;
	cin >> value;

	double result;
	switch (option)
	{
	case 1:
		result = transfer(USD, PLN, value);
		break;
	case 2:
		result = transfer(USD, EUR, value);
		break;
	case 3:
		result = transfer(PLN, USD, value);
		break;
	case 4:
		result = transfer(PLN, EUR, value);
		break;
	case 5:
		result = transfer(EUR, USD, value);
		break;
	case 6:
		result = transfer(EUR, PLN, value);
		break;
	}
	cout << "Po przeliczeniu to: " << result << endl;
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

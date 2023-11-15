// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;


int main()
{
	setlocale(0, "");

	string input;
	string output;

	cout << "Введите строку для архивации: ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		char sym = input[i];
		int repeat = 0;

		if (isdigit(sym))
			continue;

		int j = i;
		while (true)
		{

			if (j >= input.length() - 1)
				break;

			if (sym == input[j])
			{
				repeat++;
			}
			else
			{
				break;
			}
			j++;
		}

		if (repeat > 1)
		{
			output = output + sym + to_string(repeat);
			i += repeat - 1;
		}
		else
		{
			output = output + sym;
		}
	}
	cout << output << endl;

	input = "";
	output = "";
	string tempNum = "";
	int tempSymPos = -1;

	cout << "Введите строку для разархивации: ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		char sym = input[i];

		if (isdigit(sym))
		{
			if (tempSymPos == -1)
				tempSymPos = i - 1;
			tempNum += sym;
		}
		else
		{
			output += sym;
			continue;
		}

		if (tempSymPos != -1)
		{
			int num = stoi(tempNum);
			for (int j = 1; j < num; j++)
				output = output + input[tempSymPos];

			tempSymPos = -1;
			tempNum = "";
		}
		else
		{
			output += sym;
		}

	}

	cout << output << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

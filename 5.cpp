// ConsoleApplication5.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <string>

using namespace std;


int main()
{
	setlocale(0, "");

	string input;
	string output;

	cout << "������� ������ ��� ���������: ";
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

	cout << "������� ������ ��� ������������: ";
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

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.

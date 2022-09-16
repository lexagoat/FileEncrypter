#include <string>
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string mode;
	int choice;
	while (true)
	{
		cout << "Welcome to the encryption/decryption program\n";
		cout << "Please type in the integer corresponding to what you would like to do.\n";
		cout << "[1] - Create an encrypted copy of a file\n";
		cout << "[2] - Decrypt an encrypted file \n";
		cout << "[3] - Quit\n";
		cin >> mode;
		choice = mode[0] - '0';
		if (mode.size() == 0 || mode.size() > 1 || !isdigit(mode[0]) || choice < 1 || choice>3)
		{
			cout << "Invalid input!\n";
		}
		if (choice == 3)
		{
			cout << "Quitting...";
			exit(0);
		}
		else if (choice == 1)
		{
			cout << "Please type in the file path of the file you would like to encrypt.\n";
			cout << "Example: 'D:\GameLoop\Yeni Metin Belgesi (2).txt \n";
			string fileName;
			cin.ignore();
			getline(cin, fileName);
			fstream input;
			ofstream output;
			input.open(fileName);
			if (!input)
			{
				cout << "File not found...\n";
				continue;
			}
			output.open("output.txt");
			if (!output)
			{
				cout << "Error in creating output file...\n";
				continue;
			}
			char curr;
			while (input.eof() == 0)
			{
				input >> curr;
				curr = curr + 100;
				output << curr;
			}
			input.close();
			output.close();
			cout << "Encrypted using caesar cipher in output file labeled output.txt\n";
		}
		else if (choice == 2)
		{
			cout << "Please type the file you would like to decrypt.\n";
			cout << "Example: 'D:\GameLoop\Yeni Metin Belgesi (2).txt \n";
			string fileName;
			cin.ignore();
			getline(cin, fileName);
			fstream input;
			ofstream output;
			input.open(fileName);
			if (!input);
			{
				cout << "File not found...\n";
				continue;
			}
			output.open("Decrypted.txt");
			if (!output)
			{
				cout << "Output file creation error...\n";
				continue;
			}
			char curr;
			while (input.eof() == 0)
			{

				input >> curr;
				curr = curr - 100; 
				output << curr;
			}
			input.close();
			output.close();
			cout << "Decrypted caesar cipher file in file named 'Decrypted.txt' \n";
		}
	}
	return 0;
}
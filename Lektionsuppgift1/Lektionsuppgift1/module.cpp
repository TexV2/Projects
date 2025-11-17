#include "header.h"

using namespace std;
void icecreamadder(int icenumber)
{
	fstream file("icecream.txt", ios::out);
	cout << "What ice cream would you like to add to the list?" << std::endl;
	cin.ignore();
	for (int i = 0; i < icenumber; i++)
	{
		string icecream;
		cin >> icecream;
		file << icecream << "\n";
	}
	file.close();
	return;
}

void icecreamranker(int icenumber)
{
	int i = 0;
	bool done = false;
	float* icecreamranking = new float[icenumber]();
	fstream file1("icecream.txt", ios::in);
	if (!file1.is_open()) { cerr << "Could not open icecream.txt\n"; return; }
	string line;
	int ranking;
	int gradingsnumber = 0;
	i = 0;
	cout << "Rank the ice creams 1-5!" << std::endl;
	while (getline(file1, line))
		{
			cout << line << endl;
			cin >> ranking;
			if (ranking > 0 && ranking < 6)
			{
				icecreamranking[i] += ranking;
				i++;
			}
			else
			{
			}
		}
	gradingsnumber = 1;
	file1.clear();
	file1.seekg(0, ios::beg);
		while (!done)
		{
		char choice;
		std::cout << "Add more rankings? (Y/N)" << std::endl;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			i = 0;
			file1.clear();            // clear EOF flag
			file1.seekg(0, ios::beg);
			cout << "Rank the ice creams 1-5!" << std::endl;
			while (getline(file1, line))
			{
				cout << line << endl;
				cin >> ranking;
				if (ranking > 0 && ranking < 6)
				{
					icecreamranking[i] += ranking;
					i++;
				}
			}
			gradingsnumber++;
		}
		else
		{
			done = true;
		}
	}
	fstream file2("rating.txt", ios::app);
	if (!file2.is_open()) { cerr << "Could not open rating.txt\n"; return; }
	for (int index = 0; index <i; index++)
	{
		icecreamranking[index] = icecreamranking[index] / gradingsnumber;
		file2 << icecreamranking[index] << "\n";
	}
	file2.close();
}

void printresult(int icenumber, int gradingsnumber)
{
	fstream file1("icecream.txt", ios::in);
	if (!file1.is_open()) { cerr << "Could not open icecream.txt\n"; return; }
	string line1;
	fstream file2("rating.txt", ios::in);
	if (!file2.is_open()) { cerr << "Could not open icecream.txt\n"; return; }
	string line2;
	int lineNumber;
	cout << "The average rating for each icecream is:" << endl;
	while (getline(file1, line1) && getline(file2, line2)) {
		cout << line1 << " : " << line2 << endl;
	}
	file1.clear();   
	file1.seekg(0, ios::beg);
	file2.clear();
	file2.seekg(0, ios::beg);

	cout << "The highest rated icecream is:" << endl;

	string* names = new string[icenumber];
	float* ratings = new float[icenumber];
	for (int i = 0; i < icenumber; i++)
		getline(file1, names[i]);
	for (int i = 0; i < icenumber; i++)
		file2 >> ratings[i];
	int bestindex = 0;
	int worstindex = 0;
	for (int i = 1; i < icenumber; i++)
	{
		if (ratings[i] > ratings[bestindex])
		{
			bestindex = i;
		}
		if (ratings[i] < ratings[worstindex])
		{
			worstindex = i;
		}
	}
	cout << names[bestindex] << endl;
	cout << "and the worst:" << endl << names[worstindex];
	ofstream fileice("icecream.txt", std::ios::out);
	ofstream filerat("rating.txt", std::ios::out);
	fileice.close();
	filerat.close();
}
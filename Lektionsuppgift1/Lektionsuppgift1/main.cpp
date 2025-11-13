#include <iostream>
#include <string>
#include <algorithm>

void icecreamadder(std::string icecream[], int icenumber)
{
	std::cout << "What ice cream would you like to add to the list?" << std::endl;
	std::cin.ignore();
	for (int i = 0; i < icenumber; i++)
	{
		std::getline(std::cin, icecream[i]);
	}
	return;
}

void icecreamranker(std::string icecream[], float icecreamranking[], int icenumber)
{
	float ranking = 0;
	std::cout << "Rank the ice creams 1-5!" << std::endl;
	for (int i = 0; i < icenumber; i++)
	{
		ranking = 0;
		std::cout << icecream[i] << std::endl;
		std::cin >> ranking;
		if (ranking > 0 && ranking <= 5)
		{
			icecreamranking[i] += ranking;
		}
	}
	return;
}

void printresult(std::string icecream[], float icecreamranking[], int icenumber, int gradingsnumber)
{
	std::string favorite;
	float* maxPtr = std::max_element(icecreamranking, icecreamranking + icenumber);
	int maxIndex = maxPtr - icecreamranking;
	float* minPtr = std::min_element(icecreamranking, icecreamranking + icenumber);
	int minIndex = minPtr - icecreamranking;
	std::cout << "The number of gradings " << gradingsnumber << std::endl;
	std::cout << "The average score for each icecream is: " << std::endl;
	for (int i = 0; i < icenumber; i++)
	{
		std::cout << icecream[i] << " " << icecreamranking[i] / gradingsnumber << std::endl;
	}
	std::cout << "The icecream with the highest grading is: " << icecream[maxIndex] << std::endl;
	std::cout << "The icecream with the lowest grading is: " << icecream[minIndex] << std::endl;
	std::cout << "Input the name of your favorite icecream!" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, favorite);
	bool favoriteexists = false;
	for (int i = 0; i < icenumber; i++)
		if (icecream[i] == favorite)
		{
			std::cout << icecream[i] << " has been graded";
			favoriteexists = true;
			break;
		}
	if (favoriteexists == false)
	{
		std::cout << favorite << " has not been graded";
	}
}

int main()
{
	int gradingsnumber = 0;
	bool done = false;
	std::string icecreamarray[10];
	float icecreamranking[10] = { 0 };
	std::cout << "Between 1-10 how many ice creams do you want to list?" << std::endl;
	int icenumber;
	std::cin >> icenumber;
	if (icenumber > 0 && icenumber <= 10)
	{
		icecreamadder(icecreamarray, icenumber);
	}
	else
	{
		std::cout << "Invalid input!";
		std::cin;
		return 0;
	}
	icecreamranker(icecreamarray, icecreamranking, icenumber);
	gradingsnumber += 1;
	while (done == false)
	{
		char choice;
		std::cout << "Add more rankings? (Y/N)" << std::endl;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			icecreamranker(icecreamarray, icecreamranking, icenumber);
			gradingsnumber += 1;
		}
		else
		{
			done = true;
		}
	}
	printresult(icecreamarray, icecreamranking, icenumber, gradingsnumber);
}

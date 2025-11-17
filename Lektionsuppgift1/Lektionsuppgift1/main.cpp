#include <iostream>
#include <string>
#include <algorithm>
#include "header.h"

using namespace std;

int main()
{
	std::cout << "How many ice creams do you want to list?" << std::endl;
	int icenumber;
	std::cin >> icenumber;
	int gradingsnumber = 0;
	ofstream file;
	icecreamadder(icenumber);
	icecreamranker(icenumber);
	printresult(icenumber, gradingsnumber);
}

//#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

void displayMenu()
{
	std::cout << "MENU:\n"
		"1. Read string\n"
		"2. List\n"
		"3. Quit\n"
		<< std::endl;
}

int main()
{
	int choice = 0;

	displayMenu();

	std::map<std::string, int> bst;

	while(std::cin >> choice)
	{

		switch(choice)
		{
			case 1:
			{
				std::string input;
				std::cin.ignore();
				getline(std::cin, input);
				bst.insert(std::pair<std::string, int>(input, 1));
				std::cout << "Inserted " << input << std::endl;
				break;
			}

			case 2:
			{
				int count = 1;
				if(bst.size() == 0)
					std::cout << "Empty BST!" << std::endl;
				for(auto item = bst.begin(); item != bst.end(); item++)
				{
					std::cout << "BST items in ascending order:\n" << count++ << ".) " << item->first << std::endl;
				}
				break;
			}

			case 3:
			{
				exit(0);
			}
			break;
			default:
			{
				std::cout << "Wrong input! \n\n\n"
					<< std::endl;
			}
		}

		displayMenu();
	}
	return 0;
}

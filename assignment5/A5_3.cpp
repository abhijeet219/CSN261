//#include "stdafx.h"
#include <iostream>
#include <map>

int main()
{
	std::map<int, int> bst;

	bst.insert(std::pair<int, int>(2, 1));
	bst.insert(std::pair<int, int>(3, 1));
	bst.insert(std::pair<int, int>(5, 1));
	bst.insert(std::pair<int, int>(8, 1));
	bst.insert(std::pair<int, int>(1, 1));

	int k = 4, count = 1;
	for(auto item = bst.begin(); item != bst.end(); item++, count++)
	{
		if(k > bst.size())
		{
			std::cout << "Index overflow" << std::endl;
			break;
		}

		if(count == k)
		{
			std::cout << k;
			switch(k % 10)
			{
				case 1:
					std::cout << "st ";
					break;
				case 2:
					std::cout << "nd ";
					break;
				case 3:
					std::cout << "rd ";
					break;
				default:
					std::cout << "th ";
			}

			std::cout << "smallest element: " << item->first << std::endl;
			break;
		}
	}
	std::cin.get();
}
//============================================================================
// Name        : data_collector.cpp
// Author      : Aladdin Gharbi
// Version     :
// Copyright   : Your copyright notice
// Description : data collector prototype
//============================================================================

#include <stdbool.h>
#include <stdio.h>
#include "helper.h"
#include <iostream>

int main(int argv , char *argc[]) {
//loop until the lz4 file is found

	while (true)
	{
		if (1 == search_file(argc[1]))
		{
			// file found, breakup the loop
			break;
		}
		else 
		{
			std::cout << "not found" << std::endl ;  
		}
	}

	// retrieve data-to-be-compressed from a file specified in the arg list
	std::vector<std::string> data_vector; 
	data_vector = collect_data(argc[2]);
	

	// compress it into a .tar file
	compress_data(data_vector,argc[3]);


}
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
/*/
Assumptions :
	arg1 lz4 directory
	arg2 format file name
	arg3 source directory
	arg4 destination directory

*/

int main(int argv , char *argc[]) {

/*
	printf("number of argumets is %i \n", argv-1 );
	for (int i = 0 ; i < argv ; i++)
	{
		printf("argument %i is %s \n", i, argc[i]);
	}
*/

//loop until the lz4 file is found

	while (true)
	{
		if (1 == search_file(argc[1], argc[2]))
		{
			// file found, breakup the loop
			break;
		}
		else 
		{
			std::cout << "not found" << std::endl ; 
			break; 
		}
	}

	// get all the data in the source directory and compress it to source
	collect_and_compress_data(argc[3],argc[4]);


}
/*
 * helper.h
 *
 *  Created on: Sep 22, 2023
 *      Author: aladdin
 */

#ifndef HELPER_H_
#define HELPER_H_


    
int search_file (char* lz4_directory, char* file_format);
void collect_data (char* source_directory);
void compress_data (char* target_directory);

#endif /* HELPER_H_ */
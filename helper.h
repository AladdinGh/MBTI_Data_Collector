#ifndef HELPER_H_
#define HELPER_H_

#include <vector>
#include <string>
#include <ctime>
#include <iomanip>


int search_file (char* lz4_directory);
std::vector<std::string> collect_data (char * data_to_compress_file); 
void compress_data (std::vector<std::string> data_vector, char* target_directory);
std::string get_uniqueId(); 

#endif /* HELPER_H_ */
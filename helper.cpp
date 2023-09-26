#include "helper.h"
#include <iostream>
#include <experimental/filesystem>
#include <regex>
#include <fstream>


namespace fs = std::experimental::filesystem; 

/* search_file
 * 
 * @param lz4_directory - Path to search recursively 
 *
 * @returns 1, if found, 0 if not.
 */
int search_file (char* lz4_directory)
{
    // traverse the directory
    std::string path; // to replace with lz4_directory
    path = "/home/aladdin/Desktop/BMTI_aufgabe"; //lz4_directory 

    // Define a regular expression pattern to match the desired file format
    std::regex file_pattern("core\\.[A-Za-z]+\\.[0-9A-Fa-f]+(\\.[0-9A-Fa-f]+)*\\.lz4");
    //std::regex file_pattern("core\\.[A-Za-z]+\\.[0-9A-Fa-f]+\\.lz4");
    /*
    * core\\. matches "core." at the beginning of the filename.
    * [A-Za-z0-9]+ matches one or more alphanumeric characters (variable name of a service).
    * \\. matches a dot.
    * [0-9A-Fa-f]+ matches one or more hexadecimal characters (the first hexadecimal id).
    * (\\.[0-9A-Fa-f]+)* matches zero or more additional hexadecimal id separated by dots.
    * \\.lz4 matches ".lz4" at the end of the filename.
    */

    // auto &p is loop variable
    for (auto & p: fs::recursive_directory_iterator(path))
    {
        if (std::regex_match(p.path().filename().string(),file_pattern))
        {
            std::clog << "File " << p.path().filename() << "found" << std::endl << std::endl;
            return(1); 
        }
    }
    return(0); 

}

/* collect_data
 * 
 * @param data_to_compress_path - Path file of data to compress
 *
 * @returns vector of all files and dirs to be compressed 
 */
std::vector<std::string> collect_data (char * data_to_compress_path)
{   
    // to be replaced with cmd arg
    std::string data_to_compress_path__ = "/home/aladdin/Desktop/BMTI_aufgabe/data_to_compress.txt" ; 
    std::vector<std::string> data_vector; 

    std::ifstream inputFile;
    inputFile.open(data_to_compress_path__.c_str()); 

    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        // no files found, vector will be empty and returned empty 
    }
    else 
    {
        std::clog << "triggering data collection ..." << std::endl ; 
    }

    // iterate over the lines and save them in the data_vector 
    std::string line;
    while (std::getline(inputFile, line)) 
    {
        data_vector.push_back(line);  
    }

    inputFile.close();
    std::clog << "data collected" << std::endl ;

    return data_vector;
}

/* compress_data
 * 
 * @param target_directory - Path of tar file
 *
 * @returns nothing
 */
void compress_data (std::vector<std::string> data_vector, char * target_directory)
{
    std::string target = "/home/aladdin/Desktop/BMTI_aufgabe/special_folder/";

    std::string command; // command to be executed with system call
    std::vector<std::string>::iterator it; 
    int return_code; // retuen code of the system call
    
    // constructing the commando string
    command.append("tar -cf "); // -cf create file
    command.append(target); // tar -cf target_path/
    std::string tar_name = get_uniqueId(); 
    command.append(tar_name); // tar -cf target_path/tar_name
    command.append(" "); // tar -cf target_path/tar_name

    for (it = data_vector.begin(); it != data_vector.end(); it++ )
    {
        command.append(*it);
        command.append(" ");
    }
    // tar -cf target_path/tar_name file1 file 2 ...

    std::clog << command << std::endl;
    std::clog << "compressing data ..." << std::endl; 


    return_code = std::system(command.c_str());
    if (0 == return_code)
    {
        std::clog << "data compressed, file " << tar_name << " is created in the " << target << " directory" << std::endl; 
    }
    else 
    {
        std::clog << "please verify the list of documents to be compressed" << std::endl ; 
        std::clog << ".tar file is created but with missing files" << std::endl ; 
    }
}

std::string get_uniqueId()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&currentTime);
    std::ostringstream oss;
    oss << std::put_time(timeInfo, "%Y%m%d%H%M%S");

    // Create the unique filename
    std::string uniqueFilename = "data_to_collect_" + oss.str() + ".tar"; 

    return(uniqueFilename); 
}






#include "helper.h"
#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <regex>


namespace fs = std::experimental::filesystem; 

/* search_file
 * 
 * @param lz4_directory - Path to search recursively in ("/home", "/etc", ...)
 * @param file_format  - Term to search for ("file.txt", "movie.mkv", ...)
 *
 * @returns fs path to the file, if found.
 */
int search_file (char* lz4_directory, char* file_format)
{
    // traverse the directory
    std::string path;
    int result; 
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
        //std::string filename = entry.path().filename().string();
        if (std::regex_match(p.path().filename().string(),file_pattern))
        //if (p.path().filename() == fs::path(term)) // fs::is_regular_file(p) &&
        {
            std::cout << "file " << p.path().filename() << "found" << std::endl ; 
            return(1); 
        }
    }
    return(0); 

}



void collect_data (char* source_directory)
{
    path = "/home/aladdin/Desktop/BMTI_aufgabe/data_to_collect"; //source_directory 
    std::system("ls -l >test.txt");
}
void compress_data (char* target_directory){}





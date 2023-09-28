# Data collector

***Prerequisites :***
  * Lunix
  * gtest libraray  (https://github.com/google/googletest/tree/main)
  * CMake 3.5.1

***Summary :*** 
  * Data_collector is a CLI tool service that collects system information upon reception of a trigger event (the presence of a .LZ4 file in a configurable directory (first argument of command line arguments)).
  * Once the trigger is received, a file (specified by the second argument from the command line arguments) ,which contains directory/files paths, is read. The specified data is collected and compressed into a .tar file.
  * The .tar file has a unique name. It is stored in the directory specified by the third argement from the command line arguments
    
***Assumptions :***<br>
	* arg1 = lz4 directory<br>
	* arg2 = data to compress file<br>
	* arg3 = target directory<br>

***How to use :***
   * Example :
     * >./main "/home/user/Desktop/MBTI_data_collector" "/home/user/Desktop/MBTI_data_collector/data_to_compress.txt" "/home/user/Desktop/MBTI_data_collector/where_to_store_tar_file/"
     
     * "/home/user/Desktop/MBTI_data_collector" : is the directory where the LZ4 file (trigger) is searched.
     * "/home/user/Desktop/MBTI_data_collector/data_to_compress.txt" : a file which contains all the files or directories to be compressed.
     * "/home/user/Desktop/MBTI_data_collector/where_to_store_tar_file/" : storage location of the .tar file


***Tests :***<br>
     * Googletest is used to test this application. In order to execute the tests, run runtests found under /tests.<br>
     * There are 4 tests : 2 to test the presence of LZ4 file trigger (the case where the user gives a right and wrong paths) and 2 to test the correctness of the data_to_compress.txt file

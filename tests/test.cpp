#include "../helper.h"
#include <gtest/gtest.h>


TEST(Search_file_Test, search_existing_file) { 

    /* test what happens if user gives right paths */
    char * st1 = "/home/aladdin/Desktop/BMTI_aufgabe";
    ASSERT_EQ(1, search_file(st1));

}

TEST(Search_file_non_existent_Test, search_existing_file) { 

    /* test what happens if user gives wrong paths */
    char * st1 = "/home/aladdin/Desktop/BMTI_aufgaben";
    ASSERT_EQ(0, search_file(st1));

}


TEST(CollectData_full_vector_Test, data_file) { 
    /* test what happens if the data file is present */
    std::vector<std::string> result_vector_test;
    result_vector_test.push_back("core.ServiceName.3057.57dd721409bc4ab4b38a3c33a36a608a.3717.1647975805000000.lz4");
    result_vector_test.push_back("core.ServiceName.3057.lz4");
    result_vector_test.push_back("data_to_collect");
    result_vector_test.push_back("helper.cpp");
    result_vector_test.push_back("helper.h");
    result_vector_test.push_back("main.cpp");
    
    char * st0 = "/home/aladdin/Desktop/BMTI_aufgabe/data_to_compress.txt";
    ASSERT_EQ(result_vector_test, collect_data(st0));

}

TEST(CollectData_Test, data_file) { 
    /* test what happens if the data file is not present */
    std::vector<std::string> result_vector_test_empty;
    char * st1 = "/home/aladdin/Desktop/BMTI_aufgabe/data_to_compress.txht";
    ASSERT_EQ(result_vector_test_empty,collect_data(st1));

}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

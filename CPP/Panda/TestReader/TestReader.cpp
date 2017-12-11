#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

void test_reader(std::string file, std::string student_id) {
	std::ifstream x;
	x.open(file.c_str());
	while(!x.eof())
    { 
            std::string file_student_id;
			std::string grade;
            x >> file_student_id;
            x >> grade;
			if(!student_id.compare(file_student_id)) {
				std::cout << "STUDENT ID" << student_id << std::endl;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				std::cout << "The id is: " << student_id << std::endl;
				std::cout << file << " Grade is:  " << grade << std::endl;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			}
			
            if(x.eof())
              break;
			
	}
    x.close();
	x.clear();
}

int main() {
	
	test_reader("cis201.txt", "00005");
	test_reader("eng108.txt", "00005");
	
	return 0;
}
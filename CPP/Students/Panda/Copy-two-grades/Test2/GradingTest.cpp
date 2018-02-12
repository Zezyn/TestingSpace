#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Comments needed

class Student
{
    public:
      Student();
      void print();
      std::string test_reader(std::string file, std::string student_id);
      std::string list_ids();
      void collect_classes();
      std::string collect_grades(std::string id);
      void selected_id(std::string id_lookup);
    private:
      std::string student_id;
      std::string class1, class2, class3, class4, class5;
      std::string grade1, grade2, grade3, grade4, grade5;  
    
};

Student::Student()
{
  
}

void Student::print()
{
    std::cout << "Student ID: " << student_id << std::endl;
    std::cout << "-=-=-=-=-=-" << std::endl;
    std::cout << "Class: " << class1 << "   Grade: " << grade1 << std::endl;
    std::cout << "Class: " << class2 << " Grade: " << grade2 << std::endl;
    std::cout << "Class: " << class3 << " Grade: " << grade3 << std::endl;
    std::cout << "Class: " << class4 << " Grade: " << grade4 << std::endl;
    std::cout << "Class: " << class5 << " Grade: " << grade5 << std::endl;
    std::cout << "-=-=-=-=-=-" << std::endl;  
}

std::string Student::test_reader(std::string file, std::string student_id) 
{
    std::ifstream x;
    x.open(file.c_str());
    while(!x.eof())
    { 
            std::string file_student_id;
            std::string grade;
            x >> file_student_id;
            x >> grade;
            if(!student_id.compare(file_student_id)) {
                std::cout << "STUDENT ID " << student_id << std::endl;
                std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
                std::cout << "The id is: " << student_id << std::endl;
                std::cout << "CSC1 Grade is:  " << grade << std::endl;
                std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
            }
            
            if(x.eof())
              break;
            
    }
    x.close();
    x.clear();
}

std::string Student::list_ids()
{
    std::ifstream input;
    input.open("StudentIDs.txt");
    if(!input.fail())
    {
        while(!input.eof())
        {
            std::string student_id;
            std::string grade;
            input >> student_id;
            if(input.eof())
              break;
            std::cout << "The id is: " << student_id << std::endl;
        }
    }

}

void Student::collect_classes()
{
    std::ifstream courses;
    courses.open("classes.txt");
    courses >> class1;
    courses >> class2;
    courses >> class3;
    courses >> class4;
    courses >> class5;    
            
    courses.close();
    courses.clear();
}

std::string Student::collect_grades(std::string id)
{

    std::ifstream classes;
    classes.open("classes.txt");
    while(!classes.eof())
    {
        std::string classname;
        std::getline(classes,classname);
        if(classes.eof())
            break;
        std::ifstream class_file;
        classname += ".txt";
        class_file.open(classname.c_str());
        if(!class_file.fail())
        {
            std::cout << "will open the class file: " << classname << std::endl;
            std::cout << "and will look for the student id: " << id << std::endl;
            std::cout << "it will then get the grade from the line that the " << std::endl;
            std::cout << "id is on, to then use that to build the report. : " << std::endl;
        }
        else
        {
            std::cout << "The file " << classname << " cannot be opened" << std::endl;
        }
    }


}

void Student::selected_id(std::string id_lookup)
{
    student_id = id_lookup;
}

int main()
{
    std::vector<Student> students;
  
    //bool more = true;
    //while(more)
    //{
        
        Student s;
    
        s.list_ids();
        
        std::cout << "Enter a student ID: ";
        std::string entered_id;
        //std::cin >> entered_id;
        entered_id = "00004";
        
        
        s.selected_id(entered_id);
        s.collect_classes();
        //s.collect_grades("00001");
        s.print();  
        

        //char response;
        //std::cout << "Look up another Student?" << std::endl;
        //std::cin >> response;      
        //if(response != 'y' && response != 'Y')
          //more = false;
    //}
  
  
    return 0;
}

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Grades
{
  public:
    Grades(const std::string& course,const std::string& grade);
    std::string get_course();
    std::string get_grade();
    void print() const;
  private:
    std::string m_course;
    std::string m_grade;
};
/////////////Class Grades Start/////////////////
Grades::Grades(const std::string& course,const std::string& grade)
{
  
}
    
std::string Grades::get_course()
{
  std::cout << "getting course" << std::endl;
}

std::string Grades::get_grade()
{
  std::cout << "getting grades" << std::endl;
}
void Grades::print() const
{
  std::cout << "Print function" << std::endl;
}
/////////////Class Grades End///////////////////


class Students
{
  public:
    Students(const std::string& id);
    //void list_students();
    //std::string select_student();
    std::vector<Grades> get_grade();
    void add_grade(const Grades& grade);
    void print() const;
  private:
    std::string studentid;
    std::vector<Grades> m_grades;
};
/////////////Class Students Start////////////////
Students::Students(const std::string& id)
{

}

void Students::add_grade(const Grades& grade)
{

}    

void Students::print() const
{

}


/////////////Class Students End///////////////////
class Course
{
  public:
    Course(const std::string& filename);
    std::vector<std::string> get_classes();
    Students get_student(std::string id);
    void add_grades(Students & stu);
  private:
    std::vector<std::string> m_classes;
};
 
 /////////////Class Course Start///////////////////
Course::Course(const std::string& filename)
{
     
}

Students Course::get_student(std::string id)
{
    std::ifstream input;
    std::ifstream class2;
    std::ifstream class3;
    std::ifstream class4;
    std::ifstream class5;
    input.open("csc1.txt");

    //class3.open("eng108.txt");
    //class4.open("math90.txt");
    //class5.open("psy201.txt");
    
    if(!input.fail())
    {
        while(!input.eof())
        { 
            //std::string student_id;
			int student_id;
            std::string grade;
            input >> student_id;
            input >> grade;
            if(input.eof())
              break;
          //  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
            std::cout << "The id is: " << student_id << std::endl;
            std::cout << "CSC1 Grade is:  " << grade << std::endl;
           // std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
        }
    }
    input.close();
	input.clear();
	class2.open("math90.txt");
    if(!class2.fail())
    {
        while(!class2.eof())
        { x
            //std::string student_id2;
			int student_id2;
            std::string grade2;
            input >> student_id2;
            input >> grade2;
            if(class2.eof())
              break;
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
            std::cout << "The id is: " << student_id2 << std::endl;
            std::cout << "CIS201 Grade is:  " << grade2 << std::endl;
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
        }
    }
	class2.close();
}

void Course::add_grades(Students & stu)
{

}

/////////////Class Course End/////////////////////
 
int main()
{
  
  Course classes("classes.txt");
  //please.list_students();
  //please.select_student();
  std::vector<std::string> students;
  students.push_back("00001");
  students.push_back("00002");
  students.push_back("00003");
  students.push_back("00004");
  students.push_back("00005");
  for(int i=0;i<(students.size()-1);i++)
  {
    Students s = classes.get_student(students[i]);  // extract the student data from the files that the class container will open
    s.print();  // print the student
  }

return 0;
}




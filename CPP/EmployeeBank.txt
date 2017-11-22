#include <iostream>
#include <vector>
#include <string>

////////////////////Bank-start/////////////////////////
class Bank
{
  public:
    //Constructor
     Bank();
     
    //Prints out Account Name and Balance
     void print(); 
     
    //Sets the salary divided by 12 and sets it into 'balance'
     void set_balance(double salary);
     
    //Gets the balance 
     double get_balance();
     
     //Sets the account name
     void set_account(std::string lastname);
     
    //Gets account name
     std::string get_account();

  private:
     //Used to keep track of the balance
     double balance;
    //Used as the account name
     std::string account_name;
};

Bank::Bank()
{
  balance = 0.0;
  account_name = " ";
}

void Bank::set_balance(double salary)
{
  balance = salary;
}

double Bank::get_balance()
{
  return balance;
}

void Bank::set_account(std::string lastname)
{
  account_name = lastname;
}

std::string Bank::get_account()
{
  return account_name;
}

void Bank::print()
{
  std::cout << "Bank Account Name: " << account_name << std::endl;
  std::cout << "Bank Account Balance: " << balance << std::endl;
}
////////////////////Bank-end/////////////////////////


//////////////////Employee-start///////////////////////
class Employee
{
  public:
    //Constructor
     Employee();
     
    //Enters the information into first_name, last_name, salary
     void read();
     
     //Prints out name and balance
     void print() const;
     
     //Gets balance
     double get_balance();
     
     //Takes the salary and does the arithmitect storing it in balance
     void set_balance();
     
     //Corrects the balance if the employee last names are the same
     void put_balance(double);
     
    //Get salary
     double get_salary();
     
    //Returns full name
     std::string get_name();
     
    //Returns just last_name
     std::string get_lastname();
     
     //Sends balance to bank class
     void send_to_bank();
     
    //Pointer to the BANK class
     Bank *bank_account;
     
  private:
     double balance;
     double salary;
     std::string first_name;
     std::string last_name;
};

Employee::Employee()
{
  balance = 0.00;
  salary = 0.00;
  bank_account = new Bank();
}

void Employee::read()
{
   std::cout << "Enter Employees's first name [ENTER]." << std::endl;    
   std::cin >> first_name;
   std::cout << "Enter Employees's last name [ENTER]." << std::endl;
   std::cin >> last_name;
   std::cout << "Enter Employees's Salary [ENTER]." << std::endl;
   std::cin >> salary;
   set_balance();
}

void Employee::print() const
{
   std::cout << "Employee Name: " << " " << first_name << " " << last_name << std::endl;
   std::cout << "Employee Balance: " << balance << std::endl;
   bank_account->print();
}

void Employee::send_to_bank() {
   bank_account->set_account(last_name);
   bank_account->set_balance(balance);
}

void Employee::set_balance() 
{
  balance = (salary / 12) + balance;
  send_to_bank();
}

void Employee::put_balance(double temp_balance) {
  balance = temp_balance;
  send_to_bank();
}

double Employee::get_balance()
{
  return balance;
}

double Employee::get_salary()
{
  return salary;
}

std::string Employee::get_name()
{
  return first_name + " " + last_name;
}

std::string Employee::get_lastname()
{
  return last_name;
}

//////////////////Employee-end///////////////////////

//Used to print the employees vector
void print_employee(const std::vector<Employee> e)
{
  for(int i = 0; i < e.size();i++)
  e[i].print();
}

void delete_accounts()
{
  
}

void compare(std::vector<Employee> e) {
    //Iterate over first employee's last name
    for(int i = 0; i < e.size();i++) {
      //Iterate over second employee's last name
      for(int j = 1; j < e.size(); j++) {
        //std::cout << "LASTNAME!!!:: " << e[i].get_lastname() << std::endl;
        //std::cout << "LASTNAME!!!:: " << e[j].get_lastname() << std::endl;
      
        //Compares last name and if == set the balances the same
        if(e[i].get_lastname() == e[j].get_lastname())
          { 
            double temp_balance = e[i].get_balance();
            e[j].put_balance(temp_balance); 
          }
      }
    }
}

int main()
{
  //Creating a Vector for the employees
  std::vector<Employee> employee;
  
  //A loop to take in more employees
  bool more = true;
  while(more)
  {
    //Creates the employee object
    Employee e;
    
    //Runs the constructor for Employee class
    e.read();
    //Adds employee to the vector (employees)
    employee.push_back(e);
    
    std::cout << "Enter another employee? y/n" << std::endl;
    char response;
    std::cin >> response;
    if(response != 'y' && response != 'Y')
       more = false;
  }

  //Compares the last name of two employees
  compare(employee);

  //Prints the information from employee Vector
  print_employee(employee);
  
  
  return 0;
}
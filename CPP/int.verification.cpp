#include<iostream>
#include<string>
using namespace std;

bool is_printable(char c) //Checks to see it is a printable char
{
      return ( c >= ' ' && c <= '~');
}

bool is_digit(char c) //Checks to verify int range 0 - 9
{
      return c >='0' && c <= '9';
}

int to_int(char c) //Checks to insure char is an int
{
      return c - '0';
}

bool is_valid_number(string s) //Used to run boolean functions and returns to main
{
    char character;
    bool answer;

    for(int i = 0;i < s.size(); i++) { //used to iterate over a string and check individual chars
        //character = to_int(s[i]);
        character = s[i];
        cout << "Character: " << character << endl;
 
       if(is_digit(character)) { //If is_digit is true move to is_printable()
            if(is_printable(character)) { //If is_printable is true return true to answer    
                answer = true;
            }    
            else { //returns false to answer if to_printable is false
                    answer = false;  
            }
        }
        else { //return false to answer if is_digit is false
                cout << "IS_DIGIT is FALSE" << endl;
                answer = false;
        }
        if(answer == false) { 
            return answer; 
        }
    }
    return answer;
}

int main()
{
  string s = "3034987534095803498503948509348502a4958";
  
        if(is_valid_number(s)) //prints out to terminal determined by true or false
        {
          cout << s << endl << "Yes it is valid";
        }
        else
        {
          cout << s << endl << "No it is not valid";
        }
    return 0;
}

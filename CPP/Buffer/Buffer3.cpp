#include <iostream>
#include <string.h>

char *next_line(char *char_ptr)
{
    while (*char_ptr != '\0')
        char_ptr++;
    return char_ptr + 1;
}
char *double_lines(char **lines, int &size)
{
    char* new_lines[size* 2];
    for (int i = 0; i <size; i++)
    {
        new_lines[i] = lines[i];
    }
    size *= 2;
    lines = new_lines;
    return *lines;
}

char *double_buffer(char *buffer, int &size)
{
    std::cout<<sizeof(buffer) / sizeof(char);
    char* new_buffer = new char[size * 2];
	//std::array<char, size> new_buffer = buffer;	
	//memccpy(&new_buffer, &buffer, sizeof(buffer));
	
	new_buffer = buffer;
	
    for (int i = 0; i=size; i++)
    {
        //new_buffer[i] = buffer [i];
		std::cout << buffer[i];
    }
	
    //delete [] buffer;
    //buffer = new_buffer;
    //delete [] new_buffer;
    
    size *= 2;
    
    std::cout << sizeof(buffer) / sizeof(char);
     return buffer;
}
int main()
{
    int B_SIZE = 10;
    int L_SIZE = 1;
    char *buffer = new char[B_SIZE];
    char *lines[L_SIZE];

    int b_count = 0;
    int l_count = 0;
    
	
	std::cout << "Enter input:" << std::endl;
    
	char c;
	
//while (!std::cin.eof())
	do
    {

        std::cin.get(c);
        if (c == '\n')
        {
            buffer[b_count] = '\0';
            l_count++;
         if(l_count == L_SIZE) { double_lines(lines, L_SIZE); }
        }
		else if(b_count == B_SIZE) {
              double_buffer(buffer, B_SIZE);
        }
        else { 
			buffer[b_count] = c; 
		    b_count++;
			print();
		}
	} while(!std::cin.eof());
	
	return 0;
}

void print();
    char *current_char = buffer;
    for (int i = 0; i < l_count; i++)
    {
        lines[i] = current_char;
        current_char = next_line(current_char);
    }

    for (int j = 0; j < l_count; j++)
    {
        std::cout << "Before" << std::endl;
        std::cout << &lines[j] << std::endl; //never prints
        std::cout << "After" << std::endl; // never prints
    }

}

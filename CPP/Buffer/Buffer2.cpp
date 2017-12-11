#include <iostream>
#include <cstdint>
#include <cstring>

char *next_line(char *char_ptr)
{
    while (*char_ptr != '\0')
        char_ptr++;
    return char_ptr + 1;
}

void *double_lines(char **lines, int &size)
{
   char* new_lines[size* 2];
   
   std::memcpy(new_lines, lines, (size*2));
   
   //for(int i = 0; i < size; i++)
   //{
   //   new_lines[i] = lines[i];
   //}
   //size *= 2;
   //lines = new_lines;
}

void *double_buffer(char *buffer, int size)
{	std::cout << "SIZE: " << size << std::endl;
   std::cout << "BEFORE FUNCTION: " << sizeof(buffer) << std::endl;
   int new_size = size*2;
   std::cout << "NEW SIZE: " << new_size << std::endl;
   char *new_buffer[new_size];
   
   //for(int i = 0; i < sizeof(buffer); i++)
   //{
   //   new_buffer[i] = &buffer[i];
   //}
   
   std::memcpy(buffer, new_buffer, size);
   
   delete [] &buffer;
   
   std::memcpy(new_buffer, buffer, new_size);

   //delete [] &new_buffer;

   std::cout << "AFTER FUNCTION: " << sizeof(buffer) << std::endl;
   std::cout << "NEW BUFFER: " << sizeof(new_buffer) << std::endl;
}



int main()
{
    int B_SIZE = 1000;
    int L_SIZE = 100;
    char *buffer = new char[B_SIZE];
    char *lines[L_SIZE];

    int b_count = 0;
    int l_count = 0;
    
	char c;
	
    while (!std::cin.eof())
    {
        
        std::cin.get(c);
        if (c == '\n')
        {
            buffer[b_count] = '\0';
            l_count++;
         if(l_count == L_SIZE)
			{ double_lines(lines, L_SIZE); }
        }
        else
			{ buffer[b_count] = c; b_count++; }
        
      if(b_count == B_SIZE) {
			double_buffer(buffer, B_SIZE);
			std::cout << sizeof(buffer) << std::endl;
	  }
	  
    }

    char *current_char = buffer;
    for (int i = 0; i < L_SIZE; i++)
    {
        lines[i] = current_char;
        current_char = next_line(current_char);
    }

    for (int i = l_count - 1; i >= 0; i--)
    {
        std::cout << lines[i] << std::endl; 
    }

    return 0;
}
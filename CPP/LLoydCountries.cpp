#include <iostream>
#include <string>

using namespace std;

class country
{
  public:
    country();
  
  void read();
  void rec_density();
   
  long rec_population(); 
  long rec_area();

  
  bool greatest_pop();
  bool greatest_area();
  bool greatest_density();
  
  string best_country_pop;
  string best_country_area;
  string best_country_density;
  
  long best_population;
  long best_area;
  long best_density;
  
  private:
  
  string countryname;
  long population;
  long area;
  long density;
  
};

country::country()
  {
  read();
  best_density = 0;
  best_area = 0;
  best_population = 0;
  }

void country::read()
{
  bool more = true;
  while (more)
  {
  cout << "Please enter a country: " << endl;
  getline(cin, countryname);
  cout << "Please enter the country's population: " << endl;
  cin >> population;
  cout << "Please enter the country's area: " << endl;
  cin >> area;
  cin.ignore();
  
  greatest_pop();
  greatest_area();
  greatest_density();
  rec_density();
  
  cout << "More data? y/n ";
   string answer;
   getline(cin, answer);
   if (answer != "y")
      more = false;
  }
  cout << "The country with the highest population is: " << best_country_pop << "And they have " << best_population << "people " << endl;
  cout << "The country with the highest area is: " << best_country_area << "And they have " << best_area << "people " << endl;
  cout << "The country with the highest population is: " << best_country_density << "And they have " << best_density << "people " << endl;
}
  
long country::rec_population()
{
  return population;
}

long country::rec_area()
{
  return area;
}

bool country::greatest_pop()
{
  //if(population > best_population)
  //{
    //best_population = population;
    //best_country_pop = countryname;
  //}  // Saves the countries greatest pop.
}

bool country::greatest_area()
{
  if(area > best_area)
  {
    best_area = area;
    best_country_area = countryname;
  }
}   // Saves the countries best area.


bool country::greatest_density()
{
 if (density > best_density)
 {
   best_density = density;
   best_country_density = countryname;
 }
}
// Saves the countries best density.  

void country::rec_density()
{
  density = population / area;
}

int main() {
  
  country usa;
  
  return 0;
}

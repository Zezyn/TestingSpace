#include <iostream>
#include <string>

using namespace std;

class Country
{
  public:
     Country();
     
     
     bool greater_population(Country p);
     bool greater_area(Country a);
     bool greater_density(Country pd);
     
     void read();
     void print();
     
     long get_population(long country_pop);
     double get_area(double area);
     void get_population_density();
     
     string best_country_population;
     string best_country_area;
     string best_country_density;
     
  private:
     
     string country_name;
     double area;
     long population;
     double population_density;
     
};

Country::Country()
{
   read();
}

void Country::read()
{
   cout << "Please enter the country name: ";
   getline(cin, country_name);
   cout << "Please enter the population: ";
   cin >> population;
   cout << "Please enter the country's area: ";
   cin >> area;
   cin.ignore();
}

bool Country::greater_population(Country p)
{
  
  Country best;
  bool best_population = true;
  p.read();
  if(p.greater_population(best))
  {
     best = p;
     best_country_population = country_name;
  }
  
  
  // holds on to the greatest country of population
}

bool Country::greater_area(Country a)
{
  Country best;
  bool best_area = true;
  while (best_area)
  {
    
    Country next;
    next.read();
    if(next.greater_area(best))
        best = next;
        best_country_area = country_name;
  }
  // holds on to the greatest country of area
}

bool Country::greater_density(Country pd)
{
  
  // Holds on to the country with the greatest population_density
}

long Country::get_population(long country_pop)
{
  return population;
}

double Country::get_area(double country_area)
{
  return area;
}

void Country::get_population_density()
{
    population_density = population / area;
    cout << "Population Density: " << population_density << endl;
}

void Country::print()
{
  //will print the data  
}

int main()
{
  Country songs_about_my_girl_leaving_me_but_at_least_i_have_my_truck_and_my_dog;
  //runs shit... nah sayin
return 0;
}

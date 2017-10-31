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
     long get_area(long area);
     void get_population_density();


     string best_country_name;     
     long best_country_population;
     long best_country_area;
     long best_country_density;
     
  private:
     
     string country_name;
     long area;
     long population;
     long population_density;
     
};

Country::Country()
{
   
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

  // holds on to the greatest country of population
bool Country::greater_population(Country p)
{
    bool best_population = true;
    if(p.population > population)
    {
     best_country_name = p.country_name;
     best_country_population = p.population;
    }
    else {
        best_country_name = country_name;
        best_country_population = population;
    }
}

bool Country::greater_area(Country p)
{
  // holds on to the greatest country of area
}

bool Country::greater_density(Country p)
{
  
  // Holds on to the country with the greatest population_density
}

long Country::get_population(long country_pop)
{
  return population;
}

long Country::get_area(long country_area)
{
  return area;
}

void Country::get_population_density()
{
    population_density = population / area;
}

    //will print the data  
void Country::print()
{

    cout << endl << "Best Country Population: " << best_country_name << " With " << best_country_population << endl;
/*
      cout << "Best Country Pop: " << best_country_population << endl;
      cout << "Best Country Area: " << best_country_area << endl;
      cout << "Best Country Density: " << best_country_density << endl;

      cout << "Country Name: " << country_name << endl;
      cout << "Area: " <<  area << endl;
      cout << "Population: " << population << endl;
      cout << "Population Density: " <<  population_density << endl;
*/

    //will print the data  
}


void Check_Population(Country one, Country two) {

        if (one.greater_population(two)) {
             one.print();
        }
        else {
            two.print();
        }
}

int main()
{
   
        Country USA;
        Country Iraq;  
        Country SA;
	USA.read();
        Iraq.read();
	SA.read();
        
        Check_Population(USA, Iraq);

   return 0;
}


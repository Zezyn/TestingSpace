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
    get_population_density();
    print();

}

bool Country::greater_population(Country p)
{
   cout << "The current values for this object:";
   print();
   cout << endl;
   cout << "The current values for the parameter object:";
   p.print();
   cout << endl; 
 
  Country best;
  bool best_population = true;
  if(p.population > population)
  {
     best = p;
     best_country_population = country_name;
    //cout << "Best: " << best << endl;
    cout << "Best Country Pop: " << best_country_population << endl;
  }
  
  
  // holds on to the greatest country of population
}

bool Country::greater_area(Country a)
{
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
}

void Country::print()
{
      cout << "Best County Pop: " << best_country_population << endl;
      cout << "Best Country Area: " << best_country_area << endl;
      cout << "Best Country Density: " << best_country_density << endl;

      cout << "Country Name: " << country_name << endl;
      cout << "Area: " <<  area << endl;
      cout << "Population: " << population << endl;
      cout << "Population Density: " <<  population_density << endl;


    //will print the data  
}

int main()
{
   
    //bool more = true;
    //while (more)
    //{    
      Country USA;
      //Country;
      Country Iraq;  
      //Country next;
      USA.read();
      Iraq.read();  
      if (USA.greater_population(Iraq))
         USA.print();

      //cout << "More data? (y/n) ";
      //string answer;
      //getline(cin, answer);
      //if (answer != "y")
         //more = false;
   //}

   return 0;
}

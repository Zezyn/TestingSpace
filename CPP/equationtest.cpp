#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double pi = 3.14159;

  double sphere_volume(double r)
  {
    double volume;
    volume = 4.0/3.0 * pi * pow(r,3);
    return volume;
  }
 
    double sphere_volume2(double r) {
    double volume;
    volume = 1/6 * pi * pow((r/2),3);
    return volume;
    }

int main() {

    double user_input_r;
    double user_input_d;    


    cout << "Radius: " << endl;
    cin >> user_input_r;
    cout << sphere_volume(user_input_r); 

    cout << "Diameter: " << endl;
    cin >> user_input_d;
    cout << sphere_volume(user_input_d);

    return 0;
}

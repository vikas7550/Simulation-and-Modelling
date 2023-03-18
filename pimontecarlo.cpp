#include <iostream>
#include <random>

using namespace std;


double monte_carlo_sqrt(int iteration = 10000000) {
    
    int inside = 0;
    for (int i = 0; i < iteration; i++)
     {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if ((x*x  + (y*y)) < 1) {
            inside++;
        }
    }
    
    return ((double)inside / iteration) * (double)4;
}

int main() 
{
    
    cout << "Value of pie using monte carlo method"<< endl;
    cout << monte_carlo_sqrt() << endl;
    return 0;
}

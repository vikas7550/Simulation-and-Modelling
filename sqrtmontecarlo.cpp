#include <iostream>
#include <random>

using namespace std;


double monte_carlo_sqrt(int n,int iteration = 100000000) {
    
    int inside = 0;
    for (int i = 0; i < iteration; i++)
     {
        double x = (double)rand() / RAND_MAX*n;
        
        if ((x*x) < (n)) {
            inside++;
        }
    }
    
    return ((double)iteration / inside);
}

int main() 
{
    int n;
    cout << "enter the value to find the square root" << endl;
    cin >> n;
    cout << "Value of square root using monte carlo method" << endl;
    cout << monte_carlo_sqrt(n) << endl;
    return 0;
}
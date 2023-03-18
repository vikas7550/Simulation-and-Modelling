#include<iostream>
#include<ctime>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    // this will be taken input from the user
    int re_point, re_quantity;
    int pending_order = 0, order_arrival_day = -1;
    int current_stock = 115; //given in the problem
    int demand;
    double carrying_cost,shortage_cost;
    double cost = 0;

    cout << "enter the reorder point" << endl;
    cin >> re_point;
    cout << "enter the reorder quantity" << endl;
    cin >> re_quantity;

    srand(time(0));
    for (int day  = 0; day < 18; day++)
    {
        demand = (double)rand()/RAND_MAX*100; //generating random demand between 0 to 99 for each day
        if(pending_order > 0 && order_arrival_day == day)
        {
            pending_order = 0;
            current_stock += re_quantity;
        }
        if (demand <= current_stock)
        {
            current_stock -= demand;
            carrying_cost = (double)current_stock *0.75;
            cost += carrying_cost;
        }
        else
        {
            shortage_cost = (demand - current_stock) * 18;
            cost += shortage_cost;
            current_stock = 0;
        }
        if ((pending_order+current_stock) <= re_point && order_arrival_day < day)
        {
            pending_order = re_quantity;
            cost+=75;
            order_arrival_day = day + 3; //there is 3 day lag between the order and arrival.
        }
    }
    
    cout << endl << endl << "cost for this policy is = " << cost; 

    return 0;

}
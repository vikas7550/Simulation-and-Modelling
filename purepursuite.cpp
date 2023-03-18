#include<iostream>
#include<math.h>

using std::endl;
using std::cout;
using std::cin;

int main()
{

	int t,i;
    double d; //to compute distance
    
    //vf is velocity of fighter plane
    //xf & yf are coordinate of fighter
    //xb & yb are coordinate of bomber
	double xf[12],yf[12],xb[12],yb[12],vf;
	
	cout << "\nSIMULATION OF PURE PURSUIT PROBLEM IN C\n\n";
	
    //taking input trajectory of the bomber over time t = 0  to t = 12 
    cout << "Enter Bomber path, xb[t] & yb[t]:";
	for(i=0;i<12;i++)
	{
        cin >>xb[i]>>yb[i];
    }
	
	cout << "Enter Fighter's Initial path, xf[0] & yf[0]:";
    cin  >> xf[0] >> yf[0];
	cout << "Enter Fighter velocity, vf:";
    cin >> vf;
	
    for(t=0;t<13;t++) 
	{
		d=sqrt(pow((yb[t]-yf[t]),2)+pow((xb[t]-xf[t]),2));  
		if(d<10)
        {
		    cout << "\nCaught at %d minuts and %f kms\n",t,d;
            break;
        }
        else
        {
            xf[t+1]=xf[t]+(vf*(xb[t]-xf[t])/d);
            yf[t+1]=yf[t]+(vf*(yb[t]-yf[t])/d);
		}
	}
	
    if(t>12){cout << "Target Escaped\n";}


return(0);
  
}
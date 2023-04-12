#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    srand(time(NULL));
    double tab[] = {0.3, 0.7, 0.8, 1.0};
    int size_of_tab = 4;
    int results[] {0,0,0,0};
    double r = 0;
    for(int i = 0; i<100000; i++){
        r = ((double) rand() / (RAND_MAX));
        
        for(int j=0; j <size_of_tab; j++){
            //cout<<r<<" "<<tab[j]<<endl;
            if(r<tab[j]){
                results[j]++;
                
                break;
            }
        }
        
    }
    
    for(int i=0; i <size_of_tab; i++){
        cout<<i+1<<": "<<results[i]<<endl;
    }
    
    
    cout<<endl<<endl;
    //2 
    //int interval = floor ((10 * x) / double (1.0));
    // pr_distribution1[interval]++;
    // y = 100x + 50

    
    double tab1[] = {0.3, 0.7, 0.8, 1.0};
    int size_of_tab1 = 10;
    int results1[] {0,0,0,0,0,0,0,0,0,0};
    double r1 = 0;
    
    for(int i = 0; i<100000; i++){
        r1 = ((double) rand() / (RAND_MAX));
        double x = (r1*100 + 50);
        //cout<<x<<endl;
        int interval = floor ((10* (x - 50)) / double (100.0));
        results1[interval]++;
        
        
    }
    
    for(int i=0; i <size_of_tab1; i++){
        cout<<i+1<<": "<<results1[i]<<endl;
    }
    

    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    srand(time(NULL));
    //double tab[];
    double tab_x[] = {0.35, 0.4, 0.7, 1.0}; // tablica wartości dla osi X
    double wsp[4] = {2.85714, 20.0, 3.33333, 3.33333};
    double tab_y[][4] = {
        {0.2*wsp[0], 0.2*wsp[0], 0.35*wsp[0], 0.35*wsp[0]}, // 0.35 *2.85714 == 1
        {0.05*wsp[1], 0.05*wsp[1], 0.05*wsp[1], 0.05*wsp[1]},
        {0.0*wsp[2], 0.1*wsp[2], 0.1*wsp[2], 0.3*wsp[2]},
        {0.3*wsp[3], 0.3*wsp[3], 0.3*wsp[3], 0.3*wsp[3]}
        
    }; // tablica wartości dla osi Y
    int size_of_tab = 4; // rozmiar tablic
    int results[size_of_tab][size_of_tab] = {0}; // dwuwymiarowa tablica wyników
    
    for(int i = 0; i < 100000; i++){
        double r_x = ((double) rand() / (RAND_MAX)); // losujemy wartość dla osi X
        double r_y = ((double) rand() / (RAND_MAX)); // losujemy wartość dla osi Y
        
        // szukamy odpowiedniej kategorii na osi X i Y
        int category_x = 0;
        int category_y = 0;
        for(int j = 0; j < size_of_tab; j++){
            if(r_x < tab_x[j]){
                category_x = j;
                break;
            }
        }
        
        //cout<<category_x<<endl;
        for(int k = 0; k < size_of_tab; k++){
            if(r_y < tab_y[category_x][k]){
                //cout<<tab_y[category_y][k]<<endl;
                category_y = k;
                break;
            }
        }
        
        // zwiększamy wynik dla odpowiedniej kategorii
        results[category_x][category_y]++;
    }
    
    // wyświetlamy wyniki
    for(int j = 0; j < size_of_tab; j++){
        for(int k = 0; k < size_of_tab; k++){
            cout << results[k][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector <int>Nums={1,2,4,5,6};

    cout << "inital vector: ";

    for (const &i:Nums){
        cout << i << " ";

        // i = 70; Error coz i is a constance so it for read Only
    }
    printf("\n\n Updated Vector : ");
    
    for(int &i:Nums){
        i = 10;
        cout << i << " ";
    }
    
    Nums[1] = 10;
    Nums.at(2) = 40;
    Nums.at(4) = 100;
    
    printf("\n\n Updated Vector : ");

    for (const int &i : Nums) //when we use const in this case  that make the program faster
    {
        cout << i << " ";
    }

    return 0;
}
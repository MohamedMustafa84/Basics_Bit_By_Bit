#include <iostream>
using namespace std; 
#include "../ClsLoginScreen.h"


int main(){

     while(true){
         if (!clsLoginScreen::ShowLoginScreen()){
             break;
         }
    }
    return 0;
}
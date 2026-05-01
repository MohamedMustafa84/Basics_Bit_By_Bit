#include <iostream>
using namespace std; 

// printf formatting integer

int main(){
    int page = 1, totalPages = 10;
    
    // print string and int variable
    printf("the Page Number =%d\n", page);
    printf("you are in page %d of %d \n", page, totalPages);

    // width specification
    printf("the page number= %0*d \n", 2, page);
    printf("the page number= %0*d \n", 3, page);
    printf("the page number= %0*d \n", 5, page);
    printf("the page number= %0*d \n", 4, page);

    int Number1 = 20, Number2 = 30;
    printf("the Result of %d + %d =%d\n",Number1,Number2,Number1+Number2);


    return 0;
}
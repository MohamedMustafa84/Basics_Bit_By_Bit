#include <iostream>
using namespace std;

// default Parameters == optional Parameters

// من الحياة الواقعية :
// عندما كنت صغير  عندما كانت امك ترسلك الى البقالة كانت بعد ان تخبرك  بطلبات المنزل  كانت تعطيك ورقة مكتوب عليها طلبات المنزل  لانها تعلم انك بمجرد ان ترى الحلوى  سوف تنسى حتى اسمك  نفس الشي في البرمجة عندما يفشل مصدر ادخال البيانات سواء كانت تاتي عن طريق المستخدم او اي طريقة اخرى بقوم بعمل قيمة افتراضية حتى لا تحصل سيناريوهات غير متوقعة   

// parameters c  and d are Default Parameters 

int MySum(int a,int b,int c=0 ,int d=0){
    return (a + b + c + d);
}



int main(){
    cout <<MySum(30,40)<<endl;
    cout <<MySum(20,30,40)<<endl;
    cout <<MySum(10,20,30,40)<<endl;



    return 0;
}
#include <iostream>
using namespace std;

int main() 

{
    int num = 60;
    int* ptr = &num; 

    cout << "Before modification: " << endl;
    cout << "Variable value: " << num << endl;
    
    cout << "Pointer value: " << *ptr << endl;

    *ptr = 20;

    cout << "\nAfter modification: " << endl;
    
    cout << "Variable value: " << num << endl;
    cout << "Pointer value: " << *ptr << endl;



    return 0;
    
    
    
    
    
}



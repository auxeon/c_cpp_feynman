#include<iostream>

// accepting by reference is same as const pointer
void func1(int &a,int * const b){
    std::cout<<&a<<" : func1 : (&a) Address"<<std::endl;
    std::cout<<b<<" : func1 : (b) Address"<<std::endl;
    std::cout<<a<<" : func1 (a) Value"<<std::endl;
    std::cout<<*b<<" : func1 (*b) Value"<<std::endl<<std::endl;
}

// global just to play around with func2 and func3 
int x = 10;

// returning by a const pointer
int* const func2(void){
    std::cout<<"func2 called"<<std::endl;
    // just increment x and also return
    ++::x;
    return(&::x);
}

// returning by reference is same as returning a const pointer
int& func3(void){
    std::cout<<"func3 called"<<std::endl;
    // just increment x and also return
    ++::x;
    return(::x);
}

int main(int argc, char ** argv){

    int i = 10;            // int
    int &j = i;            // j is reference to an int
    int * const k = &i;    // k is a const pointer that points to address of i 

    std::cout<<"PLAIN LOCAL REFERENCES AND CONST POINTERS"<<std::endl;
    std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<i<<" : (i) Value"<<std::endl;                 // 10 : (i) Value
    std::cout<<j<<" : (j) Value"<<std::endl;                 // 10 : (j) value
    std::cout<<k<<" : (k) Address"<<std::endl<<std::endl;    // 0x7ffee6037a0c : (k) Address

    std::cout<<&i<<" : (&i) Address"<<std::endl;                        // 0x7ffee6037a0c : (&i) Address
    std::cout<<&j<<" : (&j) Address"<<std::endl;                        // 0x7ffee6037a0c : (&j) Address
    std::cout<<&k<<" : (&k) Address"<<std::endl<<std::endl;             // 0x7ffee60379f8 : (&k) Address

    std::cout<<*k<<" : (*k) Value"<<std::endl;                          // 10 : (*k) Value
    std::cout<<i<<" : (i) Value"<<std::endl;                            // 10 : (i) Value
    std::cout<<&(*k)<<" : (&(*k)) Address"<<std::endl;                  // 0x7ffee6037a0c : (&(*k)) Address
    std::cout<<k<<" : (k) Address"<<std::endl;                          // 0x7ffee6037a0c : (k) Address
    std::cout<<&i<<" : (&i) Address"<<std::endl;                        // 0x7ffee6037a0c : (&i) Address
    std::cout<<&k<<" : (&k) Address"<<std::endl<<std::endl;             // 0x7ffee60379f8 : (&k) Address
    

    std::cout<<"PASSING func1 PARAMS BY CONST POINTER AND REFERENCE"<<std::endl;
     std::cout<<"------------------------------------------"<<std::endl;
    // passing by reference
    func1(i,&i);


    std::cout<<"GLOBALS"<<std::endl;
     std::cout<<"------------------------------------------"<<std::endl;
    // returning by reference
    // int & y; // ILLEGAL as it is const pointer internally, same as below PROOF
    // int * const z; // cannot declare and then later assign value as it is const pointer
    
    // intially x 
    std::cout<<x<<" : (x) Value : main"<<std::endl;
    std::cout<<&x<<" : (&x) Address : main"<<std::endl<<std::endl;

    std::cout<<"RETURNING BY CONST POINTER"<<std::endl;
    std::cout<<"------------------------------------------"<<std::endl;
    // called func2 and store in reference - PROOF that &y needs lvalue which it then internally auto dereferences
    int &y = *func2();
    std::cout<<y<<" : (y) Value : After func2"<<std::endl;                   // 11 : (y) Value : After func2
    std::cout<<x<<" : (x) Value : After func2"<<std::endl;                   // 11 : (x) Value : After func2
    std::cout<<&y<<" : (&y) Address : After func2"<<std::endl;               // 0x10d9520f0 : (&y) Address : After func2
    std::cout<<&x<<" : (&x) Address : After func2"<<std::endl<<std::endl;    // 0x10d9520f0 : (&x) Address : After func2
    

    std::cout<<"RETURNING BY REFERENCE"<<std::endl;
    std::cout<<"------------------------------------------"<<std::endl;
    // int * const g does not need to auto dereference as it is a const pointer and can store a return by reference(address)
    // the reference that func3 returns is actually the lvalue(memory address) that we call x so we need to get the address of the returned reference
    int * const g = &func3();
    std::cout<<*g<<" : (*g) Value : After func3"<<std::endl;      // 12 : (*g) Value : After func3
    std::cout<<x<<" : (x) Value : After func3"<<std::endl;        // 12 : (x) Value : After func3
    std::cout<<g<<" : (g) Address : After func3"<<std::endl;      // 0x10d9520f0 : (g) Address : After func3
    std::cout<<&x<<" : (&x) Address : After func3"<<std::endl;    // 0x10d9520f0 : (&x) Address : After func3
    
    return(0);
}

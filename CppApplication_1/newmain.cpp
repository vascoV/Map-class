#include <iostream>
#include <string>
#include <libintl.h>
#include "CMap.h"

class test{
private:
    int i =0;
public:
    test(){
        i = 10;
    }    
};

int main(int argc, char** argv) {
     
    CMap<int, char*>* foo = new CMap<int, char*>();
    foo->insert (1, "OK");
    foo->insert (2, "DONE");
    foo->insert (3, "VASILIS");
    foo->insert (4, "ANDREAS");
    foo->insert (5, "CHRYSANTHOS");
    
    foo->print();
    foo->at(4);
    foo->erase(2);
    foo->insert(1, "Boooo");
    foo->print();
    
//    CMap<int, test*>* obj = new CMap<int, test*>();
//  
//    obj->print();
    
    
    //foo->pop();
    
//    std::cout<<std::endl;
//    CMap<int, int>* num = new CMap<int, int>();
//    num->insert(1, 10);
//    num->insert(2, 20);
//    num->insert(3, 30);
//    num->insert(4, 40);
//    num->insert(5, 50);
//   
//    
//     //std::cout << "The top element is: " << boolean->front() << std::endl;
//    
//    num->print();
//    num->at(3);
//    num->erase(3);
//    num->insert(4, 89);
//    num->print();
    
//    std::cout<<std::endl;
//    CMap<int, bool>* boolean = new CMap<int, bool>();
//    boolean->insert(1, true);
//    boolean->insert(2, false);
//    boolean->insert(3, true);
//    boolean->insert(4, false);
//    boolean->insert(5, true);
//    
//    boolean->print();
//    boolean->at(1);
//    std::cout << "the size is: " << boolean->capacity() << std::endl;
//    boolean->erase(3);
//    boolean->print();
//    std::cout << std::endl;
//    //boolean->pop();
//    //boolean->print();
    
    
    return 0;
    
}


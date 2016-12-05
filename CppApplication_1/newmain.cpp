#include <iostream>
#include <string>
#include "CMap.h"

class MyClass
{
public:
	MyClass() {};
	~MyClass() {};

private:
	std::string x = "abc";
};


int main() {
	std::cout << "Hello from the Map test" << std::endl << std::endl;

	
	std::cout << "----------" << "Object Test" << "----------" << std::endl;
	CMap<int, MyClass*>* objMap = new CMap<int, MyClass*>();

	MyClass* c1 = new MyClass();
	MyClass* c2 = new MyClass();
	MyClass* c3 = new MyClass();
	MyClass* c4 = new MyClass();
	MyClass* c5 = new MyClass();

	objMap->insert(1, c1);
	objMap->insert(2, c2);
	objMap->insert(3, c3);
	objMap->insert(4, c4);
	objMap->insert(5, c5);
	
	objMap->print();


	std::cout << std::endl;
	std::cout << "My Map contains "<< objMap->size() << " objects." << std::endl;
	std::cout << std::endl << std::endl; //print empty two lines

	std::cout << "----------" << "String Test" << "----------" << std::endl;
	CMap<int, char*>* strMap = new CMap<int, char*>();

	strMap->insert(1, "String-1");
	strMap->insert(2, "String-2");
	strMap->insert(3, "String-3");
	strMap->insert(4, "String-4");
	strMap->insert(5, "String-5");

	strMap->print();
	strMap->at(2);
	std::cout << std::endl; //print empty line
	strMap->erase(5);
	std::cout << std::endl; //print empty line
	strMap->print();

	std::cout << std::endl;
	std::cout << "My Map contains " << strMap->size() << " strings." << std::endl << std::endl;

	std::cout << "----------" << "Integer Test" << "----------" << std::endl;
	CMap<int, int>* intMap = new CMap<int, int>();

	intMap->insert(1, 10);
	intMap->insert(2, 20);
	intMap->insert(3, 30);
	intMap->insert(4, 40);
	intMap->insert(5, 50);

	intMap->print();
	intMap->at(6);
	intMap->insert(2, 80);
	std::cout << std::endl; //print empty line
	intMap->erase(5);
	std::cout << std::endl; //print empty line
	intMap->print();

	std::cout << std::endl;
	std::cout << "My Map contains " << intMap->size() << " integers." << std::endl << std::endl;

	std::cout << "----------" << "Characters Test" << "----------" << std::endl;
	CMap<int, char>* chrMap = new CMap<int, char>();

	chrMap->insert(1, 'a');
	chrMap->insert(2, 'b');
	chrMap->insert(3, 'c');
	chrMap->insert(4, 'd');
	chrMap->insert(5, 'e');

	chrMap->print();
	chrMap->at(6);
	std::cout << std::endl; //print empty line
	chrMap->erase(3);
	std::cout << std::endl; //print empty line
	chrMap->print();

	std::cout << std::endl;
	std::cout << "My Map contains " << chrMap->size() << " characters." << std::endl << std::endl;


	system("pause");
	return 0;
}
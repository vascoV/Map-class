#include<iostream>
#include<string>
//#include"Map.h"
template <class k, class v>
struct Node {
	k key;
	v value;
};

template<class k, class v>
class MyMap
{
public:
	typedef Node<k, v> elem;
	MyMap() {
		nodes = (elem*)malloc(sizeof(elem)*size);  //array

		//for (int i = 0; i < size; i++) {
			//nodes[i].key = NULL;
			//nodes[i].value = NULL;
		//}
	}
	//what are the methods general what my ass wants to, destructor.
	//~MyMap() {
          //  delete elem;
	//}
	
	void add(k Key, v Value) {
		int indexKey = Find(Key); // get current key
		if (CheckIfExist(Key) == true) {
			std::cout << "EXIST " << nodes[indexKey].key << std::endl;
		}
		else {
			nodes[index].key = Key;                                                     ////insert
			nodes[index].value = Value;
			index++;
		}
		if (index == size - 2) {
			resize();
		}
	}

	k CheckIfExist(k Key) {
		for (int i = 0; i < size; i++) {                                          ///check if i have the same
			if (nodes[i].key == Key) {
				return true;
			}
		}
		return false;
	}
	////////////////////////////////
	k Find(k Key) {
		for (int i = 0; i < size; i++) {
			if (nodes[i].key == Key) {                              //
				return i;
			}
		}
		return -1;
	}

	void checkFind(k Key) {
		int pos = Find(Key);                                        //search 
		if (pos >= 0) {
			//std::cout << "EXIST " << std::endl;
			std::cout << "FOUND " << nodes[pos].value << std::endl;

		}
		else {
			std::cout << "NOT FOUND " << std::endl;
		}
	}
	////////////////////////////////
	void print() {
		for (int i = 0; i < index; i++) {
			std::cout << nodes[i].key << " " << nodes[i].value << std::endl;
		}
	}

	void resize() {
		nodes = (elem*)realloc(nodes, sizeof(elem)*size*2);
		size *= 2;
		for (int i = index + 2; i < size; i++) {
			nodes[i].key = k();
			nodes[i].value = v();
			//nodes[i].key = NULL;
			//nodes[i].value = NULL;
		}

	}
	void erase_key(k key) {
		for (int i = 0; i < size; i++) {
                    if (nodes[i].key == key) {
			std::cout << "The Value: " << nodes[i].key << " with the key " << nodes[i].value << " DELETED " << std::endl;

				//nodes[i].key = NULL;
				//nodes[i].value = NULL;
				////////////////////////////////////////////////////
			nodes[i].key = nodes[index - 1].key;
			nodes[i].value = nodes[index - 1].value;
			nodes[index].key = k();
			nodes[index].value = v();
			index--;
				///////////////////////////////////////////////////
			}
		}
	}
private:
	elem *nodes;
	int size = 10;
	int index = 0;
};



int main() {
	//MyMap<int, char*>* Fun = new MyMap<int, char*>();
	MyMap<int, std::string>* Fun = new MyMap<int, std::string>();
	
	Fun->add(1, "Hello1");
	Fun->add(2, "Hello2");

	Fun->print();
	
	//Fun->add(1, 1);
	//Fun->add(2, 2);
	//Fun->add(3, 3);
	//Fun->add(4, 7);
	//Fun->add(5, 5);
	//Fun->add(6, 6);
	//Fun->erase_key(4);
	//Fun->add(3, "Hello 3");
	//Fun->checkFind(5);
	//Fun->add(4, 3);
	
	//system("pause");
	return 0;

}

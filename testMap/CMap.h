template <typename K, typename DT>
struct Elements {

	K Key;
	DT Data;
};

template <typename K, typename DT>
class CMap
{
	typedef Elements<K, DT> myElement;

private:
	myElement* elements;
	int arraySize = 10;
	int positionIndex = 0;

public:
	//constructor allocates blocks of memory for the container
	CMap() {
		//An initial map with a size of 10 potential elements.
		elements = (myElement*)malloc(sizeof(myElement)*arraySize);
	}

	//destructor
	~CMap() {
		free(elements);
	}

	//insert Key and Value intio the container and make some potential checks
	void insert(K key, DT val) {
		int pos = find(key);
		if (keyExists(key) == true) { //check if the key already exist into the container ans simplu return a message
			std::cout << "The key " << elements[pos].Key << " already exists in the container!" << std::endl;
		}
		else {
			elements[positionIndex].Key = key; //add the key into the map container
			elements[positionIndex].Data = val; //add the value into the map container
			positionIndex++;
		}

		//check if the container size exceed 
		if (positionIndex == arraySize) {
			extendSize(); //reallocate for extra memory 
		}
	}

	//this function create another array and reallocates extra memory  
	void extendSize() {
			elements = (myElement*)realloc(elements, sizeof(myElement)*arraySize * 2);
			arraySize *= 2;
			for (int i = positionIndex + 2; i < arraySize; i++) {
			elements[i].Key = K();
			elements[i].Data = DT();
                    }
		}
	

	//check if key already exists into the container
	bool keyExists(K key) {
		for (int i = 0; i < arraySize; i++) {
			if (elements[i].Key == key) {
				return true;
			}
		}
		return false;
	}

	//this function return the current key
	K find(K key) {
		for (int i = 0; i < arraySize; i++) {
			if (elements[i].Key == key) {
				return i;
			}
		}
		return -1;
	}

	//takes as input any key and corespondingly return the key and its value or just say that the key doen't exist into the container
	void at(K key) {
		int pos = find(key);
		if (pos >= 0) {
                    std::cout << "The Key " << elements[pos].Key << " was found with value " << elements[pos].Data << std::endl;
		}
		else {
                    std::cout << "The key that you trying to acces doesn't exist!!" << std::endl;
		}
	}

	bool isEmpty() {
		if (positionIndex == 0)
			return true;
		else
			return false;
	}

	//return the current size of the container
	int size() {
		return positionIndex;
	}

	//swap the curent key with the last key and delete it
	void erase(K key) {
		for (int i = 0; i < positionIndex; i++) {
			if (elements[i].Key == key) {
				std::cout << "The value " << elements[i].Data << " with key " << elements[i].Key << " was deleted " << std::endl;
				elements[i].Key = elements[positionIndex - 1].Key;
				elements[i].Data = elements[positionIndex - 1].Data;
				elements[positionIndex].Key = K();
				elements[positionIndex].Data = DT();
				positionIndex--;
			}
		}
	}

	//print into the console
	void print()
	{
		for (int i = 0; i < positionIndex; i++)
		{
			std::cout << elements[i].Key << " " << elements[i].Data << std::endl;
		}
	}
};
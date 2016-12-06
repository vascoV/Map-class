/*
 * This struct is used to group the Key and the Data under one element
 */
template <typename K, typename DT>
struct Elements {
    K Key;
    DT Data;
    Elements* next;
};

/*
 * The map class include methods and variable to work like a look up table
 */
template <typename K, typename DT>
class CMap
{
    typedef Elements<K, DT> myElement;

/*
 *The private: only the class can access the data
 */    
private:
    myElement* elements;
    int arraySize = 10;
    int positionIndex = 0;

/*
 * The public: all the methods canbe accessed outside the class
 */    
public:
    /*
     * Constructor: used to allocate memory for the array
     */
    CMap() {		//An initial map with a size of 10 potential elements.
        elements = (myElement*)malloc(sizeof(myElement)*arraySize);
    }

    //Destructor used to free blocks of memory
    ~CMap() {
        free(elements);
    }

	/*
         * adding elements onto the array, check for key repetition
         */
	void insert(K key, DT val) {
            int pos = find(key); //store the current key into the pos variable
            if (keyExists(key) == true) { //check if the key already exist into the array 
                std::cout << "The key " << elements[pos].Key << " already exists in the container!" << std::endl;
            }
            else {
                elements[positionIndex].Key = key; //add the key into the map container
            	elements[positionIndex].Data = val; //add the value into the map container
		positionIndex++;
            }

            //check if the array is full, if yes reallocates extra positions and memory
            if (positionIndex == arraySize) {
                extendSize(); //reallocate for extra memory 
            }
	}

	/*
         * Extend the array size and reallocates extra memory for the array
         */ 
	void extendSize() {
            elements = (myElement*)realloc(elements, sizeof(myElement)*arraySize * 2); //memory reallocation using realloc
            arraySize *= 2; //extend the array size
            for (int i = positionIndex + 2; i < arraySize; i++) {
                elements[i].Key = K();
                elements[i].Data = DT();
            }
	}
	

	/*
         * Function for checking if key already exist and retyrn true and false correspondingly 
         */
	bool keyExists(K key) {
            for (int i = 0; i < arraySize; i++) {
                if (elements[i].Key == key) {
                    return true;
		}
            }
            return false;
	}

	/*
         * Function to find the current key and return it
         */
	K find(K key) {
            for (int i = 0; i < arraySize; i++) {
                if (elements[i].Key == key) {
                    return i;
		}
            }
            return -1;
	}

	//this function takes as argument any key and return the key and its' value or message that the key doesn't exist 
        void at(K key) {
            int pos = find(key);
            if (pos >= 0) {
                std::cout << "The Key " << elements[pos].Key << " has value " << " '" << elements[pos].Data << "' " << std::endl;
            }
            else {
                std::cout << "The key doesn't exist!" << std::endl;
            }
	}

        //check if the array is empty
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

	//swap the current key with the last key and delete it
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
	void print(){
            for (int i = 0; i < positionIndex; i++)
            {
                std::cout << elements[i].Key << " " << elements[i].Data << std::endl;
            }
	}
};
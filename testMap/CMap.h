/*
 * This struct is used to group the Key and the Data under one element
 */
template <typename K, typename DT>
struct Elements {
    K Key;
    DT Data;
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
        elements = (myElement*) calloc(arraySize, sizeof(myElement));
    }

    //Destructor used to free blocks of memory
    ~CMap() {
        free(elements);
    }

    /*
     * adding elements onto the array, check for key repetition
     */
    void insert(K key, DT val) {
        // 1, 2, 3, 4, 5
        // 7
        int pos = find(key); // -1, -1, 3, -1
       
        if(pos != -1){
            
            throw std::out_of_range("The key already exists");  
        }
        
        elements[positionIndex].Key = key; //add the key into the map container
        elements[positionIndex].Data = val; //add the value into the map container

        positionIndex++;

        //check if the array is full, if yes reallocates extra positions and memory
        if (positionIndex == arraySize) {
            extendSize(); //reallocate for extra memory 
        }
    }

    /*
     * Extend the array size and reallocates extra memory for the array
     */ 
    void extendSize() {
        arraySize *= 2; //extend the array size
        elements = (myElement*)realloc(elements, sizeof(myElement)*arraySize); //memory reallocation using realloc


//            for (int i = positionIndex + 2; i < arraySize; i++) {
//                elements[i].Key = K();
//                elements[i].Data = DT();
//            }
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
    int find(K key) {
        for (int i = 0; i < arraySize; i++) {
            if (elements[i].Key == key) {
                return i;
            }
        }
        
        return -1;
    }

    //this function takes as argument any key and return the key and its' value or message that the key doesn't exist 
    DT at(K key) {
        int pos = find(key);
         if(pos == -1)
             
            throw std::out_of_range("The key doesn't exist");  
   
        return elements[pos].Data;
    }


    //check if the array is empty
//    bool isEmpty() {
//        
//        return (positionIndex == 0);
//    }

    //return the current size of the container
    int size() {
        return positionIndex;
    }

    //swap the current key with the last key and delete it
    void erase(K key) {
        int pos = find(key);
        elements[pos].Key = elements[positionIndex].Key;
        elements[pos].Data = elements[positionIndex].Data;
//        elements[positionIndex].Key = K();
//        elements[positionIndex].Data = DT();
        positionIndex--;
        
        
        
    }

};
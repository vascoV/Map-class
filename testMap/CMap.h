/*
 * This struct is used to group the Key and the Data under one element
 */
template <typename K, typename DT>
struct Elements {
    K Key;
    DT Data;
    
    friend std::ostream &operator<<(std::ostream &output, const Elements<K, DT> &pair){
        output << pair.Key << " " << pair.Data;
        return output;
    }
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
   
public:
    /*
     * Constructor: used to allocate memory for the array
     */
    CMap() {		//An initial map with a size of 10 potential elements.
        elements = (myElement*)calloc(arraySize, sizeof(myElement));
    }

    //Destructor used to free blocks of memory
    ~CMap() {
        free(elements);
        delete elements;
    }

    /*
     * adding elements onto the array, check for key repetition
     */
    void insert(K key, DT val) {
       
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

    //erase, remove the pair and move the position
    void erase(K key) {
        int pos = find(key);
        for(int i = pos; i < positionIndex; i++){
            elements[i].Key = elements[i + 1].Key;
            elements[i].Data = elements[i + 1].Data;
        }
        positionIndex--;
        //empry array
//        delete[] elements;
//        arraySize = 10;
//        positionIndex = 0;
//        elements = (myElement*)calloc(arraySize, sizeof(myElement));
        
        
        
//        elements[pos].Key = elements[positionIndex-1].Key;
//        elements[pos].Data = elements[positionIndex-1].Data;
////        elements[positionIndex].Key = K();
////        elements[positionIndex].Data = DT();
//        positionIndex--;
//        positionIndex--;
    }
    
    void print(){
        for(int i = 0; i < positionIndex; i++){
            std::cout << elements[i] << std::endl;
        }
    }
    
    /*
     * Quick sort function
     */
    void qSort(myElement* e, int left, int right){
        
        int i = left,
            j = right;
        
        myElement* tmp;
        
        int pivot = e[(i+j) / 2].Key; //finds the middle element of the array
        
        while ( i <= j){ //check the number of the left side with the right side and swap the smallest from the right to the left side
            while( e[i]->Key > pivot)
                i++;
            while( e[j]->Key > pivot)
                j++;
            //start swapping
            if(i <= j){
                tmp->Key = e[i]->Key;
		e[i]->Key = e[j]->Key;
		e[j]->Key = tmp->Key;
		i++;
		j--;
            }
            
            
        };
        /* recursion */
        if (left < j)
            qSort(e, left, j);
        if (i < right)
            qSort(e, i, right);
    }
    
    
    
//    void quickSort(Measurement measurements[], int left, int right)
//{
//	int i = left, j = right;
//	Measurement tmp;
//	int pivot = measurements[(i + j) / 2].theReading; // finds the middle element of the array
//
//	/* partition */
//	while (i <= j) { // check the number of the left side with the right side and swap the smallest from the right to the left sight
//		while (measurements[i].theReading < pivot) 
//			i++;
//		while (measurements[j].theReading > pivot)
//			j--;
//		// start swaping
//		if (i <= j) {
//			tmp.theReading = measurements[i].theReading;
//			measurements[i].theReading = measurements[j].theReading;
//			measurements[j].theReading = tmp.theReading;
//			i++;
//			j--;
//		}
//	};
//	/* recursion */
//	if (left < j)
//		quickSort(measurements, left, j);
//	if (i < right)
//		quickSort(measurements, i, right);
//}
};
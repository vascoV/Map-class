
template <typename K, typename DT>
class Element {
    private:
    K Key;
    DT Data;
    Element* next;
    public:
        Element(K &key, DT &data){
            this->Key = key;
            this->Data = data;
            next = nullptr;
        }
        
        K getKey(){
            return Key;
        }
        
        DT getData(){
            return Data;
        }
        
        Element* getNext(){
            return next;
        }
        
        void setData(DT data){
            this->Data = data;
        }
        
        void setNext(Element* next){
            this->next = next;
        }
//    friend std::ostream &operator<<(std::ostream &output, const Element<K, DT> &pair){
//        output << pair.Key << " " << pair.Data;
//        return output;
//    }
};

/*
 * The map class include methods and variable to work like a look up table
 */
template <typename K, typename DT>
class CMap
{
    typedef Element<K, DT> myElement;

/*
 *The private: only the class can access the data
 */    
private:
    myElement** elements;
    int arraySize;
    int positionIndex;
    
    
    
public:
    /*
     * Constructor: used to allocate memory for the array
     */
    CMap() {		
        arraySize = 10;
        positionIndex = 0;
        
        //An initial map with a size of 10 potential elements.
        elements = new myElement*[arraySize]();
   
//        for(int i = 0; i < arraySize; i++)
//        {
//           std::cout << elements[i] << std::endl; 
//        }    
    }

    //Destructor used to free blocks of memory
//    ~CMap() {
//        for(int i = 0; i <= positionIndex; i++){
//            delete elements[i];
//        }
//        delete elements;
//    }

    /*
     * Adding elements onto the array, check for key repetition
     */
    void insert(K key, DT val) {
       
        int pos = find(key); // 
       
        if(pos != -1){
            
            throw std::out_of_range("The key already exists");  
        }
        else{
            myElement* tmp= new myElement(key,val);
            elements[positionIndex]=tmp;
            positionIndex++;
        }

        //check if the array is full, if yes reallocates extra positions and memory
//        if (positionIndex == arraySize) {
//            extendSize(); //extend the array size
//        }
    }

    /*
     * Extend the array size
     */ 
    void extendSize() {
        int newSize = arraySize *2; //extend the array size
        myElement** newElements = new myElement*[arraySize]();
        memcpy(newElements, elements, arraySize*sizeof(myElement)); //copy the old array to the new array
        arraySize = newSize;
        delete[] elements;
        elements = newElements; //point the start of the newElements
    }


    /*
     * Function for checking if key already exist and return true and false correspondingly 
     */
//    bool keyExists(K key) {
//        for (int i = 0; i < arraySize; i++) {
//            if (elements[i].Key == key) {
//                return true;
//            }
//        }
//        return false;
//    }

    /*
     * Function to find the current key and return it
     */
    int find(K key) {
        for (int i = 0; i < positionIndex; i++) {
            if (elements[i]->getKey() == key) {
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
   
        return elements[pos]->getData();
    }
    

    //erase, remove the pair and move the position
    void erase(K key) {
        int pos = find(key);
        for(int i = pos; i < positionIndex; i++){
            elements[i]->getNext();
            elements[i]->getKey() = elements[i + 1]->getKey();
            elements[i]->getData() = elements[i + 1]->getData();
        }
        positionIndex--;
        
//******************************************************************************
        //empry array
//        delete[] elements;
//        arraySize = 10;
//        positionIndex = 0;
//        elements = (myElement*)calloc(arraySize, sizeof(myElement));
//******************************************************************************        
    }
    
    
    void print(){
        for(int i = 0; i < positionIndex; i++){
            std::cout << elements[i]->getKey() << " " << elements[i]->getNext() << std::endl;
        }
    }
    
    
    /*
     * Return the current size of the container 
     */
    int getSize() {
        return positionIndex;
    }
    
    
    /*
     * Quick sort function
     */
//    void qSort(int left, int right){
//        
//        int i = left,
//            j = right;
//        
//        K tmp;
//        
//        //myElement tmp;
//        int pivot = positionIndex/2;//this->size()/2; //finds the middle element of the array
//        
//        /*partitions*/
//        while ( i <= j){ //check the number of the left side with the right side and swap the smallest from the right to the left side
//            while(elements[i].Key < elements[pivot].Key)
//                i++;
//            while(elements[j].Key > elements[pivot].Key)
//                j++;
//            //start swapping 
//            if(i <= j){
//                tmp = elements[i].Key;
//                tmp = elements[i].Data;
//                
//		elements[i].Key = elements[j].Key;
//                elements[i].Data = elements[j].Data;
//                
//		elements[j].Key = tmp;
//                elements[j].Data = tmp;
//		i++;
//		j--;
//            }    
//        }
//        /* recursion */
//        if (left < j)
//            qSort(left, j);
//        if (i < right)
//            qSort(i, right);
//    }
       
};
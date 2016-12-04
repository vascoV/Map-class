template <typename K, typename DT>
struct Element{
    
   K key;
   DT data;
};

template <typename K, typename DT>
class CMap 
{
    
  typedef Element<K, DT> myElement;
    
  private:
    myElement* elements;
    int size = 10;
    int position = 0;
    
  public:

    CMap(){
        //An initial map with a size of 10 potential elements.
        elements = (myElement*)malloc(sizeof(myElement)*size);
        //elements = new myElement[size];
        //for(int i =0; i < size; i++)
        //{
          //  elements[i].key = NULL;
          //  elements[i].data = NULL;
            //elements[i].key = K();
            //elements[i].data = DT();
        //}
    }
    
    //destructor
    ~CMap(){
       free(elements); 
    }
    
    void insert(K key, DT val){
        int pos = find(key);
        if(keyExists(key) == true){
            std::cout << "The key "<< elements[pos].key << " already exists in the container!" << std::endl;
        }else{
            elements[position].key = key;
            elements[position].data = val;
            position++;
         }
        
        if(position == size - 2){
            extendSize();
        }
    }
    void print()
    {
        for(int i =0; i<position;i++)
        {
           std::cout << elements[i].key <<" "<< elements[i].data <<std::endl;
        }
    }
    
    void extendSize(){
        //int max = 4294967295;
       // if(sizeof(elements) < max && (sizeof(elements)*2)<max )
        //else
          //  std::cout<< " You have reached the maximum amount of memory" << std::endl;
        elements = (myElement*)realloc(elements, sizeof(myElement)*size*2);
        size*=2;
        for (int i = position + 2; i < size; i++){
            //elements[i].key = NULL;
            //elements[i].data = NULL;
            elements[i].key = K();
            elements[i].data = DT();
        }
           
    }
    
    K keyExists(K key){
        for(int i = 0; i < size; i++){
            if(elements[i].key == key){
                
                return true;
            }
        } 
        return false;
    }
    
    K find(K key){
        for(int i = 0; i < size; i++){
            if(elements[i].key == key){
                return i;
            }
        }
        return -1;
    }
    
    void at(K key){
        int pos = find(key);
        if(pos >= 0){
            std::cout << "Key " << elements[pos].key << " Found for value " << elements[pos].data << std::endl;
        }else{
            std::cout << "NO existing key" << std::endl;
        }
    }
    
    bool isEmpty() {
        if (position == 0)
            return true;
	else
            return false;
    }
    
    int capacity(){
        return position;
    }
    
    void erase(K key){
        for(int i = 0; i < position; i++){
            if(elements[i].key == key){
               std::cout << "Value " << elements[i].data << " with key " << elements[i].key << " is deleted " << std::endl;
               elements[i].key = elements[position-1].key;
               elements[i].data = elements[position-1].data;
               elements[position].key = K();
               elements[position].data = DT();
               position--;
            }
        }
    }
    
  
};

  
  
  

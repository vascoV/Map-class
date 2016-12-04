template <typename K, typename DT>
struct Element{
    
   K key;
   DT data;
};

template <typename K, typename DT>
class CMap 
{
  public:
    typedef Element<K, DT> myElement;

    CMap(){
        //An initial map with a size of 10 potential elements.
        //position = 0;
        //size = 10;
        elements = (myElement*)malloc(sizeof(myElement)*size);
        for(int i =0; i<size;i++)
        {
            elements[i].data = NULL;
            elements[i].key = NULL;
        }
    }
    
    //destructor
    ~CMap(){
       free(elements); 
    }
    
    void insert(K key, DT val){
        if(keyExists(key) == true){
            std::cout << " This key already exists " << std::endl;
        }else{
            elements[position].key = key;
            elements[position].data = val;
            position++;
         }
        if(position == size - 2){
            resize();
        }
    }
    void print()
    {
        for(int i =0; i<position;i++)
        {
           std::cout << elements[i].key <<" "<< elements[i].data <<std::endl;
        }
    }
    
    void resize(){
        //int max = 13010121;
       // if(sizeof(elements) < max && (sizeof(elements)*2)<max )
        //else
          //  std::cout<< " You have reached the maximum amount of memory" << std::endl;
        elements = (myElement*)realloc(elements, sizeof(myElement)*size*2);
        size*=2;
        for (int i = position + 2; i < size; i++){
            elements[i].key = NULL;
            elements[i].data = NULL;
        }
           
    }
    
    bool keyExists(K key){
        for(int i = 0; i < size; i++){
            if(elements[i].key == key){
                
                return true;
            }
        } 
        return false;
    }
    
    int find(K key){
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
    
    K capacity(){
        return position;
    }
    
    void pop(){
        if(!isEmpty()){
            position--;
        }
    }
    
    void erase(K key){
        for(int i = 0; i < position; i++){
            if(elements[i].key == key){
               std::cout << "Value " << elements[i].data << " with key " << elements[i].key << " is deleted " << std::endl;
               elements[i].key = elements[position-1].key;
               elements[i].data = elements[position-1].data;
               elements[position].key = 0;
               elements[position].data = 0;
               position--;
            }
        }
    }
    
  private:
    myElement* elements;
    int size = 10;
    int position = 0;
};

  
  
  

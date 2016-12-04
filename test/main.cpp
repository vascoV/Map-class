template <typename K, typename DT>
class Element
{
  public:
    K key;
    DT data;
};

template <typename K, typename DT>
class myMap 
{
  public:
    typedef Element<K, DT> myElement;

    myMap();
    void insert (K const & key, DT const & val);

  private:
    myElement  *elements;
    int size;
};

  template <typename K, typename DT>
myMap<K, DT>::myMap()
{
  //An initial map with a size of 10 potential elements.
  size = 10;
  elements = new myElement[size];    
}

  template <typename K, typename DT>
void myMap<K, DT>::insert(const K &key, const DT &val)
{
  elements[0].key = key;
  elements[0].data = val;
}
 

#include <string>

int main () {
  myMap<int, std::string> foo;
  foo.insert (5, "cat");

  return 0;
}
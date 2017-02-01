package concurrencyassignmentpart1;


public class Sleight {
    
    private final Present [] sleight;
    private int nextIn = 0; //next empty slot in the sleight (buffer)
    private static  int Sleight_Size;
    
    public Sleight(int size){
        sleight = new Present[size];
        Sleight_Size = size;
    }
    
    /**
      * Add a value to the buffer.  If the buffer is full, 
      */
    public void addToSleight(Present item){
        
        nextIn++;
        sleight[nextIn-1] = item; //if 120 so you are 119
        
//        System.out.println("Producing Gifts: " + "\t" + "counter: " + nextIn);
    }
    
    public Present extract(){
        
        Present item = sleight[nextIn-1];
        nextIn--;
        
//         System.out.println("Remove Gifts: " + "\t" + "counter: " + nextIn);
        
        return item;
    }
    
    public boolean isFull(){
        
        boolean sleightFull = true;
        
        sleightFull = nextIn == Sleight_Size;
        
        return sleightFull;
    }
    
    public boolean isEmpty(){
       
        boolean sleightEmpty = true;
        
        sleightEmpty = nextIn == 0;
        
        return sleightEmpty;
    }
    
    public int numOfToys(){
       
        int i;
        
        i = nextIn;
        
        return nextIn;
    }
    
    public int getCounter(){
        return nextIn;
    }
}
package concurrencyassignmentpart1;

import java.util.concurrent.Semaphore;

public class Sleight {
    private final Present [] sleight;
    private int nextIn = 0; //next empty slot in the sleight (buffer)
//    private int nextOut = 0; //next available data slot
//    private int count = 0;
//    
    private static final int Sleight_Size = 120;
//    private final Semaphore mutex = new Semaphore(1); //provides limited access to the sleight (buffer) (mutual exclusion)
//    public final Semaphore numAvail = new Semaphore(0); //indicated the number of item that are ready to be consumed
//    private final Semaphore numFree; //indicates the number of free buffer slots 
    
    
    public Sleight(){
        
        sleight = new Present[Sleight_Size];
//        numFree = new Semaphore(Sleight_Size);//array begins with all empty elements
    }
    
    /**
	 * Add a value to the buffer.  If the buffer is full, 
	 * it waits until there is room in the buffer
         */
    public void addToSleight(Present item){
        
        
        nextIn++;
        sleight[nextIn-1] = item; //if 120 so you are 119
        
        System.out.println("Elfs are producing Gifts: " + "\t" + item + "\t" + "counter: " + nextIn);
        
        
        
        
        

//        while(items == full){
//            //do nothing, if the buffer item canno be used (because full)
//        }
 
//        try {
//            /**
//             * Keep track of number of empty elements (value--)
//             * This provides synchronization for the producer,
//             * because this makes stop running when sleight (buffer) is full
//             */
//            numFree.acquire();
//            mutex.acquire(); //mutual exclusion 
//        
//        } catch (InterruptedException ex) {
//            System.out.println("Error in addToSleight(): " + ex);
//        }
//        
//        //add item to the sleight (buffer)
//        ++count;
//        sleight[nextIn] = item;
////        items++;
//
//        nextIn = (nextIn+1) % Sleight_Size;
//        
//        //sleight (buffer information feedback)
//        if(count == Sleight_Size){
//            System.out.println("BUFFER FULL "
//               + "Producer inserted \"" + item 
//               + "\" count=" + count + ", "
//               + "in=" + nextIn + ", out=" + nextOut);
//        } else {
//            System.out.println("Producer inserted \"" + item 
//               + "\t" +"\" count=" + count + ", "
//               + "in=" + nextIn + ", out=" + nextOut);
//        }
//        
////        try {
////        
////            Thread.sleep((int) (Math.random() * 10));
////        
////        } catch (InterruptedException ex) {}
////        
////        nextIn++;
////        
////        if(nextIn == sleight.length){
////          //elf should wait if the statemen is true
////            nextIn = 0;
////        
////        }
//        
//        mutex.release(); //mutual exclusion
//        numAvail.release(); //if buffer was empty then this wakes up the consumer 
    }
    
    public Present extract(){
        
        Present item = sleight[nextIn-1];
        nextIn--;
        
         System.out.println("Santas are removing Gifts: " + "\t" + item + "\t" + "counter: " + nextIn);
        
        return item;
        
        
        
//        Present item = null;
//        
////        while(count==0){
////            //if nothing in the buffer then do nothing
////            //the buffer array cannot be used beacause is empty
////        }
//        try {
//        
//            numAvail.acquire();
//            mutex.acquire();
//        
//        } catch (InterruptedException ex) {
//             System.out.println("ERROR in try(): " + ex);
//        }
//        
//        //remove item from the sleight (buffer)
//        --count;
//        item = sleight[nextOut];
//        
//        nextOut = (nextOut + 1) % Sleight_Size;
//        
////        buffer information feedback
//          if(count == 0){
//              System.out.println("BUFFER EMPTY "
//               + "Consumer removed \"" + item 
//               + "\t" + "\" count=" + count + ", "
//               + "in=" + nextIn + ", out=" + nextOut);
//          } else {
//              System.out.println("Consumer removed \"" + item 
//               + "\" count=" + count + ", "
//               + "in=" + nextIn + ", out=" + nextOut);
//          }
////        Present res ;
////        res = sleight[nextOut];
////        count--;
////        
////        try {
////            
////            Thread.sleep((int) (Math.random() * 10));
////            
////        } catch (InterruptedException ex) {}
////
////            
////        nextOut++;
////        
//        //Only GOD knows
////        if (nextOut==sleight.length)
////            nextOut=0;
////        
//        
//        mutex.release();
//        numFree.release();
//        return item;
    }
    
    public boolean isFull(){
        
        boolean sleightFull = true;
        
       
//            mutex.acquire();
            sleightFull = nextIn == Sleight_Size;
        
        
//        } finally {
//            mutex.release();
//        }
        
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
package concurrencyassignmentpart1;


import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

public class Elf extends Thread {

    Clock clock = Clock.getInstance();

    Sleight sleight;
    String elf_id;
    
    private final int rand = 1000;
    int toyCount = 0;

    int ticksWaiting = 0;
//    int reports = 0;
    
    int hCount = 0;
    int hTicks = 0;

    /**
     * Arbitrary list with toys 
     */
    private static final String[] toys = { "Doll", "Train", "Car", "Dinosaur", "Drums", "Barbie", "Drone", "Guitar", "Puzzle", "Tablet", "PC" };

    /**
     * output to a txt file
     */
    PrintWriter writer;
    private int lastPrint = 0;

    public Elf(String name, Sleight s) {
        
        this.elf_id = name;
        sleight = s;

        try {
            
            /**
             * Each text file has the name of the corresponding elf
             */
            writer = new PrintWriter("Elf-" + elf_id + ".txt", "UTF-8");
            
        } catch (FileNotFoundException | UnsupportedEncodingException ex) {
            
            System.out.println("Error in writing to file:" + "\t" + elf_id);
        }
    }

    
    private void Produce(Present p) {
        sleight.addToSleight(p);
    }
    
    @Override
    public void run() {
        while (!clock.isStopped()) {
           
//            report();

            /**
             * Choosing toys from the shelves
             * of the toy department
             */
            try {
                
                sleep((int) (Math.random() * rand));
                
            } catch (InterruptedException ex) {}
            
//            report();

            /**
             * Storing a random toy from the toys array
             * into the toy variable of type String
             */
            String toy = toys[(int) (Math.random() * toys.length)];

            /**
             * boolean variable for detecting if
             * it is boy or girl
             * it return a random boolean true or false
             */
            boolean gender;
            boolean colour;
            colour = Math.random() < 0.5;
            gender = Math.random() < 0.5;
            
            writer.println(clock.toString() + "Elf " + elf_id + "\t" + "Selected toy " + toy + " for " +(gender?"boy":"girl"));
            
            /**
             * Wrapping toy in a corresponding paper
             */
            try {
                
                sleep((int) (Math.random() * rand)); //pause the thread for random period of time
                
            } catch (InterruptedException ex) {}
            
//            report();
                        
            Present p = new Present(toy, gender, colour);

            writer.println(clock.toString() + "Elf " + elf_id + "\t" + "Wrapped toy " + toy + " in "+ (gender?(colour? "blue":"red"):(colour? "pink" : "silver")) + " wrapping paper");

            synchronized(sleight){
                if(clock.isStopped()) { break; }
                int startTime = clock.getTick();
                while(sleight.isFull() && clock.getState() != Thread.State.TERMINATED){
                    
                    try{
                        System.out.println(elf_id + " is" + " Waiting....");
                        sleight.wait();
                    } catch (InterruptedException ex){}
                }
                sleight.notifyAll();
                int endTime = clock.getTick();
                ticksWaiting += endTime - startTime;
                if(!sleight.isFull()){ 
                    Produce(p);
                }
                
               
            }

            writer.println(clock.toString() + "Elf " + elf_id + "\t" + "Placed toy " + toy + " on sleigh");
            toyCount++;
            hCount++;
            if((int) (clock.getTick()/60) > lastPrint){
//                report();
                lastPrint++;
            }
        }
        writer.close();
    }

    public void output() {
        System.out.println("Elf " + elf_id + "\t" +"Number of gifts wrapped: " + toyCount);
        System.out.println("Elf " + elf_id + "\t" +"Time Spent waiting: " + ticksWaiting + " minutes" + "\n");
    }

    public void report() {
        System.out.println();
        String report = "Hourly Report: " + clock.getTick()/60 + " " + "Elf " + elf_id + "has wrapped " + hCount + " and have waited " + ticksWaiting;
        System.out.println(report);
        System.out.println();
    }
}
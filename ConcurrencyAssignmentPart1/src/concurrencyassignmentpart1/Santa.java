package concurrencyassignmentpart1;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class Santa extends Thread {

    Clock clock = Clock.getInstance();

    Sleight buf;
    String santa_id;

    List<Present> sack;

    private final int rand = 1000;
    private final int Sack_Capacity = 10;

    int toyCount = 0;
    
    int ticksWaiting = 0;
    int reports = 0;

    int hTicks = 0;
    int hCount = 0;

    PrintWriter writer;
    
    public Santa(String name, Sleight s) {
        
        this.sack = new ArrayList<>();
        buf = s;
        this.santa_id = name;

        try {
            
            /**
             * Each text file has the name of the corresponding Santa
             */
            writer = new PrintWriter("Santa-" + santa_id + ".txt", "UTF-8");
        
        } catch (FileNotFoundException | UnsupportedEncodingException ex) {
        
            System.out.println("Error in writing to file" + "\t" + santa_id);
        }
    }

    public Present consume() {
        
        Present nextItem = buf.extract();
        return nextItem;
    }

    @Override
    public void run() {
        
        while (!clock.isStopped()) {
        
            report();
            
            while(sack.size() < Sack_Capacity ) {
                
                synchronized(buf){ 
                    int startTime = clock.getTick();
                    while(buf.isEmpty() && clock.getState() != Thread.State.TERMINATED){

                        try{
                            System.out.println(santa_id + " is" + "waiting....");
                            buf.wait();
                        } catch (InterruptedException ex){}
                    }
                    int endTime = clock.getTick();
                    ticksWaiting += endTime - startTime;
//                    if(buf.getCounter() >= 6){
                        Present s = consume();
                        writer.println(clock.toString() + "Santa " + santa_id + "\t" +"Took toy " + s + " from sleigh.");
                        sack.add(s);
//                    }
                    buf.notify();
                }
                
                if(sack.size() >= 6 && buf.isEmpty()){      
                    break;
                }
            }

//            while(sack.size() < Sack_Capacity){
//                
//                 boolean isEmpty = buf.isEmpty();
//                int diff = 0;
//            
//                if (isEmpty) {
//                
//                    diff = clock.getTick();
//                }
//
//                Present s = consume();
//
//                if (isEmpty) {
//                    
//                    diff = (clock.getTick() - diff);
//                    ticksWaiting += diff;
//                    hTicks += diff;
//                }
//                
//                 writer.println(clock.toString() + "Santa " + santa_id + "\t" +"Took toy " + s + " from sleigh.");
//                 sack.add(s);
//                    
//                if(sack.size() >= 6 && buf.isEmpty()){
//                   
//                    break;
//                }
//            }
            
            /**
             * Santa need some time to Walk back
             * to his own department
             */
            try {
                
//                sleep((int) (Math.random() * rand));
               sleep(ThreadLocalRandom.current().nextInt(1000, 3000));     
            } catch (InterruptedException ex) {}
            
            report();

            writer.println(clock.toString() + "Santa " + santa_id + "\t" +"Walked back to his own allocated department");
      

            for (Iterator<Present> i = sack.iterator(); i.hasNext() && !clock.isStopped();) {
               
                /**
                 * Santa spent some time with child
                 * to give presents
                 */
                try { 
                
//                    sleep((int) (Math.random() * rand));
                    sleep(ThreadLocalRandom.current().nextInt(1000, 2000)); 
                } catch (InterruptedException ex) {}

                report();

                Present g = i.next();

                writer.println(clock.toString() + "Santa " + santa_id + "\t" +"Gives Toy " + g);
                
                i.remove();
                toyCount++;
                hCount++;
            }
            
             /**
             * Santa need some time to Walk back
             * to the toy department
             */
            try {
                
                sleep((int) (Math.random() * rand));
            } catch (InterruptedException ex) {}
            
            report();

            writer.println(clock.toString() + "Santa " + santa_id + "\t" +"Walked back to the Toy Store!");
        }
        writeSantaReport();
        writer.close();
    }

    public void report() {
        if (clock.getTick() > 60 * (reports + 1)) {

            writeSantaReport();

            /**
             * hourly ticks and count is reseted 
             * for the next hour
             */
            hTicks = 0;
            hCount = 0;
            reports++;
        }
    }

    public void output() {
        System.out.println("Santa " + santa_id + "\t" + "Number of gifts gave: " + toyCount);
        System.out.println("Santa " + santa_id + "\t" + "Time Spent waiting: " + ticksWaiting + " minutes");
        System.out.println("Santa " + santa_id + "\t" + "Toys left in bag: " + sack.size() + "\n");
    }

    public void writeSantaReport() {
        writer.println();
        writer.println("************** Hourly Report **************");
        writer.println("Santa " + santa_id + "\t" + "Number of gifts given this hour: " + hCount);
        writer.println("Santa " + santa_id + "\t" + "Time Spent waiting duirng this hour: " + hTicks + " minutes");
        writer.println("************************************************************************");
        writer.println();
    }
}

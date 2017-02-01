package concurrencyassignmentpart1;

public class ConcurrencyAssignmentPart1 {

    public static void main(String[] args) {
        
        System.out.println("Start of the Working Day" + "\n");
        
        Clock clock = Clock.getInstance();
        
        /**
         * Constructor passes the max number 
         * of gifts in to the sleight
         */
        Sleight sleight = new Sleight(120);

        Santa santa1 = new Santa("Kevin", sleight);
        Santa santa2 = new Santa("Richard", sleight);
        Santa santa3 = new Santa("Martin", sleight);
        
        Elf elf_1 = new  Elf("Bushy Evergreen", sleight);
        Elf elf_2 = new Elf("Pepper Minstix", sleight);
        Elf elf_3 = new Elf("Alabaster Snowball", sleight);
        Elf elf_4 = new Elf("Sugarplum Mary", sleight);
        Elf elf_5 = new Elf("Wunorse Openslae", sleight);
        
        /**
         * Begin execution of the threads
         */
        santa1.start();
        santa2.start();
        santa3.start();
        
        elf_1.start();
        elf_2.start();
        elf_3.start();
        elf_4.start();
        elf_5.start();
        
        clock.start();
        
//        while(clock.getState() != Thread.State.TERMINATED){
//            
//            if ((clock.getTick() % 60) == 0 && clock.getTick()!=0){ 
//                try {
//                   Thread.sleep(200);
//                    
//                } catch (Exception e) {
//                }
//
//                elf_1.writeElfReport();
//            }
//        }
        
        /**
         * Causes the current thread 
         * to pause execution until 
         * each thread terminates
         */
        try {
            
            elf_1.join();
            elf_2.join();
            elf_3.join();
            elf_4.join();
            elf_5.join();
            
            santa1.join();
            santa2.join();
            santa3.join();
            
        } catch (InterruptedException ex) { }
       
        
        
        /**
         * Output on the console the 
         * activities of the day
         */
        elf_1.output();
        elf_2.output();
        elf_3.output();
        elf_4.output();
        elf_5.output();
        
        System.out.println("\n");
        
        santa1.output();
        santa2.output();
        santa3.output();
        
        System.out.println("\n");
        System.out.println("Toys left into the sleigh at the end of the day: " + sleight.numOfToys() + "\n");
        System.out.print("\n");
        System.out.println("End of the Working Day");
    }
}

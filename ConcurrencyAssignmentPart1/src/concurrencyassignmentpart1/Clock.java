package concurrencyassignmentpart1;

public class Clock extends Thread {

    private volatile int count = 0;
    boolean stop = false;
    final int MAXTICK = 60 * 8;
    final int TICKTIME = 1000;

    boolean finished = false;

    private Clock() {

    }

    private static class InstanceHolder {

        private static final Clock instance = new Clock();
    }

    public static Clock getInstance() {
        return InstanceHolder.instance;
    }

    public int getTick() {
        return count;
    }

    public void start() {
        run();
    }

    public boolean isHour() {
        return count % 60 == 0;
    }

    public boolean isStopped() {
        return finished;
    }

    @Override
    public void run() {

        while (count < MAXTICK) {
            
            count++;
            
            try {
            
                Thread.sleep(TICKTIME);
            } catch (InterruptedException ex) {}
        }
        
        finished = true;
    }

    @Override
    public String toString() {
        return "Time " + count + ": ";
    }

}

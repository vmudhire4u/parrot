package com.zpcat.sample;

public class SleepCommand implements Command {

    private Command mWakeupCommand = null;
    private ActiveObjectEngine engine = null;
    private long sleepTime = 0;
    private long startTime = 0;
    private boolean started = false;
    
    public SleepCommand(long milliseconds, ActiveObjectEngine e, 
            Command wakeupCommand) {
        sleepTime = milliseconds;
        engine = e;
        mWakeupCommand = wakeupCommand;
    }
    
    @Override
    public void execute() throws Exception {
        long currentTime = System.currentTimeMillis();
        
        if (!started) {
            started = true;
            startTime = currentTime;
            engine.addCommand(this);
        } else if ((currentTime - startTime) < sleepTime) {
            engine.addCommand(this);
        } else {
            engine.addCommand(mWakeupCommand);
        }

    }

}

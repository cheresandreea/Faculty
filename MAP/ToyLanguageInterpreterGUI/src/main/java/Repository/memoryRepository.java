package Repository;

import Model.Exceptions.MyException;
import Model.State.programState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class memoryRepository implements iRepository
{
    List<programState> programStatesQueue;
    String logFilePath;

    public String getLogFilePath() {
        return logFilePath;
    }

    public memoryRepository(String logFilePath)
    {
        this.programStatesQueue = new ArrayList<>();
        this.logFilePath = logFilePath;

    }

    @Override
    public void setProgramState(List<programState> prg)
    {
        this.programStatesQueue = prg;
    }

    @Override
    public List<programState> getProgramList() {
        return this.programStatesQueue;
    }

    @Override
    public void setProgramList(List<programState> prg) {
        this.programStatesQueue = prg;
    }

//    public programState getCurrentProgramState() throws MyException
//    {
//        return this.currentProgramState;
//    }
    @Override
    public void addProgramState(programState newProgramState) {
        programStatesQueue.add(newProgramState);
    }

    @Override
    public void logProgramStateExecution(programState prgstate) throws MyException
    {
        PrintWriter logFile = null;
        try
        {
            logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
            logFile.println(prgstate.toString());

        }
        catch (Exception exception)
        {
            throw new MyException(exception.getMessage());
        }
        finally
        {
            if (logFile != null)
                logFile.close();
        }
    }

    public void clearLogFile() throws MyException
    {
        PrintWriter logFile = null;
        try
        {
            logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, false)));
            logFile.println("");

        }
        catch (Exception exception)
        {
            throw new MyException(exception.getMessage());
        }
        finally
        {
            if (logFile != null)
                logFile.close();
        }
    }

}

package Repository;

import Model.Exceptions.MyException;
import Model.State.programState;

import java.util.List;

public interface iRepository
{
    void setProgramState(List<programState> prg);

    List<programState> getProgramList();

    void setProgramList(List<programState> prg);

    //    public programState getCurrentProgramState() throws MyException
    //    {
    //        return this.currentProgramState;
    //    }
    void addProgramState(programState newProgramState);

    //programState getCurrentProgramState() throws MyException;
    void logProgramStateExecution(programState prgstate) throws MyException;

    void clearLogFile() throws MyException;
}

package Controller;

import Model.Exceptions.MyException;
import Model.State.programState;

import java.util.List;

public interface iController
{
    //programState executeOneStep(programState state) throws MyException;
    //programState executeAll(programState state) throws MyException;


    void executeAll(List<programState> prgList) throws InterruptedException;
}

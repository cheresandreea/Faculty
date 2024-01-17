package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.iType;

public interface iStatement
{
    iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException;
    programState execute(programState state) throws ExecutionException, EvaluationException;
    iStatement deepCopy();

}

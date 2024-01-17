package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.iType;

public class noOperationStatement implements iStatement
{
    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state)
    {
        return null;
    }

    @Override
    public String toString()
    {
        return "No operation";
    }

    @Override
    public iStatement deepCopy()
    {
        return new noOperationStatement();
    }
}

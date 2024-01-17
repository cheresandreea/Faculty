package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Structures.iStack;
import Model.Structures.iDictionary;
import Model.State.programState;
import Model.Types.iType;


public class compoundStatement implements iStatement
{
    iStatement one;
    iStatement two;

    @Override
    public  String toString()
    {
        return "(" + one.toString() + "; " + two.toString() + ")";
    }

    public compoundStatement(iStatement one, iStatement two)
    {
        this.one = one;
        this.two = two;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        return two.typeCheck(one.typeCheck(typeEnvironment));
    }

    @Override
    public programState execute(programState state) throws EvaluationException
    {
        iStack<iStatement> stack = state.getExecutionStack();
        stack.push(two);
        stack.push(one);
        return null;
    }

    @Override
    public iStatement deepCopy()
    {
        return new compoundStatement(one.deepCopy(), two.deepCopy());
    }

}

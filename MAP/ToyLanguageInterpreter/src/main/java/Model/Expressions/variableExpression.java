package Model.Expressions;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Values.iValue;


public class variableExpression implements iExpression
{
    private final String variable;

    public variableExpression(String variable)
    {
        this.variable = variable;
    }

    @Override
    public iType typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException {
        return typeEnvironment.lookup(variable);
    }

    @Override
    public iValue evaluate(iDictionary<String, iValue> table, iHeap<Integer, iValue> heap) throws EvaluationException
    {
        return table.getValue(variable);
    }

    public String toString()
    {
        return variable;
    }

    @Override
    public iExpression deepCopy()
    {
        return new variableExpression(variable);
    }
}

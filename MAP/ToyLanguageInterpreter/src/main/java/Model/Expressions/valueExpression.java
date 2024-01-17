package Model.Expressions;

import Model.Exceptions.EvaluationException;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Values.iValue;


public class valueExpression implements  iExpression
{
    public iValue value;

    public valueExpression(iValue value)
    {
        this.value = value;
    }

    @Override
    public iType typeCheck(iDictionary<String, iType> typeEnvironment) {
        return value.getType();
    }

    @Override
    public iValue evaluate(iDictionary<String, iValue> table, iHeap<Integer, iValue> heap) throws EvaluationException
    {
        return value;
    }

    public String toString()
    {
        return value.toString();
    }

    @Override
    public iExpression deepCopy()
    {
        return new valueExpression(value.deepCopy());
    }

}

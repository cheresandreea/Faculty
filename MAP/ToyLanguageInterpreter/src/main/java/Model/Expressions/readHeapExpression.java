package Model.Expressions;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Types.refType;
import Model.Values.iValue;
import Model.Values.refValue;

public class readHeapExpression implements iExpression
{
    private iExpression expression;

    public readHeapExpression(iExpression expression)
    {
        this.expression = expression;
    }

    @Override
    public String toString()
    {
        return "readHeap(" + expression.toString() + ")";
    }

    @Override
    public iType typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException {
        iType typ = expression.typeCheck(typeEnvironment);
        if (typ instanceof refType)
        {
            refType refTyp = (refType) typ;
            return refTyp.getInner();
        }
        else
            throw new MyException("Expression is not of type reference!");

    }

    @Override
    public iValue evaluate(iDictionary<String, iValue> table, iHeap<Integer, iValue> heap) throws EvaluationException
    {
        iValue value = expression.evaluate(table, heap);
        if (!(value instanceof refValue))
            throw new EvaluationException("Expression is not of type reference!");

        int address = ((refValue) value).getAddr();
        if (!heap.isDefined(address))
            throw new EvaluationException("Address is not defined in heap!");

        try
        {
            return heap.get(address);
        }
        catch (MyException e)
        {
            throw new RuntimeException(e);
        }
    }

    @Override
    public iExpression deepCopy()
    {
        return new readHeapExpression(expression.deepCopy());
    }
}

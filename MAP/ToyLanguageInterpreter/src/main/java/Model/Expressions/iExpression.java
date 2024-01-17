package Model.Expressions;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Values.iValue;

public interface iExpression
{
    iType typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException;
    iValue evaluate(iDictionary<String, iValue> table, iHeap<Integer, iValue> heap) throws EvaluationException;

    iExpression deepCopy();
}

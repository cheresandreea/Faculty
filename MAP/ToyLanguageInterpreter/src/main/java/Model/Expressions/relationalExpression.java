package Model.Expressions;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.boolType;
import Model.Types.iType;
import Model.Types.intType;
import Model.Values.iValue;
import Model.Values.intValue;
import Model.Values.boolValue;

public class relationalExpression implements iExpression
{
    iExpression firstExpression;
    iExpression secondExpression;
    String operator;

    public relationalExpression(iExpression firstExpression, iExpression secondExpression, String operator)
    {
        this.firstExpression = firstExpression;
        this.secondExpression = secondExpression;
        this.operator = operator;
    }

    @Override
    public String toString()
    {
        return firstExpression.toString() + " " + operator + " " + secondExpression.toString();
    }

    @Override
    public iType typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException {
        iType typ1, typ2;
        typ1 = firstExpression.typeCheck(typeEnvironment);
        typ2 = secondExpression.typeCheck(typeEnvironment);
        if (typ1.equals(new intType()))
        {
            if (typ2.equals(new intType()))
                return new boolType();
            else
                throw new MyException("Second operand is not an integer!");
        }
        else
            throw new MyException("First operand is not an integer!");
    }

    @Override
    public iValue evaluate(iDictionary<String, iValue> table, iHeap<Integer, iValue> heap) throws EvaluationException
    {
        iValue value1, value2;
        value1 = firstExpression.evaluate(table, heap);
        if (value1.getType().equals(new intType()))
        {
            value2 = secondExpression.evaluate(table, heap);
            if (value2.getType().equals(new intType()))
            {
                intValue intValue1 = (intValue) value1;
                intValue intValue2 = (intValue) value2;
                int number1, number2;
                number1 = intValue1.getValue();
                number2 = intValue2.getValue();
                switch (operator)
                {
                    case "<":
                        return new boolValue(number1 < number2);
                    case "<=":
                        return new boolValue(number1 <= number2);
                    case "==":
                        return new boolValue(number1 == number2);
                    case "!=":
                        return new boolValue(number1 != number2);
                    case ">":
                        return new boolValue(number1 > number2);
                    case ">=":
                        return new boolValue(number1 >= number2);
                    default:
                        throw new EvaluationException("Invalid operator!");
                }
            }
            else
                throw new EvaluationException("Second operand is not an integer!");
        }
        else
            throw new EvaluationException("First operand is not an integer!");
    }



    @Override
    public iExpression deepCopy()
    {
        return new relationalExpression(firstExpression.deepCopy(), secondExpression.deepCopy(), operator);
    }
}

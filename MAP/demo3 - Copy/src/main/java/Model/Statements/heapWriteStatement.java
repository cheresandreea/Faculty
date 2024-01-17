package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.iType;
import Model.Types.refType;
import Model.Values.iValue;
import Model.Values.refValue;

public class heapWriteStatement implements iStatement
{
    String var_name;
    iExpression expression;

    public heapWriteStatement(String var_name, iExpression expression)
    {
        this.var_name = var_name;
        this.expression = expression;
    }

    @Override
    public String toString()
    {
        return "writeHeap(" + var_name + ", " + expression.toString() + ");";
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        iType typeVar = typeEnvironment.getValue(var_name);
        iType typeExp = expression.typeCheck(typeEnvironment);
        if (!typeVar.equals(new refType(typeExp)))
            throw new EvaluationException("Variable and expression do not have the same type!");
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws EvaluationException
    {
        if (!state.getSymbolTable().isDefined(var_name))
            throw new EvaluationException("Variable is not defined!");

        iValue value = state.getSymbolTable().getValue(var_name);
        if (!(value.getType() instanceof refType))
            throw new EvaluationException("Variable is not of type reference!");

        refValue ref_value = (refValue) value;
        int address = ref_value.getAddr();
        if (!state.getHeap().isDefined(address))
            throw new EvaluationException("Address is not defined in heap!");

        iValue expression_value = expression.evaluate(state.getSymbolTable(), state.getHeap());
        if (!expression_value.getType().equals(ref_value.getInner()))
            throw new EvaluationException("Type of expression and type of variable do not match!");

        try
        {
            state.getHeap().update(address, expression_value);
        }
        catch (MyException e)
        {
            throw new RuntimeException(e);
        }

        return null;
    }

    @Override
    public iStatement deepCopy()
    {
        return new heapWriteStatement(var_name, expression.deepCopy());
    }


}

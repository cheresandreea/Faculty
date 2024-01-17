package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Values.iValue;
import Model.Expressions.iExpression;


public class printStatement implements iStatement
{
    private iExpression expression;

    public printStatement(iExpression expression)
    {
        this.expression = expression;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        expression.typeCheck(typeEnvironment);
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        iDictionary<String, iValue> symbolTable = state.getSymbolTable();
        iHeap<Integer, iValue> heap = state.getHeap();
        iValue value = expression.evaluate(symbolTable, heap);
        state.getOutput().append(value);
        return null;
    }

    @Override
    public String toString()
    {
        return "print(" + expression.toString() + ")";
    }

    @Override
    public iStatement deepCopy()
    {
        return new printStatement(expression.deepCopy());
    }
}

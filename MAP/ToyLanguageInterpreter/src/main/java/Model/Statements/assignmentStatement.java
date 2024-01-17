package Model.Statements;

import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Values.iValue;
import Model.Structures.iDictionary;

public class assignmentStatement implements iStatement
{
    private String variableName;
    private iExpression expression;

    public assignmentStatement(String variableName, iExpression expression)
    {
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException {
        iType variableType = typeEnvironment.lookup(variableName);
        iType expressionType = expression.typeCheck(typeEnvironment);
        if (variableType.equals(expressionType))
            return typeEnvironment;
        else
            throw new MyException("Assignment: right hand side and left hand side have different types!");
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        iDictionary<String, iValue> symbolTable = state.getSymbolTable();
        iHeap<Integer, iValue> heap = state.getHeap();
        iValue value = expression.evaluate(symbolTable, heap);
        if (symbolTable.containsKey(variableName))
        {
            iType variableType = (symbolTable.getValue(variableName)).getType();
            if (value.getType().equals(variableType))
                symbolTable.update(variableName, value);
            else
                throw new ExecutionException("Declared type of variable " + variableName + " and type of the assigned expression do not match!");
        }
        else
            throw new ExecutionException("The used variable " + variableName + " was not declared before!");
        return null;
    }

    @Override
    public String toString()
    {
        return variableName + "=" + expression.toString();
    }

    @Override
    public iStatement deepCopy()
    {
        return new assignmentStatement(variableName, expression.deepCopy());
    }
}

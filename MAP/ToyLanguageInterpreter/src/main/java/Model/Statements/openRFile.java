package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.iType;
import Model.Types.stringType;
import Model.Values.stringValue;
import Model.Values.iValue;

public class openRFile implements iStatement
{
    iExpression expression;

    public openRFile(iExpression expression)
    {
        this.expression = expression;
    }

    @Override
    public String toString()
    {
        return "openRFile(" + expression.toString() + ");";
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        iType typeExpression = expression.typeCheck(typeEnvironment);
        if (typeExpression.equals(new stringType()))
            return typeEnvironment;
        else
            throw new MyException("Expression is not a string");
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        iValue typeCheck = expression.evaluate(state.getSymbolTable(), state.getHeap());
        if (!typeCheck.getType().equals(new stringType()))
            throw new ExecutionException("Expression is not a string");

        stringValue fileName = (stringValue) typeCheck;
        if (state.getFileTable().isDefined(fileName.getValue()))
            throw new ExecutionException("File already opened");

        try
        {
            java.io.BufferedReader bufferedReader = new java.io.BufferedReader(new java.io.FileReader(fileName.getValue()));
            state.getFileTable().put(fileName.getValue(), bufferedReader);
        }
        catch (java.io.FileNotFoundException exception)
        {
            throw new ExecutionException("File does not exist");
        }
        return null;
    }

    @Override
    public iStatement deepCopy()
    {
        return new openRFile(expression.deepCopy());
    }
}

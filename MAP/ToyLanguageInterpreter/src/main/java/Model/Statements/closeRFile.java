package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.iType;
import Model.Types.stringType;
import Model.Values.iValue;
import Model.Values.stringValue;

import java.io.BufferedReader;

public class closeRFile implements iStatement
{
    iExpression expression;

    public closeRFile(iExpression expression)
    {
        this.expression = expression;
    }

    @Override
    public String toString()
    {
        return "closeRFile(" + expression.toString() + ");";
    }

    @Override
    public iStatement deepCopy()
    {
        return new closeRFile(expression.deepCopy());
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        iType typeExpression = expression.typeCheck(typeEnvironment);
        if (typeExpression.equals(new stringType()))
            return typeEnvironment;
        else
            throw new MyException("closeRFile: expression is not a string");
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        iValue typeCheck = expression.evaluate(state.getSymbolTable(), state.getHeap());
        if (!typeCheck.getType().equals(new stringType()))
            throw new ExecutionException("Expression is not a string");

        stringValue fileName = (stringValue) typeCheck;
        if (!state.getFileTable().isDefined(fileName.getValue()))
            throw new ExecutionException("File is not opened");

        BufferedReader bufferedReader = (BufferedReader) state.getFileTable().getValue(fileName.getValue());
        try
        {
            bufferedReader.close();
        }
        catch (Exception exception)
        {
            throw new ExecutionException("File does not exist");
        }
        state.getFileTable().remove(fileName.getValue());

        return null;
    }
}

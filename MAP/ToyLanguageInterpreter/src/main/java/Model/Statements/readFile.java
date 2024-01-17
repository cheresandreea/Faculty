package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Structures.iHeap;
import Model.Types.iType;
import Model.Types.stringType;
import Model.Values.iValue;
import Model.Values.intValue;
import Model.Values.stringValue;

import java.io.BufferedReader;

public class readFile implements iStatement
{
    iExpression expression;
    iExpression variable;

    public readFile(iExpression expression, iExpression variable)
    {
        this.expression = expression;
        this.variable = variable;
    }

    @Override
    public String toString()
    {
        return "readFile(" + expression.toString() + ", " + variable.toString() + ");";
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        if (!expression.typeCheck(typeEnvironment).equals(new stringType()))
            throw new MyException("readFile: variable is not a string");
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        // check if variable is defined
        if (!state.getSymbolTable().isDefined(variable.toString()))
            throw new ExecutionException("readFile: variable is not defined");

        // check if expression is a string
        iDictionary<String, iValue> symbolTable = state.getSymbolTable();
        iHeap<Integer, iValue> heap = state.getHeap();
        iValue typeCheck = expression.evaluate(symbolTable, heap);
        if (!typeCheck.getType().equals(new stringType()))
            throw new ExecutionException("readFile: expression is not a string");

        // check if file is opened
        stringValue fileName = (stringValue) typeCheck;
        if (!state.getFileTable().isDefined(fileName.getValue()))
            throw new ExecutionException("readFile: file is not opened");


        // read from file
        String line = null;
        try
        {
            line = ((BufferedReader) state.getFileTable().getValue(fileName.getValue())).readLine();
        }
        catch (Exception exception)
        {
            throw new ExecutionException("readFile: file does not exist");
        }


        iValue value;
        if (line == null)
            value = new intValue(0);
        else
        {
            try
            {
                value = new intValue(Integer.parseInt(line));
            }
            catch (Exception exception)
            {
                throw new ExecutionException("readFile: file does not contain an integer");
            }
        }
        symbolTable.update(variable.toString(), value);

        return null;
    }

    @Override
    public iStatement deepCopy()
    {
        return new readFile(expression.deepCopy(), variable.deepCopy());
    }
}

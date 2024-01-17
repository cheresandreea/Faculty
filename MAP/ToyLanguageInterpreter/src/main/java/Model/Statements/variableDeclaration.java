package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.iType;
import Model.Values.iValue;


public class variableDeclaration implements iStatement
{
    private String name;
    private iType type;

    public variableDeclaration(String name, iType type)
    {
        this.name = name;
        this.type = type;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        typeEnvironment.put(name, type);
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        iDictionary<String, iValue> symbolTable = state.getSymbolTable();
        if (symbolTable.containsKey(name))
            throw new ExecutionException("Variable " + name + " already declared!");
        else
            symbolTable.put(name, type.getDefaultValue());
        return null;
    }

    @Override
    public String toString()
    {
        return type.toString() + " " + name;
    }

    @Override
    public iStatement deepCopy()
    {
        return new variableDeclaration(name, type);
    }
}

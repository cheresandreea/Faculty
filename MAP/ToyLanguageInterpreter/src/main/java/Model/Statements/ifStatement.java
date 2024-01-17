package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Types.iType;
import Model.Types.boolType;
import Model.Values.iValue;
import Model.Values.boolValue;
import Model.Structures.iDictionary;

public class ifStatement implements iStatement
{
    private iExpression expression;
    private iStatement thenStatement;
    private iStatement elseStatement;

    public ifStatement(iExpression expression, iStatement thenStatement, iStatement elseStatement)
    {
        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        iType typeExpression = expression.typeCheck(typeEnvironment);
        if (typeExpression.equals(new boolType()))
        {
            thenStatement.typeCheck(typeEnvironment.copy());
            elseStatement.typeCheck(typeEnvironment.copy());
            return typeEnvironment;
        }
        else
            throw new MyException("Condition expression is not of type bool!");

    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException
    {
        iValue condition = expression.evaluate(state.getSymbolTable(), state.getHeap());
        if (!condition.getType().equals(new boolType()))
            throw new ExecutionException("Condition expression is not of type bool!");

        boolValue boolCondition = (boolValue)condition;
        if (boolCondition.getValue())
            state.getExecutionStack().push(thenStatement);
        else
            state.getExecutionStack().push(elseStatement);
        return null;
    }

    @Override
    public String toString()
    {
        return "if(" + expression.toString() + ") then(" + thenStatement.toString() + ") else(" + elseStatement.toString() + ")";
    }

    @Override
    public iStatement deepCopy()
    {
        return new ifStatement(expression.deepCopy(), thenStatement.deepCopy(), elseStatement.deepCopy());
    }
}

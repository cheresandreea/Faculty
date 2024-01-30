package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Expressions.iExpression;
import Model.State.programState;
import Model.Structures.iDictionary;
import Model.Types.boolType;
import Model.Types.iType;
import Model.Values.boolValue;

public class whileStatement implements iStatement
{
    iExpression condition;
    iStatement statement;

    public whileStatement(iExpression c, iStatement s)
    {
        condition = c;
        statement = s;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        iType typeExpression = condition.typeCheck(typeEnvironment);
        if(!typeExpression.equals(new boolType()))
        {
            throw new EvaluationException("Condition is not a boolean");
        }
        statement.typeCheck(typeEnvironment.copy());
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws EvaluationException
    {
        if(!condition.evaluate(state.getSymbolTable(), state.getHeap()).getType().equals(new boolType()))
        {
            throw new EvaluationException("<ERROR> Condition is not a boolean");
        }
        boolValue val = (boolValue) condition.evaluate(state.getSymbolTable(), state.getHeap());
        if(val.getValue())
        {
            state.getExecutionStack().push(this);
            state.getExecutionStack().push(statement);
        }
        return null;

    }

    @Override
    public iStatement deepCopy() {
        return new whileStatement(condition.deepCopy(), statement.deepCopy());
    }

    @Override
    public String toString() {
        return "while(" + condition.toString() + "){" + statement.toString() + "}";
    }
}

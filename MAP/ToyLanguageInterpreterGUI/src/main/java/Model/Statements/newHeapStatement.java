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

import javax.swing.text.IconView;

public class newHeapStatement implements iStatement
{
    String var_name;
    iExpression exp;

    public newHeapStatement(String var_name, iExpression exp) {
        this.var_name = var_name;
        this.exp = exp;
    }

    @Override
    public String toString() {
        return "new(" + var_name + ", " + exp.toString() + ");";
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        iType typeVar = typeEnvironment.getValue(var_name);
        iType typeExp = exp.typeCheck(typeEnvironment);
        if (!typeVar.equals(new refType(typeExp)))
            throw new EvaluationException("Type of variable and type of expression do not match!");
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws EvaluationException {
        iValue val = state.getSymbolTable().getValue(var_name);
        if (!(val.getType() instanceof refType RefVal))
            throw new EvaluationException("Variable is not of type reference!");

        iValue val_exp = exp.evaluate(state.getSymbolTable(), state.getHeap());

        if (!val_exp.getType().equals(RefVal.getInner()))
            throw new EvaluationException("Type of expression and type of variable do not match!");

        int addr = state.getHeap().put(val_exp);
        state.getSymbolTable().update(var_name, new refValue(addr, val_exp.getType()));

        return null;
    }

    @Override
    public iStatement deepCopy() {
        return new newHeapStatement(var_name, exp.deepCopy());
    }

}

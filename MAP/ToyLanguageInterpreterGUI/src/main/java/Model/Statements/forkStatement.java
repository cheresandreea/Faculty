package Model.Statements;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Structures.adtDictionary;
import Model.Structures.adtStack;
import Model.Structures.iDictionary;
import Model.Structures.iStack;
import Model.Types.iType;
import Model.Values.iValue;
import java.util.stream.IntStream;

public class forkStatement implements iStatement {
    iStatement statement;

    public forkStatement(iStatement statement) {
        this.statement = statement;
    }

    @Override
    public iDictionary<String, iType> typeCheck(iDictionary<String, iType> typeEnvironment) throws MyException, EvaluationException {
        statement.typeCheck(typeEnvironment.copy());
        return typeEnvironment;
    }

    @Override
    public programState execute(programState state) throws ExecutionException, EvaluationException {
        iStack<iStatement> newStack = new adtStack<>();
        iDictionary<String, iValue> symTbl = state.getSymbolTable();
        iDictionary<String, iValue> newDictionary = symTbl.copy();

        return new programState(newStack, newDictionary, state.getOutput(),this.statement, state.getFileTable(), state.getHeap(), programState.generateNewID());
    }

    @Override
    public iStatement deepCopy() {
        return new forkStatement(this.statement);
    }

    @Override
    public String toString(){
        return "fork( " + this.statement + " );";
    }
}

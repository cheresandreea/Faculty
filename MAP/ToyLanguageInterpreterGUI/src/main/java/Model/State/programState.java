package Model.State;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.ExecutionException;
import Model.Exceptions.MyException;
import Model.Structures.*;
import Model.Values.iValue;
import Model.Statements.iStatement;
import Model.Values.stringValue;

import java.io.BufferedReader;
import java.util.Collections;


public class programState
{
    private static int nextID = 0;
    public iStack<iStatement> executionStack;
    public iDictionary<String, iValue> symbolTable;
    public iHeap<Integer, iValue> heap;
    public iList<iValue> output;

    public iDictionary<String, BufferedReader> fileTable;

    public iStatement originalProgram;
    int id;

    public static synchronized int generateNewID(){
        return nextID++;
    }

    public programState(iStack<iStatement> executionStack, iDictionary<String, iValue> symbolTable, iList<iValue> output, iStatement program, iDictionary<String, BufferedReader> fileTable, iHeap<Integer, iValue> heap, int id)
    {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.output = output;
        this.originalProgram = program.deepCopy();
        this.executionStack.push(program);
        this.fileTable = fileTable;
        this.heap = heap;
        this.id = id;
    }

    /*public programState(iStatement program)
    {
        this.executionStack = new adtStack<>();
        this.symbolTable = new adtDictionary<>();
        this.output = new adtList<>();
        this.fileTable = new adtDictionary<>();


        this.executionStack.push(program);
    }*/

    public iStatement getOriginalProgram()
    {
        return originalProgram;
    }

    public iStack<iStatement> getExecutionStack()
    {
        return executionStack;
    }

    public iDictionary<String, iValue> getSymbolTable()
    {
        return symbolTable;
    }

    public iList<iValue> getOutput()
    {
        return output;
    }

    public iDictionary<String, BufferedReader> getFileTable()
    {
        return fileTable;
    }

    public iHeap<Integer, iValue> getHeap()
    {
        return heap;
    }

    public void setExecutionStack(iStack<iStatement> executionStack)
    {
        this.executionStack = executionStack;
    }

    public void setSymbolTable(iDictionary<String, iValue> symbolTable)
    {
        this.symbolTable = symbolTable;
    }

    public void setOutput(iList<iValue> output)
    {
        this.output = output;
    }

    public void setOriginalProgram(iStatement originalProgram)
    {
        this.originalProgram = originalProgram;
    }

    public boolean isNotCompleted()
    {
        return !executionStack.isEmpty();
    }

    public programState executeOneStep() throws MyException
    {

        if (executionStack.isEmpty())
            throw new MyException("PrgState stack is empty");

        iStatement currentStatement = executionStack.pop();
        try
        {
            return currentStatement.execute(this);
        }
        catch (ExecutionException | EvaluationException exception)
        {
            throw new MyException(exception.getMessage());
        }
    }
    /*
    public String executionStackToString()
    {
        StringBuilder result = new StringBuilder();
        for (iStatement statement : executionStack)
            result.append(statement.toString()).append(" | ");
        return result.toString();
    }*/
    /*
    public String symbolTableToString()
    {
        StringBuilder result = new StringBuilder();
        for (String key : Collections.list(symbolTable.getKeys()))
        {
            result.append(String.format("%s -> %s\n", key, symbolTable.getValue(key).toString()));
        }
        return result.toString();
    }*/
    /*
    public String outputToString()
    {
        StringBuilder result = new StringBuilder();
        for (iValue value : output)
            result.append(value.toString()).append("\n");
        return result.toString();
    }*/
    /*

    public String fileTableToString()
    {
        StringBuilder result = new StringBuilder();
        for (String key : Collections.list(fileTable.getKeys()))
        {
            result.append(String.format("%s -> %s\n", key.toString(), fileTable.getValue(key).toString()));
        }
        return result.toString();
    }
    */




    @Override
    public String toString()
    {
        String return_string = "{\n";
        return_string += "Program ID:\n";
        return_string += id;
        return_string += "\nExecution Stack:\n";
        return_string += executionStack.toString();
        return_string += "\nHeap:\n";
        return_string += heap.toString();
        return_string += "\nSymbol Table:\n";
        return_string += symbolTable.toString();
        return_string += "\nOutput:\n";
        return_string += output.toString();
        return_string += "\nFileTable:\n";
        return_string += fileTable.toString();
        return_string += "\n}\n";
        return return_string;
    }

    public void reset()
    {
        executionStack.clear();
        symbolTable.clear();
        output.clear();
        fileTable.clear();
        heap.clear();
        iStatement program = originalProgram.deepCopy();
        executionStack.push(program);
    }

    public int getId() {
        return id;
    }
}

package View;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;
import Model.Expressions.*;
import Model.State.programState;
import Model.Statements.*;
import Model.Structures.*;
import Model.Types.*;
import Model.Values.boolValue;
import Model.Values.iValue;
import Model.Values.intValue;
import Model.Values.stringValue;
import Repository.iRepository;
import Repository.memoryRepository;
import Controller.Controller;

import java.io.BufferedReader;
import java.util.HashMap;

public class Interpreter
{
    public static void main(String[] args) throws MyException, EvaluationException {
        iStatement ex1 = new compoundStatement(new variableDeclaration("v", new intType()),
                new compoundStatement(new assignmentStatement("v", new valueExpression(new intValue(2))),
                        new printStatement(new variableExpression("v"))));

        iStack<iStatement> executionStack1 = new adtStack<>();
        iList<iValue> output1 = new adtList<>();
        iDictionary<String, iValue> symbolTable1 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable1 = new adtDictionary<>();
        iHeap<Integer, iValue> heap1 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id1 = 1;
        programState state1 = new programState(executionStack1, symbolTable1, output1, ex1, fileTable1, heap1, id1);
        String logFilePath1 = "log1.txt";
        iRepository repository1 = new memoryRepository(logFilePath1);
        Controller controller1 = new Controller(repository1);
        try{
            ex1.typeCheck(new adtDictionary<String, iType>());
            repository1.addProgramState(state1);
        }catch (MyException e)
        {
            System.out.println(e.getMessage());
        }


        iStatement ex2 = new compoundStatement(new variableDeclaration("a", new intType()),
                            new compoundStatement(new variableDeclaration("b", new intType()),
                                    new compoundStatement(
                                            new assignmentStatement("a",
                                                    new arithmeticExpression('+', new valueExpression(new intValue(2)),
                                                            new arithmeticExpression('*', new valueExpression(new intValue(3)),
                                                                    new valueExpression(new intValue(5))))),
                                                                        new compoundStatement(
                                                                                new assignmentStatement("b",
                                                                                        new arithmeticExpression('+', new variableExpression("a"), new valueExpression(new intValue(1)))),
                                                                                new printStatement(new variableExpression("b"))))));

        iStack<iStatement> executionStack2 = new adtStack<>();
        iList<iValue> output2 = new adtList<>();
        iDictionary<String, iValue> symbolTable2 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable2 = new adtDictionary<>();
        iHeap<Integer, iValue> heap2 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id2 = 2;
        programState state2 = new programState(executionStack2, symbolTable2, output2, ex2, fileTable2, heap2, id2);
        String logFilePath2 = "log2.txt";
        iRepository repository2 = new memoryRepository(logFilePath2);
        Controller controller2 = new Controller(repository2);
        try{
            ex2.typeCheck(new adtDictionary<String, iType>());
            repository2.addProgramState(state2);
        }catch (MyException e)
        {
            System.out.println("ex2 " + e.getMessage());
        }


        iStatement ex3 = new compoundStatement(new variableDeclaration("a", new boolType()),
                new compoundStatement(new variableDeclaration("v", new intType()),
                        new compoundStatement(new assignmentStatement("a", new valueExpression(new boolValue(true))),
                                new compoundStatement(new ifStatement(new variableExpression("a"), new assignmentStatement("v",
                                        new valueExpression(new intValue(2))), new assignmentStatement("v", new valueExpression(new intValue(3)))),
                                            new printStatement(new variableExpression("v"))))));

        iStack<iStatement> executionStack3 = new adtStack<>();
        iList<iValue> output3 = new adtList<>();
        iDictionary<String, iValue> symbolTable3 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable3 = new adtDictionary<>();
        iHeap<Integer, iValue> heap3 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id3 = 3;
        programState state3 = new programState(executionStack3, symbolTable3, output3, ex3, fileTable3, heap3, id3);
        String logFilePath3 = "log3.txt";
        iRepository repository3 = new memoryRepository(logFilePath3);
        Controller controller3 = new Controller(repository3);
        try{
            ex3.typeCheck(new adtDictionary<String, iType>());
            repository3.addProgramState(state3);
        }catch (MyException e)
        {
            System.out.println("ex3 " + e.getMessage());
        }

        //(string varf; (varf=test.in; (openRFile(varf);; (int varc; (readFile(varf, varc);; (print(varc); (readFile(varf, varc);; (print(varc); closeRFile(varf);))))))))

        iStatement ex4 = new compoundStatement(new variableDeclaration("varf", new stringType()),
                new compoundStatement(new assignmentStatement("varf", new valueExpression(new stringValue("test.in"))),
                        new compoundStatement(new openRFile(new variableExpression("varf")),
                                new compoundStatement(new variableDeclaration("varc", new intType()),
                                        new compoundStatement(new readFile(new variableExpression("varf"), new variableExpression("varc")),
                                                new compoundStatement(new printStatement(new variableExpression("varc")),
                                                        new compoundStatement(new readFile(new variableExpression("varf"), new variableExpression("varc")),
                                                                new compoundStatement(new printStatement(new variableExpression("varc")),
                                                                        new closeRFile(new variableExpression("varf"))))))))));

        iStack<iStatement> executionStack4 = new adtStack<>();
        iList<iValue> output4 = new adtList<>();
        iDictionary<String, iValue> symbolTable4 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable4 = new adtDictionary<>();
        iHeap<Integer, iValue> heap4 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id4 = 4;
        programState state4 = new programState(executionStack4, symbolTable4, output4, ex4, fileTable4, heap4, id4);
        String logFilePath4 = "log4.txt";
        iRepository repository4 = new memoryRepository(logFilePath4);
        Controller controller4 = new Controller(repository4);
        try{
            ex4.typeCheck(new adtDictionary<String, iType>());
            repository4.addProgramState(state4);
        }catch (MyException e)
        {
            System.out.println("ex4 " + e.getMessage());
        }


       iStatement ex5 = new compoundStatement(new variableDeclaration("a", new intType()),
                new compoundStatement(new variableDeclaration("b", new intType()),
                        new compoundStatement(new assignmentStatement("a", new valueExpression(new intValue(2))),
                                new compoundStatement(new ifStatement(new relationalExpression(new variableExpression("a"), new valueExpression(new intValue(3)), "<"), new assignmentStatement("b",
                                        new valueExpression(new intValue(10))), new assignmentStatement("b", new valueExpression(new intValue(5)))),
                                        new printStatement(new variableExpression("b"))))));

        iStack<iStatement> executionStack5 = new adtStack<>();
        iList<iValue> output5 = new adtList<>();
        iDictionary<String, iValue> symbolTable5 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable5 = new adtDictionary<>();
        iHeap<Integer, iValue> heap5 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id5 = 5;
        programState state5 = new programState(executionStack5, symbolTable5, output5, ex5, fileTable5, heap5, id5);
        String logFilePath5 = "log5.txt";
        iRepository repository5 = new memoryRepository(logFilePath5);
        Controller controller5 = new Controller(repository5);
        try{
            ex5.typeCheck(new adtDictionary<String, iType>());
            repository5.addProgramState(state5);
        }catch (MyException e)
        {
            System.out.println("ex5 " + e.getMessage());
        }


    iStatement ex6 = new compoundStatement(new variableDeclaration("v", new refType(new intType())),
            new compoundStatement(new newHeapStatement("v", new valueExpression(new intValue(20))),
                    new compoundStatement(new variableDeclaration("a", new refType(new refType(new intType()))),
                            new compoundStatement(new newHeapStatement("a", new variableExpression("v")),
                                    new compoundStatement(new newHeapStatement("v", new valueExpression(new intValue(30))),
                                            new compoundStatement(new printStatement(new variableExpression("v")),
                                                    new compoundStatement(new printStatement(new readHeapExpression(new variableExpression("v"))),
                                                            new compoundStatement(new printStatement(new variableExpression("a")),
                                                                    new compoundStatement(new printStatement(new readHeapExpression(new variableExpression("a"))),
                                                                            new printStatement(new readHeapExpression(new readHeapExpression(new variableExpression("a")))))))))))));

        iStack<iStatement> executionStack6 = new adtStack<>();
        iList<iValue> output6 = new adtList<>();
        iDictionary<String, iValue> symbolTable6 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable6 = new adtDictionary<>();
        iHeap<Integer, iValue> heap6 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id6 = 6;
        programState state6 = new programState(executionStack6, symbolTable6, output6, ex6, fileTable6, heap6, id6);
        String logFilePath6 = "log6.txt";
        iRepository repository6 = new memoryRepository(logFilePath6);
        Controller controller6 = new Controller(repository6);
        try{
            ex6.typeCheck(new adtDictionary<String, iType>());
            repository6.addProgramState(state6);
        }catch (MyException e)
        {
            System.out.println("ex6 " + e.getMessage());
        }

        //  int v; v=4; (while (v>0) print(v);v=v-1);print(v)

        iStatement ex7 = new compoundStatement(new variableDeclaration("v", new intType()),
                new compoundStatement(new assignmentStatement("v", new valueExpression(new intValue(4))),
                        new compoundStatement(new whileStatement(new relationalExpression(new variableExpression("v"), new valueExpression(new intValue(0)), ">"),
                                new compoundStatement(new printStatement(new variableExpression("v")),
                                        new assignmentStatement("v", new arithmeticExpression('-', new variableExpression("v"), new valueExpression(new intValue(1)))))),
                                new printStatement(new variableExpression("v")))));

        iStack<iStatement> executionStack7 = new adtStack<>();
        iList<iValue> output7 = new adtList<>();
        iDictionary<String, iValue> symbolTable7 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable7 = new adtDictionary<>();
        iHeap<Integer, iValue> heap7 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id7 = 7;
        programState state7 = new programState(executionStack7, symbolTable7, output7, ex7, fileTable7, heap7, id7);
        String logFilePath7 = "log7.txt";
        iRepository repository7 = new memoryRepository(logFilePath7);

        Controller controller7 = new Controller(repository7);
        try{
            ex7.typeCheck(new adtDictionary<String, iType>());
            repository7.addProgramState(state7);
        }catch (MyException e)
        {
            System.out.println("ex7 " + e.getMessage());
        }

        //int v; Ref int a; v=10;new(a,22);
        // fork(wH(a,30);v=32;print(v);print(rH(a)));
        // print(v);print(rH(a))
        iStatement ex8 = new compoundStatement(new variableDeclaration("v", new intType()),
                new compoundStatement(new variableDeclaration("a", new refType(new intType())),
                        new compoundStatement(new assignmentStatement("v", new valueExpression(new intValue(10))),
                                new compoundStatement(new newHeapStatement("a", new valueExpression(new intValue(22))),
                                        new compoundStatement(new forkStatement(new compoundStatement(new heapWriteStatement("a", new valueExpression(new intValue(30))),
                                                new compoundStatement(new assignmentStatement("v", new valueExpression(new intValue(32))),
                                                        new compoundStatement(new printStatement(new variableExpression("v")),
                                                                new printStatement(new readHeapExpression(new variableExpression("a"))))))),
                                                new compoundStatement(new printStatement(new variableExpression("v")),
                                                        new printStatement(new readHeapExpression(new variableExpression("a")))))))));


        iStack<iStatement> executionStack8 = new adtStack<>();
        iList<iValue> output8 = new adtList<>();
        iDictionary<String, iValue> symbolTable8 = new adtDictionary<>();
        iDictionary<String, BufferedReader> fileTable8 = new adtDictionary<>();
        iHeap<Integer, iValue> heap8 = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
        int id8 = 8;

        programState state8 = new programState(executionStack8, symbolTable8, output8, ex8, fileTable8, heap8, id8);
        String logFilePath8 = "log8.txt";
        iRepository repository8 = new memoryRepository(logFilePath8);
        Controller controller8 = new Controller(repository8);

        try
        {
            ex8.typeCheck(new adtDictionary<String, iType>());
            repository8.addProgramState(state8);
        }catch (MyException e)
        {
            System.out.println("ex8 " + e.getMessage());
        }






        //cleaning the log files
        try
        {
            repository1.clearLogFile();
            repository2.clearLogFile();
            repository3.clearLogFile();
            repository4.clearLogFile();
            repository5.clearLogFile();
            repository6.clearLogFile();
            repository7.clearLogFile();
            repository8.clearLogFile();
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", ex1.toString(), controller1));
        menu.addCommand(new RunExample("2", ex2.toString(), controller2));
        menu.addCommand(new RunExample("3", ex3.toString(), controller3));
        menu.addCommand(new RunExample("4", ex4.toString(), controller4));
        menu.addCommand(new RunExample("5", ex5.toString(), controller5));
        menu.addCommand(new RunExample("6", ex6.toString(), controller6));
        menu.addCommand(new RunExample("7", ex7.toString(), controller7));
        menu.addCommand(new RunExample("8", ex8.toString(), controller8));
        menu.show();
    }
}

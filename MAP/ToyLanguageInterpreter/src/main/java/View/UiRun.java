package View;

import Model.Exceptions.MyException;
import Model.Expressions.arithmeticExpression;
import Model.Expressions.valueExpression;
import Model.Expressions.variableExpression;
import Model.Statements.*;
import Model.Structures.*;
import Model.Types.boolType;
import Model.Types.intType;
import Model.Values.boolValue;
import Model.Values.iValue;
import Model.Values.intValue;
import Model.State.programState;
import Repository.iRepository;
import Repository.memoryRepository;
import Controller.Controller;

import java.io.BufferedReader;
import java.util.*;

public class UiRun
{
    private void printMenu(ArrayList<iStatement> programState)
    {
        for (int i = 0; i < programState.size(); i++) {
            System.out.println((i + 1) + " " + programState.get(i).toString());
        }
        System.out.println("0. Exit.");
    }

    public void run()
    {
        // example 1
        iStatement ex1 = new compoundStatement(new variableDeclaration("v", new intType()),
                new compoundStatement(new assignmentStatement("v", new valueExpression(new intValue(2))),
                        new printStatement(new variableExpression("v"))));

        // example 2
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


        // example 3
        iStatement ex3 = new compoundStatement(new variableDeclaration("a", new boolType()),
                new compoundStatement(new variableDeclaration("v", new intType()),
                        new compoundStatement(new assignmentStatement("a", new valueExpression(new boolValue(true))),
                                new compoundStatement(new ifStatement(new variableExpression("a"), new assignmentStatement("v",
                                        new valueExpression(new intValue(2))), new assignmentStatement("v", new valueExpression(new intValue(3)))),
                                        new printStatement(new variableExpression("v"))))));


        System.out.println("Choose a program:");
        ArrayList<iStatement> programState = new ArrayList<>();
        programState.add(ex1);
        programState.add(ex2);
        programState.add(ex3);
        int option = -1;
        while (option != 0)
        {
            printMenu(programState);
            Scanner scanner = new Scanner(System.in);
            //System.out.println("Input the number of the program you want to run: ");
            try
            {
                System.out.print("> ");
                option = scanner.nextInt();
            } catch (Exception e) {
                System.out.println("Please enter a number.");
                continue;
            }

            iStatement exercise = null;
            switch (option)
            {
                case 1:
                    exercise = ex1;
                    break;
                case 2:
                    exercise = ex2;
                    break;
                case 3:
                    exercise = ex3;
                    break;
                default:
                    System.out.println("Invalid option!");
                    continue;
            }

            try
            {
                iStack<iStatement> executionStack = new adtStack<>();
                iList<iValue> output = new adtList<>();
                iDictionary<String, iValue> symbolTable = new adtDictionary<>();
                iDictionary<String, BufferedReader> fileTable = new adtDictionary<>();
                iHeap<Integer, iValue> heap = new adtHeap<Integer, iValue>(new HashMap<Integer, iValue>());
                int id0 = 0;
                programState state = new programState(executionStack, symbolTable, output, exercise, fileTable, heap, id0);
                String logFilePath = "log.txt";
                iRepository repository = new memoryRepository(logFilePath);
                Controller controller = new Controller(repository);
                //controller.executeAll(state);

                ///iList<iValue> out = state.getOutput();
                ///System.out.println(out.toString());
                ///System.out.println(state.executionStackToString());
                ///System.out.println(state.getSymbolTable().toString());
                System.out.println(state.toString());
                //clear the log file
                repository.clearLogFile();

            }
            catch (MyException e)
            {
                System.out.println(e.getMessage());
            }

        }
    }


}

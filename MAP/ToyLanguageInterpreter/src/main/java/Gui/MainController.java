package Gui;

import Controller.Controller;
import Model.DataTransfer.SymbolTableEntry;
import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Statements.iStatement;
import Model.Statements.noOperationStatement;
import Model.Structures.*;
import Model.Values.iValue;
import Model.Values.stringValue;
import Repository.iRepository;
import Repository.memoryRepository;
import View.RunExample;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldListCell;
import javafx.util.Pair;
import Model.DataTransfer.HeapEntry;
import javafx.util.StringConverter;

import java.io.BufferedReader;
import java.util.List;

public class MainController {
    @FXML
    private Label welcomeText;
    private SelectController selectController;
    private RunExample selectedExample;
    private programState selectedProgramState;

    @FXML
    private Button runOneStepButton;

    @FXML
    private TextField nrOfProgramStatesTextField;
    @FXML
    private TableView<HeapEntry> heapTableView;
    @FXML
    private TableColumn<HeapEntry, String> addressColumn;
    @FXML
    private TableColumn<HeapEntry, String> valueHeapColumn;
    @FXML
    private ListView<iValue> outListView;
    @FXML
    private ListView<stringValue> fileTableListView;
    @FXML
    private ListView<programState> programStatesListView;
    @FXML
    private TableView<SymbolTableEntry> symbolTableView;
    @FXML
    private TableColumn<SymbolTableEntry, String> variableNameColumn;
    @FXML
    private TableColumn<SymbolTableEntry,String> valueSymColumn;
    @FXML
    private ListView<iStatement> executionStackListView;

    public void setSelectController(SelectController newselectController) {
        // Set the selector controller
        this.selectController = newselectController;
        // Create a listener for the list of examples. If an example is selected and it is changed, the necessary changes
        // will be made in the tables
        // So more exactly, it looks whether the current selected example is changed or not
        this.selectController.getExamplesListView().getSelectionModel().selectedItemProperty().addListener((a,b,ex)->this.showDataForSelectedExample(ex));

    }

    @FXML
    private void initialize() {
        this.nrOfProgramStatesTextField.setEditable(false);

        this.addressColumn.setCellValueFactory(new PropertyValueFactory<HeapEntry, String>("heapAddress"));
        this.valueHeapColumn.setCellValueFactory(new PropertyValueFactory<HeapEntry, String >("heapValue"));

        this.variableNameColumn.setCellValueFactory(new PropertyValueFactory<SymbolTableEntry, String>("variableName"));
        this.valueSymColumn.setCellValueFactory(new PropertyValueFactory<SymbolTableEntry, String>("value"));


        this.outListView.setCellFactory(TextFieldListCell.forListView(new StringConverter<iValue>() {
            @Override
            public String toString(iValue valueInterface) {
                return valueInterface.toString();
            }

            @Override
            public iValue fromString(String s) {
                return null;
            }
        }));

        this.fileTableListView.setCellFactory(TextFieldListCell.forListView(new StringConverter<stringValue>() {
            @Override
            public String toString(stringValue stringValue) {
                return stringValue.toString();
            }

            @Override
            public stringValue fromString(String s) {
                return null;
            }
        }));

        this.programStatesListView.setCellFactory(TextFieldListCell.forListView(new StringConverter<programState>() {
            @Override
            public String toString(programState programState) {
                return Integer.toString(programState.getId());
            }

            @Override
            public programState fromString(String s) {
                return null;
            }
        }));

        this.executionStackListView.setCellFactory(TextFieldListCell.forListView(new StringConverter<iStatement>() {
            @Override
            public String toString(iStatement statementInterface) {
                return statementInterface.toString();
            }

            @Override
            public iStatement fromString(String s) {
                return null;
            }
        }));


        // Like that we are able to select the first item from the list
        this.programStatesListView.getSelectionModel().select(0);

        this.programStatesListView.getSelectionModel().selectedItemProperty().addListener((a,b,state)-> {
            if(state != null)
                showDataForSelectedProgramState(state);

        });

        // We activate the button and connect it to the runOneStep function
        this.runOneStepButton.setOnAction(actionEvent -> runOneStep(this.selectController.getExamplesListView().getSelectionModel().getSelectedItems().get(0)));

    }

    private void runOneStep(RunExample runExample) {

        try{
            List<programState> programStates = runExample.getController().getRepo().getProgramList();
            runExample.getController().executeAll(programStates);
        }
        catch (Exception e){
            e.getMessage();
        }

        showDataForSelectedExample(runExample);
    }

    private void showDataForSelectedProgramState(programState program) {
        //We clear the execution stack and the symbol stack
        this.symbolTableView.getItems().clear();
        this.executionStackListView.getItems().clear();

        iStack<iStatement> executionStack = program.getExecutionStack();
        iDictionary<String, iValue> symbolTable = program.getSymbolTable();

        //We are going to repopulate them back with the "new values" if it's the case
        executionStack.getStack().forEach((statement)->this.executionStackListView.getItems().add(statement));
        symbolTable.getContent().forEach((name, value)->this.symbolTableView.getItems().add(new SymbolTableEntry(name, value)));

    }


    private void showDataForSelectedExample(RunExample ex) {
        // We clear all the tables and lists and prepare them for new data
        this.heapTableView.getItems().clear();
        this.outListView.getItems().clear();
        this.fileTableListView.getItems().clear();
        this.programStatesListView.getItems().clear();
        this.symbolTableView.getItems().clear();
        this.executionStackListView.getItems().clear();

        // We get the list with the existing programStates
        List<programState> programStates = ex.getController().getRepo().getProgramList();
        if(!programStates.isEmpty())
            this.selectedProgramState = programStates.get(0);

        // We get the heap, fileTable and output based on the programState 0 because they are shared and have the same
        // values for each program state
        iHeap<Integer, iValue> sharedHeap = this.selectedProgramState.getHeap();
        iDictionary<String, BufferedReader> fileTable = this.selectedProgramState.getFileTable();
        iList<iValue> output = this.selectedProgramState.getOutput();

        // We update their content with the new content
        sharedHeap.getContent().forEach((address, value)->this.heapTableView.getItems().add(new HeapEntry(address, value)));
        fileTable.getContent().forEach((fileName, filePath) -> {
            stringValue stringValue = new stringValue(fileName);
            this.fileTableListView.getItems().add(stringValue);
        });
        output.getList().forEach((value)->this.outListView.getItems().add(value));


        programStates.forEach((programState)->this.programStatesListView.getItems().add(programState));

        // We update the number of program states
        this.nrOfProgramStatesTextField.setText(Integer.toString(programStates.size()));
        this.programStatesListView.getSelectionModel().select(0);


    }
}
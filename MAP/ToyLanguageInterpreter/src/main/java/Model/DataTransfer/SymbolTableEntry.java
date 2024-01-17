package Model.DataTransfer;

import Model.Values.iValue;
import javafx.beans.property.SimpleStringProperty;


public class SymbolTableEntry {
    private SimpleStringProperty variableName;
    private SimpleStringProperty value;

    public SymbolTableEntry(String variableName, iValue value){
        this.variableName = new SimpleStringProperty(variableName);
        this.value = new SimpleStringProperty(value.toString());
    }

    public String getVariableName(){
        return this.variableName.get();
    }

    public String getValue(){
        return this.value.get();
    }

    public void setVariableName(String newVariableName){
        this.variableName.set(newVariableName);
    }

    public void setValue(String newValue){
        this.value.set(newValue);
    }

}

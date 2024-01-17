package Model.DataTransfer;

import Model.Values.iValue;
import javafx.beans.property.SimpleStringProperty;

public class HeapEntry {

    private SimpleStringProperty heapAddress;
    private SimpleStringProperty heapValue;

    public HeapEntry(Integer heapAddress, iValue heapValue) {
        this.heapAddress = new SimpleStringProperty(Integer.toString(heapAddress));
        this.heapValue = new SimpleStringProperty(heapValue.toString());
    }

    public String getHeapAddress() {
        return heapAddress.get();
    }

    public String getHeapValue() {
        return heapValue.get();
    }

    public void setHeapAddress(Integer heapAddress) {
        this.heapAddress.set(Integer.toString(heapAddress));
    }

    public void setHeapValue(iValue heapValue) {
        this.heapValue.set(heapValue.toString());
    }
}

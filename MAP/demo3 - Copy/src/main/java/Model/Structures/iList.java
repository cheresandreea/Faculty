package Model.Structures;

import Model.Exceptions.ListException;
import java.util.List;

public interface iList<T> extends iClearable
{
    T pop() throws ListException;
    void append(T value);
    boolean isEmpty();
    //List<T> getList();

    List<T> getList();

    String toString();

}

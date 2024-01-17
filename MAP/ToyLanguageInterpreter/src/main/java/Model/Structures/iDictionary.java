package Model.Structures;

import java.util.Map;
import java.util.Dictionary;
import java.util.Enumeration;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;

public interface iDictionary <K, V> extends iClearable
{

    V lookup(K key) throws MyException;
    boolean isDefined(K key);
    int size();
    boolean isEmpty();
    void update(K key, V value) throws EvaluationException;
    Enumeration<K> getKeys();
    Enumeration<V> getValues();
    V getValue(K key);
    void remove(K key);
    V put(K key, V value);
    iDictionary<K, V> copy();
    Map<K, V> getContent();
    boolean containsKey(K key);

    String toString();
}

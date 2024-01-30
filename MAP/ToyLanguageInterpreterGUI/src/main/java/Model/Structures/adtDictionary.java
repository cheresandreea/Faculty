package Model.Structures;

import java.util.Map;
import java.util.Hashtable;
import java.util.Enumeration;

import Model.Exceptions.EvaluationException;
import Model.Exceptions.MyException;

public class adtDictionary<K, V> implements iDictionary<K, V>
{
    Hashtable<K, V> dictionary = new Hashtable<>();
    @Override
    public boolean containsKey(K key)
    {
        return dictionary.containsKey(key);
    }

    @Override
    public V lookup(K key) throws MyException
    {
        if (dictionary.containsKey(key))
            return dictionary.get(key);
        else
            throw new MyException("The key does not exist in the dictionary!");

    }

    @Override
    public boolean isDefined(K key)
    {
        return dictionary.containsKey(key);
    }

    @Override
    public int size()
    {
        return dictionary.size();
    }

    @Override
    public boolean isEmpty()
    {
        return dictionary.isEmpty();
    }

    @Override
    public void update(K key, V value) throws EvaluationException
    {
        if (dictionary.containsKey(key))
            dictionary.replace(key, value);
        else
            throw new EvaluationException("The key does not exist in the dictionary!");
    }

    @Override
    public Enumeration<K> getKeys()
    {
        return dictionary.keys();
    }

    @Override
    public Enumeration<V> getValues()
    {
        return dictionary.elements();
    }

    @Override
    public V getValue(K key)
    {
        return dictionary.get(key);
    }

    @Override
    public void remove(K key)
    {
        dictionary.remove(key);
    }

    @Override
    public V put(K key, V value)
    {
        return dictionary.put(key, value);
    }

    @Override
    public iDictionary<K, V> copy()
    {
        iDictionary<K, V> copy = new adtDictionary<>();
        for (K key : dictionary.keySet())
            copy.put(key, dictionary.get(key));
        return copy;
    }

    @Override
    public Map<K, V> getContent()
    {
        return dictionary;
    }

    @Override
    public String toString()
    {
        StringBuilder string = new StringBuilder();
        for (K key : dictionary.keySet())
        {
            string.append(key.toString());
            string.append("->");
            string.append(dictionary.get(key).toString());
            string.append("\n");
        }
        return string.toString();
    }

    @Override
    public void clear()
    {
        dictionary.clear();
    }

}

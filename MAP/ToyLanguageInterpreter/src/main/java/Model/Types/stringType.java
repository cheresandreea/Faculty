package Model.Types;

import Model.Values.iValue;
import Model.Values.stringValue;

public class stringType implements iType
{
    public boolean equals(Object other)
    {
        return other instanceof stringType;
    }

    public iType getType()
    {
        return new stringType();
    }

    public String toString()
    {
        return "string";
    }

    public iValue getDefaultValue()
    {
        return new stringValue("");
    }
}

package Model.Exceptions;

public class EvaluationException extends Exception
{
    public EvaluationException()
    {
        super();
    }

    public EvaluationException(String message)
    {
        super(message);
    }

    public EvaluationException(String message, Throwable cause)
    {
        super(message, cause);
    }
}

package View;

import Controller.Controller;

public class RunExample extends Command
{

    private Controller controller;
    public RunExample(String key, String desc, Controller controller)
    {
        super(key, desc);
        this.controller = controller;
    }

    @Override
    public void execute()
    {
        try
        {
            controller.oneStep();
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }

    }

    public Controller getController()
    {
        return this.controller;
    }

    public String toString()
    {
        return this.getKey() + " " + this.getDescription();
    }
}
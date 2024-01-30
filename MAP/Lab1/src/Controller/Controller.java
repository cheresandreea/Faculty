package Controller;

import Model.IAnimal;
import Repository.IRepository;
import Repository.MyException;

public class Controller {
    private IRepository irepo;
    public Controller(IRepository repository){
        this.irepo = repository;
    }
    public void addAnimal(IAnimal a){
        try{
            irepo.addAnimal(a);
        }catch (MyException e){
            System.out.println(e.getMessage());
        }
    }
    public void removeAnimal(double a) throws MyException {
        try{
            irepo.removeAnimal(a);
        }catch (MyException e){
            System.out.println(e.getMessage());
        }
    }
    public IAnimal[] getAll()
    {
        return irepo.getAll();
    }

    public IAnimal[] filter() throws MyException {
        return irepo.filter();
    }
}

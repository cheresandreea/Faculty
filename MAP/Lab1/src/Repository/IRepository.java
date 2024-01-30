package Repository;

import Model.IAnimal;

public interface IRepository {
    void addAnimal(IAnimal a) throws MyException;
    void removeAnimal(double kg) throws MyException;

    IAnimal[] getAll();

    IAnimal[] filter() throws MyException;
}

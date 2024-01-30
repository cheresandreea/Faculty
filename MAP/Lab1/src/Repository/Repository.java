package Repository;


import Model.IAnimal;

import java.util.Vector;

public class Repository implements IRepository {
    private IAnimal[] animals;
    private int count;
    public Repository(int cap) {
        this.animals = new IAnimal[cap];
        this.count = 0;
    }
    @Override
    public void addAnimal(IAnimal a) throws MyException{
        if(count == animals.length){
            throw new MyException("Array is full");
        }
        this.animals[this.count] = a;
        this.count++;

    }
    @Override
    public void removeAnimal(double kg) throws MyException {
        if (count == 0) {
            throw new MyException("Array is empty");
        }

        int c = count;
        boolean animalFound = false;

        for (int i = 0; i < count; i++) {
            if (animals[i].getKg() == kg) {
                animalFound = true;
                for (int j = i; j < count - 1; j++) {
                    animals[j] = animals[j + 1];
                }
                animals[count - 1] = null;
                count--;
                i--;
            }
        }

        if (!animalFound) {
            throw new MyException("Animal not found!");
        }
    }
    public IAnimal[] getAll()
    {
        return this.animals;
    }

    public IAnimal[] filter() throws MyException {
        IAnimal[] filteredAnimals = new IAnimal[animals.length]; // Create an array with the same size

        int filteredCount = 0; // Keep track of the number of filtered animals

        for (IAnimal animal : this.animals) {
            if (animal != null && animal.getKg() > 3) {
                filteredAnimals[filteredCount++] = animal;
            }
        }
        if(filteredCount == 0)
            throw new MyException("Empty array!");
        return filteredAnimals;
    }
}

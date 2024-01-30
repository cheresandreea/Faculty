import Controller.Controller;
import Model.Bird;
import Model.IAnimal;
import Model.Pig;
import Model.Cow;
import Repository.Repository;
import Repository.MyException;
import View.View;

import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) throws MyException {
//        4. La o ferma se cresc pasari, vaci si porci.
//        Sa se afiseze toate animalele care au greutatea
//        mai mare decat 3kg.

        IAnimal pasare1 = new Bird(3.1);
        IAnimal pasare2 = new Bird(1.6);
        IAnimal porc1 = new Pig(34.6);
        IAnimal porc2 = new Pig(2.3);
        IAnimal vaca1 = new Cow(78.2);
        IAnimal vaca2 = new Cow(100.2);


        Repository repo = new Repository(10);
        Controller controller = new Controller(repo);
        View view = new View(controller);


        controller.addAnimal(pasare1);
        controller.addAnimal(pasare2);
        controller.addAnimal(porc1);
        controller.addAnimal(porc2);
        controller.addAnimal(vaca1);
        controller.addAnimal(vaca2);

        IAnimal[] animals = repo.getAll();

        boolean x = true;
        while(x){
            System.out.println("Select an option: ");
            System.out.println("Show the vector vector <show>");
            System.out.println("Add an animal in the vector <add>");
            System.out.println("Delete an animal from the vector <delete>");
            System.out.println("Filter the animals from the vector <filter>");

            Scanner scanner = new Scanner(System.in);
            String choice = scanner.nextLine();

            try{
                switch (choice) {
                    case "show" -> {
                        for (IAnimal animal : animals) {
                            if (animal != null) {
                                System.out.println(animal.toString());
                            }}
                    }
                    case "add" -> {
                        System.out.println("1.Bird ");
                        System.out.println("2.Cow ");
                        System.out.println("3.Pig ");
                        Scanner scanner2 = new Scanner(System.in);
                        String choice2 = scanner2.nextLine();
                        System.out.println("Give the kg of the animal: ");
                        Scanner scanner3 = new Scanner(System.in);
                        double choice3 = scanner2.nextDouble();
                        IAnimal animal = switch (choice2) {
                            case "1" -> new Bird(choice3);
                            case "2" -> new Cow(choice3);
                            case "3" -> new Pig(choice3);
                            default -> throw new MyException("Invalid choice");
                        };
                        System.out.println("Animal successfully added!");
                        controller.addAnimal(animal);

                    }
                    case "delete" ->
                    {
                        System.out.println("Introduce the kg of the animal you want to delete: ");
                        Scanner scanner3 = new Scanner(System.in);
                        double choice3 = scanner3.nextDouble();
                        controller.removeAnimal(choice3);
                    }
                    case "filter" -> {
                        System.out.println("Filter the animals so that we get the animals with their kg > 3");
                        IAnimal[] filteredAnimals = controller.filter();
                        for(IAnimal a : filteredAnimals){
                            if(a != null)
                                System.out.println(a.toString());
                        }

                    }
                    default -> throw new MyException("Invalid choice");
                }


            } catch (MyException e) {
                System.err.println("An error occured: " + e.getMessage());
            }

        }

        view.afisare(controller);

    }
}


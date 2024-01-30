package View;

import Controller.Controller;
import Model.IAnimal;

public class View {
    private Controller controller;
    public View(Controller controller){
        this.controller = controller;
    }

    public void afisare(Controller controller){
        for(IAnimal animal : controller.getAll()){
            System.out.println(animal);
        }
    }
}

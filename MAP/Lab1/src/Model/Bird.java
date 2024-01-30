package Model;

public class Bird implements IAnimal {
    private double kg;

    public Bird(double kg) {
        this.kg = kg;
    }

    @Override
    public String toString() {
        return "Pasare{" +
                "kg=" + kg +
                '}';
    }

    @Override
    public double getKg() {
        return kg;
    }

    @Override
    public boolean equal(Object ob){
        if(ob instanceof Bird){
            if(this.getKg() == ((Bird) ob).getKg()){
                return true;
            }
            else return false;
        }
        else return false;
    }
}


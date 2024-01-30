package Model;

public class Pig implements IAnimal {
    private double kg;

    public Pig(double kg) {
        this.kg = kg;
    }

    @Override
    public String toString() {
        return "Porc{" +
                "kg=" + kg +
                '}';
    }

    @Override
    public double getKg()
    {
        return kg;
    }

    @Override
    public boolean equal(Object ob){
        if(ob instanceof Pig){
            if(this.getKg() == ((Pig) ob).getKg()){
                return true;
            }
            else return false;
        }
        else return false;
    }
}

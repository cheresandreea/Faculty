package Model;

public class Cow implements IAnimal {
    private double kg;

    public Cow(double kg) {
        this.kg = kg;
    }

    @Override
    public String toString() {
        return "Vaca{" +
                "kg=" + kg +
                '}';
    }

    @Override
    public double getKg(){
        return kg;
    }

    @Override
    public boolean equal(Object ob){
        if(ob instanceof Cow){
            if(this.getKg() == ((Cow) ob).getKg()){
                return true;
            }
            else return false;
        }
        else return false;
    }
}


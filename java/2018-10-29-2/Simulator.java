public class Simulator{
    public void playSound(Animal animal){
        System.out.println("animal's name is:" + animal.getAnimalName());
        System.out.println("animal'sounds is:");animal.cry();
    }
}
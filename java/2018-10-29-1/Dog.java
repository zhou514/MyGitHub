public class Dog extends Animal{
    public void cry(){
        System.out.println("汪汪");
    }
    @Override
    public String getAnimalName() {
        return "dog";
    }
}
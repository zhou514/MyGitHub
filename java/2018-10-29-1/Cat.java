public class Cat extends Animal{
    @Override
    public void cry() {
        System.out.println("喵喵");
    }
    @Override
    public String getAnimalName() {
        return "Cat";
    }
}
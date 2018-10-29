
public class People {
	int age;
	int leg = 2;
	int hand = 2;
	private int sex = 0; //0 1 表示男女
	
	protected void showPeopleMessage() {
		System.out.printf("%d岁，%d只手，%d只腿\t",age,hand,leg);
	}
	
	public void getSex() {
		System.out.println(sex);
	}
}

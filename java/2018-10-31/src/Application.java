
public class Application {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ShowBoard borad = new ShowBoard();
		//向参数传递Output的子类OutputEnglish的对象
		borad.showMessage(new OutputEnglish());
		borad.showMessage(new Output() { //向参数传递Output的匿名子类
			
			@Override
			public void output() {
				// TODO Auto-generated method stub
				for(char ch = 'α';ch <= 'ω';ch++) {
					System.out.println(ch);
				}
			}
		});
	}

}

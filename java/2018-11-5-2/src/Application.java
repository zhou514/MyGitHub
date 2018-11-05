
public class Application {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CargoBoat ship = new CargoBoat();
		ship.setMaxContent(1000);
		int m = 600;
		try {
			ship.loading(m);
			m = 400;
			ship.loading(m);
			m = 200;
			ship.loading(m);
		}catch (DangerException e) {
			// TODO: handle exception
			System.out.println(e.warnMess());		
		}finally {
			System.out.println("货船将在下午5点启航！！！！！！");
		}
	}

}

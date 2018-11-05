
public class CargoBoat {
	int realContent; //实际装载的重量
	int maxContent; //最大的装载量
	
	public void setMaxContent(int c) {
		maxContent = c;
//		this.maxContent = c; //当局部变量与实体变量名称相同时，赋值语句要使用this关键字
		
	}
	public void loading(int m) throws DangerException {
		realContent += m;
		if(realContent > maxContent) {
			throw new DangerException();
		}
		System.out.println("111111111111");
	}
}


public class CargoBoat {
	int realContent; //ʵ��װ�ص�����
	int maxContent; //����װ����
	
	public void setMaxContent(int c) {
		maxContent = c;
//		this.maxContent = c; //���ֲ�������ʵ�����������ͬʱ����ֵ���Ҫʹ��this�ؼ���
		
	}
	public void loading(int m) throws DangerException {
		realContent += m;
		if(realContent > maxContent) {
			throw new DangerException();
		}
		System.out.println("111111111111");
	}
}

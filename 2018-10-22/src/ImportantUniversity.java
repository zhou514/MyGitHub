
public class ImportantUniversity extends University{
	String department;
	
	void setValue(String d) {
		//��д��Ŀ�ģ�����ͨ����������д�������ؼ̳еķ���������ͨ����������д���԰Ѹ����״̬����Ϊ�ı�Ϊ�����״̬����Ϊ��
		kindsOfClass = 5;
		this.department = d;
		System.out.println("������д����д֮��new���������д�ķ���");
		System.out.println("����department is " + d);
		System.out.println(kindsOfClass);
	}
	
	String f() {
		super.department = "IT Department";
		return super.department;
	}
	void f2() {
		System.out.println(super.ClassIsOver());
	}
	
	
}

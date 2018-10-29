
public class University {
	String department; 
	int kindsOfClass;

	void setValue(String d) {
		kindsOfClass = 10;
		this.department = d;
		System.out.println("∏∏¿‡department is " + d);
	}
	
	String ClassIsOver() {
		return (department + " " +kindsOfClass);
	}
}

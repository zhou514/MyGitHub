//try {}
//	catch(Exception e) {}
//	finally {//����try�����Ƿ����쳣��finally��䶼�ᱻִ��
//		}
//	}
//	���������
//	1.���try-catch������return��䣬��ôfinally��Ȼ�ᱻִ��
//	2.���try-catch����ִ���˳����˳����룬��ִ�� System.exit(0); ,�򲻻�ִ��finally����䣻��ȻҲ����ִ�к����������

public class DangerException extends Exception{
	final String message = "����";
	public String warnMess() {
		return message;
	}
}

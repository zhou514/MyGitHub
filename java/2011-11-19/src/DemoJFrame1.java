import java.awt.Color;
import java.awt.Container;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class DemoJFrame1 {
	public static void main(String args[]) {
		JFrame window1 = new JFrame();//����һ���ޱ���Ĵ��ڡ�
		JFrame window2 = new JFrame("hello java");//����һ���б���Ĵ���
		
		Container con1 = window1.getContentPane();
		con1.setBackground(Color.red);
		
		window1.setBounds(60,100,200,200);//���ô���λ�úʹ�С
		window2.setBounds(10, 60, 150, 180);
		window1.setVisible(true); //���ô��ڿɼ���Ĭ���ǲ��ɼ�
		window2.setVisible(true);
		
		window1.setResizable(false);//���ô��ڴ�С�Ƿ�ɵ�
		
//		window1.setJMenuBar(menubar); //ֻ���򴰿����һ���˵���
//		JMenu�����˵�
//		JMenuItem �˵���
//		�˵�ͼ�� icon������һ��ͼ�ꣻʹ��������ImageIcon����һ��ͼ��
//		Icon icon = new ImageIcon("a.jpg");
//		window1.setMenuBar(mb);
		
		window1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //����رգ��˳��رմ���
		window2.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//������ǰ���ڣ��ͷŴ���ʹ�õ���Դ
	}
}

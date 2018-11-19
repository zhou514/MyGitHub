import java.awt.Color;
import java.awt.Container;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class DemoJFrame1 {
	public static void main(String args[]) {
		JFrame window1 = new JFrame();//创建一个无标题的窗口。
		JFrame window2 = new JFrame("hello java");//创建一个有标题的窗口
		
		Container con1 = window1.getContentPane();
		con1.setBackground(Color.red);
		
		window1.setBounds(60,100,200,200);//设置窗口位置和大小
		window2.setBounds(10, 60, 150, 180);
		window1.setVisible(true); //设置窗口可见，默认是不可见
		window2.setVisible(true);
		
		window1.setResizable(false);//设置窗口大小是否可调
		
//		window1.setJMenuBar(menubar); //只能向窗口添加一个菜单条
//		JMenu创建菜单
//		JMenuItem 菜单项
//		菜单图标 icon类声明一个图标；使用其子类ImageIcon创建一个图标
//		Icon icon = new ImageIcon("a.jpg");
//		window1.setMenuBar(mb);
		
		window1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //点击关闭，退出关闭窗口
		window2.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//撤销当前窗口，释放窗口使用的资源
	}
}

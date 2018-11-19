import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class WindowMenu extends JFrame{
	//����
	JMenuBar menuBar; //�˵���
	JMenu menu; //�˵�
	JMenu subMenu; //���Ӳ˵��Ĳ˵���
	JMenuItem item1,item2; //�Ӳ˵���
	
	//����
	//���췽��
	public WindowMenu() {}
	public WindowMenu(String s,int x,int y,int w,int h) {
		init(s);
		setLocation(x, y);
		setSize(w, h);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	
	//�˵���ʼ������
	void init(String s) {
		setTitle(s);
		menuBar = new JMenuBar();
		menu = new JMenu("�˵�");
		subMenu = new JMenu("��������");
		item1 = new JMenuItem("��ѧ����", new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\a.gif"));
		item2 = new JMenuItem("��⿻���", new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\b.gif"));
		menu.add(item1);
		menu.add(item2);
		menu.add(subMenu);
		subMenu.add(new JMenuItem("����",new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\c.gif")));
		subMenu.add(new JMenuItem("����",new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\d.gif")));
		menuBar.add(menu);
		setJMenuBar(menuBar);
	}
}

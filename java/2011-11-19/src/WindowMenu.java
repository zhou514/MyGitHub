import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class WindowMenu extends JFrame{
	//属性
	JMenuBar menuBar; //菜单条
	JMenu menu; //菜单
	JMenu subMenu; //带子菜单的菜单名
	JMenuItem item1,item2; //子菜单名
	
	//方法
	//构造方法
	public WindowMenu() {}
	public WindowMenu(String s,int x,int y,int w,int h) {
		init(s);
		setLocation(x, y);
		setSize(w, h);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	
	//菜单初始化方法
	void init(String s) {
		setTitle(s);
		menuBar = new JMenuBar();
		menu = new JMenu("菜单");
		subMenu = new JMenu("体育话题");
		item1 = new JMenuItem("文学话题", new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\a.gif"));
		item2 = new JMenuItem("烹饪话题", new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\b.gif"));
		menu.add(item1);
		menu.add(item2);
		menu.add(subMenu);
		subMenu.add(new JMenuItem("足球",new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\c.gif")));
		subMenu.add(new JMenuItem("篮球",new ImageIcon("C:\\Develop\\eclipse-workspace\\2011-11-19\\src\\d.gif")));
		menuBar.add(menu);
		setJMenuBar(menuBar);
	}
}

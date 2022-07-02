import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class DrawerFrame extends JFrame {

  DrawerFrame() {
    setTitle("Drawer");

//    화면 2/3의 크기의 프레임 만들어서 가운데 위치 시키기
    Toolkit tk = Toolkit.getDefaultToolkit();
    Dimension d = tk.getScreenSize();
    int scrHeight = d.height;
    int scrWidth = d.width;
    setSize(scrWidth * 2 / 3, scrHeight * 2 / 3);
    setLocation(scrWidth / 6, scrHeight / 6);

//    메뉴바 생성
    JMenuBar menus = new JMenuBar();
    setJMenuBar(menus);

    JMenu fileMenu = new JMenu("파일(F)");
    menus.add(fileMenu);

    JMenuItem newFile = new JMenuItem("새 파일(N)");
    fileMenu.add(newFile);
    JMenuItem openFile = new JMenuItem("열기(N)");
    fileMenu.add(openFile);
    JMenuItem saveFile = new JMenuItem("저장(N)");
    fileMenu.add(saveFile);
    JMenuItem anotherFile = new JMenuItem("다른 이름으로 저장(N)");
    fileMenu.add(anotherFile);
    JMenuItem exit = new JMenuItem("종료(X)");
    fileMenu.add(exit);

    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }
}
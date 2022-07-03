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
//    아이콘 추가
    Image img = tk.getImage("img/ball.gif");
    setIconImage(img);

//    메뉴바 생성
    JMenuBar menus = new JMenuBar();
    setJMenuBar(menus);

//    파일 메뉴
    JMenu fileMenu = new JMenu("파일(F)");
    menus.add(fileMenu);

    JMenuItem newFile = new JMenuItem("새 파일(N)");
    fileMenu.add(newFile);
    newFile.setMnemonic('N');
    newFile.setIcon(new ImageIcon("img/new.gif"));
    newFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, InputEvent.CTRL_DOWN_MASK));
    newFile.addActionListener((e) -> {
      System.out.println("test");
    });

    JMenuItem openFile = new JMenuItem("열기(O)");
    fileMenu.add(openFile);
    openFile.setMnemonic('O');
    openFile.setIcon(new ImageIcon("img/open.gif"));
    openFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, InputEvent.CTRL_DOWN_MASK));

    JMenuItem saveFile = new JMenuItem("저장(S)");
    fileMenu.add(saveFile);
    saveFile.setMnemonic('S');
    saveFile.setIcon(new ImageIcon("img/save.gif"));
    saveFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_DOWN_MASK));

    JMenuItem anotherFile = new JMenuItem("다른 이름으로 저장(A)");
    fileMenu.add(anotherFile);

    fileMenu.addSeparator();

    JMenuItem exit = new JMenuItem("종료(X)");
    fileMenu.add(exit);
    exit.addActionListener((e) -> {
      System.exit(0);
    });

//    도움말 메뉴
    JMenu helpMenu = new JMenu("도움말(H)");
    menus.add(helpMenu);

    JMenuItem infoHelp = new JMenuItem("Drawer 정보(I)");
    helpMenu.add(infoHelp);

    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }
}
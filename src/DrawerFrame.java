import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class DrawerFrame extends JFrame {

  DrawerView view;
  StatusBar statusBar;

  DrawerFrame() {
    statusBar = new StatusBar();
    view = new DrawerView(this);

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

//    그림 선택 메뉴
    JMenu figureMenu = new JMenu("그림(F)");
    menus.add(figureMenu);

    JMenuItem figurePoint = new JMenuItem(view.getPointAction());
    figureMenu.add(figurePoint);
    JMenuItem figureBox = new JMenuItem(view.getBoxAction());
    figureMenu.add(figureBox);
    JMenuItem figureLine = new JMenuItem(view.getLineAction());
    figureMenu.add(figureLine);
    JMenuItem figureCircle = new JMenuItem(view.getCircleAction());
    figureMenu.add(figureCircle);

//    Dialog 메뉴
    JMenu toolMenu = new JMenu("도구(T)");
    menus.add(toolMenu);

    JMenuItem modalTool = new JMenuItem("Modal(M)");
    toolMenu.add(modalTool);
    modalTool.addActionListener((e) -> {
      FigureDialog dialog = new FigureDialog("Figure Dialog", view);
      dialog.setModal(true);
      dialog.setVisible(true);
    });
    JMenuItem modalessTool = new JMenuItem("Modaless(S)");
    toolMenu.add(modalessTool);
    modalessTool.addActionListener((e) -> {
      FigureDialog dialog = new FigureDialog("Figure Dialog ", view);
      dialog.setModal(false);
      dialog.setVisible(true);
    });

//    도움말 메뉴
    JMenu helpMenu = new JMenu("도움말(H)");
    menus.add(helpMenu);

    JMenuItem infoHelp = new JMenuItem("Drawer 정보(I)");
    helpMenu.add(infoHelp);
    infoHelp.addActionListener((e) -> {
      JOptionPane.showMessageDialog(null,
          "Java Swing GUI Programming practice.\r\nThanks to Prof. Tae Gyun Kim",
          "XDrawer with Java",
          JOptionPane.INFORMATION_MESSAGE);
    });

//    Content panel 생성
    Container container = this.getContentPane();
    container.add(view, "Center");
    container.add(statusBar, "South");

    addComponentListener(new ComponentAdapter() {
      public void componentResized(ComponentEvent e) {
        Dimension sz = view.getSize();
        String s = sz.width + " X " + sz.height + "px";
        statusBar.writeSize(s);
      }
    });

    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  public void writePosition(String s) {
    statusBar.writePosition(s);
  }

  public void writeFigureType(String s) {
    statusBar.writeFigureType(s);
  }
}
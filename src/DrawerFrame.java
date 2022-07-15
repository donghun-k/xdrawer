import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class DrawerFrame extends JFrame {

  DrawerView view;
  StatusBar statusBar;
  FigureDialog dialog;
  TableDialog tableDialog;
  JScrollPane sp;

  DrawerFrame() {
    setTitle("Drawer");

    statusBar = new StatusBar();
    view = new DrawerView(this);

//    스크롤 바
    sp = new JScrollPane(view);
    sp.registerKeyboardAction(e -> {
          JScrollBar scrollBar = sp.getVerticalScrollBar();
          scrollBar.setValue(scrollBar.getValue() + scrollBar.getBlockIncrement());
        }
        , KeyStroke.getKeyStroke(KeyEvent.VK_PAGE_DOWN, 0)
        , JComponent.WHEN_IN_FOCUSED_WINDOW);
    sp.registerKeyboardAction(e -> {
          JScrollBar scrollBar = sp.getVerticalScrollBar();
          scrollBar.setValue(scrollBar.getValue() - scrollBar.getBlockIncrement());
        }
        , KeyStroke.getKeyStroke(KeyEvent.VK_PAGE_UP, 0)
        , JComponent.WHEN_IN_FOCUSED_WINDOW);
    sp.registerKeyboardAction(e -> {
          JScrollBar scrollBar = sp.getHorizontalScrollBar();
          scrollBar.setValue(scrollBar.getValue() + scrollBar.getBlockIncrement());
        }
        , KeyStroke.getKeyStroke(KeyEvent.VK_PAGE_DOWN, InputEvent.CTRL_DOWN_MASK)
        , JComponent.WHEN_IN_FOCUSED_WINDOW);
    sp.registerKeyboardAction(e -> {
          JScrollBar scrollBar = sp.getHorizontalScrollBar();
          scrollBar.setValue(scrollBar.getValue() - scrollBar.getBlockIncrement());
        }
        , KeyStroke.getKeyStroke(KeyEvent.VK_PAGE_UP, InputEvent.CTRL_DOWN_MASK)
        , JComponent.WHEN_IN_FOCUSED_WINDOW);
    sp.registerKeyboardAction(e -> view.increaseHeight()
        , KeyStroke.getKeyStroke(KeyEvent.VK_PAGE_DOWN, InputEvent.ALT_DOWN_MASK)
        , JComponent.WHEN_IN_FOCUSED_WINDOW);
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
    JMenuItem figureTV = new JMenuItem(view.getTVAction());
    figureMenu.add(figureTV);
    JMenuItem figureKite = new JMenuItem(view.getKiteAction());
    figureMenu.add(figureKite);

//    Dialog 메뉴
    JMenu toolMenu = new JMenu("도구(T)");
    menus.add(toolMenu);

    JMenuItem modalTool = new JMenuItem("Modal(M)");
    toolMenu.add(modalTool);
    modalTool.addActionListener((e) -> {
      if (dialog == null) {
        dialog = new FigureDialog("Figure Dialog", view);
      }
      dialog.setModal(true);
      dialog.setVisible(true);
    });
    JMenuItem modalessTool = new JMenuItem("Modaless(S)");
    toolMenu.add(modalessTool);
    modalessTool.addActionListener((e) -> {
      if (dialog == null) {
        dialog = new FigureDialog("Figure Dialog", view);
      }
      dialog.setModal(false);
      dialog.setVisible(true);
    });
    JMenuItem tableTool = new JMenuItem("Table(T)");
    toolMenu.add(tableTool);
    tableTool.addActionListener((e) -> {
      if (tableDialog == null) {
        tableDialog = new TableDialog("Table Dialog", view);
        tableDialog.setModal(true);
      }
      tableDialog.setVisible(true);
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

//    Tool bar
    JToolBar selectToolBar = new JToolBar();
    selectToolBar.add(view.getPointAction());
    selectToolBar.add(view.getBoxAction());
    selectToolBar.add(view.getLineAction());
    selectToolBar.add(view.getCircleAction());
    selectToolBar.add(view.getTVAction());
    selectToolBar.add(view.getKiteAction());

//    Content panel 생성
    Container container = this.getContentPane();
    container.add(sp, "Center");
    container.add(statusBar, "South");
    container.add(selectToolBar, "North");

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

  public void writeSize(String s) {
    statusBar.writeSize(s);
  }
}
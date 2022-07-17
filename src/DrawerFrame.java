import java.awt.Container;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import javax.swing.ImageIcon;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JToolBar;
import javax.swing.KeyStroke;
import javax.swing.filechooser.FileNameExtensionFilter;

class DrawerFrame extends JFrame {

  DrawerView view;
  StatusBar statusBar;
  FigureDialog dialog;
  TableDialog tableDialog;
  TreeDialog treeDialog;
  JScrollPane sp;

  String fileName = "noname.jdr";

  DrawerFrame() {
    setTitle("Drawer - [noname.jdr]");

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
    Image img = tk.getImage("img/icon.png");
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
      view.doFileNew();
    });

    JMenuItem openFile = new JMenuItem("열기(O)");
    fileMenu.add(openFile);
    openFile.setMnemonic('O');
    openFile.setIcon(new ImageIcon("img/open.gif"));
    openFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, InputEvent.CTRL_DOWN_MASK));
    openFile.addActionListener(e -> doOpen());

    JMenuItem saveFile = new JMenuItem("저장(S)");
    fileMenu.add(saveFile);
    saveFile.setMnemonic('S');
    saveFile.setIcon(new ImageIcon("img/save.gif"));
    saveFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_DOWN_MASK));
    saveFile.addActionListener(e -> {
      view.doSave(fileName);
    });

    JMenuItem anotherFile = new JMenuItem("다른 이름으로 저장(A)");
    fileMenu.add(anotherFile);
    anotherFile.addActionListener(e -> doSaveAs());

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
//    테이블
    JMenuItem tableTool = new JMenuItem("Table(T)");
    toolMenu.add(tableTool);
    tableTool.addActionListener((e) -> {
      if (tableDialog == null) {
        tableDialog = new TableDialog("Table Dialog", view);
        tableDialog.setModal(true);
      }
      tableDialog.setVisible(true);
    });
//    트리
    JMenuItem treeTool = new JMenuItem("Tree(R)");
    toolMenu.add(treeTool);
    treeTool.addActionListener(e -> {
      if (treeDialog == null) {
        treeDialog = new TreeDialog("Tree Dialog", view);
        treeDialog.setModal(true);
      }
      treeDialog.setVisible(true);
    });

//    Zoom 메뉴
    JMenu zoomMenu = new JMenu("Zoom");
    toolMenu.add(zoomMenu);

    JMenuItem zoom100 = new JMenuItem("100%");
    zoomMenu.add(zoom100);
    zoom100.addActionListener(e -> {
      view.zoom(100);
    });
    JMenuItem zoom80 = new JMenuItem("80%");
    zoomMenu.add(zoom80);
    zoom80.addActionListener(e -> {
      view.zoom(80);
    });
    JMenuItem zoom50 = new JMenuItem("50%");
    zoomMenu.add(zoom50);
    zoom50.addActionListener(e -> {
      view.zoom(50);
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
    selectToolBar.add(new ZoomBox(view));
    selectToolBar.add(javax.swing.Box.createGlue());

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

  public void doOpen() {
    JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
    chooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
    chooser.setDialogType(JFileChooser.OPEN_DIALOG);
    chooser.setFileFilter(new FileNameExtensionFilter("JDrawer file", "jdr"));
    int value = chooser.showOpenDialog(null);
    if (value != JFileChooser.APPROVE_OPTION) {
      return;
    }
    fileName = chooser.getSelectedFile().getPath();
    setTitle("Drawer - [" + fileName + "]");
    view.doOpen(fileName);
  }

  public void doSaveAs() {
    JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
    chooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
    chooser.setDialogType(JFileChooser.SAVE_DIALOG);
    chooser.setFileFilter(new FileNameExtensionFilter("JDrawer file", "jdr"));
    int value = chooser.showSaveDialog(null);
    if (value != JFileChooser.APPROVE_OPTION) {
      return;
    }
    fileName = chooser.getSelectedFile().getPath();
    if (fileName.endsWith(".jdr") == false) {
      fileName = fileName + ".jdr";
    }
    setTitle("Drawer - [" + fileName + "]");
    view.doSave(fileName);
  }

  static class ZoomBox extends JComboBox implements ActionListener {


    static String[] size = {"100", "80", "50"};
    DrawerView view;

    ZoomBox(DrawerView view) {
      super(size);
      this.view = view;
      setMaximumSize(new Dimension(1500, 200));
      addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
      JComboBox box = (JComboBox) e.getSource();
      String ratio = (String) box.getSelectedItem();
      view.zoom(Integer.parseInt(ratio));
    }
  }
}
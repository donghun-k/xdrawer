import java.util.ArrayList;
import javax.swing.JColorChooser;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;
import javax.swing.JPopupMenu;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  public static int DRAW_POINT = 1;
  public static int DRAW_BOX = 2;
  public static int DRAW_LINE = 3;
  public static int DRAW_CIRCLE = 4;

  public static int NOTHING = 0;
  public static int DRAWING = 1;
  public static int MOVING = 2;

  private int actionMode;
  private int whatToDraw;
  private Figure selectedFigure;
  // polymorphic collection or polymorphic container
  private ArrayList<Figure> figures = new ArrayList<Figure>();

  private int currentX;
  private int currentY;


  Popup mainPopup;
  Popup pointPopup;
  Popup boxPopup;
  Popup linePopup;
  Popup circlePopup;

  DrawerView() {
    actionMode = 0;
    whatToDraw = 2;
    selectedFigure = null;
    mainPopup = new MainPopup(this);
    pointPopup = new FigurePopup(this, "Point", false);
    boxPopup = new FigurePopup(this, "Box", true);
    linePopup = new FigurePopup(this, "Line", false);
    circlePopup = new FigurePopup(this, "Circle", true);
    addMouseListener(this);
    addMouseMotionListener(this);
  }

  void setWhatToDraw(int figureType) {
    whatToDraw = figureType;
  }

  //  팝업 getter
  public Popup getPointPopup() {
    return pointPopup;
  }

  public Popup getBoxPopup() {
    return boxPopup;
  }

  public Popup getLinePopup() {
    return linePopup;
  }

  public Popup getCirclePopup() {
    return circlePopup;
  }


  //  색 설정
  void setFigureColor(Color color) {
    if (selectedFigure == null) {
      return;
    }
    selectedFigure.setColor(color);
    repaint();
  }

  void setBlackColor() {
    setFigureColor(Color.black);
  }

  void setRedColor() {
    setFigureColor(Color.red);
  }

  void setGreenColor() {
    setFigureColor(Color.green);
  }

  void setBlueColor() {
    setFigureColor(Color.blue);
  }

  void showColorChooser() {
    new JColorChooser();
    Color color = JColorChooser.showDialog(null, "Color Choose", Color.black);
    setFigureColor(color);
  }


  //  paint event 시 자동 호출
  public void paintComponent(Graphics g) {

    super.paintComponent(g);

    // Collection에 담긴 그림 객체 순회하면서 그리기
    for (Figure pFigure : figures) {
      pFigure.draw(g);
    }
  }

  public void addFigure(Figure newFigure) {
    newFigure.makeRegion();
    figures.add(newFigure);
    repaint();
  }

  public void deleteFigure() {
    if (selectedFigure == null) {
      return;
    }
    figures.remove(selectedFigure);
    selectedFigure = null;
    repaint();
  }

  public void copyFigure() {
    if (selectedFigure == null) {
      return;
    }
    Figure newFigure = selectedFigure.copy();
    addFigure(newFigure);
    selectedFigure = newFigure;
  }

  public void fillFigure() {
    if (selectedFigure == null) {
      return;
    }
    selectedFigure.setFill();
    repaint();
  }

  private Figure find(int x, int y) {
    for (Figure pFigure : figures) {
      if (pFigure.contains(x, y)) {
        return pFigure;
      }
    }
    return (Figure) null;
  }

  //  마우스 이벤트 리스너
  public void mousePressed(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    if (e.getButton() == MouseEvent.BUTTON3) {
      actionMode = NOTHING;
      return;
    }

    selectedFigure = find(x, y);
    if (selectedFigure != null) {
      actionMode = MOVING;
      currentX = x;
      currentY = y;
      figures.remove(selectedFigure);
      repaint();
      return;
    }

    if (whatToDraw == DRAW_POINT) {
      selectedFigure = new Point(Color.black, x, y);
      selectedFigure.setPopup(pointPopup);
    } else if (whatToDraw == DRAW_BOX) {
      selectedFigure = new Box(Color.black, x, y);
      selectedFigure.setPopup(boxPopup);
    } else if (whatToDraw == DRAW_LINE) {
      selectedFigure = new Line(Color.black, x, y);
      selectedFigure.setPopup(linePopup);
    } else if (whatToDraw == DRAW_CIRCLE) {
      selectedFigure = new Circle(Color.black, x, y);
      selectedFigure.setPopup(circlePopup);
    }
    actionMode = DRAWING;

  }

  public void mouseMoved(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    selectedFigure = find(x, y);
    if (selectedFigure != null) {
      setCursor(Cursor.getPredefinedCursor(Cursor.MOVE_CURSOR));
    } else {
      setCursor(Cursor.getDefaultCursor());
    }
  }

  public void mouseDragged(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    Graphics g = getGraphics();
    g.setXORMode(getBackground());
    if (actionMode == DRAWING) {
      selectedFigure.drawing(g, x, y);
    } else if (actionMode == MOVING) {
      selectedFigure.move(g, x - currentX, y - currentY);
      currentX = x;
      currentY = y;
    }
  }

  public void mouseReleased(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    //    마우스 우클릭
    if (e.isPopupTrigger()) {
      selectedFigure = find(x, y);
      if (selectedFigure == null) {
        mainPopup.popup(x, y);
      } else {
        selectedFigure.popup(x, y);
      }
      return;
    }

    Graphics g = getGraphics();
    if (actionMode == DRAWING) {
      selectedFigure.setXY2(x, y);
    }
    selectedFigure.draw(g);
    addFigure(selectedFigure);
    selectedFigure = null;
  }

  public void mouseClicked(MouseEvent e) {

  }

  public void mouseEntered(MouseEvent e) {

  }

  public void mouseExited(MouseEvent e) {

  }
}

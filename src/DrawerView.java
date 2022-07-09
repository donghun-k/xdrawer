import java.util.ArrayList;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  public static int DRAW_BOX = 1;
  public static int DRAW_LINE = 2;

  public static int NOTHING = 0;
  public static int DRAWING = 1;
  public static int MOVING = 2;

  private int actionMode;
  private int whatToDraw;
  private Figure currentFigure;
  // polymorphic collection or polymorphic container
  private ArrayList<Figure> figures = new ArrayList<Figure>();

  private int currentX;
  private int currentY;

  DrawerView() {
    actionMode = 0;
    whatToDraw = 1;
    currentFigure = null;
    addMouseListener(this);
    addMouseMotionListener(this);
  }

  void setWhatToDraw(int figureType) {
    whatToDraw = figureType;
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

  private Figure find(int x, int y) {
    for (int i = 0; i < figures.size(); i++) {
      Figure pFigure = figures.get(i);
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
//    마우스 우클릭
    if (e.isPopupTrigger()) {
      return;
    }

    currentFigure = find(x, y);
    if (currentFigure != null) {
      actionMode = MOVING;
      currentX = x;
      currentY = y;
      figures.remove(currentFigure);
      repaint();
      return;
    }

    if (whatToDraw == DRAW_BOX) {
      currentFigure = new Box(x, y);
    } else if (whatToDraw == DRAW_LINE) {
      currentFigure = new Line(x, y);
    }
    actionMode = DRAWING;

  }

  public void mouseMoved(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    currentFigure = find(x, y);
    if (currentFigure != null) {
      setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
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
      currentFigure.drawing(g, x, y);
    } else if (actionMode == MOVING) {
      currentFigure.move(g, x - currentX, y - currentY);
      currentX = x;
      currentY = y;
    }
  }

  public void mouseReleased(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    Graphics g = getGraphics();
    if (actionMode == DRAWING) {
      currentFigure.setXY2(x, y);
    }
    currentFigure.draw(g);
    addFigure(currentFigure);
    currentFigure = null;
  }

  public void mouseClicked(MouseEvent e) {

  }

  public void mouseEntered(MouseEvent e) {

  }

  public void mouseExited(MouseEvent e) {

  }
}

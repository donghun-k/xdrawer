import java.util.ArrayList;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  public static int DRAW_BOX = 1;
  public static int DRAW_LINE = 2;

  private int whatToDraw;
  private Figure currentFigure;
  // polymorphic collection or polymorphic container
  private ArrayList<Figure> figures = new ArrayList<Figure>();

  DrawerView() {
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

  //  마우스 이벤트 리스너
  public void mouseClicked(MouseEvent e) {

  }

  public void mousePressed(MouseEvent e) {
    if (whatToDraw == DRAW_BOX) {
      currentFigure = new Box(e.getX(), e.getY());
    } else if (whatToDraw == DRAW_LINE) {
      currentFigure = new Line(e.getX(), e.getY());
    }

  }

  public void mouseReleased(MouseEvent e) {
    Graphics g = getGraphics();

    currentFigure.setXY2(e.getX(), e.getY());
    currentFigure.draw(g);
    figures.add(currentFigure);
    currentFigure = null;
  }

  public void mouseEntered(MouseEvent e) {

  }

  public void mouseExited(MouseEvent e) {

  }

  public void mouseMoved(MouseEvent e) {

  }

  public void mouseDragged(MouseEvent e) {
    Graphics g = getGraphics();
    g.setXORMode(getBackground());
    currentFigure.drawing(g, e.getX(), e.getY());
    currentFigure.drawing(g, e.getX(), e.getY());
  }
}

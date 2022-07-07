import java.util.ArrayList;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  public static int DRAW_BOX = 1;
  public static int DRAW_LINE = 2;

  private int whatToDraw;
  private Box pBox;
  private ArrayList<Box> boxes = new ArrayList<Box>();

  DrawerView() {
    whatToDraw = 0;
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
    for (Box p : boxes) {
      pBox.draw(g);
    }
  }

  //  마우스 이벤트 리스너
  public void mouseClicked(MouseEvent e) {

  }

  public void mousePressed(MouseEvent e) {
    if (whatToDraw == DRAW_BOX) {
      pBox = new Box(e.getX(), e.getY());
      boxes.add(pBox);
    }

  }

  public void mouseReleased(MouseEvent e) {
    Graphics g = getGraphics();

    pBox.setXY2(e.getX(), e.getY());
    pBox.draw(g);
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
    pBox.drawing(g, e.getX(), e.getY());
    pBox.drawing(g, e.getX(), e.getY());
  }
}

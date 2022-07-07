import java.util.ArrayList;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  static int MAX = 100;
  private Box pBox;
  private ArrayList<Box> boxes = new ArrayList<Box>();

  DrawerView() {
    addMouseListener(this);
    addMouseMotionListener(this);
  }

  //  paint event 시 자동 호출
  public void paintComponent(Graphics g) {

    super.paintComponent(g);

    for (int i = 0; i < boxes.size(); i++) {
      Box tBox = boxes.get(i);
      tBox.draw(g);
    }
  }

  //  마우스 이벤트 리스너
  public void mouseClicked(MouseEvent e) {

  }

  public void mousePressed(MouseEvent e) {
    pBox = new Box(e.getX(), e.getY());

    boxes.add(pBox);
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

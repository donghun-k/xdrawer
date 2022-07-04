import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  int startX;
  int startY;

  DrawerView() {
    startX = 0;
    startY = 0;

    addMouseListener(this);
    addMouseMotionListener(this);
  }

  //  paint event 시 자동 호출
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
  }

  //  마우스 이벤트 리스너
  public void mouseClicked(MouseEvent e) {

  }

  public void mousePressed(MouseEvent e) {
    startX = e.getX();
    startY = e.getY();
  }

  public void mouseReleased(MouseEvent e) {
    int endX = e.getX();
    int endY = e.getY();

    int minX = Math.min(startX, endX);
    int minY = Math.min(startY, endY);
    int width = Math.abs(endX - startX);
    int height = Math.abs(endY - startY);

    Graphics g = getGraphics();
    g.drawRect(minX, minY, width, height);
  }

  public void mouseEntered(MouseEvent e) {

  }

  public void mouseExited(MouseEvent e) {

  }

  public void mouseMoved(MouseEvent e) {

  }

  public void mouseDragged(MouseEvent e) {
    int endX = e.getX();
    int endY = e.getY();

    int minX = Math.min(startX, endX);
    int minY = Math.min(startY, endY);
    int width = Math.abs(endX - startX);
    int height = Math.abs(endY - startY);

    Graphics g = getGraphics();
    g.drawRect(minX, minY, width, height);
  }
}

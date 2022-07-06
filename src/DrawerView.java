import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel implements MouseListener, MouseMotionListener {

  static int MAX = 100;
  Box pBox;
  Box boxes[];
  int nBox;

  DrawerView() {
    pBox = null;
    boxes = new Box[MAX];
    nBox = 0;
    addMouseListener(this);
    addMouseMotionListener(this);
  }

  //  paint event 시 자동 호출
  public void paintComponent(Graphics g) {

    super.paintComponent(g);

    for (int i = 0; i < nBox; i++) {
      int minX = Math.min(boxes[i].x1, boxes[i].x2);
      int minY = Math.min(boxes[i].y1, boxes[i].y2);
      int width = Math.abs(boxes[i].x2 - boxes[i].x1);
      int height = Math.abs(boxes[i].y2 - boxes[i].y1);

      g.drawRect(minX, minY, width, height);
    }
  }

  //  마우스 이벤트 리스너
  public void mouseClicked(MouseEvent e) {

  }

  public void mousePressed(MouseEvent e) {
    pBox = new Box(e.getX(), e.getY());
    boxes[nBox++] = pBox;
  }

  public void mouseReleased(MouseEvent e) {
    pBox.x2 = e.getX();
    pBox.y2 = e.getY();

    int minX = Math.min(pBox.x1, pBox.x2);
    int minY = Math.min(pBox.y1, pBox.y2);
    int width = Math.abs(pBox.x2 - pBox.x1);
    int height = Math.abs(pBox.y2 - pBox.y1);

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
//    이전 그림 지우기
    int minX = Math.min(pBox.x1, pBox.x2);
    int minY = Math.min(pBox.y1, pBox.y2);
    int width = Math.abs(pBox.x2 - pBox.x1);
    int height = Math.abs(pBox.y2 - pBox.y1);

    Graphics g = getGraphics();
    g.setXORMode(getBackground());
    g.drawRect(minX, minY, width, height);
    g.setPaintMode();

//    새 그림 그리기
    pBox.x2 = e.getX();
    pBox.y2 = e.getY();

    minX = Math.min(pBox.x1, pBox.x2);
    minY = Math.min(pBox.y1, pBox.y2);
    width = Math.abs(pBox.x2 - pBox.x1);
    height = Math.abs(pBox.y2 - pBox.y1);

    g.setColor(Color.black);
    g.drawRect(minX, minY, width, height);
  }
}

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyMouseListener implements MouseListener {

  DrawerFrame frame;

  MyMouseListener(DrawerFrame frame) {
    this.frame = frame;
  }

  @Override
  public void mouseClicked(MouseEvent e) {

  }

  @Override
  public void mousePressed(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();
    Graphics g = frame.getGraphics();
    g.drawLine(x - 10, y - 10, x + 10, y + 10);
    g.drawLine(x + 10, y - 10, x - 10, y + 10);
  }

  @Override
  public void mouseReleased(MouseEvent e) {

  }

  @Override
  public void mouseEntered(MouseEvent e) {

  }

  @Override
  public void mouseExited(MouseEvent e) {

  }
}

class DrawerFrame extends JFrame {

  DrawerFrame() {
    setTitle("Drawer");
    setSize(700, 500);
    setLocation(100, 100);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    addMouseListener(new MyMouseListener(this));
  }
}

public class Drawer {

  public static void main(String[] args) {
    JFrame drawerFrame = new DrawerFrame();
    drawerFrame.setVisible(true);
  }
}

import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;

public class DrawerView extends JPanel {

  DrawerView() {
  }

  //  paint event 시 자동 호출
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.drawLine(0, 0, 200, 200);
  }
}

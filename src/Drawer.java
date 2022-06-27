import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class DrawerFrame extends JFrame {

  DrawerFrame() {
    setTitle("Drawer");
    setSize(700, 500);
    setLocation(100, 100);
  }
}

public class Drawer {

  public static void main(String[] args) {
    JFrame drawerFrame = new DrawerFrame();
    drawerFrame.setVisible(true);
  }
}

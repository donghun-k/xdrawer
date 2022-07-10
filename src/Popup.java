import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;

public class Popup {

  DrawerView view;
  JPopupMenu popupPtr;

  Popup(DrawerView view, String title) {
    this.view = view;
    popupPtr = new JPopupMenu();
    popupPtr.add(title);
    popupPtr.addSeparator();
  }

  public void popup(int x, int y) {
    popupPtr.show(view, x, y);
  }

}

import java.io.Serializable;
import javax.swing.JPopupMenu;

public class Popup implements Serializable {

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

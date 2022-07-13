import javax.swing.AbstractAction;
import javax.swing.ImageIcon;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;

public class MainPopup extends Popup {


  MainPopup(DrawerView view) {
    super(view, "그림");
    JMenuItem pointItem = new JMenuItem(view.getPointAction());
    popupPtr.add(pointItem);
    JMenuItem boxItem = new JMenuItem(view.getBoxAction());
    popupPtr.add(boxItem);
    JMenuItem lineItem = new JMenuItem(view.getLineAction());
    popupPtr.add(lineItem);
    JMenuItem circleItem = new JMenuItem(view.getCircleAction());
    popupPtr.add(circleItem);
    JMenuItem tvItem = new JMenuItem(view.getTVAction());
    popupPtr.add(tvItem);
  }
}

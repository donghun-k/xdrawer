import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;

public class MainPopup extends Popup {


  MainPopup(DrawerView view) {
    super(view, "그림");
    JMenuItem boxItem = new JMenuItem("Box(B)");
    popupPtr.add(boxItem);
    boxItem.addActionListener((event) -> {
      view.setWhatToDraw(DrawerView.DRAW_BOX);
    });
    JMenuItem lineItem = new JMenuItem("Line(L)");
    popupPtr.add(lineItem);
    lineItem.addActionListener((event) -> {
      view.setWhatToDraw(DrawerView.DRAW_LINE);
    });
  }
}

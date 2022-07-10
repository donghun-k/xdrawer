import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;

public class FigurePopup extends Popup {

  FigurePopup(DrawerView view, String title, boolean fillFlag) {
    super(view, title);
    JMenuItem deleteItem = new JMenuItem("Delete");
    deleteItem.addActionListener(e -> view.deleteFigure());
    popupPtr.add(deleteItem);

    JMenuItem copyItem = new JMenuItem("Copy");
    copyItem.addActionListener(e -> view.copyFigure());
    popupPtr.add(copyItem);
  }
}
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;

public class FigurePopup extends Popup {

  FigurePopup(DrawerView view, String title, boolean isFillable) {
    super(view, title);
    JMenuItem deleteItem = new JMenuItem("Delete");
    deleteItem.addActionListener(e -> view.deleteFigure());
    popupPtr.add(deleteItem);

    JMenuItem copyItem = new JMenuItem("Copy");
    copyItem.addActionListener(e -> view.copyFigure());
    popupPtr.add(copyItem);

    JMenu colorMenu = new JMenu("Colors");
    popupPtr.add(colorMenu);

    JMenuItem blackItem = new JMenuItem("Black");
    blackItem.addActionListener((e) -> view.setBlackColor());
    colorMenu.add(blackItem);
    JMenuItem redItem = new JMenuItem("Red");
    redItem.addActionListener((e) -> view.setRedColor());
    colorMenu.add(redItem);
    JMenuItem greenItem = new JMenuItem("Green");
    greenItem.addActionListener((e) -> view.setGreenColor());
    colorMenu.add(greenItem);
    JMenuItem blueItem = new JMenuItem("Blue");
    blueItem.addActionListener((e) -> view.setBlueColor());
    colorMenu.add(blueItem);
    JMenuItem chooserItem = new JMenuItem("choose");
    chooserItem.addActionListener(e -> view.showColorChooser());
    colorMenu.add(chooserItem);

    if (isFillable) {
      JMenuItem fillItem = new JMenuItem("Fill");
      fillItem.addActionListener(e -> view.fillFigure());
      popupPtr.add(fillItem);
    }

  }
}
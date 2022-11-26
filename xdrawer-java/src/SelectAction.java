import java.io.Serial;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class SelectAction extends AbstractAction {

  @Serial
  private static final long serialVersionUID = 1201423933277417991L;
  private DrawerView view;

  public SelectAction(String name, Icon icon, DrawerView view, int id) {
    putValue(Action.NAME, name);
    putValue(Action.SMALL_ICON, icon);
    putValue("id", id);
    this.view = view;
  }

  public void actionPerformed(ActionEvent e) {
    int id = (int) getValue("id");
    view.setWhatToDraw(id);
  }
}


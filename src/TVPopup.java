import java.io.Serial;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TVPopup extends FigurePopup {

  @Serial
  private static final long serialVersionUID = 1406616085775463601L;

  TVPopup(DrawerView view) {
    super(view, "TV", false);

    JMenuItem powerItem = new JMenuItem("ON/OFF");
    powerItem.addActionListener((e) -> view.onOffTV());
    popupPtr.add(powerItem);

    JMenuItem antennaItem = new JMenuItem("Antenna");
    antennaItem.addActionListener((e) -> view.setAntenna());
    popupPtr.add(antennaItem);
  }
}

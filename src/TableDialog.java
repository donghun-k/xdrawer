import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.event.TableModelListener;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.TableColumn;
import javax.swing.table.TableColumnModel;
import javax.swing.table.TableModel;

public class TableDialog extends JDialog {

  static class FigureTableModel implements TableModel {

    DrawerView view;
    ArrayList<Figure> figures;
    static final String[] columnNames = new String[]{
        "Figure Type", "x1", "y1", "x2", "y2"
    };
    static final Class[] columnTypes = new Class[]{
        String.class, Integer.class, Integer.class, Integer.class, Integer.class
    };

    FigureTableModel(DrawerView view) {
      this.view = view;
      figures = view.getFigures();
    }

    public int getRowCount() {
      return figures.size();
    }

    public int getColumnCount() {
      return columnNames.length;
    }

    public String getColumnName(int columnIndex) {
      return columnNames[columnIndex];
    }

    public Class getColumnClass(int columnIndex) {
      return columnTypes[columnIndex];
    }

    public boolean isCellEditable(int rowIndex, int columnIndex) {
      return false;
    }

    public Object getValueAt(int rowIndex, int columnIndex) {
      Figure ptr = figures.get(rowIndex);
      return switch (columnIndex) {
        case 0 -> ptr.getClass().getName();
        case 1 -> ptr.getX1();
        case 2 -> ptr.getY1();
        case 3 -> (ptr.getX2() > 0) ? ptr.getX2() : null;
        case 4 -> (ptr.getY2() > 0) ? ptr.getY2() : null;
        default -> null;
      };
    }

    public void setValueAt(Object aValue, int rowIndex, int columnIndex) {

    }

    public void addTableModelListener(TableModelListener l) {

    }

    public void removeTableModelListener(TableModelListener l) {

    }
  }

  static class FigureTable extends JTable {

    FigureTable(DrawerView view) {
      super(new FigureTableModel(view));
      DefaultListSelectionModel selectionModel = new DefaultListSelectionModel();
      setSelectionModel(selectionModel);

      TableColumnModel colModel = getColumnModel();
      TableColumn nameColumn = colModel.getColumn(0);
      DefaultTableCellRenderer renderer = new DefaultTableCellRenderer();
      renderer.setHorizontalAlignment(SwingConstants.CENTER);
      nameColumn.setCellRenderer(renderer);
    }

    public int getSelectedIndex() {
      return selectionModel.getMinSelectionIndex();
    }
  }

  static class DialogPanel extends JPanel implements ActionListener {

    JDialog dialog;
    DrawerView view;
    JButton done;
    JButton remove;
    FigureTable table;

    DialogPanel(JDialog dialog, DrawerView view) {
      this.view = view;
      this.dialog = dialog;
      setLayout(new BorderLayout());

      table = new FigureTable(view);
      JScrollPane sp = new JScrollPane(table);
      add(sp, BorderLayout.CENTER);

      JPanel bottom = new JPanel();
      bottom.add(remove = new JButton("Remove"));
      bottom.add(done = new JButton("Done"));
      add(bottom, BorderLayout.SOUTH);

      remove.addActionListener(this);
      done.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
      if (e.getSource() == remove) {
        view.removeFromDialog(table.getSelectedIndex());
        updateUI();
      } else if (e.getSource() == done) {
        dialog.setVisible(false);
      }
    }

    public void updateUI() {
      if (table != null) {
        table.updateUI();
      }
    }
  }

  TableDialog(String title, DrawerView view) {
    super((JFrame) null, title);
    setLocation(200, 300);
    setSize(400, 300);

    Container container = getContentPane();
    JPanel panel = new TableDialog.DialogPanel(this, view);
    container.add(panel);

    addWindowListener(new WindowAdapter() {
      public void windowActivated(WindowEvent e) {
        panel.updateUI();
      }
    });
  }
}

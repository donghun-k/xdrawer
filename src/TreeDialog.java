import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.event.TreeModelListener;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;

public class TreeDialog extends JDialog {

  static class MyTreeNode {

    Object userObject;
    ArrayList<MyTreeNode> children;

    MyTreeNode(Object data) {
      userObject = data;
      children = new ArrayList<MyTreeNode>();
    }

    public String toString() {
      return userObject.toString();
    }

    public Object getUserObject() {
      return userObject;
    }

    public MyTreeNode getChildAt(int index) {
      return children.get(index);
    }

    public int getChildCount() {
      return children.size();
    }

    public int getIndex(MyTreeNode child) {
      return children.indexOf(child);
    }

    public boolean isLeaf() {
      return children.size() == 0;
    }


    public void add(MyTreeNode child) {
      children.add(child);
    }

  }

  static class FigureTreeModel implements TreeModel {

    DrawerView view;
    ArrayList<Figure> figures;
    MyTreeNode root;

    FigureTreeModel(DrawerView view) {
      this.view = view;
      figures = view.getFigures();
      constructTree();
    }

    public void constructTree() {
      root = new MyTreeNode("Figure");

      int length = DrawerView.figureTypes.length;

      ArrayList<String> names = new ArrayList<String>();
      MyTreeNode[] nodes = new MyTreeNode[length];

      for (int i = 0; i < length; i++) {
        String name = DrawerView.figureTypes[i];
        names.add(name);
        MyTreeNode node = new MyTreeNode(name);
        root.add(node);
        nodes[i] = node;
        root.add(node);
      }
      for (Figure ptr : figures) {
        String figureTypeName = ptr.getClass().getName();
        int index = names.indexOf(figureTypeName);
        nodes[index].add(new MyTreeNode(ptr));
      }
    }

    public Object getRoot() {
      return root;
    }

    public Object getChild(Object parent, int index) {
      MyTreeNode pNode = (MyTreeNode) parent;
      return pNode.getChildAt(index);
    }

    public int getChildCount(Object parent) {
      MyTreeNode pNode = (MyTreeNode) parent;
      return pNode.getChildCount();
    }

    public boolean isLeaf(Object node) {
      MyTreeNode pNode = (MyTreeNode) node;
      return pNode.isLeaf();
    }

    public int getIndexOfChild(Object parent, Object child) {
      MyTreeNode pNode = (MyTreeNode) parent;
      MyTreeNode cNode = (MyTreeNode) child;
      return pNode.getIndex(cNode);
    }

    public void valueForPathChanged(TreePath path, Object newValue) {

    }

    public void addTreeModelListener(TreeModelListener l) {

    }

    public void removeTreeModelListener(TreeModelListener l) {

    }
  }

  static class FigureTree extends JTree {

    FigureTreeModel model;

    FigureTree(DrawerView view) {
      super();
      model = new FigureTreeModel(view);
      setModel(model);
//      super(new FigureTableModel(view));
//      DefaultListSelectionModel selectionModel = new DefaultListSelectionModel();
//      setSelectionModel(selectionModel);
//
//      TableColumnModel colModel = getColumnModel();
//      TableColumn nameColumn = colModel.getColumn(0);
//      DefaultTableCellRenderer renderer = new DefaultTableCellRenderer();
//      renderer.setHorizontalAlignment(SwingConstants.CENTER);
//      nameColumn.setCellRenderer(renderer);
    }

    public void updateUI() {
      if (model != null) {
        model.constructTree();
        super.updateUI();
        setExpandedState(getPathForRow(0), true);
      }
    }
  }

  static class DialogPanel extends JPanel implements ActionListener {

    JDialog dialog;
    DrawerView view;
    JButton done;
    JButton remove;
    FigureTree tree;

    DialogPanel(JDialog dialog, DrawerView view) {
      this.view = view;
      this.dialog = dialog;
      setLayout(new BorderLayout());

      tree = new FigureTree(view);
      JScrollPane sp = new JScrollPane(tree);
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
        TreePath selectedPath = tree.getSelectionPath();
        if (selectedPath == null) {
          return;
        }
        MyTreeNode selectedNode = (MyTreeNode) selectedPath.getLastPathComponent();
        updateUI();
        Object selectedObject = selectedNode.getUserObject();
        if (selectedObject instanceof Figure) {
          view.remove((Figure) selectedObject);
          updateUI();
        }
      } else if (e.getSource() == done) {
        dialog.setVisible(false);
      }
    }

    public void updateUI() {
      if (tree != null) {
        tree.updateUI();
      }
    }
  }

  TreeDialog(String title, DrawerView view) {
    super((JFrame) null, title);
    setLocation(200, 300);
    setSize(400, 300);

    Container container = getContentPane();
    JPanel panel = new TreeDialog.DialogPanel(this, view);
    container.add(panel);

    addWindowListener(new WindowAdapter() {
      public void windowActivated(WindowEvent e) {
        panel.updateUI();
      }
    });
  }
}

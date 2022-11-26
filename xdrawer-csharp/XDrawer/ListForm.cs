using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace XDrawer
{
    public partial class ListForm : Form
    {
        XDrawer mainForm;
        Button[] button = new Button[4];
        public ListForm(XDrawer mainForm)
        {
            InitializeComponent();
            this.mainForm = mainForm;

            listView.Parent = this;
            listView.Dock = DockStyle.Fill;
            listView.View = View.Details;
            listView.MultiSelect = false;

            this.TopMost = true;

            this.SetBounds(100, 100, 400, 400);
            listView.Columns.Add("Figure", 70, HorizontalAlignment.Center);
            listView.Columns.Add("X1", 70, HorizontalAlignment.Center);
            listView.Columns.Add("Y1", 70, HorizontalAlignment.Center);
            listView.Columns.Add("X2", 70, HorizontalAlignment.Center);
            listView.Columns.Add("Y2", 70, HorizontalAlignment.Center);

            Panel panel = new Panel();
            panel.Dock = DockStyle.Bottom;
            panel.Parent = this;

            String[] buttonName = { "Detail", "List", "Tile", "Cancel" };
            for(int i = 0; i< buttonName.Length; i++)
            {
                button[i] = new Button();
                button[i].Text = buttonName[i];
                button[i].SetBounds(10 + 70 * i, 20, 60, 40);
                button[i].Click += new EventHandler(buttonClicked);
                panel.Controls.Add(button[i]);
            }
            showAllFigures();
        }
        void buttonClicked(object sender, EventArgs e)
        {
            if (!(sender is Button)) return;
            Button button = (Button)sender;

            String btnName = button.Text;
            if (btnName.Equals("Detail"))
            {
                listView.View = View.Details;
            }
            else if (btnName.Equals("List"))
            {
                listView.View = View.List;
            }
            else if (btnName.Equals("Tile"))
            {
                listView.View = View.Tile;
            }
            else if (btnName.Equals("Cancel"))
            {
                Hide();
            }
        }
        void showAllFigures()
        {
            List<Figure> figures = mainForm.Figures;
            foreach (Figure ptr in figures)
            {
                ListViewItem item = null;
                item = new ListViewItem(ptr.getClassName());                
                int x1 = ptr.getX1();
                int y1 = ptr.getY1();
                int x2 = ptr.getX2();
                int y2 = ptr.getY2();

                item.SubItems.Add("" + x1);
                item.SubItems.Add("" + y1);

                if (x2 >= 0 && y2 >= 0)
                {
                    item.SubItems.Add("" + x2);
                    item.SubItems.Add("" + y2);
                }
                listView.Items.Add(item);
            }
        }
    }
}

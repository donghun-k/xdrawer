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
    public partial class TreeForm : Form
    {
        XDrawer mainForm;
        public TreeForm(XDrawer mainForm)
        {
            InitializeComponent();
            this.mainForm = mainForm;
            treeView.Dock = DockStyle.Fill;
            
            this.TopMost = true;
            treeView.Nodes.Add("Figures");
            treeView.Nodes[0].Nodes.Add("Point");
            treeView.Nodes[0].Nodes.Add("Line");
            treeView.Nodes[0].Nodes.Add("Box");
            treeView.Nodes[0].Nodes.Add("Circle");

            showAllFigures();
        }
        void showAllFigures()
        {
            TreeNodeCollection nodesToAdd = null;
            List<Figure> figures = mainForm.Figures;
            foreach (Figure ptr in figures)
            {
                // Run Tiem Type Identification
                if (ptr is Point)
                {
                    nodesToAdd = treeView.Nodes[0].Nodes[0].Nodes;
                } 
                else if (ptr is Line)
                {
                    nodesToAdd = treeView.Nodes[0].Nodes[1].Nodes;
                }
                else if (ptr is Box)
                {
                    nodesToAdd = treeView.Nodes[0].Nodes[2].Nodes;
                }
                else if (ptr is Circle)
                {
                    nodesToAdd = treeView.Nodes[0].Nodes[3].Nodes;
                }
                int x1 = ptr.getX1();
                int y1 = ptr.getY1();
                int x2 = ptr.getX2();
                int y2 = ptr.getY2();

                String s = "X1 : " + x1 + ", Y1 : " + y1;
                if (x2 >= 0 && y2 >= 0)
                {
                    s = s + " / X2: " + x2 + ", Y2: " + y2;
                }

                nodesToAdd.Add(s);
            }
        }
    }
}

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
    public partial class FigureDialog : Form
    {
        XDrawer mainForm;
        static String[] figureTypes = { "Point", "Box", "Line", "Circle", "Kite", "TV" };
        public FigureDialog(XDrawer form)
        {   
            mainForm = form;
            InitializeComponent();

            textX1.Text = "0";
            textY1.Text = "0";
            textX2.Text = "0";
            textY2.Text = "0";

            foreach (string type in figureTypes)
            {
                selectBox.Items.Add(type);
            }

            selectBox.SelectedIndex = 1;

            redButton.ForeColor = Color.Red;
            yellowButton.ForeColor = Color.Yellow;
            blueButton.ForeColor = Color.Blue;

            ToolTip tip = new ToolTip();
            tip.SetToolTip(blackButton, "Black Color");
            tip.SetToolTip(redButton, "Red Color");
            tip.SetToolTip(yellowButton, "Yellow Color");
            tip.SetToolTip(blueButton, "Blue Color");
            tip.SetToolTip(blackButton, "Black Color");

            blackButton.Select();

            mainForm.CurrentColor = Color.Black;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void okayButton_Click(object sender, EventArgs e)
        {
            if (textX1.Text.Length == 0) return;
            if (textY1.Text.Length == 0) return;
            if (textX2.Text.Length == 0) return;
            if (textY2.Text.Length == 0) return;

            int x1 = int.Parse(textX1.Text);
            int y1 = int.Parse(textY1.Text);
            int x2 = int.Parse(textX2.Text);
            int y2 = int.Parse(textY2.Text);

            Figure newFigure = null;

            mainForm.setFigureTypeLable(figureTypes[selectBox.SelectedIndex]);

            if (selectBox.SelectedIndex+1 == XDrawer.DRAW_POINT)
            {
                newFigure = new Point(mainForm.pointPopup, x1, y1);
            }
            else if (selectBox.SelectedIndex+1 == XDrawer.DRAW_LINE)
            {
                newFigure = new Line(mainForm.linePopup, x1, y1, x2, y2);
            }
            else if (selectBox.SelectedIndex+1 == XDrawer.DRAW_BOX)
            {
                newFigure = new Box(mainForm.boxPopup, x1, y1, x2, y2);
            }
            else if (selectBox.SelectedIndex+1 == XDrawer.DRAW_CIRCLE)
            {
                newFigure = new Circle(mainForm.circlePopup, x1, y1, x2, y2);
            }
            else if (selectBox.SelectedIndex + 1 == XDrawer.DRAW_KITE)
            {
                newFigure = new Kite(mainForm.kitePopup, x1, y1, x2, y2);
            }
            else if (selectBox.SelectedIndex + 1 == XDrawer.DRAW_TV)
            {
                newFigure = new TV(mainForm.tvPopup, x1, y1);
            }
            newFigure.setColor(mainForm.CurrentColor);            

            mainForm.addFigure(newFigure);
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            Hide();
        }

        private void FigureDialog_Load(object sender, EventArgs e)
        {

        }

        private void selectBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void blackButton_CheckedChanged(object sender, EventArgs e)
        {
            mainForm.CurrentColor = Color.Black;
        }

        private void redButton_CheckedChanged(object sender, EventArgs e)
        {
            mainForm.CurrentColor = Color.Red;
        }

        private void yellowButton_CheckedChanged(object sender, EventArgs e)
        {
            mainForm.CurrentColor = Color.Yellow;
        }

        private void blueButton_CheckedChanged(object sender, EventArgs e)
        {
            mainForm.CurrentColor = Color.Blue;
        }

        private void selectColor_Click(object sender, EventArgs e)
        {
            ColorDialog dialog = new ColorDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                mainForm.CurrentColor = dialog.Color;
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class MainPopup : Popup
    {
        public MainPopup(XDrawer view)
            : base(view, "Figure")
        {
            ToolStripMenuItem lineItem = new ToolStripMenuItem("Line");
            ToolStripMenuItem boxItem = new ToolStripMenuItem("Box");
            ToolStripMenuItem circleItem = new ToolStripMenuItem("Circle");
            _popupPtr.Items.Add(lineItem);
            _popupPtr.Items.Add(boxItem);
            _popupPtr.Items.Add(circleItem);

            lineItem.Click += new EventHandler(view.lineToolStripMenuItem_Click);
            boxItem.Click += new EventHandler(view.boxToolStripMenuItem_Click);
            circleItem.Click += new EventHandler(view.circleToolStripMenuItem_Click);
        }
    }
}

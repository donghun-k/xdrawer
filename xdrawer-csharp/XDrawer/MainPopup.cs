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
            ToolStripMenuItem pointItem = new ToolStripMenuItem("Point");
            ToolStripMenuItem lineItem = new ToolStripMenuItem("Line");
            ToolStripMenuItem boxItem = new ToolStripMenuItem("Box");
            ToolStripMenuItem circleItem = new ToolStripMenuItem("Circle");
            ToolStripMenuItem kiteItem = new ToolStripMenuItem("Kite");
            ToolStripMenuItem tvItem = new ToolStripMenuItem("TV");

            _popupPtr.Items.Add(pointItem);
            _popupPtr.Items.Add(lineItem);
            _popupPtr.Items.Add(boxItem);
            _popupPtr.Items.Add(circleItem);
            _popupPtr.Items.Add(kiteItem);
            _popupPtr.Items.Add(tvItem);


            pointItem.Click += new EventHandler(view.pointToolStripMenuItem_Click);
            lineItem.Click += new EventHandler(view.lineToolStripMenuItem_Click);
            boxItem.Click += new EventHandler(view.boxToolStripMenuItem_Click);
            circleItem.Click += new EventHandler(view.circleToolStripMenuItem_Click);
            kiteItem.Click += new EventHandler(view.kiteToolStripMenuItem_Click);
            tvItem.Click += new EventHandler(view.tVToolStripMenuItem_Click);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class TVPopup : FigurePopup
    {
        public TVPopup(XDrawer view)
            : base(view, "TV", false)
        {
            ToolStripMenuItem powerItem = new ToolStripMenuItem("ON / OFF");
            powerItem.Click += new EventHandler(view.onToggleTV);
            _popupPtr.Items.Add(powerItem);

            ToolStripMenuItem antennaitem = new ToolStripMenuItem("안테나 조작");
            antennaitem .Click += new EventHandler(view.onSetAntenna);
            _popupPtr.Items.Add(antennaitem);
        }
    }
}

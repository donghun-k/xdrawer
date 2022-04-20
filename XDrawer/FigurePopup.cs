using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public class FigurePopup : Popup
    {
        public FigurePopup(XDrawer view, String title, bool fillFlag)
            : base(view, title)
        {
            ToolStripMenuItem deleteItem = new ToolStripMenuItem("지우기");
            deleteItem.Click += new EventHandler(view.deleteFigure);
            ToolStripMenuItem copyItem = new ToolStripMenuItem("복사하기");
            copyItem.Click += new EventHandler(view.copyFigure);
            _popupPtr.Items.Add(deleteItem);
            _popupPtr.Items.Add(copyItem);

            ToolStripMenuItem[] colorOption = new ToolStripMenuItem[4];
            colorOption[0] = new ToolStripMenuItem("검정색");
            colorOption[1] = new ToolStripMenuItem("빨간색");
            colorOption[2] = new ToolStripMenuItem("노란색");
            colorOption[3] = new ToolStripMenuItem("파란색");
            colorOption[0].Click += new EventHandler(view.setBlackColor);
            colorOption[1].Click += new EventHandler(view.setRedColor);
            colorOption[2].Click += new EventHandler(view.setYellowColor);
            colorOption[3].Click += new EventHandler(view.setBlueColor);
            ToolStripMenuItem subMenu = new ToolStripMenuItem("색 정하기");
            foreach (ToolStripMenuItem item in colorOption)
            {
                subMenu.DropDownItems.Add(item);
            }
            _popupPtr.Items.Add(subMenu);

            if (fillFlag == true)
            {
                ToolStripMenuItem fillItem = new ToolStripMenuItem("채우기");
                fillItem.Click += new EventHandler(view.setFill);
                _popupPtr.Items.Add(fillItem);
            }
        }
    }
}

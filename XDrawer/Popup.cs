using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public class Popup
    {
        protected ContextMenuStrip _popupPtr;
        protected XDrawer _pView;

        public Popup(XDrawer view, String title)
        {
            _pView = view;
            _popupPtr = new ContextMenuStrip();

            if (title != null)
            {
                _popupPtr.Items.Add(title);
                _popupPtr.Items.Add("-");
            }
        }

        public void popup(System.Drawing.Point pos)
        {
            _popupPtr.Show(_pView.Canvas, pos);
        }
    }
}

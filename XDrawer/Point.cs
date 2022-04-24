using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    [Serializable]
    public class Point : OnePointFigure
    {
        public Point(Popup popup, int x, int y)
            : base(popup, x, y)
        {
        }
        [System.Runtime.InteropServices.DllImport("gdi32.dll")]
        internal static extern bool Rectangle(IntPtr hdc, int ulCornerX, int ulCornerY, int IrCornerX, int IrCornerY);
        public override void draw(IntPtr hdc)
        {
            Rectangle(hdc, _x1 - DELTA, _y1 - DELTA, _x1 + DELTA, _y1 + DELTA);
        }
        public override void draw(Graphics g, Pen pen)
        {
            Color oldColor = pen.Color;
            pen.Color = _color;
            g.DrawRectangle(pen, _x1 - DELTA, _y1 - DELTA, 2*DELTA, 2*DELTA);
            pen.Color = oldColor;
        }
        public override Figure clone()
        {
            Point newFigure = new Point(_popup, _x1, _y1);
            newFigure._color = _color;
            return newFigure;
        }
        public override String getClassName()
        {
            return "Point";
        }
    }
}


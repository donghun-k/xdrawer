using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class Circle : TwoPointFigure
    {
        public Circle(Popup popup, int x, int y)
            : base(popup, x, y)
        {
        }
        public override void draw(Graphics g, Pen pen)
        {
            g.DrawEllipse(pen, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
        }
    }
}

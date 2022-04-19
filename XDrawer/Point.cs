using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public class Point : OnePointFigure
    {
        public Point(Popup popup, int x, int y)
            : base(popup, x, y)
        {
        }
        public override void draw(Graphics g, Pen pen)
        {
            g.DrawRectangle(pen, _x1 - DELTA, _y1 - DELTA, 2*DELTA, 2*DELTA);
        }
    }
}


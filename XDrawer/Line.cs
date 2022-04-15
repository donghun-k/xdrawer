using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class Line : TwoPointFigure
    {
        public Line(int x, int y) : base(x, y)
        {
        }
        public override void draw(Graphics g, Pen pen)
        {   
            g.DrawLine(pen, _x1, _y1, _x2, _y2);
        }
    }
}

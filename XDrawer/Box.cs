using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class Box : TwoPointFigure
    {
        public Box(int x, int y) : base(x, y)
        {
        }
        public override void draw(Graphics g, Pen pen)
        {
            g.DrawRectangle(pen, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
        }
    }
}

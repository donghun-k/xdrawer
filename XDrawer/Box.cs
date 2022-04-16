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
        public Box(int x1, int y1, int x2, int y2) : base(x1, y1, x2, y2)
        {
        }
        public override void draw(Graphics g, Pen pen)
        {
            g.DrawRectangle(pen, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
        }
    }
}

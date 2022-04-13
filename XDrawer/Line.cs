using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class Line
    {
        private int _x1;
        private int _y1;
        private int _x2;
        private int _y2;
        public Line(int x, int y)
        {
            _x1 = _x2 = x;
            _y1 = _y2 = y;
        }
        public void draw(Graphics g, Pen pen)
        {   
            g.DrawLine(pen, _x1, _y1, _x2, _y2);
        }
        public void setXY2(int newX, int newY)
        {
            _x2 = newX;
            _y2 = newY;
        }
    }
}

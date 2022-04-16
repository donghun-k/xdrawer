using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal abstract class TwoPointFigure : Figure
    {
        protected int _x1;
        protected int _y1;
        protected int _x2;
        protected int _y2;
        public TwoPointFigure(int x, int y)
        {
            _x1 = _x2 = x;
            _y1 = _y2 = y;
        }
        public TwoPointFigure(int x1, int y1, int x2, int y2)
        {
            _x1 = x1;
            _y1 = y1;
            _x2 = x2;
            _y2 = y2;
        }
        public override void setXY2(int newX, int newY)
        {
            _x2 = newX;
            _y2 = newY;
        }
    }
}

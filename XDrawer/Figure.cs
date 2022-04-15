using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal abstract class Figure
    {
        public Figure()
        {
        }
        public abstract void draw(Graphics g, Pen pen);
        public abstract void setXY2(int newX, int newY);
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public abstract class Figure
    {
        protected Region _region;
        public Figure()
        {
        }
        public bool ptInRegion(int x, int y)
        {
            if(_region != null)
            {
                return _region.IsVisible(x, y);
            }
            else
            {
                return false;
            }
        }
        public abstract void draw(Graphics g, Pen pen);
        public abstract void setXY2(int newX, int newY);
        public abstract void makeRegion();
        
    }
}

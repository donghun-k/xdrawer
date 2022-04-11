using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    internal class Box
    {
        public int x1;
        public int y1;
        public int x2;
        public int y2;
        public Box(int x, int y)
        {
            x1 = x2 = x;
            y1 = y2 = y;
        }
    }
}

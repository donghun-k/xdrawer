using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing.Drawing2D;

namespace XDrawer
{
    public abstract class OnePointFigure : Figure
    {
        protected static int DELTA = 5;
        protected int _x1;
        protected int _y1;
        public OnePointFigure(Popup popup, int x, int y)
            : base(popup)
        {
            _x1 = x;
            _y1 = y;
        }
        public override void setXY2(int newX, int newY)
        {
            _x1 = newX;
            _y1 = newY;
        }
        public override void makeRegion()
        {
            System.Drawing.Point[] pt = new System.Drawing.Point[4];
            pt[0].X = _x1 - DELTA; pt[0].Y = _y1 - DELTA;
            pt[1].X = _x1 + DELTA; pt[1].Y = _y1 - DELTA;
            pt[2].X = _x1 + DELTA; pt[2].Y = _y1 + DELTA;
            pt[3].X = _x1 - DELTA; pt[3].Y = _y1 + DELTA;

            byte[] type = new byte[4];
            type[0] = (byte)PathPointType.Line;
            type[1] = (byte)PathPointType.Line;
            type[2] = (byte)PathPointType.Line;
            type[3] = (byte)PathPointType.Line;

            GraphicsPath gp = new GraphicsPath(pt, type);
            _region = new Region(gp);
        }
    }
}

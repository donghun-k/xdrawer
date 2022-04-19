using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing.Drawing2D;

namespace XDrawer
{
    internal abstract class TwoPointFigure : Figure
    {
        protected int _x1;
        protected int _y1;
        protected int _x2;
        protected int _y2;
        public TwoPointFigure(Popup popup, int x, int y)
            : base(popup)
        {
            _x1 = _x2 = x;
            _y1 = _y2 = y;
        }
        public TwoPointFigure(Popup popup, int x1, int y1, int x2, int y2)
            : base(popup)
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
        public override void makeRegion()
        {
            Point[] pt = new Point[4];
            pt[0].X = _x1; pt[0].Y = _y1;
            pt[1].X = _x2; pt[1].Y = _y1;
            pt[2].X = _x2; pt[2].Y = _y2;
            pt[3].X = _x1; pt[3].Y = _y2;

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

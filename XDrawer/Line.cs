using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing.Drawing2D;

namespace XDrawer
{
    public class Line : TwoPointFigure
    {
        public Line(Popup popup, int x, int y)
            : base(popup, x, y)
        {
        }
        public override void draw(Graphics g, Pen pen)
        {
            Color oldColor = pen.Color;
            pen.Color = _color;
            g.DrawLine(pen, _x1, _y1, _x2, _y2);
            pen.Color = oldColor;
        }
        public override void makeRegion()
        {
            int regionWidth = 20;
            int x = _x1;
            int y = _y1;
            int w = _x2 - _x1;
            int h = _y2 - _y1;
            int sign_h = 1;
            if (h < 0) sign_h = -1;
            double angle;
            double theta = (w != 0) ? Math.Atan((double)(h) / (double)(w)) : sign_h * Math.PI / 2.0;
            if (theta < 0) theta = theta + 2 * Math.PI;
            angle = (theta + Math.PI / 2.0);
            int dx = (int)(regionWidth * Math.Cos(angle));
            int dy = (int)(regionWidth * Math.Sin(angle));
            System.Drawing.Point[] pt = new System.Drawing.Point[4];
            pt[0].X = x + dx; pt[0].Y = y + dy;
            pt[1].X = x - dx; pt[1].Y = y - dy;
            pt[2].X = x + w - dx; pt[2].Y = y + h - dy;
            pt[3].X = x + w + dx; pt[3].Y = y + h + dy;
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

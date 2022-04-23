using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public class Circle : TwoPointFigure
    {
        private bool _fillFlag;
        public Circle(Popup popup, int x, int y)
            : base(popup, x, y)
        {
            _fillFlag = false;
        }
        public Circle(Popup popup, int x1, int y1, int x2, int y2)
            : base(popup, x1, y1, x2, y2)
        {
            _fillFlag = false;
        }
        public override void setFill()
        {
            _fillFlag = !_fillFlag;
        }
        public override void draw(Graphics g, Pen pen)
        {
            if (_fillFlag == true)
            {
                Brush br = new SolidBrush(_color);
                g.FillEllipse(br, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
                br.Dispose();
            }
            Color oldColor = pen.Color;
            pen.Color = _color;
            g.DrawEllipse(pen, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
            pen.Color = oldColor;
        }
        public override Figure clone()
        {
            Circle newFigure = new Circle(_popup, _x1, _y1, _x2, _y2);
            newFigure._color = _color;
            newFigure._fillFlag = _fillFlag;
            return newFigure;
        }
        public override String getClassName()
        {
            return "Circle";
        }
    }
}

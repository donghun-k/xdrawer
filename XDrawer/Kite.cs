using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    [Serializable]
    public class Kite : Box
    {
        Circle circle;
        Line line1;
        Line line2;
        Line line3;
        Line line4;
        public Kite(Popup popup, int x, int y)
            : base(popup, x, y)
        {
            circle = new Circle(popup, x, y);
            line1 = new Line(popup, x, y);
            line2 = new Line(popup, x, y);
            line3 = new Line(popup, x, y);
            line4 = new Line(popup, x, y);
        }
        public Kite(Popup popup, int x1, int y1, int x2, int y2)
            : base(popup, x1, y1, x2, y2)
        {
            int w = Math.Abs(x2 - x1);
            int h = Math.Abs(y2 - y1);
            int x = Math.Min(x1, x2);
            int y = Math.Min(y1, y2);
            circle = new Circle(popup, x + w / 4, y + h / 4, x + 3 * w / 4, y + 3 * h / 4);
            line1 = new Line(popup, x1, y1, x2, y2);
            line2 = new Line(popup, x1 + w / 2, y1, x1 + w / 2, y2);
            line3 = new Line(popup, x2, y1, x1, y2);
            line4 = new Line(popup, x1, y1 + h / 2, x2, y1 + h / 2);
        }
        public override void draw(Graphics g, Pen pen)
        {
            base.draw(g, pen);
            // delegation 
            circle.draw(g, pen);
            line1.draw(g, pen);
            line2.draw(g, pen);
            line3.draw(g, pen);
            line4.draw(g, pen);
        }
        public override void move(int dx, int dy)
        {
            base.move(dx, dy);
            // delegation
            circle.move(dx, dy);
            line1.move(dx, dy);
            line2.move(dx, dy);
            line3.move(dx, dy);
            line4.move(dx, dy);
        }
        public override void draw(IntPtr hdc)
        {
            base.draw(hdc);
            // delegation
            circle.draw(hdc);
            line1.draw(hdc);
            line2.draw(hdc);
            line3.draw(hdc);
            line4.draw(hdc);
        }
        
        public override void setColor(Color color)
        {
            base.setColor(color);
            circle.setColor(color);
            line1.setColor(color);
            line2.setColor(color);
            line3.setColor(color);
            line4.setColor(color);
        }
        public override Figure clone()
        {
            Kite newFigure = new Kite(_popup, _x1, _y1, _x2, _y2);
            newFigure.setColor(_color);
            return newFigure;
        }
        public override void setXY2(int newX, int newY)
        {
            base.setXY2(newX, newY);
            int w = newX - _x1;
            int h = newY - _y1;
            circle.setXY12(_x1 + w / 4, _y1 + h / 4, _x1 + 3 * w / 4, _y1 + 3 * h / 4);
            line1.setXY12(_x1, _y1, newX, newY);
            line2.setXY12(_x1 + w / 2, _y1, _x1 + w / 2, newY);
            line3.setXY12(newX, _y1, _x1, newY);
            line4.setXY12(_x1, _y1 + h / 2, newX, _y1 + h / 2);
        }
        public override String getClassName()
        {
            return "Kite";
        }
    }
}

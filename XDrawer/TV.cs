using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    [Serializable]
    internal class TV : TwoPointFigure
    {
        private bool _antennaFlag;
        // role name
        private Box _frame;
        private Box _screen;
        private Circle _channelButton;
        private Circle _volumnButton;
        private Circle _menuButton;
        private Box _powerButton;
        private Line _antenna1;
        private Line _antenna2;
        private static int FRAME_WIDTH = 150;
        private static int FRAME_HEIGHT = 90;
        private static int ANTENNA_WIDTH = 30;
        private static int ANTENNA_HEIGHT = 40;
        private static int FRAME_GAP = 12;
        private static int SCREEN_WIDTH = 105;
        private static int SCREEN_HEIGHT = FRAME_HEIGHT - 2 * FRAME_GAP;
        private static int SWITCH_GAP = 17;
        private static int SWITCH_SIZE = 10;
        private static int POWER_SWITCH_WIDTH = 15;
        private static int POWER_SWITCH_HEIGHT = 8;
        private static int TOTAL_WIDTH = FRAME_WIDTH;
        private static int TOTAL_HEIGHT = FRAME_HEIGHT + ANTENNA_HEIGHT;
        List<Figure> list;

        public TV(Popup popup, int x, int y)
            : base(popup, x, y, x + TOTAL_WIDTH, y + TOTAL_HEIGHT)
        {
            int x1, y1, x2, y2;
            bool antennaOption = true;

            x1 = x;
            y1 = y + ANTENNA_HEIGHT;
            x2 = x + FRAME_WIDTH;
            y2 = y + TOTAL_HEIGHT;
            _frame = new Box(popup, x1, y1, x2, y2);
            x1 = x1 + FRAME_GAP;
            y1 = y1 + FRAME_GAP;
            x2 = x1 + SCREEN_WIDTH;
            y2 = y1 + SCREEN_HEIGHT;
            _screen = new Box(popup, x1, y1, x2, y2);
            x1 = x2 + FRAME_GAP;
            y1 = y1 + FRAME_GAP / 2;
            x2 = x1 + SWITCH_SIZE;
            y2 = y1 + SWITCH_SIZE;
            _channelButton = new Circle(popup, x1, y1, x2, y2);
            y1 = y1 + SWITCH_GAP;
            y2 = y1 + SWITCH_SIZE;
            _volumnButton = new Circle(popup, x1, y1, x2, y2);
            y1 = y1 + SWITCH_GAP;
            y2 = y1 + SWITCH_SIZE;
            _menuButton = new Circle(popup, x1, y1, x2, y2);
            x1 = x1 - FRAME_GAP / 3 + 2;
            y1 = y1 + SWITCH_GAP + 2;
            x2 = x1 + POWER_SWITCH_WIDTH;
            y2 = y1 + POWER_SWITCH_HEIGHT;
            _powerButton = new Box(popup, x1, y1, x2, y2);
            _antennaFlag = antennaOption;
            if (antennaOption == true)
            {
                int cx = x + TOTAL_WIDTH / 2;
                x1 = cx - ANTENNA_WIDTH;
                y1 = y;
                x2 = cx;
                y2 = y + ANTENNA_HEIGHT;
                _antenna1 = new Line(popup, x1, y1, x2, y2);
                x1 = cx + ANTENNA_WIDTH;
                _antenna2 = new Line(popup, x1, y1, x2, y2);
            }
            else
            {
                _antenna1 = null;
                _antenna2 = null;
            }
            list = new List<Figure>();
            list.Add(_frame);
            list.Add(_screen);
            list.Add(_channelButton);
            list.Add(_volumnButton);
            list.Add(_menuButton);
            list.Add(_powerButton);
        }
        public void pressPowerButton()
        {
            _screen.setFill();
            _powerButton.setFill();
        }
        public void setAntenna()
        {
            if (_antennaFlag == true)
            {
                _antenna1 = null;
                _antenna2 = null;
            }
            else
            {
                int cx = _x1 + TOTAL_WIDTH / 2;
                int x1 = cx - ANTENNA_WIDTH;
                int y1 = _y1;
                int x2 = cx;
                int y2 = _y1 + ANTENNA_HEIGHT;
                _antenna1 = new Line(_popup, x1, y1, x2, y2);
                x1 = cx + ANTENNA_WIDTH;
                _antenna2 = new Line(_popup, x1, y1, x2, y2);
            }
            _antennaFlag = !_antennaFlag;
        }
        public override void setColor(Color color)
        {
            base.setColor(color);
            _screen.setColor(color);
        }
        public override void draw(Graphics g, Pen p)
        {           
            foreach (Figure ptr in list)
            {
                ptr.draw(g, p);
            }
            if (_antenna1 != null)
            {
                _antenna1.draw(g, p);
            }
            if (_antenna2 != null)
            {
                _antenna2.draw(g, p);
            }
        }
        public override void move(int dx, int dy)
        {
            base.move(dx, dy);            
            foreach (Figure ptr in list)
            {
                ptr.move(dx, dy);
            }
            if (_antenna1 != null)
            {
                _antenna1.move(dx, dy);
            }
            if (_antenna2 != null)
            {
                _antenna2.move(dx, dy);
            }
        }
        public override void draw(IntPtr hdc)
        {
            foreach (Figure ptr in list)
            {
                ptr.draw(hdc);
            }
            if (_antenna1 != null)
            {
                _antenna1.draw(hdc);
            }
            if (_antenna2 != null)
            {
                _antenna2.draw(hdc);
            }
        }
        public override Figure clone()
        {
            TV newFigure = new TV(_popup, _x1, _y1);
            newFigure.setColor(_color);
            if (_antennaFlag == false)
            {
                newFigure.setAntenna();
            }
            return newFigure;
        }
        public override String getClassName()
        {
            return "TV";
        }
    }
}

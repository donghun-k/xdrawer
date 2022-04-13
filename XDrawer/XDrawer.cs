namespace XDrawer
{
    public partial class XDrawer : Form
    {
        static int MAX = 100;

        static int DRAW_LINE = 2;
        static int DRAW_BOX = 3;
        static int DRAW_CIRCLE = 4;

        bool isClicked = false;

        int _whatToDraw;

        Line currentLine;
        Line[] lines = new Line[MAX];
        int nLine = 0;

        Box currentBox;
        Box[] boxes = new Box[MAX];
        int nBox = 0;

        Circle currentCircle;
        Circle[] circles = new Circle[MAX];
        int nCircle = 0;

        public XDrawer()
        {            
            InitializeComponent();
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            if (_whatToDraw == DRAW_LINE)
            {
                currentLine = new Line(e.X, e.Y);
                lines[nLine] = currentLine;
                nLine++;
            }
            else if (_whatToDraw == DRAW_BOX)
            {
                currentBox = new Box(e.X, e.Y);
                boxes[nBox] = currentBox;
                nBox++;
            }
            else if (_whatToDraw == DRAW_CIRCLE)
            {
                currentCircle = new Circle(e.X, e.Y);
                circles[nCircle] = currentCircle;
                nCircle++;
            }


            isClicked = true;
        }

        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {   
            if (isClicked == true)
            {
                int eX = e.X;
                int eY = e.Y;

                Graphics g = canvas.CreateGraphics();

                Pen pen = new Pen(Color.Black);

                if (currentBox != null)
                {
                    currentBox.draw(g, pen);
                }
                else if (currentLine != null)
                {
                    currentLine.draw(g, pen);
                }
                else if (currentCircle != null)
                {
                    currentCircle.draw(g, pen);
                }
                               
                g.Dispose(); // garbage collection!
            }     
            
            isClicked = false;

            currentBox = null;
            currentLine = null;
            currentCircle = null;

            // reset canvas -> result in canvas_Paint()
            canvas.Invalidate();
        }

        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (isClicked == true)
            {
                int newX = e.X;
                int newY = e.Y;

                Graphics g = canvas.CreateGraphics();

                Pen pen = new Pen(Color.Black);
                Pen backPen = new Pen(canvas.BackColor);

                if (currentBox != null)
                {
                    // remove temporary box
                    currentBox.draw(g, backPen);
                    // update X, Y
                    currentBox.setXY2(newX, newY);
                    // draw temporary box
                    currentBox.draw(g, pen);
                }
                else if (currentLine != null)
                {
                    currentLine.draw(g, backPen);                    
                    currentLine.setXY2(newX, newY);
                    currentLine.draw(g, pen);
                }
                else if (currentCircle != null)
                {
                    currentCircle.draw(g, backPen);
                    currentCircle.setXY2(newX, newY);
                    currentCircle.draw(g, pen);
                }


                g.Dispose(); // garbage collection!
            }
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Pen pen = new Pen(Color.DarkRed);            

            for (int i = 0; i < nBox; i++)
            {
                boxes[i].draw(g, pen);
            }
            for (int i = 0; i < nLine; i++)
            {
                lines[i].draw(g, pen);
            }
            for (int i = 0; i < nCircle; i++)
            {
                circles[i].draw(g, pen);
            }
        }

        private void canvas_Click(object sender, EventArgs e)
        {

        }

        private void figureToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void boxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_BOX;
        }

        private void lineToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_LINE;
        }

        private void circleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_CIRCLE;
        }
    }
}
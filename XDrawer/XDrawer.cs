namespace XDrawer
{
    public partial class XDrawer : Form
    {
        static int MAX = 100;

        bool isClicked = false;

        Box currentBox;
        Box[] boxes = new Box[MAX];

        int nBox = 0;

        public XDrawer()
        {            
            InitializeComponent();
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            //MessageBox.Show("X ÁÂÇ¥ : " + e.X + "\nY ÁÂÇ¥ : " + e.Y + "\nÅ¬¸¯ ¹öÆ° : " + e.Button);
            currentBox = new Box(e.X, e.Y);
            boxes[nBox] = currentBox;
            nBox++;
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

                currentBox.draw(g, pen);
               
                g.Dispose(); // garbage collection!
            }       
            isClicked = false;
            currentBox = null;

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

                // remove temporary box
                currentBox.draw(g, backPen);
                // draw temporary box
                currentBox.draw(g, pen);

                g.Dispose(); // garbage collection!

                currentBox.setXY2(newX, newY);
            }
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Pen pen = new Pen(Color.Blue);            

            for (int i = 0; i < nBox; i++)
            {
                boxes[i].draw(g, pen);
            }
        }
    }
}
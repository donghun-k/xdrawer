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
                g.DrawRectangle(backPen, Math.Min(currentBox.x1, currentBox.x2), Math.Min(currentBox.y1, currentBox.y2), Math.Abs(currentBox.x2 - currentBox.x1), Math.Abs(currentBox.y2 - currentBox.y1));
                // draw temporary box
                g.DrawRectangle(pen, Math.Min(currentBox.x1, newX), Math.Min(currentBox.y1, newY), Math.Abs(newX - currentBox.x1), Math.Abs(newY - currentBox.y1));

                g.Dispose(); // garbage collection!

                currentBox.x2 = newX;
                currentBox.y2 = newY;
            }
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Pen pen = new Pen(Color.Blue);            

            for (int i = 0; i < nBox; i++)
            {
                g.DrawRectangle(pen, Math.Min(boxes[i].x1, boxes[i].x2), Math.Min(boxes[i].y1, boxes[i].y2), Math.Abs(boxes[i].x2 - boxes[i].x1), Math.Abs(boxes[i].y2 - boxes[i].y1));
            }
        }
    }
}
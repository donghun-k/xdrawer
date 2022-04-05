namespace XDrawer
{
    public partial class XDrawer : Form
    {
        public XDrawer()
        {
            InitializeComponent();
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show("X ÁÂÇ¥ : " + e.X + "\nY ÁÂÇ¥ : " + e.Y + "\nÅ¬¸¯ ¹öÆ° : " + e.Button);
        }
    }
}
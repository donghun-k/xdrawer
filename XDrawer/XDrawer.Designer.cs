namespace XDrawer
{
    partial class XDrawer
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(XDrawer));
            this.canvas = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.figureToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pointToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lineToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.boxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.circleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dialogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.modalDialogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.modalessDialogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip = new System.Windows.Forms.ToolStrip();
            this.toolStripBlackButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripRedButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripYellowButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripBlueButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSelectBox = new System.Windows.Forms.ToolStripComboBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.positionLable = new System.Windows.Forms.ToolStripStatusLabel();
            this.figureTypeLable = new System.Windows.Forms.ToolStripStatusLabel();
            ((System.ComponentModel.ISupportInitialize)(this.canvas)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.toolStrip.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // canvas
            // 
            this.canvas.Dock = System.Windows.Forms.DockStyle.Fill;
            this.canvas.Location = new System.Drawing.Point(0, 24);
            this.canvas.Name = "canvas";
            this.canvas.Size = new System.Drawing.Size(556, 418);
            this.canvas.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.canvas.TabIndex = 0;
            this.canvas.TabStop = false;
            this.canvas.Click += new System.EventHandler(this.canvas_Click);
            this.canvas.Paint += new System.Windows.Forms.PaintEventHandler(this.canvas_Paint);
            this.canvas.MouseDown += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseDown);
            this.canvas.MouseMove += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseMove);
            this.canvas.MouseUp += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseUp);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.figureToolStripMenuItem,
            this.dialogToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(556, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.saveToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.newToolStripMenuItem.Text = "New";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.openToolStripMenuItem.Text = "Open";
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.saveToolStripMenuItem.Text = "&Save";
            // 
            // figureToolStripMenuItem
            // 
            this.figureToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.pointToolStripMenuItem,
            this.lineToolStripMenuItem,
            this.boxToolStripMenuItem,
            this.circleToolStripMenuItem});
            this.figureToolStripMenuItem.Name = "figureToolStripMenuItem";
            this.figureToolStripMenuItem.Size = new System.Drawing.Size(52, 20);
            this.figureToolStripMenuItem.Text = "Figure";
            this.figureToolStripMenuItem.Click += new System.EventHandler(this.figureToolStripMenuItem_Click);
            // 
            // pointToolStripMenuItem
            // 
            this.pointToolStripMenuItem.Name = "pointToolStripMenuItem";
            this.pointToolStripMenuItem.Size = new System.Drawing.Size(104, 22);
            this.pointToolStripMenuItem.Text = "Point";
            this.pointToolStripMenuItem.Click += new System.EventHandler(this.pointToolStripMenuItem_Click);
            // 
            // lineToolStripMenuItem
            // 
            this.lineToolStripMenuItem.Name = "lineToolStripMenuItem";
            this.lineToolStripMenuItem.Size = new System.Drawing.Size(104, 22);
            this.lineToolStripMenuItem.Text = "Line";
            this.lineToolStripMenuItem.Click += new System.EventHandler(this.lineToolStripMenuItem_Click);
            // 
            // boxToolStripMenuItem
            // 
            this.boxToolStripMenuItem.Name = "boxToolStripMenuItem";
            this.boxToolStripMenuItem.Size = new System.Drawing.Size(104, 22);
            this.boxToolStripMenuItem.Text = "Box";
            this.boxToolStripMenuItem.Click += new System.EventHandler(this.boxToolStripMenuItem_Click);
            // 
            // circleToolStripMenuItem
            // 
            this.circleToolStripMenuItem.Name = "circleToolStripMenuItem";
            this.circleToolStripMenuItem.Size = new System.Drawing.Size(104, 22);
            this.circleToolStripMenuItem.Text = "Circle";
            this.circleToolStripMenuItem.Click += new System.EventHandler(this.circleToolStripMenuItem_Click);
            // 
            // dialogToolStripMenuItem
            // 
            this.dialogToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.modalDialogToolStripMenuItem,
            this.modalessDialogToolStripMenuItem});
            this.dialogToolStripMenuItem.Name = "dialogToolStripMenuItem";
            this.dialogToolStripMenuItem.Size = new System.Drawing.Size(54, 20);
            this.dialogToolStripMenuItem.Text = "Dialog";
            // 
            // modalDialogToolStripMenuItem
            // 
            this.modalDialogToolStripMenuItem.Name = "modalDialogToolStripMenuItem";
            this.modalDialogToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.modalDialogToolStripMenuItem.Text = "Modal Dialog";
            this.modalDialogToolStripMenuItem.Click += new System.EventHandler(this.modalDialogToolStripMenuItem_Click);
            // 
            // modalessDialogToolStripMenuItem
            // 
            this.modalessDialogToolStripMenuItem.Name = "modalessDialogToolStripMenuItem";
            this.modalessDialogToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.modalessDialogToolStripMenuItem.Text = "Modaless Dialog";
            this.modalessDialogToolStripMenuItem.Click += new System.EventHandler(this.modalessDialogToolStripMenuItem_Click);
            // 
            // toolStrip
            // 
            this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripBlackButton,
            this.toolStripRedButton,
            this.toolStripYellowButton,
            this.toolStripBlueButton,
            this.toolStripSeparator1,
            this.toolStripSelectBox});
            this.toolStrip.Location = new System.Drawing.Point(0, 24);
            this.toolStrip.Name = "toolStrip";
            this.toolStrip.Size = new System.Drawing.Size(556, 25);
            this.toolStrip.TabIndex = 2;
            this.toolStrip.Text = " ";
            // 
            // toolStripBlackButton
            // 
            this.toolStripBlackButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripBlackButton.Image = ((System.Drawing.Image)(resources.GetObject("toolStripBlackButton.Image")));
            this.toolStripBlackButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripBlackButton.Name = "toolStripBlackButton";
            this.toolStripBlackButton.Size = new System.Drawing.Size(23, 22);
            this.toolStripBlackButton.Text = "Black";
            this.toolStripBlackButton.ToolTipText = "Black";
            this.toolStripBlackButton.Click += new System.EventHandler(this.toolStripBlackButton_Click);
            // 
            // toolStripRedButton
            // 
            this.toolStripRedButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripRedButton.Image = ((System.Drawing.Image)(resources.GetObject("toolStripRedButton.Image")));
            this.toolStripRedButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripRedButton.Name = "toolStripRedButton";
            this.toolStripRedButton.Size = new System.Drawing.Size(23, 22);
            this.toolStripRedButton.Text = "Red";
            this.toolStripRedButton.ToolTipText = "Red";
            this.toolStripRedButton.Click += new System.EventHandler(this.toolStripRedButton_Click);
            // 
            // toolStripYellowButton
            // 
            this.toolStripYellowButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripYellowButton.Image = ((System.Drawing.Image)(resources.GetObject("toolStripYellowButton.Image")));
            this.toolStripYellowButton.ImageTransparentColor = System.Drawing.Color.Maroon;
            this.toolStripYellowButton.Name = "toolStripYellowButton";
            this.toolStripYellowButton.RightToLeftAutoMirrorImage = true;
            this.toolStripYellowButton.Size = new System.Drawing.Size(23, 22);
            this.toolStripYellowButton.Text = "Yellow";
            this.toolStripYellowButton.ToolTipText = "Yellow";
            this.toolStripYellowButton.Click += new System.EventHandler(this.toolStripYellowButton_Click);
            // 
            // toolStripBlueButton
            // 
            this.toolStripBlueButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripBlueButton.Image = ((System.Drawing.Image)(resources.GetObject("toolStripBlueButton.Image")));
            this.toolStripBlueButton.ImageTransparentColor = System.Drawing.Color.Maroon;
            this.toolStripBlueButton.Name = "toolStripBlueButton";
            this.toolStripBlueButton.Size = new System.Drawing.Size(23, 22);
            this.toolStripBlueButton.Text = "Blue";
            this.toolStripBlueButton.Click += new System.EventHandler(this.toolStripBlueButton_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripSelectBox
            // 
            this.toolStripSelectBox.Name = "toolStripSelectBox";
            this.toolStripSelectBox.Size = new System.Drawing.Size(121, 25);
            this.toolStripSelectBox.SelectedIndexChanged += new System.EventHandler(this.toolStripSelectBox_SelectedIndexChanged);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.positionLable,
            this.figureTypeLable});
            this.statusStrip1.Location = new System.Drawing.Point(0, 420);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(556, 22);
            this.statusStrip1.TabIndex = 3;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // positionLable
            // 
            this.positionLable.Name = "positionLable";
            this.positionLable.Size = new System.Drawing.Size(87, 17);
            this.positionLable.Text = "mouse positon";
            // 
            // figureTypeLable
            // 
            this.figureTypeLable.Name = "figureTypeLable";
            this.figureTypeLable.Size = new System.Drawing.Size(29, 17);
            this.figureTypeLable.Text = "Line";
            // 
            // XDrawer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(556, 442);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.toolStrip);
            this.Controls.Add(this.canvas);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "XDrawer";
            this.Text = "XDrawer";
            this.Load += new System.EventHandler(this.XDrawer_Load);
            ((System.ComponentModel.ISupportInitialize)(this.canvas)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip.ResumeLayout(false);
            this.toolStrip.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private PictureBox canvas;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem fileToolStripMenuItem;
        private ToolStripMenuItem newToolStripMenuItem;
        private ToolStripMenuItem openToolStripMenuItem;
        private ToolStripMenuItem saveToolStripMenuItem;
        private ToolStripMenuItem figureToolStripMenuItem;
        private ToolStripMenuItem boxToolStripMenuItem;
        private ToolStripMenuItem lineToolStripMenuItem;
        private ToolStripMenuItem circleToolStripMenuItem;
        private ToolStripMenuItem dialogToolStripMenuItem;
        private ToolStripMenuItem modalDialogToolStripMenuItem;
        private ToolStripMenuItem modalessDialogToolStripMenuItem;
        private ToolStripMenuItem pointToolStripMenuItem;
        private ToolStrip toolStrip;
        private ToolStripButton toolStripBlackButton;
        private ToolStripButton toolStripRedButton;
        private ToolStripButton toolStripYellowButton;
        private ToolStripButton toolStripBlueButton;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripComboBox toolStripSelectBox;
        private StatusStrip statusStrip1;
        private ToolStripStatusLabel positionLable;
        private ToolStripStatusLabel figureTypeLable;
    }
}
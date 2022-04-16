namespace XDrawer
{
    partial class FigureDialog
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelX1 = new System.Windows.Forms.Label();
            this.textX1 = new System.Windows.Forms.TextBox();
            this.textY1 = new System.Windows.Forms.TextBox();
            this.labelY1 = new System.Windows.Forms.Label();
            this.textX2 = new System.Windows.Forms.TextBox();
            this.labelX2 = new System.Windows.Forms.Label();
            this.textY2 = new System.Windows.Forms.TextBox();
            this.labelY2 = new System.Windows.Forms.Label();
            this.okayButton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelX1
            // 
            this.labelX1.AutoSize = true;
            this.labelX1.Location = new System.Drawing.Point(63, 63);
            this.labelX1.Name = "labelX1";
            this.labelX1.Size = new System.Drawing.Size(37, 20);
            this.labelX1.TabIndex = 0;
            this.labelX1.Text = "x1 : ";
            this.labelX1.Click += new System.EventHandler(this.label1_Click);
            // 
            // textX1
            // 
            this.textX1.Location = new System.Drawing.Point(106, 60);
            this.textX1.Name = "textX1";
            this.textX1.Size = new System.Drawing.Size(78, 27);
            this.textX1.TabIndex = 1;
            // 
            // textY1
            // 
            this.textY1.Location = new System.Drawing.Point(276, 63);
            this.textY1.Name = "textY1";
            this.textY1.Size = new System.Drawing.Size(78, 27);
            this.textY1.TabIndex = 3;
            // 
            // labelY1
            // 
            this.labelY1.AutoSize = true;
            this.labelY1.Location = new System.Drawing.Point(233, 66);
            this.labelY1.Name = "labelY1";
            this.labelY1.Size = new System.Drawing.Size(37, 20);
            this.labelY1.TabIndex = 2;
            this.labelY1.Text = "y1 : ";
            // 
            // textX2
            // 
            this.textX2.Location = new System.Drawing.Point(106, 142);
            this.textX2.Name = "textX2";
            this.textX2.Size = new System.Drawing.Size(78, 27);
            this.textX2.TabIndex = 5;
            // 
            // labelX2
            // 
            this.labelX2.AutoSize = true;
            this.labelX2.Location = new System.Drawing.Point(63, 145);
            this.labelX2.Name = "labelX2";
            this.labelX2.Size = new System.Drawing.Size(37, 20);
            this.labelX2.TabIndex = 4;
            this.labelX2.Text = "x2 : ";
            // 
            // textY2
            // 
            this.textY2.Location = new System.Drawing.Point(276, 145);
            this.textY2.Name = "textY2";
            this.textY2.Size = new System.Drawing.Size(78, 27);
            this.textY2.TabIndex = 7;
            // 
            // labelY2
            // 
            this.labelY2.AutoSize = true;
            this.labelY2.Location = new System.Drawing.Point(233, 148);
            this.labelY2.Name = "labelY2";
            this.labelY2.Size = new System.Drawing.Size(32, 20);
            this.labelY2.TabIndex = 6;
            this.labelY2.Text = "y2 :";
            // 
            // okayButton
            // 
            this.okayButton.Location = new System.Drawing.Point(106, 261);
            this.okayButton.Name = "okayButton";
            this.okayButton.Size = new System.Drawing.Size(94, 29);
            this.okayButton.TabIndex = 8;
            this.okayButton.Text = "OK";
            this.okayButton.UseVisualStyleBackColor = true;
            this.okayButton.Click += new System.EventHandler(this.okayButton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.Location = new System.Drawing.Point(218, 261);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(94, 29);
            this.cancelButton.TabIndex = 8;
            this.cancelButton.Text = "Cancel";
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // FigureDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(419, 365);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.okayButton);
            this.Controls.Add(this.textY2);
            this.Controls.Add(this.labelY2);
            this.Controls.Add(this.textX2);
            this.Controls.Add(this.labelX2);
            this.Controls.Add(this.textY1);
            this.Controls.Add(this.labelY1);
            this.Controls.Add(this.textX1);
            this.Controls.Add(this.labelX1);
            this.Name = "FigureDialog";
            this.Text = "FigureDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label labelX1;
        private TextBox textX1;
        private TextBox textY1;
        private Label labelY1;
        private TextBox textX2;
        private Label labelX2;
        private TextBox textY2;
        private Label labelY2;
        private Button okayButton;
        private Button cancelButton;
    }
}
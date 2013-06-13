namespace WindowsFormsApplication1
{
    partial class Painter
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
            this.controlsBox = new System.Windows.Forms.GroupBox();
            this.button2 = new System.Windows.Forms.Button();
            this.Triangle = new System.Windows.Forms.Button();
            this.controlsBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // controlsBox
            // 
            this.controlsBox.Controls.Add(this.button2);
            this.controlsBox.Controls.Add(this.Triangle);
            this.controlsBox.Location = new System.Drawing.Point(3, 9);
            this.controlsBox.Name = "controlsBox";
            this.controlsBox.Size = new System.Drawing.Size(95, 561);
            this.controlsBox.TabIndex = 0;
            this.controlsBox.TabStop = false;
            this.controlsBox.Text = "controls";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(10, 75);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "button2";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // Triangle
            // 
            this.Triangle.Location = new System.Drawing.Point(10, 20);
            this.Triangle.Name = "Triangle";
            this.Triangle.Size = new System.Drawing.Size(75, 23);
            this.Triangle.TabIndex = 0;
            this.Triangle.Text = "Triangle";
            this.Triangle.UseVisualStyleBackColor = true;
            this.Triangle.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Triangle_MouseClick);
            // 
            // Painter
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 962);
            this.Controls.Add(this.controlsBox);
            this.MaximumSize = new System.Drawing.Size(1000, 1000);
            this.Name = "Painter";
            this.Text = "Painter";
            this.Load += new System.EventHandler(this.Painter_Load);
            this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Painter_MouseClick);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Painter_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Painter_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Painter_MouseUp);
            this.controlsBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox controlsBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button Triangle;
    }
}


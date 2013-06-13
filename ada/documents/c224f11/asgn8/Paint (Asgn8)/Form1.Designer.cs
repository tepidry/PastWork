namespace Paint__Asgn8_
{
    partial class Form1
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
            this.Red = new System.Windows.Forms.RadioButton();
            this.Blue = new System.Windows.Forms.RadioButton();
            this.Green = new System.Windows.Forms.RadioButton();
            this.Black = new System.Windows.Forms.RadioButton();
            this.Rainbow = new System.Windows.Forms.RadioButton();
            this.Random = new System.Windows.Forms.RadioButton();
            this.Small = new System.Windows.Forms.RadioButton();
            this.Medium = new System.Windows.Forms.RadioButton();
            this.Large = new System.Windows.Forms.RadioButton();
            this.Color = new System.Windows.Forms.GroupBox();
            this.boxSize = new System.Windows.Forms.GroupBox();
            this.Color.SuspendLayout();
            this.boxSize.SuspendLayout();
            this.SuspendLayout();
            // 
            // Red
            // 
            this.Red.AutoSize = true;
            this.Red.BackColor = System.Drawing.Color.Transparent;
            this.Red.ForeColor = System.Drawing.Color.Red;
            this.Red.Location = new System.Drawing.Point(6, 25);
            this.Red.Name = "Red";
            this.Red.Size = new System.Drawing.Size(48, 17);
            this.Red.TabIndex = 0;
            this.Red.TabStop = true;
            this.Red.Text = "RED";
            this.Red.UseVisualStyleBackColor = false;
            this.Red.CheckedChanged += new System.EventHandler(this.Red_CheckChanged);
            this.Red.Checked = true;
            // 
            // Blue
            // 
            this.Blue.AutoSize = true;
            this.Blue.ForeColor = System.Drawing.Color.Blue;
            this.Blue.Location = new System.Drawing.Point(6, 48);
            this.Blue.Name = "Blue";
            this.Blue.Size = new System.Drawing.Size(53, 17);
            this.Blue.TabIndex = 2;
            this.Blue.Text = "BLUE";
            this.Blue.UseVisualStyleBackColor = true;
            this.Blue.CheckedChanged += new System.EventHandler(this.Blue_CheckedChanged);
            // 
            // Green
            // 
            this.Green.AutoSize = true;
            this.Green.ForeColor = System.Drawing.Color.Lime;
            this.Green.Location = new System.Drawing.Point(6, 71);
            this.Green.Name = "Green";
            this.Green.Size = new System.Drawing.Size(63, 17);
            this.Green.TabIndex = 4;
            this.Green.Text = "GREEN";
            this.Green.UseVisualStyleBackColor = true;
            this.Green.CheckedChanged += new System.EventHandler(this.Green_CheckedChanged);
            // 
            // Black
            // 
            this.Black.AutoSize = true;
            this.Black.ForeColor = System.Drawing.Color.Black;
            this.Black.Location = new System.Drawing.Point(6, 94);
            this.Black.Name = "Black";
            this.Black.Size = new System.Drawing.Size(59, 17);
            this.Black.TabIndex = 6;
            this.Black.Text = "BLACK";
            this.Black.UseVisualStyleBackColor = true;
            this.Black.CheckedChanged += new System.EventHandler(this.Black_CheckedChanged);
            // 
            // Rainbow
            // 
            this.Rainbow.AutoSize = true;
            this.Rainbow.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.Rainbow.Location = new System.Drawing.Point(6, 117);
            this.Rainbow.Name = "Rainbow";
            this.Rainbow.Size = new System.Drawing.Size(77, 17);
            this.Rainbow.TabIndex = 8;
            this.Rainbow.Text = "RAINBOW";
            this.Rainbow.UseVisualStyleBackColor = true;
            this.Rainbow.CheckedChanged += new System.EventHandler(this.Rainbow_CheckedChanged);
            // 
            // Random
            // 
            this.Random.AutoSize = true;
            this.Random.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Random.Location = new System.Drawing.Point(6, 140);
            this.Random.Name = "Random";
            this.Random.Size = new System.Drawing.Size(73, 17);
            this.Random.TabIndex = 10;
            this.Random.Text = "RANDOM";
            this.Random.UseVisualStyleBackColor = true;
            this.Random.CheckedChanged += new System.EventHandler(this.Random_CheckedChanged);
            // 
            // Small
            // 
            this.Small.AutoSize = true;
            this.Small.Location = new System.Drawing.Point(13, 19);
            this.Small.Name = "Small";
            this.Small.Size = new System.Drawing.Size(50, 17);
            this.Small.TabIndex = 12;
            this.Small.TabStop = true;
            this.Small.Text = "Small";
            this.Small.UseVisualStyleBackColor = true;
            this.Small.CheckedChanged += new System.EventHandler(this.Small_CheckedChanged);
            this.Small.Checked = true;
            // 
            // Medium
            // 
            this.Medium.AutoSize = true;
            this.Medium.Location = new System.Drawing.Point(13, 42);
            this.Medium.Name = "Medium";
            this.Medium.Size = new System.Drawing.Size(62, 17);
            this.Medium.TabIndex = 14;
            this.Medium.TabStop = true;
            this.Medium.Text = "Medium";
            this.Medium.UseVisualStyleBackColor = true;
            this.Medium.CheckedChanged += new System.EventHandler(this.Medium_CheckedChanged);
            // 
            // Large
            // 
            this.Large.AutoSize = true;
            this.Large.BackColor = System.Drawing.Color.Transparent;
            this.Large.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Large.Location = new System.Drawing.Point(13, 65);
            this.Large.Name = "Large";
            this.Large.Size = new System.Drawing.Size(52, 17);
            this.Large.TabIndex = 16;
            this.Large.TabStop = true;
            this.Large.Text = "Large";
            this.Large.UseVisualStyleBackColor = false;
            this.Large.CheckedChanged += new System.EventHandler(this.Large_CheckedChanged);
            // 
            // Color
            // 
            this.Color.BackColor = System.Drawing.Color.Silver;
            this.Color.Controls.Add(this.Random);
            this.Color.Controls.Add(this.Red);
            this.Color.Controls.Add(this.Blue);
            this.Color.Controls.Add(this.Green);
            this.Color.Controls.Add(this.Black);
            this.Color.Controls.Add(this.Rainbow);
            this.Color.ForeColor = System.Drawing.Color.White;
            this.Color.Location = new System.Drawing.Point(2, 3);
            this.Color.Name = "Color";
            this.Color.Size = new System.Drawing.Size(85, 164);
            this.Color.TabIndex = 0;
            this.Color.TabStop = false;
            this.Color.Text = "Color";
            // 
            // boxSize
            // 
            this.boxSize.BackColor = System.Drawing.Color.Silver;
            this.boxSize.Controls.Add(this.Small);
            this.boxSize.Controls.Add(this.Medium);
            this.boxSize.Controls.Add(this.Large);
            this.boxSize.ForeColor = System.Drawing.Color.Black;
            this.boxSize.Location = new System.Drawing.Point(2, 166);
            this.boxSize.Name = "boxSize";
            this.boxSize.Size = new System.Drawing.Size(83, 88);
            this.boxSize.TabIndex = 18;
            this.boxSize.TabStop = false;
            this.boxSize.Text = "Size";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(659, 445);
            this.Controls.Add(this.boxSize);
            this.Controls.Add(this.Color);
            this.ForeColor = System.Drawing.Color.White;
            this.Name = "Form1";
            this.Text = "Form1";
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            this.Color.ResumeLayout(false);
            this.Color.PerformLayout();
            this.boxSize.ResumeLayout(false);
            this.boxSize.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RadioButton Red;
        private System.Windows.Forms.RadioButton Blue;
        private System.Windows.Forms.RadioButton Green;
        private System.Windows.Forms.RadioButton Black;
        private System.Windows.Forms.RadioButton Rainbow;
        private System.Windows.Forms.RadioButton Random;
        private System.Windows.Forms.RadioButton Small;
        private System.Windows.Forms.RadioButton Medium;
        private System.Windows.Forms.RadioButton Large;
        private System.Windows.Forms.GroupBox Color;
        private System.Windows.Forms.GroupBox boxSize;
    }
}


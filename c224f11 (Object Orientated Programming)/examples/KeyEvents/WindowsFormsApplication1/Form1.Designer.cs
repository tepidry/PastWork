namespace WindowsFormsApplication1
{
    partial class KeyEvents
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
            this.charLabel = new System.Windows.Forms.Label();
            this.keyLabel = new System.Windows.Forms.Label();
            this.enterLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // charLabel
            // 
            this.charLabel.AutoSize = true;
            this.charLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.charLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.charLabel.Enabled = false;
            this.charLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.charLabel.Location = new System.Drawing.Point(25, 13);
            this.charLabel.Name = "charLabel";
            this.charLabel.Size = new System.Drawing.Size(2, 22);
            this.charLabel.TabIndex = 0;
            // 
            // keyLabel
            // 
            this.keyLabel.AutoSize = true;
            this.keyLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.keyLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.keyLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.keyLabel.Location = new System.Drawing.Point(25, 84);
            this.keyLabel.Name = "keyLabel";
            this.keyLabel.Size = new System.Drawing.Size(2, 22);
            this.keyLabel.TabIndex = 1;
            // 
            // enterLabel
            // 
            this.enterLabel.AutoSize = true;
            this.enterLabel.Location = new System.Drawing.Point(25, 147);
            this.enterLabel.Name = "enterLabel";
            this.enterLabel.Size = new System.Drawing.Size(0, 13);
            this.enterLabel.TabIndex = 2;
            // 
            // KeyEvents
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.enterLabel);
            this.Controls.Add(this.keyLabel);
            this.Controls.Add(this.charLabel);
            this.Name = "KeyEvents";
            this.Text = "Keyboard Events";
            this.Load += new System.EventHandler(this.KeyEvents_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyEvents_KeyDown);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.KeyEvents_KeyPress);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyEvents_KeyUp);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label charLabel;
        private System.Windows.Forms.Label keyLabel;
        private System.Windows.Forms.Label enterLabel;
    }
}


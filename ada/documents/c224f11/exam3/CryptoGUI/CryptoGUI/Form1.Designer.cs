namespace CryptoGUI
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
            this.Input = new System.Windows.Forms.RichTextBox();
            this.Output = new System.Windows.Forms.RichTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Affine = new System.Windows.Forms.RadioButton();
            this.Vignere = new System.Windows.Forms.RadioButton();
            this.Encrypt = new System.Windows.Forms.RadioButton();
            this.Decrypt = new System.Windows.Forms.RadioButton();
            this.Shift = new System.Windows.Forms.TextBox();
            this.Multiplier = new System.Windows.Forms.TextBox();
            this.Key = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Go_Button = new System.Windows.Forms.Button();
            this.Copy_Button = new System.Windows.Forms.Button();
            this.Clear_Button = new System.Windows.Forms.Button();
            this.Read_Button = new System.Windows.Forms.Button();
            this.Write_Button = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Input
            // 
            this.Input.Location = new System.Drawing.Point(12, 26);
            this.Input.Name = "Input";
            this.Input.Size = new System.Drawing.Size(296, 198);
            this.Input.TabIndex = 0;
            this.Input.Text = "";
            // 
            // Output
            // 
            this.Output.Location = new System.Drawing.Point(12, 259);
            this.Output.Name = "Output";
            this.Output.Size = new System.Drawing.Size(296, 214);
            this.Output.TabIndex = 1;
            this.Output.Text = "";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Input";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 243);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Output";
            // 
            // Affine
            // 
            this.Affine.AutoSize = true;
            this.Affine.Checked = true;
            this.Affine.Location = new System.Drawing.Point(335, 27);
            this.Affine.Name = "Affine";
            this.Affine.Size = new System.Drawing.Size(52, 17);
            this.Affine.TabIndex = 4;
            this.Affine.TabStop = true;
            this.Affine.Text = "Affine";
            this.Affine.UseVisualStyleBackColor = true;
            this.Affine.CheckedChanged += new System.EventHandler(this.Affine_CheckedChanged);
            // 
            // Vignere
            // 
            this.Vignere.AutoSize = true;
            this.Vignere.Location = new System.Drawing.Point(465, 27);
            this.Vignere.Name = "Vignere";
            this.Vignere.Size = new System.Drawing.Size(61, 17);
            this.Vignere.TabIndex = 5;
            this.Vignere.TabStop = true;
            this.Vignere.Text = "Vignere";
            this.Vignere.UseVisualStyleBackColor = true;
            this.Vignere.CheckedChanged += new System.EventHandler(this.Vignere_CheckedChanged);
            // 
            // Encrypt
            // 
            this.Encrypt.AutoSize = true;
            this.Encrypt.Checked = true;
            this.Encrypt.Location = new System.Drawing.Point(7, 48);
            this.Encrypt.Name = "Encrypt";
            this.Encrypt.Size = new System.Drawing.Size(61, 17);
            this.Encrypt.TabIndex = 6;
            this.Encrypt.TabStop = true;
            this.Encrypt.Text = "Encrypt";
            this.Encrypt.UseVisualStyleBackColor = true;
            this.Encrypt.CheckedChanged += new System.EventHandler(this.Encrypt_CheckedChanged);
            // 
            // Decrypt
            // 
            this.Decrypt.AutoSize = true;
            this.Decrypt.Location = new System.Drawing.Point(6, 20);
            this.Decrypt.Name = "Decrypt";
            this.Decrypt.Size = new System.Drawing.Size(62, 17);
            this.Decrypt.TabIndex = 7;
            this.Decrypt.TabStop = true;
            this.Decrypt.Text = "Decrypt";
            this.Decrypt.UseVisualStyleBackColor = true;
            this.Decrypt.CheckedChanged += new System.EventHandler(this.Decrypt_CheckedChanged);
            // 
            // Shift
            // 
            this.Shift.Location = new System.Drawing.Point(335, 66);
            this.Shift.Name = "Shift";
            this.Shift.Size = new System.Drawing.Size(100, 20);
            this.Shift.TabIndex = 8;
            
            // 
            // Multiplier
            // 
            this.Multiplier.Location = new System.Drawing.Point(335, 105);
            this.Multiplier.Name = "Multiplier";
            this.Multiplier.Size = new System.Drawing.Size(100, 20);
            this.Multiplier.TabIndex = 9;
            // 
            // Key
            // 
            this.Key.Location = new System.Drawing.Point(465, 66);
            this.Key.Name = "Key";
            this.Key.Size = new System.Drawing.Size(100, 20);
            this.Key.TabIndex = 10;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(344, 47);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(28, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Shift";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(344, 89);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(48, 13);
            this.label7.TabIndex = 12;
            this.label7.Text = "Multiplier";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(476, 47);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(25, 13);
            this.label6.TabIndex = 13;
            this.label6.Text = "Key";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(345, 387);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 13);
            this.label4.TabIndex = 17;
            // 
            // Go_Button
            // 
            this.Go_Button.BackColor = System.Drawing.Color.Lime;
            this.Go_Button.Location = new System.Drawing.Point(479, 105);
            this.Go_Button.Name = "Go_Button";
            this.Go_Button.Size = new System.Drawing.Size(75, 59);
            this.Go_Button.TabIndex = 18;
            this.Go_Button.Text = "GO!";
            this.Go_Button.UseVisualStyleBackColor = false;
            this.Go_Button.Click += new System.EventHandler(this.Go_Button_Click);
            // 
            // Copy_Button
            // 
            this.Copy_Button.Location = new System.Drawing.Point(479, 190);
            this.Copy_Button.Name = "Copy_Button";
            this.Copy_Button.Size = new System.Drawing.Size(75, 23);
            this.Copy_Button.TabIndex = 19;
            this.Copy_Button.Text = "Copy";
            this.Copy_Button.UseVisualStyleBackColor = true;
            this.Copy_Button.Click += new System.EventHandler(this.Copy_Button_Click);
            // 
            // Clear_Button
            // 
            this.Clear_Button.Location = new System.Drawing.Point(479, 219);
            this.Clear_Button.Name = "Clear_Button";
            this.Clear_Button.Size = new System.Drawing.Size(75, 23);
            this.Clear_Button.TabIndex = 20;
            this.Clear_Button.Text = "Clear";
            this.Clear_Button.UseVisualStyleBackColor = true;
            this.Clear_Button.Click += new System.EventHandler(this.Clear_Button_Click);
            // 
            // Read_Button
            // 
            this.Read_Button.Location = new System.Drawing.Point(336, 269);
            this.Read_Button.Name = "Read_Button";
            this.Read_Button.Size = new System.Drawing.Size(99, 23);
            this.Read_Button.TabIndex = 21;
            this.Read_Button.Text = "Read";
            this.Read_Button.UseVisualStyleBackColor = true;
            this.Read_Button.Click += new System.EventHandler(this.Read_Button_Click);
            // 
            // Write_Button
            // 
            this.Write_Button.Location = new System.Drawing.Point(336, 324);
            this.Write_Button.Name = "Write_Button";
            this.Write_Button.Size = new System.Drawing.Size(99, 23);
            this.Write_Button.TabIndex = 22;
            this.Write_Button.Text = "Write";
            this.Write_Button.UseVisualStyleBackColor = true;
            this.Write_Button.Click += new System.EventHandler(this.Write_Button_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(345, 308);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 13);
            this.label3.TabIndex = 24;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Decrypt);
            this.groupBox1.Controls.Add(this.Encrypt);
            this.groupBox1.Location = new System.Drawing.Point(336, 142);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(91, 100);
            this.groupBox1.TabIndex = 25;
            this.groupBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(648, 494);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Write_Button);
            this.Controls.Add(this.Read_Button);
            this.Controls.Add(this.Clear_Button);
            this.Controls.Add(this.Copy_Button);
            this.Controls.Add(this.Go_Button);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.Key);
            this.Controls.Add(this.Multiplier);
            this.Controls.Add(this.Shift);
            this.Controls.Add(this.Vignere);
            this.Controls.Add(this.Affine);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Output);
            this.Controls.Add(this.Input);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox Input;
        private System.Windows.Forms.RichTextBox Output;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RadioButton Affine;
        private System.Windows.Forms.RadioButton Vignere;
        private System.Windows.Forms.RadioButton Encrypt;
        private System.Windows.Forms.RadioButton Decrypt;
        private System.Windows.Forms.TextBox Shift;
        private System.Windows.Forms.TextBox Multiplier;
        private System.Windows.Forms.TextBox Key;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button Go_Button;
        private System.Windows.Forms.Button Copy_Button;
        private System.Windows.Forms.Button Clear_Button;
        private System.Windows.Forms.Button Read_Button;
        private System.Windows.Forms.Button Write_Button;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}


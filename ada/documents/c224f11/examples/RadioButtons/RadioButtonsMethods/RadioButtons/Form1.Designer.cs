namespace WindowsFormsApplication1
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
            this.ButtonTypeBox = new System.Windows.Forms.GroupBox();
            this.RetryCancelButton = new System.Windows.Forms.RadioButton();
            this.YesNoButton = new System.Windows.Forms.RadioButton();
            this.YesNoCancelButton = new System.Windows.Forms.RadioButton();
            this.abortRetryIgnoreButton = new System.Windows.Forms.RadioButton();
            this.OKCancelButton = new System.Windows.Forms.RadioButton();
            this.OKButton = new System.Windows.Forms.RadioButton();
            this.IconBox = new System.Windows.Forms.GroupBox();
            this.WarningButton = new System.Windows.Forms.RadioButton();
            this.StopButton = new System.Windows.Forms.RadioButton();
            this.QuestionButton = new System.Windows.Forms.RadioButton();
            this.InformationButton = new System.Windows.Forms.RadioButton();
            this.HandButton = new System.Windows.Forms.RadioButton();
            this.ExclamationButton = new System.Windows.Forms.RadioButton();
            this.ErrorButton = new System.Windows.Forms.RadioButton();
            this.AsteriskButton = new System.Windows.Forms.RadioButton();
            this.DisplayButton = new System.Windows.Forms.Button();
            this.DisplayLabel = new System.Windows.Forms.Label();
            this.ButtonTypeBox.SuspendLayout();
            this.IconBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // ButtonTypeBox
            // 
            this.ButtonTypeBox.Controls.Add(this.RetryCancelButton);
            this.ButtonTypeBox.Controls.Add(this.YesNoButton);
            this.ButtonTypeBox.Controls.Add(this.YesNoCancelButton);
            this.ButtonTypeBox.Controls.Add(this.abortRetryIgnoreButton);
            this.ButtonTypeBox.Controls.Add(this.OKCancelButton);
            this.ButtonTypeBox.Controls.Add(this.OKButton);
            this.ButtonTypeBox.Location = new System.Drawing.Point(36, 28);
            this.ButtonTypeBox.Name = "ButtonTypeBox";
            this.ButtonTypeBox.Size = new System.Drawing.Size(139, 178);
            this.ButtonTypeBox.TabIndex = 0;
            this.ButtonTypeBox.TabStop = false;
            this.ButtonTypeBox.Text = "Button Type";
            // 
            // RetryCancelButton
            // 
            this.RetryCancelButton.AutoSize = true;
            this.RetryCancelButton.Location = new System.Drawing.Point(6, 135);
            this.RetryCancelButton.Name = "RetryCancelButton";
            this.RetryCancelButton.Size = new System.Drawing.Size(86, 17);
            this.RetryCancelButton.TabIndex = 5;
            this.RetryCancelButton.TabStop = true;
            this.RetryCancelButton.Text = "Retry Cancel";
            this.RetryCancelButton.UseVisualStyleBackColor = true;
            this.RetryCancelButton.CheckedChanged += new System.EventHandler(this.RetryCancelButton_CheckedChanged);
            // 
            // YesNoButton
            // 
            this.YesNoButton.AutoSize = true;
            this.YesNoButton.Location = new System.Drawing.Point(7, 112);
            this.YesNoButton.Name = "YesNoButton";
            this.YesNoButton.Size = new System.Drawing.Size(60, 17);
            this.YesNoButton.TabIndex = 4;
            this.YesNoButton.TabStop = true;
            this.YesNoButton.Text = "Yes No";
            this.YesNoButton.UseVisualStyleBackColor = true;
            this.YesNoButton.CheckedChanged += new System.EventHandler(this.YesNoButton_CheckedChanged);
            // 
            // YesNoCancelButton
            // 
            this.YesNoCancelButton.AutoSize = true;
            this.YesNoCancelButton.Location = new System.Drawing.Point(6, 89);
            this.YesNoCancelButton.Name = "YesNoCancelButton";
            this.YesNoCancelButton.Size = new System.Drawing.Size(96, 17);
            this.YesNoCancelButton.TabIndex = 3;
            this.YesNoCancelButton.TabStop = true;
            this.YesNoCancelButton.Text = "Yes No Cancel";
            this.YesNoCancelButton.UseVisualStyleBackColor = true;
            this.YesNoCancelButton.CheckedChanged += new System.EventHandler(this.YesNoCancelButton_CheckedChanged);
            // 
            // abortRetryIgnoreButton
            // 
            this.abortRetryIgnoreButton.AutoSize = true;
            this.abortRetryIgnoreButton.Location = new System.Drawing.Point(7, 66);
            this.abortRetryIgnoreButton.Name = "abortRetryIgnoreButton";
            this.abortRetryIgnoreButton.Size = new System.Drawing.Size(111, 17);
            this.abortRetryIgnoreButton.TabIndex = 2;
            this.abortRetryIgnoreButton.TabStop = true;
            this.abortRetryIgnoreButton.Text = "Abort Retry Ignore";
            this.abortRetryIgnoreButton.UseVisualStyleBackColor = true;
            this.abortRetryIgnoreButton.CheckedChanged += new System.EventHandler(this.abortRetryIgnoreButton_CheckedChanged);
            // 
            // OKCancelButton
            // 
            this.OKCancelButton.AutoSize = true;
            this.OKCancelButton.Location = new System.Drawing.Point(7, 43);
            this.OKCancelButton.Name = "OKCancelButton";
            this.OKCancelButton.Size = new System.Drawing.Size(76, 17);
            this.OKCancelButton.TabIndex = 1;
            this.OKCancelButton.TabStop = true;
            this.OKCancelButton.Text = "OK Cancel";
            this.OKCancelButton.UseVisualStyleBackColor = true;
            this.OKCancelButton.CheckedChanged += new System.EventHandler(this.OKCancelButton_CheckedChanged);
            // 
            // OKButton
            // 
            this.OKButton.AutoSize = true;
            this.OKButton.Location = new System.Drawing.Point(7, 20);
            this.OKButton.Name = "OKButton";
            this.OKButton.Size = new System.Drawing.Size(40, 17);
            this.OKButton.TabIndex = 0;
            this.OKButton.TabStop = true;
            this.OKButton.Text = "OK";
            this.OKButton.UseVisualStyleBackColor = true;
            this.OKButton.CheckedChanged += new System.EventHandler(this.OKButton_CheckedChanged);
            // 
            // IconBox
            // 
            this.IconBox.Controls.Add(this.WarningButton);
            this.IconBox.Controls.Add(this.StopButton);
            this.IconBox.Controls.Add(this.QuestionButton);
            this.IconBox.Controls.Add(this.InformationButton);
            this.IconBox.Controls.Add(this.HandButton);
            this.IconBox.Controls.Add(this.ExclamationButton);
            this.IconBox.Controls.Add(this.ErrorButton);
            this.IconBox.Controls.Add(this.AsteriskButton);
            this.IconBox.Location = new System.Drawing.Point(181, 28);
            this.IconBox.Name = "IconBox";
            this.IconBox.Size = new System.Drawing.Size(179, 277);
            this.IconBox.TabIndex = 1;
            this.IconBox.TabStop = false;
            this.IconBox.Text = "Icon";
            // 
            // WarningButton
            // 
            this.WarningButton.AutoSize = true;
            this.WarningButton.Location = new System.Drawing.Point(7, 188);
            this.WarningButton.Name = "WarningButton";
            this.WarningButton.Size = new System.Drawing.Size(65, 17);
            this.WarningButton.TabIndex = 7;
            this.WarningButton.TabStop = true;
            this.WarningButton.Text = "Warning";
            this.WarningButton.UseVisualStyleBackColor = true;
            this.WarningButton.CheckedChanged += new System.EventHandler(this.WarningButton_CheckedChanged);
            // 
            // StopButton
            // 
            this.StopButton.AutoSize = true;
            this.StopButton.Location = new System.Drawing.Point(7, 164);
            this.StopButton.Name = "StopButton";
            this.StopButton.Size = new System.Drawing.Size(47, 17);
            this.StopButton.TabIndex = 6;
            this.StopButton.TabStop = true;
            this.StopButton.Text = "Stop";
            this.StopButton.UseVisualStyleBackColor = true;
            this.StopButton.CheckedChanged += new System.EventHandler(this.StopButton_CheckedChanged);
            // 
            // QuestionButton
            // 
            this.QuestionButton.AutoSize = true;
            this.QuestionButton.Location = new System.Drawing.Point(7, 140);
            this.QuestionButton.Name = "QuestionButton";
            this.QuestionButton.Size = new System.Drawing.Size(67, 17);
            this.QuestionButton.TabIndex = 5;
            this.QuestionButton.TabStop = true;
            this.QuestionButton.Text = "Question";
            this.QuestionButton.UseVisualStyleBackColor = true;
            this.QuestionButton.CheckedChanged += new System.EventHandler(this.QuestionButton_CheckedChanged);
            // 
            // InformationButton
            // 
            this.InformationButton.AutoSize = true;
            this.InformationButton.Location = new System.Drawing.Point(7, 116);
            this.InformationButton.Name = "InformationButton";
            this.InformationButton.Size = new System.Drawing.Size(77, 17);
            this.InformationButton.TabIndex = 4;
            this.InformationButton.TabStop = true;
            this.InformationButton.Text = "Information";
            this.InformationButton.UseVisualStyleBackColor = true;
            this.InformationButton.CheckedChanged += new System.EventHandler(this.InformationButton_CheckedChanged);
            // 
            // HandButton
            // 
            this.HandButton.AutoSize = true;
            this.HandButton.Location = new System.Drawing.Point(7, 92);
            this.HandButton.Name = "HandButton";
            this.HandButton.Size = new System.Drawing.Size(51, 17);
            this.HandButton.TabIndex = 3;
            this.HandButton.TabStop = true;
            this.HandButton.Text = "Hand";
            this.HandButton.UseVisualStyleBackColor = true;
            this.HandButton.CheckedChanged += new System.EventHandler(this.HandButton_CheckedChanged);
            // 
            // ExclamationButton
            // 
            this.ExclamationButton.AutoSize = true;
            this.ExclamationButton.Location = new System.Drawing.Point(7, 68);
            this.ExclamationButton.Name = "ExclamationButton";
            this.ExclamationButton.Size = new System.Drawing.Size(82, 17);
            this.ExclamationButton.TabIndex = 2;
            this.ExclamationButton.TabStop = true;
            this.ExclamationButton.Text = "Exclamation";
            this.ExclamationButton.UseVisualStyleBackColor = true;
            this.ExclamationButton.CheckedChanged += new System.EventHandler(this.ExclamationButton_CheckedChanged);
            // 
            // ErrorButton
            // 
            this.ErrorButton.AutoSize = true;
            this.ErrorButton.Location = new System.Drawing.Point(7, 44);
            this.ErrorButton.Name = "ErrorButton";
            this.ErrorButton.Size = new System.Drawing.Size(47, 17);
            this.ErrorButton.TabIndex = 1;
            this.ErrorButton.TabStop = true;
            this.ErrorButton.Text = "Error";
            this.ErrorButton.UseVisualStyleBackColor = true;
            this.ErrorButton.CheckedChanged += new System.EventHandler(this.ErrorButton_CheckedChanged);
            // 
            // AsteriskButton
            // 
            this.AsteriskButton.AutoSize = true;
            this.AsteriskButton.Location = new System.Drawing.Point(7, 20);
            this.AsteriskButton.Name = "AsteriskButton";
            this.AsteriskButton.Size = new System.Drawing.Size(62, 17);
            this.AsteriskButton.TabIndex = 0;
            this.AsteriskButton.TabStop = true;
            this.AsteriskButton.Text = "Asterisk";
            this.AsteriskButton.UseVisualStyleBackColor = true;
            this.AsteriskButton.CheckedChanged += new System.EventHandler(this.AsteriskButton_CheckedChanged);
            // 
            // DisplayButton
            // 
            this.DisplayButton.Location = new System.Drawing.Point(37, 230);
            this.DisplayButton.Name = "DisplayButton";
            this.DisplayButton.Size = new System.Drawing.Size(137, 75);
            this.DisplayButton.TabIndex = 2;
            this.DisplayButton.Text = "Display";
            this.DisplayButton.UseVisualStyleBackColor = true;
            this.DisplayButton.Click += new System.EventHandler(this.DisplayButton_Click);
            // 
            // DisplayLabel
            // 
            this.DisplayLabel.AutoSize = true;
            this.DisplayLabel.Location = new System.Drawing.Point(33, 345);
            this.DisplayLabel.Name = "DisplayLabel";
            this.DisplayLabel.Size = new System.Drawing.Size(0, 13);
            this.DisplayLabel.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(371, 498);
            this.Controls.Add(this.DisplayLabel);
            this.Controls.Add(this.DisplayButton);
            this.Controls.Add(this.IconBox);
            this.Controls.Add(this.ButtonTypeBox);
            this.Name = "Form1";
            this.Text = "Radio Buttons";
            this.ButtonTypeBox.ResumeLayout(false);
            this.ButtonTypeBox.PerformLayout();
            this.IconBox.ResumeLayout(false);
            this.IconBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox ButtonTypeBox;
        private System.Windows.Forms.RadioButton RetryCancelButton;
        private System.Windows.Forms.RadioButton YesNoButton;
        private System.Windows.Forms.RadioButton YesNoCancelButton;
        private System.Windows.Forms.RadioButton abortRetryIgnoreButton;
        private System.Windows.Forms.RadioButton OKCancelButton;
        private System.Windows.Forms.RadioButton OKButton;
        private System.Windows.Forms.GroupBox IconBox;
        private System.Windows.Forms.RadioButton AsteriskButton;
        private System.Windows.Forms.Button DisplayButton;
        private System.Windows.Forms.Label DisplayLabel;
        private System.Windows.Forms.RadioButton WarningButton;
        private System.Windows.Forms.RadioButton StopButton;
        private System.Windows.Forms.RadioButton QuestionButton;
        private System.Windows.Forms.RadioButton InformationButton;
        private System.Windows.Forms.RadioButton HandButton;
        private System.Windows.Forms.RadioButton ExclamationButton;
        private System.Windows.Forms.RadioButton ErrorButton;
    }
}


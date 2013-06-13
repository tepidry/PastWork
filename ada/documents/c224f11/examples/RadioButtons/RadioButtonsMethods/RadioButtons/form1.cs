using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private MessageBoxButtons buttonType;
        private MessageBoxIcon iconType;
        public Form1()
        {
            InitializeComponent();
        }

        private void OKButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == OKButton)
                buttonType = MessageBoxButtons.OK;
        }

        private void OKCancelButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == OKCancelButton)
                buttonType = MessageBoxButtons.OKCancel;
        }

        private void abortRetryIgnoreButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == abortRetryIgnoreButton)
                buttonType = MessageBoxButtons.AbortRetryIgnore;
        }

        private void YesNoCancelButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == YesNoCancelButton)
                buttonType = MessageBoxButtons.YesNoCancel;
        }

        private void YesNoButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == YesNoButton)
                buttonType = MessageBoxButtons.YesNo;
        }

        private void RetryCancelButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == RetryCancelButton)
                buttonType = MessageBoxButtons.RetryCancel;
        }

        private void AsteriskButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == AsteriskButton)
                iconType = MessageBoxIcon.Asterisk;
        }

        
        private void ErrorButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == ErrorButton)
                iconType = MessageBoxIcon.Error;
        }

        private void ExclamationButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == ExclamationButton)
                iconType = MessageBoxIcon.Exclamation;
        }

        private void HandButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == HandButton)
                iconType = MessageBoxIcon.Hand;
        }

        private void InformationButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == InformationButton)
                iconType = MessageBoxIcon.Information;
        }

        private void QuestionButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == QuestionButton)
                iconType = MessageBoxIcon.Question;
        }

        private void StopButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == StopButton)
                iconType = MessageBoxIcon.Stop;
        }

        private void WarningButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == WarningButton)
                iconType = MessageBoxIcon.Warning;
        }

        private void DisplayButton_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Do you like this message box?", "Custom MessageBox", 
                                  buttonType, iconType);
            Console.WriteLine(iconType);
            switch (result)
            {
                case DialogResult.OK:
                    DisplayLabel.Text = "OK was pressed.";
                    break;

                case DialogResult.Cancel:
                    DisplayLabel.Text = "Cancel was pressed.";
                    break;

                case DialogResult.Abort:
                    DisplayLabel.Text = "Abort was pressed.";
                    break;

                case DialogResult.Retry:
                    DisplayLabel.Text = "Retry was pressed.";
                    break;

                case DialogResult.Ignore:
                    DisplayLabel.Text = "Ignore was pressed.";
                    break;

                case DialogResult.Yes:
                    DisplayLabel.Text = "Yes was pressed.";
                    break;

                case DialogResult.No:
                    DisplayLabel.Text = "No was pressed.";
                    break;
            }
        }
    }
        
 }

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


        private void buttonType_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == OKButton)
                buttonType = MessageBoxButtons.OK;
            else
                if (sender == OKCancelButton)
                    buttonType = MessageBoxButtons.OKCancel;
                else
                    if (sender == abortRetryIgnoreButton)
                        buttonType = MessageBoxButtons.AbortRetryIgnore;
                    else
                        if (sender == YesNoCancelButton)
                            buttonType = MessageBoxButtons.YesNoCancel;
                        else
                            if (sender == YesNoButton)
                                buttonType = MessageBoxButtons.YesNo;
                            else
                                if (sender == RetryCancelButton)
                                    buttonType = MessageBoxButtons.RetryCancel;
        }

        private void iconType_CheckedChanged(object sender, EventArgs e)
        {
            if (sender == AsteriskButton)
                iconType = MessageBoxIcon.Asterisk;
            else
                if (sender == ErrorButton)
                    iconType = MessageBoxIcon.Error;
                else
                    if (sender == ExclamationButton)
                        iconType = MessageBoxIcon.Exclamation;
                    else
                        if (sender == HandButton)
                            iconType = MessageBoxIcon.Hand;
                        else
                            if (sender == InformationButton)
                                iconType = MessageBoxIcon.Information;
                            else
                                if (sender == QuestionButton)
                                    iconType = MessageBoxIcon.Question;
                                else
                                    if (sender == StopButton)
                                        iconType = MessageBoxIcon.Stop;
                                    else
                                        if (sender == WarningButton)
                                            iconType = MessageBoxIcon.Warning;
        }
        

        private void DisplayButton_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Do you like this message box?", "Custom MessageBox", buttonType, iconType);
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

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
        
 }

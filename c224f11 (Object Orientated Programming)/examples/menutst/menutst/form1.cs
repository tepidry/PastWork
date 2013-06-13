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
        public Form1()
        {
            InitializeComponent();
        }

        private void ClearColor()
        {
            blackToolStripMenuItem.Checked = false;
            redToolStripMenuItem.Checked = false;
            blueToolStripMenuItem.Checked = false;
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("This is an example\nof using menus.", "About", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Are you sure you want to exit?", "Exit", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (result == DialogResult.Yes)
                Application.Exit();
        }

        private void blackToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearColor();
            displayLabel.ForeColor = Color.Black;
            blackToolStripMenuItem.Checked = true;
        }

        private void blueToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearColor();
            displayLabel.ForeColor = Color.Blue;
            blueToolStripMenuItem.Checked = true;
        }

        private void redToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearColor();
            displayLabel.ForeColor = Color.Red;
            blueToolStripMenuItem.Checked = true;
        }

        private void ClearFont()
        {
            TimesNewRomanToolStripMenuItem.Checked = false;
            CourierToolStripMenuItem.Checked = false;
            comicSansToolStripMenuItem.Checked = false;
        }

        private void TimesNewRomanToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFont();
            TimesNewRomanToolStripMenuItem.Checked = true;
            displayLabel.Font = new Font("Times New Roman", 12, displayLabel.Font.Style);
        }

        private void CourierToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFont();
            CourierToolStripMenuItem.Checked = true;
            displayLabel.Font = new Font("Courier", 14, displayLabel.Font.Style);
        }

        private void comicSansToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFont();
            comicSansToolStripMenuItem.Checked = true;
            displayLabel.Font = new Font("Comic Sans MS", 16, displayLabel.Font.Style);
        }

        private void boldToolStripMenuItem_Click(object sender, EventArgs e)
        {
            boldToolStripMenuItem.Checked = !boldToolStripMenuItem.Checked;
            displayLabel.Font = new Font(displayLabel.Font, displayLabel.Font.Style ^ FontStyle.Bold);
        }

        private void italicToolStripMenuItem_Click(object sender, EventArgs e)
        {
            italicToolStripMenuItem.Checked = !italicToolStripMenuItem.Checked;
            displayLabel.Font = new Font(displayLabel.Font, displayLabel.Font.Style ^ FontStyle.Italic);
        }

        private void CDriveLinkLabel_Click(object sender, EventArgs e)
        {
            CDriveLinkLabel.LinkVisited = true;
            System.Diagnostics.Process.Start(@"C:\");


        }

        private void WordLinkLabel_Click(object sender, EventArgs e)
        {
            WordLinkLabel.LinkVisited = true;
            System.Diagnostics.Process.Start("winword");
        }

        private void WebLinkLabel_Click(object sender, EventArgs e)
        {
            WebLinkLabel.LinkVisited = true;
            System.Diagnostics.Process.Start("http://www.cs.gonzaga.edu/depalma");
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            CDriveLinkLabel.LinkVisited = false;
            WordLinkLabel.LinkVisited = false;
            WebLinkLabel.LinkVisited = false;
        }

    }
}

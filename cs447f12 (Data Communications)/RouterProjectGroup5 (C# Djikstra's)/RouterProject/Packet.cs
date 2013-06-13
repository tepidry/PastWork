using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.VisualBasic.PowerPacks;

namespace RouterProject
{
    class Packet
    {
        private RectangleShape packet;
        private Router curr_loc;
        private Router r_source;
        private Router r_dest;

        public Packet()
        {
            packet = new RectangleShape();
            packet.Width = 20;
            packet.Height = 20;
            packet.FillColor = System.Drawing.Color.Red;
            packet.FillStyle = FillStyle.Cross;
            packet.BringToFront();

            //curr_loc = source;
            //r_source = source;
            //r_dest = dest;
        }
    }
}

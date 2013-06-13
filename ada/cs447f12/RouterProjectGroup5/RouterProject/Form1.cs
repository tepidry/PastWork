using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.VisualBasic.PowerPacks;
using System.Drawing.Drawing2D;


namespace RouterProject
{
    public partial class Form1 : Form
    {
        public int top = 0;
        public int left = 0;
        public static Graphics g;
        public Dictionary<int, char> numToChar = new Dictionary<int, char>(){{0,'a'}, {1,'b'}, {2,'c'},{3,'d'}, {4,'e'}, {5,'f'}, {6,'g'},{7,'h'},{8,'i'},{9,'j'}, {10,'k'}};
        public List<int> locations_top = new List<int>();
        public List<int> locations_left = new List<int>();
        private int selected_dest;
        private int selected_src;
        public Dictionary<string, char> arrayDic = new Dictionary<string, char>();
        public List<string> edgeList = new List<string>();
        public List<char> edge_Path_List = new List<char>();
        Network AwesomeNetwork = new Network();

        public Form1()
        {
            InitializeComponent();
            
            Object[] Nodes = { "Node A", "Node B", "Node C", "Node D", "Node E", "Node F", "Node G", "Node H", "Node I", "Node J", "Node K"};
            checkedListBox1.Items.AddRange(Nodes);
            dest_drop.Items.AddRange(Nodes);
            src_drop.Items.AddRange(Nodes);
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
                checkedListBox1.SetItemChecked(i, true);
            GeneralClear();
            populateLocationsLeft();
            populateLocationsTop();
            AwesomeNetwork.Create_Network();
            populateEdgeList();
        }

        private void GeneralClear()
        {
            richTextBox1.Text = "N/A";
            dest_drop.SelectedIndex = 0;
            src_drop.SelectedIndex = 0;
            path_text.Text = "N/A";
            display_path.Text = "N/A";
            selected_dest = -1;
            selected_src = -1;
        }

        public int getTop(int index)
        {
            return locations_top[index];
        }

        public int getLeft(int index)
        {
            return locations_left[index];
        }

        //at the end I put to refactor list will this get called?
        //I added so each router will be enabled or disabled upon click.
        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            checkedListBox1.CheckOnClick = true;
            int checked_Item = checkedListBox1.SelectedIndex;
            if (checkedListBox1.GetItemCheckState(checked_Item) == 0)
            {
                if (checked_Item == 0)
                {
                    ovalShapeA.FillStyle = FillStyle.Solid;
                    ovalShapeA.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[0].Disable();
                    
                }
                if (checked_Item == 1)
                {
                    ovalShapeB.FillStyle = FillStyle.Solid;
                    ovalShapeB.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[1].Disable();
                }
                if (checked_Item == 2)
                {
                    ovalShapeC.FillStyle = FillStyle.Solid;
                    ovalShapeC.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[2].Disable();
                }
                if (checked_Item == 3)
                {
                    ovalShapeD.FillStyle = FillStyle.Solid;
                    ovalShapeD.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[3].Disable();
                }
                if (checked_Item == 4)
                {
                    ovalShapeE.FillStyle = FillStyle.Solid;
                    ovalShapeE.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[4].Disable();
                }
                if (checked_Item == 5)
                {
                    ovalShapeF.FillStyle = FillStyle.Solid;
                    ovalShapeF.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[5].Disable();
                }
                if (checked_Item == 6)
                {
                    ovalShapeG.FillStyle = FillStyle.Solid;
                    ovalShapeG.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[6].Disable();
                }
                if (checked_Item == 7)
                {
                    ovalShapeH.FillStyle = FillStyle.Solid;
                    ovalShapeH.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[7].Disable();
                }
                if (checked_Item == 8)
                {
                    ovalShapeI.FillStyle = FillStyle.Solid;
                    ovalShapeI.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[8].Disable();
                }
                if (checked_Item == 9)
                {
                    ovalShapeJ.FillStyle = FillStyle.Solid;
                    ovalShapeJ.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[9].Disable();
                }
                if (checked_Item == 10)
                {
                    ovalShapeK.FillStyle = FillStyle.Solid;
                    ovalShapeK.FillColor = Color.Black;
                    AwesomeNetwork.network_routers[10].Disable();
                }
                
            }
            else 
            {
                if (checked_Item == 0)
                {
                    ovalShapeA.FillStyle = FillStyle.Transparent;   
                    AwesomeNetwork.network_routers[0].Enable();
                }
                else if (checked_Item == 1)
                {
                    ovalShapeB.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[1].Enable();
                }
                if (checked_Item == 2)
                {
                    ovalShapeC.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[2].Enable();
                }
                if (checked_Item == 3)
                {
                    ovalShapeD.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[3].Enable();
                }
                if (checked_Item == 4)
                {
                    ovalShapeE.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[4].Enable();
                }
                if (checked_Item == 5)
                {
                    ovalShapeF.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[5].Enable();
                }
                if (checked_Item == 6)
                {
                    ovalShapeG.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[6].Enable();
                }
                if (checked_Item == 7)
                {
                    ovalShapeH.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[7].Enable();
                }
                if (checked_Item == 8)
                {
                    ovalShapeI.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[8].Enable();
                }
                if (checked_Item == 9)
                {
                    ovalShapeJ.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[9].Enable();
                }
                if (checked_Item == 10)
                {
                    ovalShapeK.FillStyle = FillStyle.Transparent;
                    AwesomeNetwork.network_routers[10].Enable();
                }
                
            }
            AwesomeNetwork.Update_Tables();
        }
        
        //Need to have packet handle here.
        private void Set_src_Click(object sender, EventArgs e)
        {
            clearBorders();
            clearPacket();
            selected_src = src_drop.SelectedIndex;
            checkSrcRouterIsActive();
            
            if (selected_src >= 0)
            {
                clearPacket();
                selectSourcePacketToDraw();
                makePacket();
            }
        }

        private void checkSrcRouterIsActive()
        {
            if (!AwesomeNetwork.network_routers[selected_src].Is_Active)
            {
                MessageBox.Show("That Router is Down!");
                GeneralClear();
            }
        }

        private void checkDestRouterIsActive()
        {
            if (!AwesomeNetwork.network_routers[selected_dest].Is_Active)
            {
                MessageBox.Show("That Router is Down!");
                GeneralClear();
            }
        }

        //Need to show path and pack at destination
        private void set_Dst_Click(object sender, EventArgs e)
        {
            clearBorders();
            selected_dest = dest_drop.SelectedIndex;
            checkDestRouterIsActive();
        }

        private string displayForwardingTable()
        {
            return AwesomeNetwork.network_routers[selected_src].Show_Forwarding_Table();
        }

        private void send_Packet_Click(object sender, EventArgs e)
        {

            //Packet packet = new Packet(
            
            if (selected_dest >= 0 && selected_src >= 0)
            {
                richTextBox1.Text = displayForwardingTable();
                highlight_Path(numToChar[selected_src], numToChar[selected_dest]);
                DisplayPathValue();
                if (edge_Path_List[0] == 'z')
                {
                    displayRouterDown();
                    return;
                }
                else
                {
                    displayRouterPath();
                }
                clearPacket();
                selectDestinationPackToDraw();
                makePacket();
            }
            errorSelectDestination();
            errorSelectSource();
            selected_src = selected_dest;
            src_drop.SelectedIndex = dest_drop.SelectedIndex;
            selected_dest = -1;
            dest_drop.SelectedIndex = -1;
            
        }

        private void DisplayPathValue()
        {
            int temp = 0;
            temp = AwesomeNetwork.hopsToFrom(numToChar[selected_src], numToChar[selected_dest]);
            if (temp == 1000)
                path_text.Text = "infinity";
            else
                path_text.Text = temp.ToString();
        }

        public void errorSelectDestination()
        {
            if (selected_dest < 0)
            {
                MessageBox.Show("Please set a destination router!");
            }
        }

        public void errorSelectSource()
        {
            if (selected_src < 0)
            {
                MessageBox.Show("Please set a source router!");
            }
        }
        
        public void selectSourcePacketToDraw()
        {
            if (selected_src == 0)
            {
                top = ovalShapeA.Top;
                left = ovalShapeA.Left;
            }
            if (selected_src == 1)
            {
                top = ovalShapeB.Top;
                left = ovalShapeB.Left;
            }
            if (selected_src == 2)
            {
                top = ovalShapeC.Top;
                left = ovalShapeC.Left;
            }
            if (selected_src == 3)
            {
                top = ovalShapeD.Top;
                left = ovalShapeD.Left;
            }
            if (selected_src == 4)
            {
                top = ovalShapeE.Top;
                left = ovalShapeE.Left;
            }
            if (selected_src == 5)
            {
                top = ovalShapeF.Top;
                left = ovalShapeF.Left;
            }
            if (selected_src == 6)
            {
                top = ovalShapeG.Top;
                left = ovalShapeG.Left;
            }
            if (selected_src == 7)
            {
                top = ovalShapeH.Top;
                left = ovalShapeH.Left;
            }
            if (selected_src == 8)
            {
                top = ovalShapeI.Top;
                left = ovalShapeI.Left;
            }
            if (selected_src == 9)
            {
                top = ovalShapeJ.Top;
                left = ovalShapeJ.Left;
            }
            if (selected_src == 10)
            {
                top = ovalShapeK.Top;
                left = ovalShapeK.Left;
            }
        }

        public void selectDestinationPackToDraw()
        {
            if (selected_dest == 0)
            {
                top = ovalShapeA.Top;
                left = ovalShapeA.Left;
            }
            if (selected_dest == 1)
            {
                top = ovalShapeB.Top;
                left = ovalShapeB.Left;
            }
            if (selected_dest == 2)
            {
                top = ovalShapeC.Top;
                left = ovalShapeC.Left;
            }
            if (selected_dest == 3)
            {
                top = ovalShapeD.Top;
                left = ovalShapeD.Left;
            }
            if (selected_dest == 4)
            {
                top = ovalShapeE.Top;
                left = ovalShapeE.Left;
            }
            if (selected_dest == 5)
            {
                top = ovalShapeF.Top;
                left = ovalShapeF.Left;
            }
            if (selected_dest == 6)
            {
                top = ovalShapeG.Top;
                left = ovalShapeG.Left;
            }
            if (selected_dest == 7)
            {
                top = ovalShapeH.Top;
                left = ovalShapeH.Left;
            }
            if (selected_dest == 8)
            {
                top = ovalShapeI.Top;
                left = ovalShapeI.Left;
            }
            if (selected_dest == 9)
            {
                top = ovalShapeJ.Top;
                left = ovalShapeJ.Left;
            }
            if (selected_dest == 10)
            {
                top = ovalShapeK.Top;
                left = ovalShapeK.Left;
            }
        }

        private void displayRouterPath()
        {
            String uppercaseRouterString = "";
            for (int i = 0; i < edge_Path_List.Count; i++)
            {
                uppercaseRouterString = uppercaseRouterString + char.ToUpper(edge_Path_List[i]);
                if (i != edge_Path_List.Count - 1)
                {
                    uppercaseRouterString = uppercaseRouterString + " -> ";
                }
            }
            display_path.Text = uppercaseRouterString;
        }

        private void displayRouterDown()
        {
            List<char> downRouters = new List<char>(AwesomeNetwork.returnIDofDownRouter());
            String upperDownRouters = null;
            for(int i = 0; i < downRouters.Count; i++)
            {
                upperDownRouters = upperDownRouters + char.ToUpper(downRouters[i]);
                if (i != downRouters.Count - 1)
                {
                    upperDownRouters = upperDownRouters + ", ";
                }
            }
            MessageBox.Show("Router " + upperDownRouters + " is down");
            display_path.Text = "Router " + upperDownRouters + " is Down";
        }

        private void path_text_TextChanged(object sender, EventArgs e)
        {
            //DISPLAY SHORTEST PATH COST
        }

        private void display_path_TextChanged(object sender, EventArgs e)
        {
             

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
          
        }

        private void src_drop_SelectedIndexChanged(object sender, EventArgs e)
        {
            //DROP DOWN FOR SOURCE
        }

        private void dest_drop_SelectedIndexChanged(object sender, EventArgs e)
        {
            //DROP DOWN FOR DEST
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeH_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeA_Click(object sender, EventArgs e)
        {

        }

        private void populateLocationsTop()
        {
            locations_top.Add(ovalShapeA.Top);
            locations_top.Add(ovalShapeB.Top);
            locations_top.Add(ovalShapeC.Top);
            locations_top.Add(ovalShapeD.Top);
            locations_top.Add(ovalShapeE.Top);
            locations_top.Add(ovalShapeF.Top);
            locations_top.Add(ovalShapeG.Top);
            locations_top.Add(ovalShapeH.Top);
            locations_top.Add(ovalShapeI.Top);
            locations_top.Add(ovalShapeJ.Top);
            locations_top.Add(ovalShapeK.Top);
        }

        private void populateLocationsLeft()
        {
            locations_top.Add(ovalShapeA.Left);
            locations_top.Add(ovalShapeB.Left);
            locations_top.Add(ovalShapeC.Left);
            locations_top.Add(ovalShapeD.Left);
            locations_top.Add(ovalShapeE.Left);
            locations_top.Add(ovalShapeF.Left);
            locations_top.Add(ovalShapeG.Left);
            locations_top.Add(ovalShapeH.Left);
            locations_top.Add(ovalShapeI.Left);
            locations_top.Add(ovalShapeJ.Left);
            locations_top.Add(ovalShapeK.Left);
        }

        private void ovalShapeB_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeC_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeD_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeE_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeG_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeF_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeI_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeJ_Click(object sender, EventArgs e)
        {

        }

        private void ovalShapeK_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Set_src.Enabled = true;
            set_Dst.Enabled = true;
            checkedListBox1.Enabled = true;
            path_text.Enabled = true;
            send_Packet.Enabled = true;
            src_drop.Enabled = true;
            dest_drop.Enabled = true;
            clearRouters();
            clearPacket();
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SelectedIndex.Equals(true);
                checkedListBox1.SetItemCheckState(i, CheckState.Checked);
            }
            clearBorders();
           
            for (int i = 0; i < AwesomeNetwork.network_routers.Count; i++)
            {
                AwesomeNetwork.network_routers[i].Enable();
            }
            GeneralClear();
            AwesomeNetwork.Update_Tables();
        }

        //This is two function one that will fill public list edge_Path_List
        //the other will highlight that path according to that list.
        private void highlight_Path(char src, char dest)
        {
            Router correctRouter = new Router(AwesomeNetwork.returnRouterFrom(src));
            edge_Path_List = correctRouter.ReturnTravelList(dest);
            for (int i = 0; i < edge_Path_List.Count -1 ; i++)
            {
                highlightEdge(edge_Path_List[i], edge_Path_List[(i + 1)]);
            }
            
        }

        public void clearPacket()
        {
            //g = null;
            g = panel2.CreateGraphics();
            g.FillRectangle(new SolidBrush(Color.Gray), left - 25, top + 10, 20, 30);
            g.Dispose();


        }

        public void makePacket()
        {
            //g = null;
            g = panel2.CreateGraphics();
            g.FillRectangle(new SolidBrush(Color.Green),left - 25 , top + 10, 20, 30);
            g.Dispose();

            
        }

        public void clearRouters()
        {
            ovalShapeA.FillStyle = FillStyle.Transparent;
            ovalShapeB.FillStyle = FillStyle.Transparent;
            ovalShapeC.FillStyle = FillStyle.Transparent;
            ovalShapeD.FillStyle = FillStyle.Transparent;
            ovalShapeE.FillStyle = FillStyle.Transparent;
            ovalShapeF.FillStyle = FillStyle.Transparent;
            ovalShapeH.FillStyle = FillStyle.Transparent;
            ovalShapeI.FillStyle = FillStyle.Transparent;
            ovalShapeJ.FillStyle = FillStyle.Transparent;
            ovalShapeK.FillStyle = FillStyle.Transparent;
            ovalShapeG.FillStyle = FillStyle.Transparent;
        }

        public void clearBorders()
        {
            LineAB.BorderWidth = 1;
            LineAB.BorderColor = Color.Black;
            LineBC.BorderWidth = 1;
            LineBC.BorderColor = Color.Black;
            LineCD.BorderWidth = 1;
            LineCD.BorderColor = Color.Black;
            LineDE.BorderWidth = 1;
            LineDE.BorderColor = Color.Black;
            LineAH.BorderWidth = 1;
            LineAH.BorderColor = Color.Black;
            LineGI.BorderWidth = 1;
            LineGI.BorderColor = Color.Black;
            LineAG.BorderWidth = 1;
            LineAG.BorderColor = Color.Black;
            LineIJ.BorderWidth = 1;
            LineIJ.BorderColor = Color.Black;
            LineJK.BorderWidth = 1;
            LineJK.BorderColor = Color.Black;
            LineAF.BorderWidth = 1;
            LineAF.BorderColor = Color.Black;
            LineFJ.BorderWidth = 1;
            LineFJ.BorderColor = Color.Black;
        }

        public void populateEdgeList()
        {
            edgeList.Add("LineAB");
            edgeList.Add("LineBC");
            edgeList.Add("LineCD");
            edgeList.Add("LineDE");
            edgeList.Add("LineAH");
            edgeList.Add("LineAG");
            edgeList.Add("LineGI");
            edgeList.Add("LineIJ");
            edgeList.Add("LineJK");
            edgeList.Add("LineAF");
            edgeList.Add("LineFJ");
            edgeList.Add("Not In");
        }

        public void highlightEdge(char src, char dest)
        {
            int edgeindex = AwesomeNetwork.get_Neighbor(src, dest);
            getEdgeName(edgeindex);
            string edge = getEdgeName(edgeindex);
            if (edge == "LineAB")
            {
                LineAB.BorderWidth = 10;
                LineAB.BorderColor = Color.Red;
            }
            if (edge == "LineBC")
            {
                LineBC.BorderWidth = 10;
                LineBC.BorderColor = Color.Red;
            }
            if (edge == "LineCD")
            {
                LineCD.BorderWidth = 10;
                LineCD.BorderColor = Color.Red;
            }
            if (edge == "LineDE")
            {
                LineDE.BorderWidth = 10;
                LineDE.BorderColor = Color.Red;
            }
            if (edge == "LineAH")
            {
                LineAH.BorderWidth = 10;
                LineAH.BorderColor = Color.Red;
            }
            if (edge == "LineGI")
            {
                LineGI.BorderWidth = 10;
                LineGI.BorderColor = Color.Red;
                
            }
            if (edge == "LineAG")
            {
                LineAG.BorderWidth = 10;
                LineAG.BorderColor = Color.Red;
            }
            if (edge == "LineIJ")
            {
                LineIJ.BorderWidth = 10;
                LineIJ.BorderColor = Color.Red;
            }
            if (edge == "LineJK")
            {
                LineJK.BorderWidth = 10;
                LineJK.BorderColor = Color.Red;
            }
            if (edge == "LineAF")
            {
                LineAF.BorderWidth = 10;
                LineAF.BorderColor = Color.Red;
            }
            if (edge == "LineFJ")
            {
                LineFJ.BorderWidth = 10;
                LineFJ.BorderColor = Color.Red;
            }
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        public string getEdgeName(int edgeindex)
        {
            return edgeList[edgeindex];
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
        
    }
}

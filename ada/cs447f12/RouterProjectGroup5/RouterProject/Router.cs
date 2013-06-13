using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.VisualBasic.PowerPacks;

namespace RouterProject
{
    public class Router
    {
        public OvalShape _router;
        public char r_id;
        public string r_addr;
        public bool is_active;

        public Dictionary<Router, Router> forward_table = new Dictionary<Router,Router>();
        public Dictionary<Router, int> dest_distance = new Dictionary<Router,int>();

        public Router(char id, string addr, bool active)
        {
            _router = new OvalShape();
            r_id = id;
            r_addr = addr;
            is_active = active;

            _router.Width = 64;
            _router.Height = 64;
        }

        public Router(Router copyThis)
        {
            r_id = copyThis.r_id;
            r_addr = copyThis.r_addr;
            is_active = copyThis.is_active;

            forward_table = copyThis.forward_table;
            dest_distance = copyThis.dest_distance;
        }

        

        public bool Is_Active
        {
            get
            {
                return is_active;
            }
        }

        public int Left
        {
            get
            {
                return _router.Left;
            }
        }

        public int Top
        {
            get
            {
                return _router.Top;
            }
        }

        public List<char> ReturnTravelList(char dest_id)
        {
            bool lastItemBeforeSource = true;
            char newDest = dest_id;
            List<char> tempPath = new List<char>();
            List<char> edge_Path_List = new List<char>();
            if (r_id == dest_id)
            {
                edge_Path_List.Add(r_id);
                return edge_Path_List;
            }
            else if (is_active == false)
            {
                edge_Path_List.Add('z');
                return edge_Path_List;
            }
            else if (is_active == true)
            {
                while(lastItemBeforeSource)
                {
                    foreach (KeyValuePair<Router, Router> pair in forward_table)
                    {
                        if (pair.Key.id == newDest && pair.Key != pair.Value)
                        {
                            if (pair.Value == null)
                            {
                                edge_Path_List.Add('z');
                                return edge_Path_List;
                            }
                            tempPath.Add(newDest);
                            newDest = pair.Value.id;
                        }
                        else if (pair.Key.id == newDest && pair.Key == pair.Value)
                        {
                            tempPath.Add(newDest);
                            lastItemBeforeSource = false;
                        }
                    }
                }
            }

            tempPath.Add(r_id);
            tempPath.Reverse();
            edge_Path_List = tempPath;
            return edge_Path_List;
        }

        /// <summary>
        /// return router identifier
        /// </summary>
        public char id
        {
            get
            {
                return r_id;
            }
        }
        /// <summary>
        /// returns the ip address of the router
        /// </summary>
        public string IP_Address
        {
            get
            {
                return r_addr;
            }
        }

        /// <summary>
        /// returns the node id
        /// </summary>
        public char Node
        {
            get
            {
                return r_id;
            }
        }

        public void SetHeight(int height)
        {
            _router.Height = height;
        }

        public void SetWidth(int width)
        {
            _router.Width = width;
        }

        public void Disable()
        {
            is_active = false;
        }

        public void Enable()
        {
            is_active = true;
        }

        public int NumHops(char dest)
        {
            int temp = 0;
            foreach (KeyValuePair<Router, int> pair in dest_distance)
            {
                if (pair.Key.id == dest)
                {
                    temp = pair.Value;
                }
            }
            return temp;
        }

        /// <summary>
        /// Updates the forwarding and distance tables of the router
        /// </summary>
        /// <param name="network_map"></param>
        public void Update_Tables(Dictionary<Router, List<Edge>> network_map)
        {
            dest_distance.Clear();
            forward_table.Clear();

            ///The routers that have been iterated through
            List<Router> touched_routers = new List<Router>();
            touched_routers.Add(this);
            ///Initialize the dest_distance table and forward table
            foreach (Router rout in network_map.Keys)
            {
                if (rout.r_id != this.r_id)
                {
                    dest_distance.Add(rout, 1000);
                    forward_table.Add(rout, null);
                }
            }
            ///Find the immediate neighbors, update forward table and dest_dist
            List<Edge> temp_edges = network_map[this];
            foreach (Edge ed in temp_edges)
            {
///Console.WriteLine(ed.Involved_Routers.ToString());
                Router temp_r = ed.Connected_To(this);
                dest_distance[temp_r] = ed.EdgeCost;
                forward_table[temp_r] = temp_r;
            }

            ///Next is the router minimum D(w) of w not in N'
            Router next = _Djikstra_Next(touched_routers);
            while (next != null)
            {
                List<Edge> eList = network_map[next];
                foreach (Edge ed in eList)
                {
                    Router temp_r = ed.Connected_To(next);
                    if (temp_r != this)
                    {
                        if (dest_distance[temp_r] > (dest_distance[next] + ed.EdgeCost))
                        {
                            dest_distance[temp_r] = ed.EdgeCost + dest_distance[next];
                            forward_table[temp_r] = next;
                        }
                    }
                }
                touched_routers.Add(next);
                next = _Djikstra_Next(touched_routers);
            }
        }

        public string Show_Forwarding_Table()
        {
            string forwardList = "";
            Console.WriteLine("-------------------NODE '" + this.r_id + "'---------------------");
            Console.WriteLine(" Dest || Next");
            foreach (KeyValuePair<Router,Router> pair in forward_table)
            {
                if (pair.Value == null)
                {
                    forwardList += "     " + pair.Key.r_id + "  |  " + "NULL  \n ";
                    //Console.WriteLine(pair.Key.r_id + " | " + "null");
                }
                else
                {
                    forwardList += "     " + char.ToUpper(pair.Key.r_id) + "  |  " + char.ToUpper(pair.Value.r_id) + "       \n";
                    //Console.WriteLine(pair.Key.r_id + " | " + pair.Value.r_id);
                }
            }
            return forwardList;
        }

        public void Show_Distance_Table()
        {
            string destList = "";
            Console.WriteLine("-------------------NODE '" + this.r_id + "'---------------------");
            Console.WriteLine("Dest | Dist");
            foreach (KeyValuePair<Router, int> pair in dest_distance)
            {
                destList += "{" + pair.Key.r_id + " | " + pair.Value.ToString() + "}  ";
            }
            Console.WriteLine(destList);
        }

        /// <summary>
        /// Finds the minimum distance in the dest_distance dictionary.
        /// </summary>
        /// <param name="touched">N' of the nodes already mapped.</param>
        /// <returns>The minimum distanced node from this router</returns>
        private Router _Djikstra_Next(List<Router> touched)
        {
            var items = from pair in dest_distance
                  orderby pair.Value ascending
                  select pair;
            foreach (KeyValuePair<Router, int> wanted in items)
            {
                if (!touched.Contains(wanted.Key))
                {
                    return wanted.Key;
                }
            }
            return null;
        }
    }

}

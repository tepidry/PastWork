using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.VisualBasic.PowerPacks;

namespace RouterProject
{
    public class Edge
    {
        private LineShape channel;
        private int edge_cost;
        private List<Router> connected = new List<Router>();

        public Edge(Router one, Router two, int cost)
        {
            LineShape channel = new LineShape(one.Left, one.Top, two.Left, two.Top);
            channel.BorderWidth = 3;
            edge_cost = cost;
            connected.Add(one);
            connected.Add(two);
        }

        /// <summary>
        /// Returns a list of the connected routers
        /// </summary>
        public List<Router> Involved_Routers
        {
            get
            {
                return connected;
            }
        }

        /// <summary>
        /// Used to determine the router that is at the other end of the edge
        /// </summary>
        /// <param name="src_router"></param>
        /// <returns></returns>
        public Router Connected_To(Router src_router)
        {
            foreach (Router r in connected)
            {
                if (r.id != src_router.id && r.is_active)
                {
                    return r;
                }
            }
            return null;
        }

        public char ConnectedTo(char src_router)
        {
            foreach (Router r in connected)
            {
                if (r.id == src_router && r.is_active)
                {
                    return r.id;
                }
            }
            return 'z';
        }

        /// <summary>
        /// a property is accessed by
        /// router_a.Cost;
        /// </summary>
        public int EdgeCost
        {
            get
            {
                return edge_cost;
            }
        }


        /// <summary>
        /// Returns true if the connection is live (both nodes are active)
        /// returns false if one or more of the nodes on the connection are disabled
        /// </summary>
        public bool Is_Active
        {
            get
            {
                foreach (Router node in connected)
                {
                    if (!node.Is_Active)
                    {
                        return false;
                    }
                }
                return true;
            }
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RouterProject
{
    class Network
    {
        public List<Router> network_routers = new List<Router>();
        public List<Edge> network_edges = new List<Edge>();
        /// <summary>
        /// A dictionary in which the key is the router and the value is the list of edges it is involved with.
        /// </summary>
        public Dictionary<Router, List<Edge>> router_connections = new Dictionary<Router, List<Edge>>();

        public Network()
        { }

        public void Create_Network()
        {
            Router router_a = new Router('a', "1.1.1.0", true);
            Router router_b = new Router('b', "1.1.1.1", true);
            Router router_c = new Router('c', "1.1.1.2", true);
            Router router_d = new Router('d', "1.1.1.3", true);
            Router router_e = new Router('e', "1.1.1.4", true);
            Router router_f = new Router('f', "1.1.1.5", true);
            Router router_g = new Router('g', "1.1.1.6", true);
            Router router_h = new Router('h', "1.1.1.7", true);
            Router router_i = new Router('i', "1.1.1.8", true);
            Router router_j = new Router('j', "1.1.1.9", true);
            Router router_k = new Router('k', "1.1.1.10", true);

            network_routers.Add(router_a);
            network_routers.Add(router_b);
            network_routers.Add(router_c);
            network_routers.Add(router_d);
            network_routers.Add(router_e);
            network_routers.Add(router_f);
            network_routers.Add(router_g);
            network_routers.Add(router_h);
            network_routers.Add(router_i);
            network_routers.Add(router_j);
            network_routers.Add(router_k);

            Edge edge_a_b = new Edge(router_a, router_b, 5);
            Edge edge_b_c = new Edge(router_b, router_c, 2);
            Edge edge_c_d = new Edge(router_c, router_d, 1);
            Edge edge_d_e = new Edge(router_d, router_e, 2);
            Edge edge_a_h = new Edge(router_a, router_h, 3);
            Edge edge_a_g = new Edge(router_a, router_g, 1);
            Edge edge_g_i = new Edge(router_g, router_i, 2);
            Edge edge_i_j = new Edge(router_i, router_j, 2);
            Edge edge_j_k = new Edge(router_j, router_k, 3);
            Edge edge_a_f = new Edge(router_a, router_f, 3);
            Edge edge_f_j = new Edge(router_f, router_j, 1);

            network_edges.Add(edge_a_b);
            network_edges.Add(edge_b_c);
            network_edges.Add(edge_c_d);
            network_edges.Add(edge_d_e);
            network_edges.Add(edge_a_h);
            network_edges.Add(edge_a_g);
            network_edges.Add(edge_g_i);
            network_edges.Add(edge_i_j);
            network_edges.Add(edge_j_k);
            network_edges.Add(edge_a_f);
            network_edges.Add(edge_f_j);

            Update_Tables();
        }

        /// <summary>
        /// Should be called each time a router leaves/enters a network
        /// </summary>
        public void Update_Tables()
        {
            Store_Router_Connections();
            foreach (Router r in router_connections.Keys)
            {
                r.Update_Tables(router_connections);
                //r.Show_Distance_Table();
                //r.Show_Forwarding_Table();
            }
        }

        public List<char> returnIDofDownRouter()
        {
            List<char> downRouters = new List<char>();
            foreach (Router j in network_routers)
            {
                if (!j.Is_Active)
                {
                    downRouters.Add(j.r_id);
                }
            }
            return downRouters;
        }

        public Router returnRouterFrom(char src)
        {
            Router correctRouter = new Router('z', "0.0.0", false);
            foreach (Router a in network_routers)
            {
                if (src == a.id)
                {
                    correctRouter = a;
                }
            }
            return correctRouter;
        }

        public List<Edge> getEdges()
        {
            return network_edges;
        }

        public int hopsToFrom(char src, char dest)
        {
            int temp = 0;
            foreach (Router a in network_routers)
            {
                if (src == a.id)
                {
                    return a.NumHops(dest);
                }
            }
            return temp;
        }

        /// <summary>
        /// returns what number they are in network index the connecting edge is else network_edges.count + 1;
        /// </summary>
        /// <param name="src"></param>
        /// <param name="dest"></param>
        /// <returns></returns>
        public int get_Neighbor(char src, char dest)
        {
            int i = 0; 
            List<Router> both = new List<Router>();
            foreach(Edge a in network_edges)
            {
                both = a.Involved_Routers;
                if(src == both[0].id && dest == both[1].id)
                {
                    return i;
                }
                else if (src == both[1].id && dest == both[0].id)
                {
                    return i;
                }
                i++;
            }
            return i;
        }
        
        public int getNumRouters()
        {
            return network_routers.Count;
        }

        public int getEdgeCount()
        {
            return network_edges.Count;
        }

        /// <summary>
        /// Updates the private variable router connections
        /// </summary>
        private void Store_Router_Connections()
        {
            router_connections.Clear();
            foreach (Router r in network_routers)
            {
                if (r.Is_Active)
                {
                    List<Edge> temp_edges = new List<Edge>();
                    foreach (Edge e in network_edges)
                    {
                        if (e.Involved_Routers.Contains(r))
                        {
                            if (e.Is_Active)
                            {
                                temp_edges.Add(e);
                            }
                        }
                    }
                    router_connections.Add(r, temp_edges);
                }
            }
        }
    }
}
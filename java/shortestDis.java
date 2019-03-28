import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class shortestDis{
    static int[][][] d=new int[5][5][5];
    public static void main(String[] args) {
        Point s=new Point("s");
        Point t=new Point("t");
        Point y=new Point("y");
        Point x=new Point("x");
        Point z=new Point("z");
        s.addEdge(t, 6);
        s.addEdge(y, 7);
        t.addEdge(x, 5);
        t.addEdge(y, 8);
        t.addEdge(z, -4);
        x.addEdge(t, -2);
        y.addEdge(x, -3);
        y.addEdge(z, 9);
        z.addEdge(s,2);
        z.addEdge(x,7); 
        Edge e1=new Edge(s,t,6);
        Edge e2=new Edge(s,y,7);
        Edge e3=new Edge(t,x,5);
        Edge e4=new Edge(t,y,8);
        Edge e5=new Edge(t,z,-4);
        Edge e6=new Edge(x,t,-2);
        Edge e7=new Edge(y,x,-3);
        Edge e8=new Edge(y,z,9);
        Edge e9=new Edge(z,s,2);
        Edge e10=new Edge(z,x,7);
        Edge[] es={e1,e2,e3,e4,e5,e6,e7,e8,e9,e10};
        Point[] p={s,t,y,x,z};
        Graph gr=new Graph(p,es);
        bellman_ford(gr,s);
        print_path(gr, s, y);
        System.out.println();
        print_path(gr, s, t);
        System.out.println();
        print_path(gr, s, x);
        System.out.println();
        print_path(gr, s, z);
        System.out.println();
         int[][] g= { {  0,  3,  8,100, -4},
                      {100,  0,100,  1,  7},
                      {100,  4,  0,100,100},
                      {  2,100, -5,  0,100},
                      {100,100,100,  6,  0}
                    };//多源问题矩阵
        int[][] r=slow_all_pairs_shortest_paths(g);
         for(int i=0;i<r.length;i++){
            for(int j=0;j<r.length;j++){
                if(i!=j){
                    System.out.println("从"+i+"到"+j+"的距离为"+r[i][j]+",");
                }
                
            }
            System.out.println();
        } 
    }
    public static class Graph{
        int[][] matrix;//图的邻接矩阵表示
        Point[] points;//图所包含的点
        Edge[] edges;//图所包含的边
        Graph(Point[] p){
            this.points=p;
            /* for(int i=0;i<p.length;i++){
                for(int j=0;j<p.length;j++){
                    if(p[i].edges.get()){
                        matrix[i][j]=p
                    }
                }
            } */
        }
        Graph(int[][] matrix){  
        }
        Graph(Point[] p,Edge[] e){
            this.edges=e;
            this.points=p;
        }
    }
    public static class Point{
        double dis;//所维持的最短路径估计
        Point forward;//前驱结点
        ArrayList<Edge> edges=new ArrayList<Edge>();//邻接边
        String name;
        public Point(String name){
            this.name=name;
        }
        public void addEdge(Point p,double dis){
            Edge e=new Edge(this,p,dis);
            edges.add(e);
        }
    }
    public static class Edge {
        Point start;//起始点
        Point end;//终点
        double dis;//两点间距
        Edge(Point s,Point e,double dis){
            this.start=s;
            this.end=e;
            this.dis=dis;
        }
    }
    public static void initialize(Graph g,Point s){
        for(int i=0;i<g.points.length;i++){
            g.points[i].dis=100;//不可超越的数
            g.points[i].forward=null;
        }
        s.dis=0;
    }
    public static void relax(Edge e){
        if(e.end.dis>e.start.dis+e.dis){
            e.end.dis=e.start.dis+e.dis;
            e.end.forward=e.start;
        }
    }
    public static void dijkstra(Graph g,Point s){
        initialize(g, s);
        Queue<Point> result=new LinkedList<Point>();
        Queue<Point> queue=new LinkedList<Point>();
        for(int i=0;i<g.points.length;i++){
            queue.add(g.points[i]);
        }
        //result.add(s);
        while(queue!=null){
            Point u=queue.poll();
            result.add(u);
            if(u!=null){
            for(int i=0;i<u.edges.size();i++){
                   relax(u.edges.get(i));
            }
        }
        }

    }
   /*  Func_Bellman-Ford(G,w,s){
        Func_Initialize-single-source(G,s);//初始化每个顶点的d和π值
        //开始进行松弛操作
        for i=1 to |V(G)|-1
            do for each edge (u,v)∈E(G)
               do Func_Relax(u,v,w)
         for each edge(u,v) ∈E(G)
            do if d[v]>d[u]+w(u,v)  //已经松弛操作了，如果还存在子顶点大于负顶点权值的情况，则存在负权回路
               then return false  //存在负权回路，返回false
         return true
    }
     */
    public static boolean bellman_ford(Graph g,Point s){
        initialize(g, s);
        for(int i=0;i<g.points.length;i++){
            for(int j=0;j<g.points[i].edges.size();j++){
                relax(g.points[i].edges.get(j));
            }
        }
        for(int k=0;k<g.points.length;k++){
            for(int l=0;l<g.points[k].edges.size();l++){
                if(g.points[k].dis>g.points[k].edges.get(l).end.dis+g.points[k].edges.get(l).dis){
                           return false;
                }
            }
        }
        return true;
    }
    public static void print_path(Graph g,Point s,Point e){
        System.out.print(e.name+","+e.dis+",  ");
        if(e.forward==null){

        }
        else if(s==e){
            
        }
        else{
          //  System.out.print(e.forward.name+","+e.forward.dis);
            print_path(g, s, e.forward);
        }
    }
    public static int[][] extend_shortest_paths(int[][] l,int[][] w){
        int n=l.length;
        int[][] l1=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                l1[i][j]=100;//等价于无穷
                for(int k=0;k<n;k++){
                    if(l[i][k]+w[k][j]<l1[i][j]){
                        l1[i][j]=l[i][k]+w[k][j];
                        
                      //  System.out.println(i+","+k+","+j);
                    }
                    
                    
                }
            }
        }
        return l1;
    }
    public static int[][] slow_all_pairs_shortest_paths(int[][] w){
        int n=w.length;
        int[][] l1=w;
        for(int m=1;m<n-1;m++){
            l1=extend_shortest_paths(l1, w);
        }
        return l1;
    }
}
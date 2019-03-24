import java.lang.Math;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
//import java.util.List;
class cloestPoint{
    public static void main(String[] args) {
        Point[] points=new Point[100];
        ArrayList<Point> pointsP = new ArrayList<Point>();
        setPoints(points);
        
   //     Arrays.sort(points);
        Arrays.sort(points,new MyComprator());
       
        for(int i=0;i<points.length;i++){
            points[i].printPoint();
            pointsP.add(points[i]);
        }
        System.out.println(cloestPointsFZ(pointsP));
        cloestPointsBL(points);
        return;
    }
    public static void setPoints(Point[] p){
        for(int i=0;i<p.length;i++){
            p[i]=new Point();
            p[i].setX((int)(Math.random()*(1000)));
            p[i].setY((int)(Math.random()*(1000)));
            p[i].printPoint();
        }
    }//生成横纵坐标范围在1000以内的点
    public static void cloestPointsBL(Point[] p){
        double mindis=1000;
        int a=0,b=0;
        for(int i=0;i<p.length;i++){
            for(int j=i+1;j<p.length;j++){
                double dis=p[i].distance(p[j]);
                if(dis<mindis){
                    mindis=dis;
                    a=i;
                    b=j;
                }
            }
        }
        System.out.println("第"+(a+1)+"个点("+p[a].getX()+","+p[a].getY()+")与第"+(b+1)+"个点("+p[b].getX()+","+p[b].getY()+"),的距离为"+mindis);
    }//暴力方法求点集的最近点对，输出点及距离
    public static double cloestPointsBL(ArrayList<Point> p){
        double mindis=1000;
    //    int a=0,b=0;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                double dis=p.get(i).distance(p.get(j));
                if(dis<mindis){
                    mindis=dis;
     //               a=i;
      //              b=j;
                }
            }
        }
       return mindis;
    }//暴力方法求点集的最近点对，输出距离
    public static double cloestPointsFZ(ArrayList<Point> p){
        double md=0;
        if(p.size()<3){
            md= cloestPointsBL(p);
        }
        else{
            ArrayList<Point> pointsL = new ArrayList<Point>();
            ArrayList<Point> pointsR = new ArrayList<Point>();//开辟用于分割点集的数组

            int mid=(0+p.size())/2;
            for(int i=0;i<p.size();i++){
                if(i<=mid){
                    pointsL.add(p.get(i));
                }
                else{
                    pointsR.add(p.get(i));
                }
            }//将点集分为左右两部分
            double md1=cloestPointsFZ(pointsL);
            double md2=cloestPointsBL(pointsR);
            md=Math.min(md1,md2);

            //对l-md~l+md区间内的点进行考虑
            double left=p.get(mid).getX()-md;
            double right=p.get(mid).getX()+md;

            ArrayList<Point> pointsBetween = new ArrayList<Point>();
            for(int i=0;i<p.size();i++){
                if(p.get(i).getX()>=left&&p.get(i).getX()<=right){
                    pointsBetween.add(p.get(i));
                }
            }
            Point[] Pb= new Point[pointsBetween.size()];
            for(int i=0;i<Pb.length;i++){
                Pb[i]=new Point();
                Pb[i]=pointsBetween.get(i);
            }
            Arrays.sort(Pb,new MyComprator());//对pointsBetween中的点集按y排序
            for(int i=0;i<Pb.length;i++){
                for(int j=i+1;j<i+8&&j<Pb.length;j++){
                    if(Pb[i].distance(Pb[j])<md){
                        md=Pb[i].distance(Pb[j]);
                    }
                }
            }
        //    System.out.println("("+result[0].getX()+","+result[0].getY()+"),("+result[1].getX()+","+result[1].getY()+"),的距离为"+md);
            
        }
     //   System.out.println(md);
        return md;
    }
  
}//分治法求最近点对，仅输出距离
class Point{
    private double x=0;
    private double y=0;

    public Point(){}
    Point(double x1,double y1){
        this.x=x1;
        this.y=y1;
    }

    public double getX(){
        return this.x;
    }
    public double getY(){
        return this.y;
    }
    public void setX(double x1){
         this.x=x1;
    }
    public void setY(double y1){
         this.y=y1;
    }


    public double distance(Point b){
        return Math.sqrt((this.x-b.x)*(this.x-b.x)+(this.y-b.y)*(this.y-b.y));
    }
    public void printPoint(){
        System.out.println("X:" + this.x + "，y:" + this.y);
    }
    public boolean compare(Point b) {
        if(this.getX()!=b.getX()||this.getY()!=b.getY()){
            return false;
        }
        else{
            return true;
        }
      //  return ;
    }

}
class MyComprator implements Comparator {
    public int compare(Object arg0, Object arg1) {
        Point t1=(Point)arg0;
        Point t2=(Point)arg1;
        if(t1.getX() != t2.getX())
            return t1.getX()>t2.getX()? 1:-1;
        else
            return t1.getY()>t2.getY()? 1:-1;
    }
}
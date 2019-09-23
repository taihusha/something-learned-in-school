import java.lang.Math;
class fuhe{
    public static void main(String[] args) {
        double sum=0;
        double simpson=0;
        double h=0.0001;
        double N=48/h;
        for(int n=1;n<N-1;n++){
            double x=n*h;
            sum+=function(x);
            if(n<N/2+1){
                simpson+=2*function(2*(n-1)*h)+function(2*h*n);
            }
        }
        double y=h/2*(function(0)+function(48)+2*sum);
        double y1=h/3*(function(0)-function(48)+2*simpson);
        System.out.println("复合梯形求积公式："+y+"，复合辛普森求积公式："+y1);
    }
    public static double function(double x){
        return Math.sqrt(1+Math.cos(x)*Math.cos(x));
        
    }
}
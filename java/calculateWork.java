class calculateWork{
    public static void main(String[] args) {
      /*    double[][] a={ {1,2,3,4,5},
                       {-2,3,4,5,6},
                       {-3,-4,5,6,7},
                       {-4,-5,-6,7,8},
                       {-5,-6,-7,-8,9}
                     };
        double[] b={55,66,63,36,-25};     */
        double[][] a={ {-3,1,1,1,1},
                       {-1,-7,1,1,1},
                       {-1,-1,-11,1,1},
                       {-1,-1,-1,-15,1},
                       {1,2,3,4,5}
                     };
        double[] b={11,-3,-27,-61,55}; 
        /* double[][] a={ {5,-1,-1,-1},
                       {-1,10,-1,-1},
                       {-1,-1,5,-1},
                       {-1,-1,-1,10}
                    };
        double[] b={-4,12,8,34};    */
        double[] x=Jacobi(a,b);
        for(int i=0;i<x.length;i++)
        {
            System.out.print(x[i]+" ,");
            
        } 
        System.out.println();
        double[] y=Gauss_Seidel(a,b);
        for(int i=0;i<y.length;i++)
        {
            System.out.print(y[i]+" ,");
            
        }
    }
    public static double toBeZheng(double num){
        if(num<0){
            return -num;
        }
        return num;
    }
    public static double umlimited_num(double[] a){
        double max= toBeZheng(a[0]);
        for(int i=0;i<a.length;i++){
            if(max< toBeZheng(a[i])){
                max=toBeZheng(a[i]);
            }
        }
        return max;
    }
    public static double[] Jacobi(double[][] a,double[] b){
        int n=a.length;
        double[] x=new double[n];
        double[] y=new double[n];
        double[] delta=new double[n];
        int k=0;
        double sub=0;
        double w=0.78;//最佳松弛因子
        do{
            for(int i=0;i<n;i++){
                x[i]=y[i];
            }
/* 
            for(int i=0;i<n;i++){
                double temp=0;
                for(int j=0;j<n;j++){
                    if(i!=j){
                        temp+=a[i][j]*x[j];
                    }
                }
                y[i]=(b[i]-temp)/a[i][i];
            } *///w=1
            for(int i=0;i<n;i++){
                double temp=0;
                for(int j=0;j<n;j++){
                    
                        temp+=a[i][j]*x[j];
                    
                }
                y[i]=x[i]+w*(b[i]-temp)/a[i][i];
            }//w!=0 
            ++k;
            if(k>100){
                System.out.println("迭代失败");
                break;
            }
            for(int i=0;i<n;i++){
                delta[i]=x[i]-y[i];
            }
            sub=umlimited_num(delta);
        }while(sub>0.00001|| sub<-0.00001);
        System.out.println(k);
        return y;
    }
    public static double[] Gauss_Seidel(double[][] a,double[] b){
        int n=a.length;
        double[] x=new double[n];
        double[] y=new double[n];
        double[] delta=new double[n];
        int k=0;
        double sub=0;
        double w=0.976668888;
        while(true){
            for(int i=0;i<n;i++){
                x[i]=y[i];
            } 
            /* for(int i=0;i<n;i++){
                double temp=0;
                for(int j=0;j<n;j++){
                    if(j<i){
                        temp+=a[i][j]*y[j];
                    }
                    else if(j>i){
                        temp+=a[i][j]*x[j];
                    }
                }
                
                y[i]=(b[i]-temp)/a[i][i];
            }//w=1 */
            for(int i=0;i<n;i++){
                double temp=0;
                for(int j=0;j<n;j++){
                    if(j<i){
                        temp+=a[i][j]*y[j];
                    }
                    else if(j>=i){
                        temp+=a[i][j]*x[j];
                    }
                }
                
                y[i]=x[i]+w*(b[i]-temp)/a[i][i];
            }//w!=1 
            ++k;
            if(k>100){
                System.out.println("迭代失败");
                break;
            }
            for(int i=0;i<n;i++){
                delta[i]=y[i]-x[i];
            }
            sub=umlimited_num(delta);
            if(sub<0.00001 && sub>-0.00001)
            {
                break;
            }
        }
           
           
        
        System.out.println(k);
        return y;
    }

    public interface func{
        double f(double x);
    }
    public class DerivedFunction{
        public static final double Delta=0.00000001;
        public func function;

        public DerivedFunction(func function){
            this.function=function;
        }

        public double get(double x){
            return (function.f(x+Delta)-function.f(x))/Delta;
        }
    }
    public static void newton() {
        
    }
}

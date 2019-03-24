
class Test{
    public static void main(String[] args) {
        System.out.println("hello world");
        Matrix a=new Matrix(16);
        a.newMatrix();
        Matrix b=new Matrix(16);
        b.newMatrix();
        Matrix result2=new Matrix(16);
        result2.newMatrix();
        System.out.println("MatrixA:");
        a.printMatrix();
        System.out.println("MatrixB:");
        b.printMatrix();
        Matrix result=new Matrix(16);
        strassen(16, a, b, result);
        System.out.println("strassen:");
        result.printMatrix();
        a.matrixMul(b,result2);
        System.out.println("normal:");
        result2.printMatrix();
    }
    public static void strassen(int n,Matrix a,Matrix b,Matrix result){
        int halfsize=n/2;
        if(n==2){
            a.matrixMul(b, result);
            return;
        }
        else{
        Matrix a11=new Matrix(halfsize);
        Matrix a12=new Matrix(halfsize);
        Matrix a21=new Matrix(halfsize);
        Matrix a22=new Matrix(halfsize);

        Matrix b11=new Matrix(halfsize);
        Matrix b12=new Matrix(halfsize);
        Matrix b21=new Matrix(halfsize);
        Matrix b22=new Matrix(halfsize);
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                a11.elements[i][j]=a.elements[i][j];
                a12.elements[i][j]=a.elements[i][j+n/2];
                a21.elements[i][j]=a.elements[i+n/2][j];
                a22.elements[i][j]=a.elements[i+n/2][j+n/2];
    
                b11.elements[i][j]=b.elements[i][j];
                b12.elements[i][j]=b.elements[i][j+n/2];
                b21.elements[i][j]=b.elements[i+n/2][j];
                b22.elements[i][j]=b.elements[i+n/2][j+n/2];
            }
        }
        
        //递归求M1
        Matrix m1=new Matrix(halfsize);
        strassen(halfsize,a11.matrixAdd(a22),b11.matrixAdd(b22),m1); 
        //M1=(A11+A22)*(B11+B22)          p5=(a+d)*(e+h)  
        //递归求M2
        Matrix m2=new Matrix(halfsize);
        strassen(halfsize,a21.matrixAdd(a22),b11,m2);
        //M2=(A21+A22)B11                 p3=(c+d)*e
        //递归求M3
        Matrix m3=new Matrix(halfsize);
        strassen(halfsize,a11,b12.matrixSubstract(b22),m3);
        //M3=A11(B12-B22)                  p1=a*(f-h)
        //递归求M4
        Matrix m4=new Matrix(halfsize);
        strassen(halfsize,a22,b21.matrixSubstract(b11),m4);
        //M4=A22(B21-B11)                  p4=d*(g-e)
        //递归求M5
        Matrix m5=new Matrix(halfsize);
        strassen(halfsize,a11.matrixAdd(a12),b22,m5);
        //M5=(A11+A12)B22                  p2=(a+b)*h
        //递归求M6
        Matrix m6=new Matrix(halfsize);
        strassen(halfsize,a21.matrixSubstract(a11),b11.matrixAdd(b12),m6);
        //M6=(A21-A11)(B11+B12)          p7=(c-a)(e+f)
        //递归求M7
        Matrix m7=new Matrix(halfsize);
        strassen(halfsize,a12.matrixSubstract(a22),b21.matrixAdd(b22),m7);
        //M7=(A12-A22)(B21+B22)          p6=(b-d)*(g+h)
    
        //计算结果子矩阵
    //    C11  <-  M1 + M4 - M5 + M7;

    //    C12  <-  M3 + M5;

    //    C21  <-  M2 + M4;

    //    C22  <-  M1 + M3 - M2 + M6;

        Matrix c11=new Matrix(halfsize);
    //    m1.matrixAdd(m4, temp);
     //   temp.matrixSubstract(m5, temp);
     //   temp.matrixAdd(m7, c11);
        c11=((m1.matrixAdd(m4)).matrixSubstract(m5)).matrixAdd(m7);

        Matrix c12=new Matrix(halfsize);
        m3.matrixAdd(m5,c12);

        Matrix c21=new Matrix(halfsize);
        m2.matrixAdd(m4,c21);

        Matrix c22=new Matrix(halfsize);
     //   m1.matrixAdd(m3, temp);
     //   temp.matrixSubstract(m2, temp);
     //   temp.matrixAdd(m6, c22);
        c22=((m1.matrixAdd(m3)).matrixSubstract(m2)).matrixAdd(m6);
        //at this point , we have calculated the c11..c22 matrices, and now we are going to
        //put them together and make a unit matrix which would describe our resulting Matrix.
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                result.elements[i][j]=c11.elements[i][j];
                result.elements[i][j+n/2]=c12.elements[i][j];
                result.elements[i+n/2][j]=c21.elements[i][j];
                result.elements[i+n/2][j+n/2]=c22.elements[i][j];
            }
        }
    }
}
    
}
class Matrix{
    
    int number;//矩阵阶数
    int[][] elements;

    Matrix(){}
    Matrix(int n){
        this.number=n;
        int[][] array=new int[n][n];
        this.elements=array;

    }
    public void newMatrix(){
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                //int)(1+Math.random()*(10-1+1)) //从1到10的int型随数
           //    this.elements[i][j]=(int)(1+Math.random()*(10-1+1));
            this.elements[i][j]=1;//全1矩阵
            }
        }
    }
    public Matrix matrixSubstract(Matrix b){
        Matrix result=new Matrix(this.number);
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                result.elements[i][j]=this.elements[i][j]-b.elements[i][j];
            }
        }
        return result;
    }
    public void matrixSubstract(Matrix b,Matrix result){
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                result.elements[i][j]=this.elements[i][j]-b.elements[i][j];
            }
        }
    }
    public void matrixAdd(Matrix b,Matrix result){
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                result.elements[i][j]=this.elements[i][j]+b.elements[i][j];
            }
        }
    }
    public Matrix matrixAdd(Matrix b){
        Matrix result=new Matrix(this.number);
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                result.elements[i][j]=this.elements[i][j]+b.elements[i][j];
            }
        }
        return result;
    }
    public void matrixMul(Matrix b,Matrix result){
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                result.elements[i][j]=0;
                for(int k=0;k<this.number;k++)
                {
                    result.elements[i][j]=result.elements[i][j]+this.elements[i][k]*b.elements[k][j];
                }
            }
        }
    }

    public void printMatrix(){
        for(int i=0;i<this.number;i++)
        {
            for(int j=0;j<this.number;j++)
            {
                System.out.print(this.elements[i][j]+" ");
            }
            System.out.println();
        }
    }
}
